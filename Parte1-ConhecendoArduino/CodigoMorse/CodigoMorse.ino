/*
Fazendo três fileiras de LED simples piscarem o código Morse em sequência para A, B e C
*/
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
}
void b(int pin){
  dash(pin);
  dot(pin);
  dot(pin);
  dot(pin);
}
void c(int pin){
  dash(pin);
  dot(pin);
  dash(pin);
  dot(pin);
}

void setup()
{
  pinMode(12, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
 a(12);
 b(7);
 c(2);
}
