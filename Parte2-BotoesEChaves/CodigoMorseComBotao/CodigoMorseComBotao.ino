#define RED_LED 12
#define BTN_A 8
#define BTN_B 7 
#define BTN_C 2
//Variáveis para leitura do estado de cada botão
int btnAState, btnBState, btnCState;
//Variável controle se botão foi clicado e já fez ação
int btnActivated = 0;

/*
Função que faz o LED piscar o o traço
*/
void dash(int pin){
  	digitalWrite(pin, HIGH);
  	delay(1500); 
  	digitalWrite(pin, LOW);
  	delay(500); 
}
/*
Função que faz o LED piscar o ponto
*/
void dot(int pin){
    digitalWrite(pin, HIGH);
  	delay(500); 
  	digitalWrite(pin, LOW);
  	delay(500);

}

/*
Funções que vão chamar a sequência correta de pontos e traços para sua letra correspondente
*/
void a(int pin){
  dot(pin);
  dash(pin);
  btnActivated = 0;
}
void b(int pin){
  dash(pin);
  dot(pin);
  dot(pin);
  dot(pin);
  btnActivated = 0;
}
void c(int pin){
  dash(pin);
  dot(pin);
  dash(pin);
  dot(pin);
  btnActivated = 0;
}
/*
Funcionamento Placa
*/
void setup(){
    pinMode(RED_LED, OUTPUT);
    pinMode(BTN_A, INPUT);
    pinMode(BTN_B, INPUT);
    pinMode(BTN_C, INPUT);
    Serial.begin(9600);
}

void loop(){
    btnAState = digitalRead(BTN_A);
    btnBState = digitalRead(BTN_B);
    btnCState = digitalRead(BTN_C);

    if(btnActivated == 0){ 
        Serial.println("Oba vamos ativar");
        if(btnAState == 1 && btnBState == 0 && btnCState == 0){
            Serial.println("Vamos fazer o A");
            btnActivated = 1;
            a(RED_LED);       
        }
        if(btnAState == 0 && btnBState == 1 && btnCState == 0){
            Serial.println("Vamos fazer o B");
            btnActivated = 1;
            b(RED_LED);       
        
        }
        if(btnAState == 0 && btnBState == 0 && btnCState == 1){
            Serial.println("Vamos fazer o C");
            btnActivated = 1;        
            c(RED_LED);        
        }
    } else {
        Serial.println("Desculpe mas o botao está ativado");
    }
}