// C++ code
//Define o pino do LED
#define RED_LED 12
#define GREEN_LED 8
//Inicializando contador
int counter = 1;
/*
Função para imprimir no Monitor Serial
*/
void debug(char title[], int integerToDebug){
  Serial.print(title);
  Serial.print(integerToDebug);
  Serial.print("\n");
}

void blinkLight(int pin, char color[]){
  digitalWrite(pin, HIGH);
  delay(1000); 
  Serial.print("A luz ");
  Serial.print(color); 
  Serial.print(" esta piscando.");
  Serial.println();
  digitalWrite(pin, LOW);
  delay(1000); 
}
void setup()
{
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  
  debug("O Led vermelho esta na porta: ", RED_LED);  
  debug("O Led verde esta na porta: ", GREEN_LED); 
  
}

void loop()
{
  debug("O loop esta na vez: ",counter); 
  if(counter%2 == 0){
    blinkLight(RED_LED, "vermelha");    
  } else {
    blinkLight(GREEN_LED, "verde");
  }
  
  counter++;
  
}