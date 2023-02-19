#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,9,8,7);


Servo servo1;
Servo servo2;
int x_key = A1;                                               
int y_key = A0;                                               
int x_pos;
int y_pos;
int servo1_pin =6 ;
int servo2_pin = 5;  
int initial_position = 90;
int initial_position1 = 90;

void setup ( ) {
Serial.begin (9600) ;
lcd.begin(16,2);
servo1.attach (servo1_pin ) ; 
servo2.attach (servo2_pin ) ; 
servo1.write (initial_position);
servo2.write (initial_position1);
pinMode (x_key, INPUT) ;                     
pinMode (y_key, INPUT) ;                      
}

void loop ( ) {
x_pos = analogRead (x_key) ;  
y_pos = analogRead (y_key) ;                      

if (x_pos < 300){
if (initial_position < 10) { } else{ initial_position = initial_position - 20; servo1.write ( initial_position ) ; lcd.print("M-1 H LEFT"); delay (100) ;
lcd.setCursor(3,1); lcd.clear(); } } if (x_pos > 700){
if (initial_position > 180)
{  
}  
else{
initial_position = initial_position + 20;
servo1.write ( initial_position ) ;
lcd.print("M-1 H RIGHT");
delay (100);
lcd.setCursor(3,1);
lcd.clear();
}
}

if (y_pos < 300){
if (initial_position1 < 10) { } else{ initial_position1 = initial_position1 - 20; servo2.write ( initial_position1 ) ;lcd.print("M-2 V LEFT");  delay (100) ;lcd.setCursor(3,1); lcd.clear(); } } if (y_pos > 700){
if (initial_position1 > 180)
{  
}        
else{
initial_position1 = initial_position1 + 20;
servo2.write ( initial_position1 ) ;
lcd.print("M-2 V RIGHT ");
delay (100) ;
lcd.setCursor(3,1);
lcd.clear();
}
}
}
