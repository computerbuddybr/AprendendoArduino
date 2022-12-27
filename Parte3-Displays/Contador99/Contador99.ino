//Definindo pinos
#define SEG_A 2
#define SEG_B 3
#define SEG_C 4
#define SEG_D 5
#define SEG_E 6
#define SEG_F 7
#define SEG_G 8


//Definindo listas com os valores para cada número
int number_values[10][7] = {{HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW}, {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW}, {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH}, {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH}, {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH}, {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH}, {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH}, {HIGH, HIGH, HIGH, LOW, LOW,LOW, LOW}, {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},{HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH}};


/*
Função que vai ligar os segmentos apropriados
*/
void number(int values[]){
  digitalWrite(SEG_A, values[0]);
  digitalWrite(SEG_B, values[1]);
  digitalWrite(SEG_C, values[2]);
  digitalWrite(SEG_D, values[3]);
  digitalWrite(SEG_E, values[4]);  
  digitalWrite(SEG_F, values[5]);  
  digitalWrite(SEG_G, values[6]); 
  delay(1000);
  
}
/*
Função para contar os números
*/
void counter(){
  Serial.println("Counter");
    for(int i = 0; i < 10; i++){
        Serial.println(i);
        number(number_values[i]);        
    }
}



/*
Funções de funcionamento da placa
*/
void setup(){
    pinMode(SEG_A, OUTPUT);
    pinMode(SEG_B, OUTPUT);
    pinMode(SEG_C, OUTPUT);
    pinMode(SEG_D, OUTPUT);
    pinMode(SEG_E, OUTPUT);
    pinMode(SEG_F, OUTPUT);
    pinMode(SEG_G, OUTPUT);
  Serial.begin(9600);
  Serial.println("Setup");

}
void loop(){   
  Serial.println("Loop");    
    counter();
}