//Struct para displays
typedef struct Display {
  char name;
  int pin_number;
} ;

//Struct para sequência de valores para ligar os leds corretos para cada número
typedef struct CountNumber {
  char number[6];
  int values_sequence[7];

};

//Definindo a variável para o display
struct Display first_display[7] = {
  {'A', 2},
  {'B', 3},
  {'C', 4},
  {'D', 5},
  {'E', 6},
  {'F', 7},
  {'G', 8}

}; 
//Definindo lista com os valores para cada número
struct CountNumber led_values[10] ={
  {"zero", {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW} }, 
  {"one", {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW}}, 
  {"two", {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH}}, 
  {"three", {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH}}, 
  {"four", {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH}}, 
  {"five", {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH}}, 
  {"six", {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH}}, 
  {"seven", {HIGH, HIGH, HIGH, LOW, LOW,LOW, LOW}}, 
  {"eight", {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}},
  {"nine", {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH}}
};

/*
Função que vai ligar os segmentos apropriados
*/
void number(struct CountNumber number_led_values[], struct Display display[], int number){
 for(int i = 0; i < 7; i++){
  digitalWrite(display[i].pin_number, number_led_values[number].values_sequence[i]);
 }
}

/*
Função para contar os números
*/
void counter(){
  Serial.println("Counter");
    for(int i = 0; i < 10; i++){
        Serial.println(i);
        number(led_values, first_display, i);
        delay(1000);        
    }
}

/*
Função para o setup do display
*/
void display_setup(struct Display display[]){
  for(int i = 0; i < 7; i++){
    pinMode(display[i].pin_number, OUTPUT);
    Serial.println(display[i].pin_number);
  }

}


/*
Funções de funcionamento da placa
*/
void setup(){
    Serial.begin(9600);
    Serial.println("Setup");
    display_setup(first_display);
    

}
void loop(){   
  Serial.println("Loop");    
    counter();
}