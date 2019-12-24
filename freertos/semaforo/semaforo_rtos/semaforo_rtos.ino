#include <Arduino_FreeRTOS.h>

const int rojo = 5;
const int amarillo = 4;
const int verde = 3;
const int tiempo_permanencia = 4000;
const int parpadeo_veces = 10;
const int buzzer = 8;
const int pinPotenciometro = A0;
boolean sonido = false;
int lecturaPotenciometro = 0;
int porcentajePotenciometro = 0;
const int pinBoton = 2;

void Semaforo(void *pvParameters);
void Potenciometro(void *pvParameters);
void Boton(void *pvParameters);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  xTaskCreate(Semaforo, (const portCHAR *)"Semaforo", 128, NULL, 2, NULL);
  xTaskCreate(Potenciometro, (const portCHAR *)"Potenciometro", 128, NULL, 2, NULL);
  xTaskCreate(Boton, (const portCHAR *)"Boton", 128, NULL, 2, NULL);
}
void loop() {}


/** inicio código para el semáforo */
void Semaforo(void *pvParameters) {
  (void) pvParameters;
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  for (;;) {
    prender(rojo);
    apagar(amarillo, verde);
    delay(tiempo_permanencia);
    prender(verde);
    apagar(amarillo, rojo);
    if (sonido) {
      sonidoVerde();
    } else {
      delay(tiempo_permanencia);
    }
    apagar(rojo, verde);
    parpadearAmarillo();
  }
}

void sonidoVerde() {
  for (int i = 0; i < 6; i++) {
    for (int i = 0; i < 100; i++)  {
      digitalWrite(buzzer, HIGH);
      delay(1);
      digitalWrite(buzzer, LOW);
      delay(1);
    }
    delay(400);
  }
}

void parpadearAmarillo() {
  for (int i = 0; i < parpadeo_veces; i++)  {
    digitalWrite(amarillo, HIGH);
    delay(100);
    digitalWrite(amarillo, LOW);
    delay(200);
    for (int i = 0; i < 80 && sonido; i++)  {
      digitalWrite(buzzer, HIGH);
      delay(1);
      digitalWrite(buzzer, LOW);
      delay(1);
    }
  }
}


void apagarTodo() {
  digitalWrite(verde, LOW);
  digitalWrite(amarillo, LOW);
  digitalWrite(rojo, LOW);
}

void prender(int color) {
  digitalWrite(color, HIGH);
}

void apagar(int color1, int color2) {
  digitalWrite(color1, LOW);
  digitalWrite(color2, LOW);
}
/** fin codigo del semáforo */
///////////////////////////////////////////////////

/** inicio del potenciometro. */
void Potenciometro(void *pvParameters) {
  (void) pvParameters;
  for (;;) {
    lecturaPotenciometro = analogRead(pinPotenciometro);
    porcentajePotenciometro = map(lecturaPotenciometro, 0, 1023, 0, 100);  // convertir a porcentaje
    Serial.println(porcentajePotenciometro);
    delay(500);
  }
}
/** fin del potenciometro. */
///////////////////////////////////////////////////


/** inicio del botón. */
void Boton(void *pvParameters) {
  (void) pvParameters;
  pinMode(pinBoton, INPUT_PULLUP);
  int estado = 0;
  for (;;) {
    Serial.print("boton: ");
    Serial.println(estado);
    estado = digitalRead(pinBoton);
    if (estado == LOW) {
      sonido = true;
    } else {
      sonido = false;
    }
    delay(500);
  }
}
/** fin del botón. */
///////////////////////////////////////////////////
