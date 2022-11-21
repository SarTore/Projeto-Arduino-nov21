#include <LiquidCrystal.h>
LiquidCrystal lcd_1(12, 11, 6,5, 4, 3);

int pinIr1 = A0;
int pinIr2 = A1;
int seconds = 0;
int count1 = 0, count2 = 0;
int XCoord = 5;
int input1 = 0, input2 = 0;
int lastInput1 = 0, lastInput2 = 0;
unsigned long lapMillis1 = 0, lapMillis2 = 0;
unsigned long startMillis1 = millis(), startMillis2 = millis();
unsigned long bestMillis1 = 9999999, bestMillis2 = 9999999 ;
float lapTime1 = 0.00, lapTime2 = 0.00;
float bestLap1 = 0.00, bestLap2 = 0.00;
float track = 6.320;


void setup()
{
  lcd_1.begin(16, 2);
  Serial.begin(9600);
  pinMode(6, INPUT);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), restart, CHANGE);
  lcd_1.setCursor(0,0);
  lcd_1.print("CAR 1");
  Serial.print("CAR 1 ");
  lcd_1.setCursor(0,1);
  lcd_1.print(count1);
  Serial.print(count1);
  Serial.print(" ");
  Serial.println("0.00");
  lcd_1.setCursor(2,1);
  lcd_1.print("0.00");
  lcd_1.setCursor(8,0);
  lcd_1.print("CAR 2");
  Serial.print("CAR 2 ");
  lcd_1.setCursor(8,1);
  lcd_1.print(count2);
  Serial.print(count2);
  Serial.print(" ");
  Serial.println("0.00");
  lcd_1.setCursor(10,1);
  lcd_1.print("0.00");
}

void loop()
{
  int input1 = analogRead(pinIr1);
    if(input1 > 500){
      count1++;
      lcd_1.setCursor(0,0);
      lcd_1.print("CAR 1");
      
      lcd_1.setCursor(0,1);
      lcd_1.print(count1);
      
      lcd_1.setCursor(8,0);
      lcd_1.print("CAR 2");
      
      lcd_1.setCursor(8,1);
      lcd_1.print(count2);
      
      lapMillis1 = millis() - startMillis1;
      startMillis1 = millis();
      lapTime1 = lapMillis1 / 1000.00;
      if (lapMillis1 < bestMillis1){
          bestMillis1 = lapMillis1;
          bestLap1 = lapTime1;
          lcd_1.setCursor(2,1);
          lcd_1.print(track/bestLap1);
    }
    while(analogRead(pinIr1) > 500){};
    Serial.print("CAR 1 ");
    Serial.print(count1);
    Serial.print(" ");
    Serial.println(track/bestLap1);
    Serial.print("CAR 2 ");
    Serial.println(count2);
    Serial.print(" ");
    Serial.println(track/bestLap2);
  }

  int input2 = analogRead(pinIr2);
    if(input2 > 500){
      count2++;
      lcd_1.setCursor(0,0);
      lcd_1.print("CAR 1");
      lcd_1.setCursor(0,1);
      lcd_1.print(count1);
      lcd_1.setCursor(8,0);
      lcd_1.print("CAR 2");
      lcd_1.setCursor(8,1);
      lcd_1.print(count2);
      lapMillis2 = millis() - startMillis2;
      startMillis2 = millis();
      lapTime2 = lapMillis2 / 1000.00;
      if (lapMillis2 < bestMillis2){
          bestMillis2 = lapMillis2;
          bestLap2 = lapTime2;
          lcd_1.setCursor(2,1);
          lcd_1.print(track/bestLap2);
    }
    while(analogRead(pinIr2) > 500){};
    Serial.print("CAR 1 ");
    Serial.print(count1);
    Serial.print(" ");
    Serial.println(track/bestLap1);
    Serial.print("CAR 2 ");
    Serial.println(count2);
    Serial.print(" ");
    Serial.println(track/bestLap2);
  }
  if (count1 == 10 and count2 < 10){
    Serial.println("CAR 1 WON");
    delay(4000);
    restart();
  }
  else if(count1 < 10 and count2 == 10){
    Serial.println("CAR 2 WON");
    delay(4000);
    restart();
  }
} 



void restart(){
  count1 = 0;
  count2 = 0;
  lapMillis1 = 0, lapMillis2 = 0;
  bestMillis1 = 9999999, bestMillis2 = 9999999 ;
  lapTime1 = 0.00, lapTime2 = 0.00;
  bestLap1 = 0.00, bestLap2 = 0.00;
  lcd_1.setCursor(0,0);
  lcd_1.print("CAR 1");
  lcd_1.setCursor(0,1);
  lcd_1.print(count1);
  lcd_1.setCursor(2,1);
  lcd_1.print("0.00");
  lcd_1.setCursor(8,0);
  lcd_1.print("CAR 2");
  lcd_1.setCursor(8,1);
  lcd_1.print(count2);
  lcd_1.setCursor(10,1);
  lcd_1.print("0.00");
  Serial.print("CAR 1 ");
    Serial.print(count1);
    Serial.print(" ");
    Serial.println(track/bestLap1);
    Serial.print("CAR 2 ");
    Serial.println(count2);
    Serial.print(" ");
    Serial.println(track/bestLap2);
    
}
