#include <LiquidCrystal.h>

// Declaración de pines e instanciación de LCD
const int RS = 12;
const int E = 11;
const int DB4 = 4;
const int DB5 = 5;
const int DB6 = 6;
const int DB7 = 7;
LiquidCrystal lcd(RS,E,DB4,DB5,DB6,DB7);

// Mapas de caracteres personalizados para cruce peatonal
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

// Indicadores de modo de servicio
volatile boolean estadoInterrupcion = false;
volatile boolean enServicio = false;

// Configuración
// Variables utilizadas en tiempos para el semáforo
unsigned long unidadTiempoLuces = 150;
unsigned long multiplicadorAmarillo = 5;
unsigned long multiplicadorRojo = 14;
unsigned long multiplicadorServicio = 3;
unsigned long ciclosServicio = 10;
unsigned long tiempoBocina = 150;
unsigned long frecuenciaTono = 494;
const int filaSenalCruce = 0;
// Pin de interrupción
const byte pinInterrupcion = 2;


void setup(){
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

void loop(){
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
  tone(A1,frecuenciaTono,tiempoBocina);
  dosPasos(0,0);
  tone(A1,frecuenciaTono,tiempoBocina);
  dosPasos(2,2);
  dosPasos(4,0);
  dosPasos(6,2);
  tone(A1,frecuenciaTono,tiempoBocina);
  dosPasos(8,0);
  tone(A1,frecuenciaTono,tiempoBocina);
  dosPasos(10,2);
  dosPasos(12,0);
  dosPasos(14,2);
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

// Función para dar 2 pasos en el caracter personalizado de cruce peatonal
void dosPasos(int posicionCursor, int numCaracter){
  lcd.setCursor(posicionCursor,filaSenalCruce);
  lcd.write(byte(numCaracter));
  delay(unidadTiempoLuces);
  lcd.clear();
  lcd.setCursor(++posicionCursor,filaSenalCruce);
  lcd.write(byte(++numCaracter));
  delay(unidadTiempoLuces);
  lcd.clear();
}

// ISR
void interrupcionServicio(){
  // Toma el estado contrario, ya que el pin de interrupción se activa en LOW
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
  // Rutina de servicio
  lcd.print("En servicio");
  int contador =  0;
  while(contador < ciclosServicio){
    digitalWrite(A4, HIGH);
    delay(unidadTiempoLuces*ciclosServicio);
    digitalWrite(A4, LOW);
    delay(unidadTiempoLuces*ciclosServicio);
    contador++;
  }
  lcd.clear();
  digitalWrite(LED_BUILTIN, LOW);
  enServicio = false;
}