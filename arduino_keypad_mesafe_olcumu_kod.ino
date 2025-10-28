#include <Keypad.h>

const int trigPin = 13;
const int echoPin = 12;
const int greenLedPin = 11;
const int redLedPin = 10;

const int numRows = 4;
const int numCols = 3;

byte rowPins[numRows] = {5, 6, 8, 9};
byte colPins[numCols] = {4, 3, 2};   

char keys[numRows][numCols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, numRows, numCols);

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    int distance = getDistance();
    Serial.println("Mesafe: " + String(distance) + " cm");
    
    if (checkRange(key, distance)) {
      digitalWrite(greenLedPin, HIGH);
      digitalWrite(redLedPin, LOW);
    } else {
      digitalWrite(greenLedPin, LOW);
      digitalWrite(redLedPin, HIGH);
    }
  } else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  }
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  return pulseIn(echoPin, HIGH) * 0.034 / 2;
}

bool checkRange(char key, int distance) {
  int lowerLimit, upperLimit;
  
  switch (key) {
    case '1':
      lowerLimit = 0;
      upperLimit = 20;
      break;
    case '4':
      lowerLimit = 20;
      upperLimit = 40;
      break;
    case '7':
      lowerLimit = 40;
      upperLimit = 60;
      break;
    default:
      return false;
  }
  
  return (distance >= lowerLimit && distance < upperLimit);

}