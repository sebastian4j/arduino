/** luz roja. */
int rojo = 5;
/** luz amarilla. */
int amarillo = 4;
/** luz verde. */
int verde = 3;
/** tiempo de permanencia en rojo y verde. */
int tiempo_permanencia = 4000;
/** cuantas veces parpadea el amarillo. */
int parpadeo_veces = 10;
int buzzer = 8;
boolean sonido = true;

void setup() {
  Serial.begin(9600);
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(13, LOW);
}


void loop() {
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
