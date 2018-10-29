#ifdef COMPETITIVE_MODE
void ULTRA_setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  ultraServo.attach(ULTRA_SERVOPIN);
}
void ULTRA_loop() {
  
  for (int i = 15; i <= 165; i++) {
    ultraServo.write(i);
    delay(30);
    calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
#ifdef PRINT_DISTANCE
    Serial.print(i); // Sends the current degree into the Serial Port
    Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print(distance); // Sends the distance value into the Serial Port
    Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
#endif
  }
  // Repeats the previous lines from 165 to 15 degrees
  for (int i = 165; i > 15; i--) {
    ultraServo.write(i);
    delay(30);
    calculateDistance();
#ifdef PRINT_DISTANCE
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
#endif
  }
}
void calculateDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2;
}
#endif
