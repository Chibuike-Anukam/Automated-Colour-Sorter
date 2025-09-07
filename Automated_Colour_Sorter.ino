/*     Arduino Project - Color Sorting Machine
 *
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *
 */
#include <Servo.h>

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6

Servo topServo;
Servo bottomServo;

int frequency = 0;
int color=0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  topServo.attach(7);
  bottomServo.attach(8);

  Serial.begin(9600);
}

void loop() {

  topServo.write(130);
  delay(500);
  
  for(int i = 130; i > 70; i--) {
    topServo.write(i);
    delay(10);
  }
  delay(500);
  
  color = readColor();
  delay(10);  

  switch (color) {
    case 1:
    bottomServo.write(50);
    break;

    case 2:
    bottomServo.write(75);
    break;

    case 3:
    bottomServo.write(100);
    break;

    case 4:
    bottomServo.write(125);
    break;

    case 5:
    bottomServo.write(150);
    break;

    case 6:
    bottomServo.write(175);
    break;
    
    case 0:
    break;
  }
  delay(300);
  
  for(int i = 70; i > 10; i--) {
    topServo.write(i);
    delay(10);
  } 
  delay(200);
  
  for(int i = 10; i < 130; i++) {
    topServo.write(i);
    delay(10);
  }
  color=0;
}

// Modified readColor() function to accept wider ranges of RGB values to identify different shades of colours
// Used AI to help make modifications
int readColor() {
  // Test different filter combinations to find the correct one
  
  // Try RED filter (original was S2=LOW, S3=LOW)
  digitalWrite(S2, LOW);  // Changed from LOW
  digitalWrite(S3, LOW);  // Changed from LOW  
  frequency = pulseIn(sensorOut, LOW, 50000);
  int R = frequency;
  Serial.print("R= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(50);

  // Try GREEN filter (original was S2=HIGH, S3=HIGH) 
  digitalWrite(S2, HIGH);   // Changed from HIGH
  digitalWrite(S3, HIGH);   // Changed from HIGH
  frequency = pulseIn(sensorOut, LOW, 50000);
  int G = frequency;
  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(50);

  // Try BLUE filter (original was S2=LOW, S3=HIGH)
  digitalWrite(S2, LOW);  // Changed from LOW
  digitalWrite(S3, HIGH);   // Changed from HIGH
  frequency = pulseIn(sensorOut, LOW, 50000);
  int B = frequency;
  Serial.print("B= ");
  Serial.print(frequency);
  Serial.println("  ");
  delay(50);

  // Rest of your color detection logic stays the same
  Serial.print("RGB Values: R=");
  Serial.print(R);
  Serial.print(" G=");
  Serial.print(G);
  Serial.print(" B=");
  Serial.print(B);

  if(R == 0 && G == 0 && B == 0) {
    Serial.println(" -> No reading!");
    return 0;
  }

  color = 0;

  // Use percentage method for better reliability
  int total = R + G + B;
  if(total == 0) return 0;
  
  float redPercent = (float)R / total * 100;
  float greenPercent = (float)G / total * 100;
  float bluePercent = (float)B / total * 100;
  
  Serial.print(" Percentages: R=");
  Serial.print(redPercent);
  Serial.print("% G=");
  Serial.print(greenPercent);
  Serial.print("% B=");
  Serial.print(bluePercent);
  Serial.print("%");

  if(redPercent > 40 && redPercent > greenPercent && redPercent > bluePercent) {
    color = 1; // Red
    Serial.println(" -> RED");
  }
  else if(greenPercent > 40 && greenPercent > redPercent && greenPercent > bluePercent) {
    color = 3; // Green
    Serial.println(" -> GREEN");
  }
  else if(bluePercent > 40 && bluePercent > redPercent && bluePercent > greenPercent) {
    color = 6; // Blue
    Serial.println(" -> BLUE");
  }
  else if(redPercent > 30 && greenPercent > 30 && bluePercent < 20) {
    color = 4; // Yellow
    Serial.println(" -> YELLOW");
  }
  else if(redPercent > greenPercent && greenPercent > bluePercent && redPercent > 25) {
    color = 2; // Orange
    Serial.println(" -> ORANGE");
  }
  else if(redPercent > 25 && greenPercent > 25 && bluePercent > 25) {
    color = 5; // Brown/Dark
    Serial.println(" -> BROWN");
  }
  else {
    color = 0;
    Serial.println(" -> UNKNOWN");
  }
  
  return color;  
}
