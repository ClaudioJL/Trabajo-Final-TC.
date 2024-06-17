// Definición de pines para semáforos
int Semaforo_Rojo_1 = 12;
int Semaforo_Amarillo_1 = 11;
int Semaforo_Verde_1 = 10;

int Peatonal_Rojo_1 = 9;
int Peatonal_Verde_1 = 8;

int Semaforo_Rojo_2 = 7;
int Semaforo_Amarillo_2 = 6;
int Semaforo_Verde_2 = 5;

int Peatonal_Rojo_2 = 4;
int Peatonal_Verde_2 = 3;

// Definición de estados
enum Estados {S1, S2, S3, S4};
Estados estadoActual = S1;

void setup() {
  // Configuración de los pines como salidas
  pinMode(Semaforo_Rojo_1, OUTPUT);
  pinMode(Semaforo_Amarillo_1, OUTPUT);
  pinMode(Semaforo_Verde_1, OUTPUT);
  pinMode(Peatonal_Rojo_1, OUTPUT);
  pinMode(Peatonal_Verde_1, OUTPUT);
  pinMode(Semaforo_Rojo_2, OUTPUT);
  pinMode(Semaforo_Amarillo_2, OUTPUT);
  pinMode(Semaforo_Verde_2, OUTPUT);
  pinMode(Peatonal_Rojo_2, OUTPUT);
  pinMode(Peatonal_Verde_2, OUTPUT);
}

void loop() {
  switch (estadoActual) {
    case S1:
      digitalWrite(Semaforo_Verde_1, HIGH);
      digitalWrite(Peatonal_Rojo_1, HIGH);
      digitalWrite(Semaforo_Rojo_2, HIGH);
      digitalWrite(Peatonal_Verde_2, HIGH);
      delay(3000); // Espera de 3 segundos

      // Intermitencia del semáforo amarillo
      for (int i = 0; i < 5; i++) {
        digitalWrite(Semaforo_Amarillo_1, HIGH);
        delay(100); // 100 milisegundos
        digitalWrite(Semaforo_Amarillo_1, LOW);
        delay(100); // 100 milisegundos
      }
      estadoActual = S2;
      break;

    case S2:
      digitalWrite(Semaforo_Verde_1, LOW);
      digitalWrite(Semaforo_Amarillo_1, HIGH);
      delay(1000); // Espera de 1 segundo
      estadoActual = S3;
      break;

    case S3:
      digitalWrite(Semaforo_Amarillo_1, LOW);
      digitalWrite(Peatonal_Rojo_1, LOW);
      digitalWrite(Semaforo_Rojo_2, LOW);
      digitalWrite(Peatonal_Verde_2, LOW);
      
      digitalWrite(Semaforo_Rojo_1, HIGH);
      digitalWrite(Peatonal_Verde_1, HIGH);
      digitalWrite(Semaforo_Verde_2, HIGH);
      digitalWrite(Peatonal_Rojo_2, HIGH);
      delay(3000); // Espera de 3 segundos
      estadoActual = S4;
      break;

    case S4:
      digitalWrite(Semaforo_Verde_2, LOW);
      digitalWrite(Semaforo_Amarillo_2, HIGH);
      delay(1000); // Espera de 1 segundo
      
      digitalWrite(Semaforo_Rojo_1, LOW);
      digitalWrite(Peatonal_Verde_1, LOW);
      digitalWrite(Semaforo_Amarillo_2, LOW);
      digitalWrite(Peatonal_Rojo_2, LOW);
      
      estadoActual = S1;
      break;
  }
}
