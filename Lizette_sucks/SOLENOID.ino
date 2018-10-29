
void SOLENOID_setup(){
  pinMode(SOLENOID_PIN, OUTPUT);
}
void SOLENOID_loop() {
  if (SolenoidFlag == true) {
    while(buttonState){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("READY FOR BUTTON");
      byte state = digitalRead(BUTTON_PIN);
      delay(10);
      if (!state){
        for(int i = TIME_START; i >=0;i--){
          lcd.clear();
          lcd.print("TIME START:");
          lcd.print(i);
          delay(1000); 
        }
        buttonState = LOW;
      }
    }
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= INTERVAL) {
      previousMillis = currentMillis;
      if (solenoidState == LOW) {
        solenoidState = HIGH;
      } else {
        solenoidState = LOW;
      }
      digitalWrite(SOLENOID_PIN, solenoidState);    //Switch Solenoid ON/OFF
    }
  }
}
