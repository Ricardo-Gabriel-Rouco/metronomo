// importamos librerias
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// iniciamos el lcd
LiquidCrystal_I2C lcd(0x27, 16, 2);

// pines
int pulsadorMas = 2;
int pulsadorMenos = 3;
int pulsadorReset = 4;
int latchPin = 8;
int buzzer = 11;
int dataPin = 12;
int clockPin = 13;

// Variables const
const int tempo = 60000;
const int limiteSup = 300;
const int limiteInf = 10;
const int BPMdefault = 120;

// variables iniciales
int BPM = BPMdefault;
byte myByte = 0b00000000; // Inicialmente todos los LEDs apagados
float dt;

// unsigned long ultimoTiempoMas = 0;
// unsigned long ultimoTiempoMenos = 0;
// unsigned long intervaloDebounce = 50; // Tiempo de debounce en milisegundos

// funciones
void actualizarRegistro(byte byteADesplazar)
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, byteADesplazar);
  digitalWrite(latchPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(pulsadorMas, INPUT);
  pinMode(pulsadorMenos, INPUT);
  pinMode(pulsadorReset, INPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tempo:");
}

void loop()
{
  int lecturamas = digitalRead(pulsadorMas);
  int lecturamenos = digitalRead(pulsadorMenos);
  int lecturareset = digitalRead(pulsadorReset);
  // && millis() - ultimoTiempoMas > intervaloDebounce
  // && millis() - ultimoTiempoMenos > intervaloDebounce
  lcd.setCursor(7, 0);
  dt = ((tempo / BPM) / 4) * -1;

  if (lecturamas == HIGH && BPM < limiteSup)
  {
    BPM = BPM + 10; // Aumenta BPM en 10 pero no supera el límite de 400
  }
  else if (lecturamas == HIGH && BPM == limiteSup)
  {
    tone(buzzer, 2500, 100);
  }

  if (lecturamenos == HIGH && BPM > limiteInf)
  {
    BPM = BPM - 1; // Disminuye BPM en 10 pero no baja del límite de 10
  }
  else if (lecturamenos == HIGH && BPM == limiteInf)
  {
    tone(buzzer, 2500, 100);
  }

  if (lecturareset == HIGH)
  {
    BPM = BPMdefault;
    tone(buzzer, 1500, 100);
  }
  for (int i = 0; i < 8; i++)
  {
    myByte |= (1 << i); // Enciende el i-ésimo LED
    actualizarRegistro(myByte);
    delay(dt);
    tone(buzzer, 1000, 20);
  }

  for (int i = 7; i >= 0; i--)
  {
    myByte &= ~(1 << i); // Apaga el i-ésimo LED
    actualizarRegistro(myByte);
    delay(dt);
    tone(buzzer, 1000, 20);
  }

  if (BPM < 100)
  {
    lcd.print(0);
    lcd.print(BPM);
  }
  else
  {
    lcd.print(BPM);
  }
  delay(200);
}
