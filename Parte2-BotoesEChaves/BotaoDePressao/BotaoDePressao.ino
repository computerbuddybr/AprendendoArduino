#define RED_LED 12 //Pino do Led
#define BTN 2 //Pino do botão
int btnState; //Variável de leitura de estado do botão

void setup(){
    pinMode(RED_LED, OUTPUT); //Setup do LED
    pinMode(BTN, INPUT); //Setup do botão

}
void loop(){
    btnState = digitalRead(BTN); //lendo o estado do botão
    if(btnState == 1){ //Verficiando se está pressionado
        digitalWrite(RED_LED, HIGH); //Ligar o led se estiver pressionado
    } else {
        digitalWrite(RED_LED, LOW); //desligar o led se estiver pressionado
    }
    
}