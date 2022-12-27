#define RED_LED 12
#define GREEN_LED 4
#define SWITCH_LEFT 7
#define SWITCH_RIGHT 2
//Variáveis para leitura do estado de cada botão
int switchState;


/*
Função que faz o LED piscar 
*/
void blink(int pin){
    digitalWrite(pin, HIGH);
  	delay(1000); 
  	digitalWrite(pin, LOW);
  	delay(1000);

}


/*
Funcionamento Placa
*/
void setup(){
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(SWITCH_LEFT, INPUT);
    pinMode(SWITCH_RIGHT, INPUT);
    Serial.begin(9600);
}

void loop(){
    int selectedLed;

   if(digitalRead(SWITCH_LEFT)){
    selectedLed = RED_LED;
    Serial.println("Vermelho");
   } 
   if(digitalRead(SWITCH_RIGHT)) {
    selectedLed = GREEN_LED;
    Serial.println("Verde");
   }
   blink(selectedLed);
}