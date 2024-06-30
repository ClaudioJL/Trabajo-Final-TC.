// Definición de pines para semáforos
const int Semaforo_Rojo_1 = 12;
const int Semaforo_Amarillo_1 = 11;
const int Semaforo_Verde_1 = 10;

const int Peatonal_Rojo_1 = 9;
const int Peatonal_Verde_1 = 8;

const int Semaforo_Rojo_2 = 7;
const int Semaforo_Amarillo_2 = 6;
const int Semaforo_Verde_2 = 5;

const int Peatonal_Rojo_2 = 4;
const int Peatonal_Verde_2 = 3;

// Definición de tiempos
const int T_Verde = 3000;
const int T_Amarillo = 1000;

// Definición de estados
enum Estados {S1, S2, S3, S4};
Estados estadoActual = S1;

// Funciones para manejar los semáforos
void encenderLuces(int rojo, int amarillo, int verde) {
  digitalWrite(rojo, HIGH);
  digitalWrite(amarillo, HIGH);
  digitalWrite(verde, HIGH);
}

void apagarLuces(int rojo, int amarillo, int verde) {
  digitalWrite(rojo, LOW);
  digitalWrite(amarillo, LOW);
  digitalWrite(verde, LOW);
}

void encenderPeatonal(int rojo, int verde) {
  digitalWrite(rojo, HIGH);
  digitalWrite(verde, HIGH);
}

void apagarPeatonal(int rojo, int verde) {
  digitalWrite(rojo, LOW);
  digitalWrite(verde, LOW);
}

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

  // Estado inicial
  apagarLuces(Semaforo_Rojo_1, Semaforo_Amarillo_1, Semaforo_Verde_1);
  apagarPeatonal(Peatonal_Rojo_1, Peatonal_Verde_1);
  apagarLuces(Semaforo_Rojo_2, Semaforo_Amarillo_2, Semaforo_Verde_2);
  apagarPeatonal(Peatonal_Rojo_2, Peatonal_Verde_2);
}

void loop() {
  switch (estadoActual) {
    case S1:
      encenderLuces(Semaforo_Verde_1, LOW, LOW);
      encenderPeatonal(Peatonal_Rojo_1, LOW);
      encenderLuces(Semaforo_Rojo_2, LOW, LOW);
      encenderPeatonal(LOW, Peatonal_Verde_2);
      delay(T_Verde);
      estadoActual = S2;
      break;

    case S2:
      apagarLuces(LOW, Semaforo_Amarillo_1, LOW);
      delay(T_Amarillo);
      estadoActual = S3;
      break;

    case S3:
      encenderLuces(Semaforo_Rojo_1, LOW, LOW);
      encenderPeatonal(LOW, Peatonal_Verde_1);
      encenderLuces(Semaforo_Verde_2, LOW, LOW);
      encenderPeatonal(Peatonal_Rojo_2, LOW);
      delay(T_Verde);
      estadoActual = S4;
      break;

    case S4:
      apagarLuces(LOW, Semaforo_Amarillo_2, LOW);
      delay(T_Amarillo);
      
      apagarLuces(Semaforo_Rojo_1, LOW, LOW);
      apagarPeatonal(LOW, Peatonal_Verde_1);
      apagarLuces(LOW, Semaforo_Amarillo_2, LOW);
      apagarPeatonal(Peatonal_Rojo_2, LOW);
      
      estadoActual = S1;
      break;
  }
}

