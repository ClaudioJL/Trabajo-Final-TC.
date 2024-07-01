// Definición de puertos para las luces
const int L11 = 11;
const int L10 = 10;
const int L9 = 9;
const int L8 = 8;
const int L7 = 7;
const int L6 = 6;
const int L5 = 5;
const int L4 = 4;
const int L3 = 3;
const int L2 = 2;
const int L13 = 13;
const int L12 = 12;

// Definición de estados
enum Estado {
    ESTADO_1,
    ESTADO_2,
    ESTADO_3,
    ESTADO_4
};

Estado estadoActual = ESTADO_1;

void setup() {
    // Configuración de puertos digitales como salida
    pinMode(L13, OUTPUT);
    pinMode(L12, OUTPUT);
    pinMode(L11, OUTPUT);
    pinMode(L10, OUTPUT);
    pinMode(L9, OUTPUT);
    pinMode(L8, OUTPUT);
    pinMode(L7, OUTPUT);
    pinMode(L6, OUTPUT);
    pinMode(L5, OUTPUT);
    pinMode(L4, OUTPUT);
    pinMode(L2, OUTPUT);
}

void loop() {
    switch (estadoActual) {
        case ESTADO_1:
            // Estado 1
            digitalWrite(L13, LOW);
            digitalWrite(L12, LOW);
            digitalWrite(L11, HIGH);
            digitalWrite(L10, HIGH);
            digitalWrite(L9, LOW);
            digitalWrite(L8, LOW);
            digitalWrite(L7, HIGH);
            digitalWrite(L6, LOW);
            digitalWrite(L5, LOW);
            digitalWrite(L4, LOW);
            digitalWrite(L2, HIGH);
            delay(4000);
            estadoActual = ESTADO_2;
            break;

        case ESTADO_2:
            // Estado 2
            digitalWrite(L13, LOW);
            digitalWrite(L12, HIGH);
            digitalWrite(L11, LOW);
            digitalWrite(L10, HIGH);
            digitalWrite(L8, LOW);
            digitalWrite(L7, HIGH);
            digitalWrite(L6, LOW);
            digitalWrite(L5, LOW);
            digitalWrite(L4, LOW);
            digitalWrite(L2, HIGH);
            delay(2000);
            estadoActual = ESTADO_3;
            break;

        case ESTADO_3:
            // Estado 3
            digitalWrite(L13, HIGH);
            digitalWrite(L12, LOW);
            digitalWrite(L11, LOW);
            digitalWrite(L10, LOW);
            digitalWrite(L8, HIGH);
            digitalWrite(L7, LOW);
            digitalWrite(L6, LOW);
            digitalWrite(L5, HIGH);
            digitalWrite(L4, HIGH);
            digitalWrite(L2, LOW);
            delay(4000);
            estadoActual = ESTADO_4;
            break;

        case ESTADO_4:
            // Estado 3
            digitalWrite(L13, HIGH);
            digitalWrite(L12, LOW);
            digitalWrite(L11, LOW);
            digitalWrite(L10, LOW);
            digitalWrite(L8, HIGH);
            digitalWrite(L7, LOW);
            digitalWrite(L6, HIGH);
            digitalWrite(L5, LOW);
            digitalWrite(L4, HIGH);
            digitalWrite(L2, LOW);
            delay(2000);
            estadoActual = ESTADO_1;
            break;
    }
}
