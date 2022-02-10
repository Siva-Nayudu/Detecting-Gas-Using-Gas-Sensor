#include<LiquidCrystal.h>
#define GREEN 2
#define YELLOW 3
#define RED 4
#define Buzzer 5
#define Sensor A0

LiquidCrystal lcd(12, 11, 9, 8, 7, 6); //Sets the interfacing pins

void setup()
{
	for(int i=2; i<6; i++)
	{
		pinMode(i,OUTPUT);
		Serial.begin(9600); 
	}
	lcd.begin(16, 2); //Initializes the 16x2 LCD
	pinMode(10, INPUT);
}

void loop()
{
	for(int i=2;i<6;i++)
	{
		digitalWrite(i,LOW);
		status_indicator();
	}
}
void status_indicator()
{
	lcd.setCursor(0,0); //Sets the position of Output in LCD screen
	int sensor_val=analogRead(A0);
	Serial.println(sensor_val);
	if(sensor_val>=150)
	{
		digitalWrite(RED, HIGH);
		if(digitalRead(10)==1)
		{
			digitalWrite(Buzzer, HIGH);
		}
		lcd.print("DANGER: HIGH    "); //Prints the output on LCD 
	}
	else if(sensor_val>=120)
	{
		digitalWrite(YELLOW, HIGH);
		lcd.print("DANGER: MODERATE"); //Prints the output on LCD 
	}
	else
	{
	          digitalWrite(GREEN, HIGH);
		 lcd.print("DANGER: LOW    "); //Prints the output on LCD 
	}
	    delay(10); //delay
}		
