// Engine warmp up
// Windows roll
// Detects controller position?
// locate car

#include <SoftwareSerial.h>

SoftwareSerial HM10(0, 1); // rx = 0 tx = 1

// pin definitions
#define R1 2
#define R2 3
#define R3 4
#define R4 5
#define R5 6
#define R6 7
#define R7 8
#define R8 9
#define LED 13

char serialData;  
String command = "";

void resetCommand(){
  command = "";
}

// toggles relay state
void toggle(int pin, String message){
  Serial.println(message);
  digitalWrite(pin, !digitalRead(pin));
  resetCommand();
}

void setup()
{
  Serial.begin(9600);
  Serial.println("HM10 serial started at 9600");
  HM10.begin(9600); // set HM10 serial at 9600 baud rate

  // pin modes
  pinMode(LED, OUTPUT); // onboard LED
  pinMode(R1, OUTPUT); // relay 1
  pinMode(R2, OUTPUT); // relay 2
  pinMode(R3, OUTPUT); // relay 3
  pinMode(R4, OUTPUT); // relay 4
  pinMode(R5, OUTPUT); // relay 5
  pinMode(R6, OUTPUT); // relay 6
  pinMode(R7, OUTPUT); // relay 7
  pinMode(R8, OUTPUT); // relay 8

  // default pin values
  digitalWrite(LED, LOW); // switch OFF LED
  // active low pins
  digitalWrite(R1, HIGH); // switch OFF relay 1
  digitalWrite(R2, HIGH); // switch OFF relay 2
  digitalWrite(R3, HIGH); // switch OFF relay 3
  digitalWrite(R4, HIGH); // switch OFF relay 4
  digitalWrite(R5, HIGH); // switch OFF relay 5
  digitalWrite(R6, HIGH); // switch OFF relay 6
  digitalWrite(R7, HIGH); // switch OFF relay 7
  digitalWrite(R8, HIGH); // switch OFF relay 8
}

void loop()
{
  // listen the HM10 port (LED)
  HM10.listen();
  digitalWrite(LED, HIGH); // switch ON LED
  while (HM10.available() > 0) {
    serialData = HM10.read();
    command = String(serialData);
    Serial.write(serialData);
  }

  // reads user input if availaLED.
  if (Serial.available()) {
    delay(10);
    HM10.write(Serial.read());
  }

  // set a relays
  if (command == "A") {
    toggle(R1, "Relay 1");
  }

  if (command == "B") {
    toggle(R2, "Relay 2");
  }

  if (command == "C") {
    toggle(R3, "Relay 3");
  }

  if (command == "D") {
    toggle(R4, "Relay 4");
  }

  // set b relays
  if (command == "E") {
    toggle(R5, "Relay 5");
  }

  if (command == "F") {
    toggle(R6, "Relay 6");
  }

  if (command == "G") {
    toggle(R7, "Relay 7");
  }

  if (command == "H") {
    toggle(R8, "Relay 8");
  }
}
