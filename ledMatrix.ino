const int green1 = 13;
const int green2 = 12;
const int green3 = 11;
const int yellow = 10;
const int red = 9;
const int blue = 8;  

void setup() {
  Serial.begin(9600);
  pinMode(green1, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(green3, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  
  Serial.println("Hello, welcome to the LED Matrix program");
  Serial.println("Now, do you want to use the:");
  delay(2000);
  Serial.println("Manual mode activated.");
  Serial.println("Enter a command:");
  Serial.println("1. manual mode");
  Serial.println("2. automatic mode");
}

void loop() {
  if (Serial.available() > 0) {
    int option = Serial.read();
    if (option == '1') {
      handle_manualOptions();
    }
    if (option == '2') {
      matrix();
    }
  }
}

void handle_manualOptions(){
  Serial.println("Manual mode activated.");
  Serial.println("Enter a command:");
  Serial.println("Commands: green1, green1low, green2, green2low, green3, green3low, yellow, yellowlow, red, redlow, blue, bluelow, allOff, exit");

  bool manualMode = true;  

  while (manualMode) {
    if (Serial.available() > 0) {
      String command = Serial.readStringUntil('\n'); 
      command.trim();
      Serial.print("Command received: ");
      Serial.println(command);
      
      // Process commands for each LED.
      if (command.equalsIgnoreCase("green1")) {
        digitalWrite(green1, HIGH);
        Serial.println("Turning on GREEN1.");
      } else if (command.equalsIgnoreCase("green1low")) {
        digitalWrite(green1, LOW);
        Serial.println("Turning off GREEN1.");
      } else if (command.equalsIgnoreCase("green2")) {
        digitalWrite(green2, HIGH);
        Serial.println("Turning on GREEN2.");
      } else if (command.equalsIgnoreCase("green2low")) {
        digitalWrite(green2, LOW);
        Serial.println("Turning off GREEN2.");
      } else if (command.equalsIgnoreCase("green3")) {
        digitalWrite(green3, HIGH);
        Serial.println("Turning on GREEN3.");
      } else if (command.equalsIgnoreCase("green3low")) {
        digitalWrite(green3, LOW);
        Serial.println("Turning off GREEN3.");
      } else if (command.equalsIgnoreCase("yellow")) {
        digitalWrite(yellow, HIGH);
        Serial.println("Turning on YELLOW.");
      } else if (command.equalsIgnoreCase("yellowlow")) {
        digitalWrite(yellow, LOW);
        Serial.println("Turning off YELLOW.");
      } else if (command.equalsIgnoreCase("red")) {
        digitalWrite(red, HIGH);
        Serial.println("Turning on RED.");
      } else if (command.equalsIgnoreCase("redlow")) {
        digitalWrite(red, LOW);
        Serial.println("Turning off RED.");
      } else if (command.equalsIgnoreCase("blue")) {
        digitalWrite(blue, HIGH);
        Serial.println("Turning on BLUE.");
      } else if (command.equalsIgnoreCase("bluelow")) {
        digitalWrite(blue, LOW);
        Serial.println("Turning off BLUE.");
      } else if (command.equalsIgnoreCase("allOff")) {
        digitalWrite(green1, LOW);
        digitalWrite(green2, LOW);
        digitalWrite(green3, LOW);
        digitalWrite(yellow, LOW);
        digitalWrite(red, LOW);
        digitalWrite(blue, LOW);
        Serial.println("Turning all LEDs off.");
      } else if (command.equalsIgnoreCase("exit")) {
        Serial.println("Exiting manual mode.");
        manualMode = false;
      } else {
        Serial.println("Invalid command.");
        Serial.println("Valid commands: green1, green1low, green2, green2low, green3, green3low, yellow, yellowlow, red, redlow, blue, bluelow, allOff, exit");
      }
      
      // Prompt for the next command if still in manual mode.
      if (manualMode) {
        Serial.println("Enter next command:");
      }
    }
  }
}

void matrix(){
  // Sample matrix sequence for demonstration.
  digitalWrite(green3, HIGH);
  delay(1000);
  digitalWrite(green2, HIGH);
  delay(1000);
  digitalWrite(green1, HIGH);
  delay(1000);
  
  digitalWrite(green1, LOW);
  delay(1000);
  digitalWrite(green2, LOW);
  delay(1000);
  digitalWrite(green3, LOW);
  delay(1000);
  
  digitalWrite(red, HIGH);
  delay(1000);
  digitalWrite(red, LOW);
  
  digitalWrite(yellow, HIGH);
  digitalWrite(blue, HIGH);
  delay(1000);
  digitalWrite(yellow, LOW);
  digitalWrite(blue, LOW);
  
  // After the matrix sequence, halt further execution.
  while (true) {
    // Infinite loop stops the code until a reset.
  }
}
