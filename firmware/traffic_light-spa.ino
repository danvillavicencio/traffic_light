#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,4,5,6,7);

byte pos0[8] = {
  B00100,
  B00100,
  B01110,
  B10101,
  B01010,
  B01001,
  B10001,
};
byte pos1[8] = {
  B00100,
  B00100,
  B01110,
  B00110,
  B00110,
  B00101,
  B01001,
};
byte pos2[8] = {
  B00100,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B01001,
};
byte pos3[8] = {
  B00100,
  B00100,
  B01110,
  B10101,
  B00110,
  B01001,
  B10001,
};

unsigned long unidadTiempoLuces = 150;
unsigned long multiplicadorAmarillo = 5;
unsigned long multiplicadorRojo = 14;

const byte pinInterrupcion = 2;

volatile boolean estadoInterrupcion = false;
volatile boolean enServicio = false;

void setup()
{
  // Declaración de entradas y salidas
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A0, INPUT);
  // Declaración de interrupción para modo servicio
  pinMode(pinInterrupcion, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinInterrupcion), interrupcionServicio, FALLING);
  // Creación de caracteres personalizados para cruce peatonal
  lcd.createChar(0,pos0);
  lcd.createChar(1,pos1);
  lcd.createChar(2,pos2);
  lcd.createChar(3,pos3);
  // Inicialización de LCD
  lcd.begin(16,2);
  lcd.print("Semaforo");
  delay(2000);
  lcd.clear();
  
  // Empezar con todos los LEDs y bocina apagados (reiniciar secuencia)
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(A5, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A1, LOW);
}

void loop()
{
  while(!enServicio){
    luzRoja();
    luzVerde();
    luzAmarilla();
  }
  servicio();
}

// Secuencia luz verde
void luzVerde(){
  // Activa también la bocina y el signo de caminar
  digitalWrite(A3, HIGH);
  tone(A1,494,150);
  lcd.home(); lcd.write(byte(0)); delay(unidadTiempoLuces); lcd.clear();
  lcd.setCursor(1,0); lcd.write(byte(1)); delay(unidadTiempoLuces); lcd.clear();
  tone(A1,494,150);
  lcd.setCursor(2,0); lcd.write(byte(2)); delay(unidadTiempoLuces); lcd.clear();
  lcd.setCursor(3,0); lcd.write(byte(3)); delay(unidadTiempoLuces); lcd.clear();
  lcd.setCursor(4,0); lcd.write(byte(0)); delay(unidadTiempoLuces); lcd.clear();
  lcd.setCursor(5,0); lcd.write(byte(1)); delay(unidadTiempoLuces); lcd.clear();
  lcd.setCursor(6,0); lcd.write(byte(2)); delay(unidadTiempoLuces); lcd.clear();
  lcd.setCursor(7,0); lcd.write(byte(3)); delay(unidadTiempoLuces); lcd.clear();
  tone(A1,494,150);
  lcd.setCursor(8,0); lcd.write(byte(0)); delay(unidadTiempoLuces); lcd.clear();
  lcd.setCursor(9,0); lcd.write(byte(1)); delay(unidadTiempoLuces); lcd.clear();
  tone(A1,494,150);
  lcd.setCursor(10,0); lcd.write(byte(2)); delay(unidadTiempoLuces); lcd.clear();
  lcd.setCursor(11,0); lcd.write(byte(3)); delay(unidadTiempoLuces); lcd.clear();
  lcd.setCursor(12,0); lcd.write(byte(0)); delay(unidadTiempoLuces); lcd.clear();
  lcd.setCursor(13,0); lcd.write(byte(1)); delay(unidadTiempoLuces); lcd.clear();
  lcd.setCursor(14,0); lcd.write(byte(2)); delay(unidadTiempoLuces); lcd.clear();
  lcd.setCursor(15,0); lcd.write(byte(3)); delay(unidadTiempoLuces); lcd.clear();
  digitalWrite(A3, LOW);
}

// Secuencia luz amarilla
void luzAmarilla(){
  digitalWrite(A4, HIGH);
  delay(unidadTiempoLuces*multiplicadorAmarillo);
  digitalWrite(A4, LOW);
}

// Secuencia luz roja
void luzRoja(){
  digitalWrite(A5, HIGH);
  delay(unidadTiempoLuces*multiplicadorRojo);
  digitalWrite(A5, LOW);
}

void interrupcionServicio(){
  estadoInterrupcion = !digitalRead(pinInterrupcion);
  
  if(estadoInterrupcion){
    digitalWrite(LED_BUILTIN, HIGH);
    enServicio = true;
  }
}

//El pulsante pone al semáforo fuera de servicio
void servicio(){
  digitalWrite(A5, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A1, LOW);
    
  lcd.print("En servicio");
  int contador =  0;
  while(contador < 10){
    digitalWrite(A4, HIGH);
    delay(500);
    digitalWrite(A4, LOW);
    delay(500);
    contador++;
  }
  lcd.clear();
  digitalWrite(LED_BUILTIN, LOW);
  enServicio = false;
}