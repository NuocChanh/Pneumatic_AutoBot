// initialize the library with the numbers of the interface pins
#ifdef LCD_DISPLAY
/*********************************************************/
void LCD_setup()
{
  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight 
}

#endif
