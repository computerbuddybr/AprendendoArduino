//Definindo os pinos da placa Arduino pra cada cor de led
const int RED_PIN = 12;
const int YELLOW_PIN = 7;
const int GREEN_PIN = 2;
//Definindo o tempo que cada cor de luz fica ligada
const int LIGHT_TIME = 10000;
//Definindo o número de vezes que pisca
const int BLINKING = 10;
//Definindo o tempo para a piscada da luz
const int BLINK_TIME = 500;

/*
Função para ligar e apagar a luz
*/
void lightUPAndDOWN(int pin, int time){
    digitalWrite(pin, HIGH);
    delay(time);
    digitalWrite(pin, LOW);
    delay(time);
}
/*
Função para fazer luz piscar
*/
void blink(int pin){
    for(int i = 0; i < BLINKING; i++){
        lightUPAndDOWN(pin, BLINK_TIME);
    }
}
/*
Função que acende luz amarela e vermelha
*/
void lightUPYEllowAndRed(int pin){
    blink(pin);
    lightUPAndDOWN(pin, LIGHT_TIME);
}
void setup(){
    pinMode(RED_PIN, OUTPUT);
    pinMode(YELLOW_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
}

void loop(){
    //Ligando e desligando a luz verde
    lightUPAndDOWN(GREEN_PIN, LIGHT_TIME);
    //Ligando a luz amarela
    lightUPYEllowAndRed(YELLOW_PIN);
    //Ligando a luz vermelha
    lightUPYEllowAndRed(RED_PIN);

}