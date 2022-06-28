

// Load Wi-Fi library
#include <ESP8266WiFi.h>

// Replace with your network credentials
const char* ssid     = "IOT";
const char* password = "Aman@132";

// Set web server port number to 80
WiFiServer server(80);


// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String S1_STATE = "STOP";
String S2_STATE = "STOP";
String S3_STATE = "STOP";
String S4_STATE = "STOP";

// Assign output variables to GPIO pins
const int LEFT_MOTOR_S1 = 16;
const int LEFT_MOTOR_S2 = 5;
const int RIGHT_MOTOR_S1 = 4;
const int RIGHT_MOTOR_S2 = 0;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(LEFT_MOTOR_S1, OUTPUT);
  pinMode(LEFT_MOTOR_S2, OUTPUT);
   pinMode(RIGHT_MOTOR_S1, OUTPUT);
   pinMode(RIGHT_MOTOR_S2, OUTPUT);
  // Set outputs to LOW
  digitalWrite(LEFT_MOTOR_S1, LOW);
  digitalWrite(LEFT_MOTOR_S2, LOW);
  digitalWrite(RIGHT_MOTOR_S1, LOW);
  digitalWrite(RIGHT_MOTOR_S2, LOW);
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   

  if (client) {                             
    Serial.println("New Client.");          
    String currentLine = "";                
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { 
      currentTime = millis();         
      if (client.available()) {             
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /16/TURNING_LEFT") >= 0) {
              Serial.println("ROBOT IS TURNING LEFT");
              S1_STATE = "TURNING_LEFT";
              digitalWrite(LEFT_MOTOR_S1, HIGH);
              digitalWrite(RIGHT_MOTOR_S1, HIGH);
            } else if (header.indexOf("GET /16/STOP") >= 0) {
              Serial.println("STOP CONDITION");
              S1_STATE = "STOP";
              digitalWrite(LEFT_MOTOR_S1, LOW);
              digitalWrite(RIGHT_MOTOR_S1, LOW);
            } else if (header.indexOf("GET /4/TURNING_RIGHT") >= 0) {
              Serial.println("ROBOT IS TURNING RIGHT");
              S3_STATE = "TURNING_RIGHT";
              digitalWrite(RIGHT_MOTOR_S2, HIGH);
            } else if (header.indexOf("GET /4/STOP") >= 0) {
              Serial.println("STOP CONDITION");
              S3_STATE = "STOP";
              digitalWrite(RIGHT_MOTOR_S1, LOW);
            }else if (header.indexOf("GET /5/BACKWARD") >= 0) {
              Serial.println("BACKWARD");
              S2_STATE = "BACKWARD";
              digitalWrite(LEFT_MOTOR_S2, HIGH);
              digitalWrite(RIGHT_MOTOR_S2, HIGH);
            } else if (header.indexOf("GET /5/STOP") >= 0) {
              Serial.println("STOP CONDITION");
              S2_STATE = "STOP";
              digitalWrite(LEFT_MOTOR_S2, LOW);
              digitalWrite(RIGHT_MOTOR_S2, LOW);
            }else if (header.indexOf("GET /0/FORWARD") >= 0) {
              Serial.println("FORWARD");
              S4_STATE = "FORWARD";
              digitalWrite(RIGHT_MOTOR_S2, HIGH);
            } else if (header.indexOf("GET /0/STOP") >= 0) {
              Serial.println("STOP CONDITION");
              S4_STATE = "STOP";
              digitalWrite(RIGHT_MOTOR_S2, LOW);
            }
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #F08080; border: none; color: black; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #F08080;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>Martian</h1>");
            
            // Display current state, and ON/OFF buttons for GPIO 5  
            client.println("<p> ROBOT STATE " + S1_STATE + "</p>");
            // If the output5State is off, it displays the ON button       
            if (S1_STATE=="STOP") {
              client.println("<p><a href=\"/16/TURNING_LEFT\"><button class=\"button\"><</button></a></p>");
            } else {
              client.println("<p><a href=\"/16/STOP\"><button class=\"button button2\"><</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO 4  
            client.println("<p>ROBOT STATE " + S3_STATE + "</p>");
            // If the output4State is off, it displays the ON button       
            if (S3_STATE=="STOP") {
              client.println("<p><a href=\"/4/TURNING_RIGHT\"><button class=\"button\">></button></a></p>");
            } else {
              client.println("<p><a href=\"/4/STOP\"><button class=\"button button2\">></button></a></p>");
            }

            // Display current state, and ON/OFF buttons for GPIO 4  
            client.println("<p>ROBOT STATE " + S2_STATE + "</p>");
            // If the output4State is off, it displays the ON button       
            if (S2_STATE=="STOP") {
              client.println("<p><a href=\"/5/BACKWARD\"><button class=\"button\">></button></a></p>");
            } else {
              client.println("<p><a href=\"/5/STOP\"><button class=\"button button2\">></button></a></p>");
            }

            // Display current state, and ON/OFF buttons for GPIO 4  
            client.println("<p>ROBOT STATE " + S4_STATE + "</p>");
            // If the output4State is off, it displays the ON button       
            if (S4_STATE=="STOP") {
              client.println("<p><a href=\"/0/FORWARD\"><button class=\"button\">></button></a></p>");
            } else {
              client.println("<p><a href=\"/0/STOP\"><button class=\"button button2\">></button></a></p>");
            }
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
