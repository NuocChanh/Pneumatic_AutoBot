
void MOTOR_setup() {
  myservo.attach(SERVO_PIN);
  myservo.write(NEUTRAL_ANG);

}

void MOTOR_loop() {
  currentAngle = ypr[0] * 180 / M_PI;
  unsigned long currentMillis = millis() - previousMillis;

  if (currentMillis >= TIME2SETTLE and
      currentMillis < (TIME2SETTLE + 100) and
      SolenoidFlag == false) {

    destinatedAngle = currentAngle;
    tempAngle = destinatedAngle;
    SolenoidFlag = true;

  }
  else if (SolenoidFlag == true) {
    if (invertFlag == true) {
      currentAngle = currentAngle - TURN_ANGLE;
    }
    int motorAngle = NEUTRAL_ANG + (currentAngle - destinatedAngle);
    if (motorAngle < NEUTRAL_ANG - LIMIT) motorAngle = NEUTRAL_ANG - LIMIT;
    if (motorAngle > NEUTRAL_ANG + LIMIT) motorAngle = NEUTRAL_ANG + LIMIT;
    myservo.write(motorAngle);

#ifdef PRINT_ANGLE
    Serial.print("motorAngle: ");
    Serial.print(motorAngle);
    Serial.print("   currentAngle: ");
    Serial.print(currentAngle);
    Serial.print("   destAngle: ");
    Serial.println(destinatedAngle);
#endif
#ifdef LCD_DISPLAY
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("M");
    lcd.print((int)motorAngle);
    lcd.print(" C");
    lcd.print((int)currentAngle);
    lcd.print(" D");
    lcd.print((int)destinatedAngle);
    lcd.setCursor(0,1);
    lcd.print(" R");
    lcd.print((int)rotCount);
#endif
  }
  else if (currentMillis < TIME2SETTLE and SolenoidFlag == false) {
    byte temp_t = (currentMillis) / 1000;
    if (temp_t != oldTime) {
      oldTime = temp_t;
      //Serial.print("Time left to settle: ");
      //Serial.print(TIME2SETTLE / 1000 - oldTime);
      //Serial.println("s");
#ifdef LCD_DISPLAY
      lcd.clear();
      lcd.setCursor(0, 0);
      //lcd.print("CALIBRATION: ");
      lcd.print("FUCK YOU: ");
      lcd.print(TIME2SETTLE / 1000 - oldTime);
      lcd.print("s");
      //delay();
#endif

    }
  }
}

