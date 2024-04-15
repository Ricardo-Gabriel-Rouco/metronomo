#include <LiquidCrystal_I2C.h>
#include <Wire.h>  // Se corrigió, se eliminó el ; al final de la definición de WIRE

int tempo = 60000;
int BPM = 120;  // default para tempo promedio

LiquidCrystal_I2C lcd(0x27, 16, 2);

int pulsadorMas = 2;
int pulsadorMenos = 4;

void setup() {
  Serial.begin(9600);
  pinMode(pulsadorMas, INPUT_PULLUP);
  pinMode(pulsadorMenos, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tempo:");  // 6 caracteres
}

void loop() {
  int lecturamas = digitalRead(pulsadorMas);
  int lecturamenos = digitalRead(pulsadorMenos);
  switch (lecturamas) {
    case HIGH:
      if (BPM <= 400) {
        BPM = BPM + 10;
      }
      break;
  }
  switch (lecturamenos) {
    case HIGH:
      if (BPM > 10) {
        BPM = BPM - 10;
      }
    break;
  }


  lcd.setCursor(7, 0);
  lcd.print(BPM);
  delay(200);
}
