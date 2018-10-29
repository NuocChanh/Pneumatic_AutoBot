void REED_setup() {
  pinMode(REED_PIN, INPUT_PULLUP);
}

void REED_loop() {
  switchState = digitalRead(REED_PIN);

  if (!switchState) {
    if (state_Flag == true) {
      rotCount++;
      state_Flag = false;
    }
    countErr = 0;
  }
  else {
    countErr++;
    if (countErr > 5) state_Flag = true;
    //delay(1);
  }
  distTraveled = rotCount * (M_PI * WHEEL_DIA) / (12 * NUMBER_OF_MAGNET);
 
  if (distTraveled >= FIRST_DISTANCE and distTraveled < SECOND_DISTANCE)              //10ft is 13.5 wheel rotations                                            change COUNTER here!
  {
    invertFlag = false;
    destinatedAngle = tempAngle + TURN_ANGLE;
    if (destinatedAngle > 180) destinatedAngle = destinatedAngle - 360;
    if (destinatedAngle < -180) destinatedAngle = destinatedAngle + 360;
    if (destinatedAngle/currentAngle < 0) {
      invertFlag = true;
      destinatedAngle = tempAngle;
    }
    else invertFlag = false;
  }

  /*else if (distTraveled >= SECOND_DISTANCE and distTraveled < THIRD_DISTANCE)              //10ft is 13.5 wheel rotations                                            change COUNTER here!
  {
    invertFlag = false;
    destinatedAngle = tempAngle + TURN_ANGLE;
    if (destinatedAngle > 180) destinatedAngle = destinatedAngle - 360;
    if (destinatedAngle < -180) destinatedAngle = destinatedAngle + 360;
    if (destinatedAngle/currentAngle < 0) {
      invertFlag = true;
      destinatedAngle = tempAngle;
    }
    else invertFlag = false;
  }*/
  else if (distTraveled >= SECOND_DISTANCE){
  //else if (distTraveled >= THIRD_DISTANCE){
    SolenoidFlag = false;
    Serial.println("Destination Reached");
  }
  
  #ifdef PRINT_DISTANCE_TRAVELED
  Serial.print("Rot:");
  Serial.print(rotCount);
  Serial.print(" Dist:");
  Serial.println(distTraveled);
  #endif
}


















