/*     Arduino Project - Color Sorting Machine with Test Function
 *
 *  Modified to include filter combination testing
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
  
  // Give time to open Serial Monitor
  delay(2000);
  Serial.println("TCS3200 Filter Test - Place a RED object in front of sensor");
  Serial.println("Look for which combination gives the HIGHEST reading for red");
  Serial.println("==================================================");
}

void loop() {
  // TESTING MODE - Comment out this section once you find the right combinations
  Serial.println("Testing filter combinations...");
  testAllFilterCombinations();
  
  // NORMAL OPERATION - Uncomment this section once testing is done
  /*
  topServo.write(130);
  delay(500);
  
  for(int i = 130; i > 70; i--) {
    topServo.write(i);
    delay(2);
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
    delay(2);
  } 
  delay(200);
  
  for(int i = 10; i < 130; i++) {
    topServo.write(i);
    delay(2);
  }
  color=0;
  */
}

// Test function to find correct filter combinations
void testAllFilterCombinations() {
  Serial.println("Filter Combination Test:");
  
  // Test combination 1: S2=LOW, S3=LOW
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  delay(100); // Give time for filter to switch
  frequency = pulseIn(sensorOut, LOW, 50000);
  Serial.print("S2=LOW, S3=LOW (supposed to be RED): ");
  Serial.println(frequency);
  
  // Test combination 2: S2=LOW, S3=HIGH  
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  delay(100);
  frequency = pulseIn(sensorOut, LOW, 50000);
  Serial.print("S2=LOW, S3=HIGH (supposed to be BLUE): ");
  Serial.println(frequency);
  
  // Test combination 3: S2=HIGH, S3=LOW
  digitalWrite(S2, HIGH);
  digitalWrite(S3, LOW);
  delay(100);
  frequency = pulseIn(sensorOut, LOW, 50000);
  Serial.print("S2=HIGH, S3=LOW (supposed to be CLEAR): ");
  Serial.println(frequency);
  
  // Test combination 4: S2=HIGH, S3=HIGH
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  delay(100);
  frequency = pulseIn(sensorOut, LOW, 50000);
  Serial.print("S2=HIGH, S3=HIGH (supposed to be GREEN): ");
  Serial.println(frequency);
  
  Serial.println("==================================================");
  delay(3000); // Wait 3 seconds before next test
}

// Your original readColor function (currently not used during testing)
int readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW, 50000);
  int R = frequency;
  // Printing the value on the serial monitor
  Serial.print("R= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(50);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW, 50000);
  int G = frequency;
  // Printing the value on the serial monitor
  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(50);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW, 50000);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");
  Serial.print(frequency);
  Serial.println("  ");
  delay(50);

  // Your original detection logic with corrected operators
  if(R<45 && R>32 && G<65 && G>55){
    color = 1; // Red
  }
  if(G<55 && G>43 && B<47 && B>35){
    color = 2; // Orange
  }
  if(R<53 && R>40 && G<53 && G>40){
    color = 3; // Green
  }
  if(R<38 && R>24 && G<44 && G>30){
    color = 4; // Yellow
  }
  if(R<56 && R>46 && G<65 && G>55){
    color = 5; // Brown
  }
  if (G<58 && G>45 && B<40 && B>26){
    color = 6; // Blue
  }
  return color;  
}