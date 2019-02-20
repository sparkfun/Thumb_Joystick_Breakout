// Thumb Joystick Breakout Example
// Modified by: Ho Yun "Bobby" Chan, SparkFun Electronics, 2/19
// Written by: Mike Grusin, SparkFun Electronics 3/11
// This code is free, baby. Use it however you like.

// This sketch shows the basic operation of the Thumb Joystick (COM-09032) and breakout board (BOB-09110).
// The joystick outputs two analog voltages (VERT and HORIZ), and one digital signal (SEL) for the pushbutton.

// Connections to joystick (change if you use different pins):

const int VERT = 0; // analog
const int HORIZ = 1; // analog
const int SEL = 2; // digital

// Also connect the joystick VCC to Arduino 5V, and joystick GND to Arduino GND.

// This sketch outputs serial data at 9600 baud (open Serial Monitor to view).

//initialize variables for analog and digital values
int vertical, horizontal, select;

void setup(){
  /* old method to turn on the pull-up resistor for the SEL line
     before Arduino IDE v1.01 (see http://arduino.cc/en/Tutorial/DigitalPins)
     make the SEL line an input*/
  //pinMode(SEL, INPUT);
  //digitalWrite(SEL, HIGH);

// make the SEL line an input
  pinMode(SEL, INPUT_PULLUP);

  // set up serial port for output
  Serial.begin(9600);
}

void loop(){

  // read all values from the joystick

  vertical = analogRead(VERT); // will be 0-1023
  horizontal = analogRead(HORIZ); // will be 0-1023
  select = digitalRead(SEL); // will be HIGH (1) if not pressed, and LOW (0) if pressed

  // print out the values

  Serial.print("vertical: ");
  Serial.print(vertical, DEC);
  Serial.print(" horizontal: ");
  Serial.print(horizontal, DEC);
  Serial.print(" select: ");
  if (select == HIGH) {
    Serial.println("not pressed");
  }
  else {
    Serial.println("PRESSED!");
  }
}
