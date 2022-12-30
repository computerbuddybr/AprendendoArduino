#include <LiquidCrystal.h>
#define ONE_SECOND 1000

LiquidCrystal lcd(6,7,8,9,10,11);

/**
 * Função para imprimir a hora
 * @param int hours
 * @param int minutes
 * @param int seconds
*/
void printTime(int hours, int minutes, int seconds){
                if(hours < 10){
                    lcd.print(0);
                }
                lcd.print(hours);
                lcd.print(":");
                if(minutes < 10){
                    lcd.print(0);
                }
                lcd.print(minutes);
                lcd.print(":");
                if(seconds < 10){
                    lcd.print(0);
                }
                lcd.print(seconds);
                delay(ONE_SECOND);
                lcd.clear();
}
/**
 * Função para contar a hora
*/
void countTime(){
    
    for(int hours = 0; hours < 24; hours++){
        for(int minutes = 0; minutes < 60; minutes++){
            for(int seconds = 0; seconds < 60; seconds++){
                printTime(hours, minutes, seconds);

        }
        }
    }
}

void setup(){
    
    lcd.begin(16,2);    
    lcd.print("Meu Relogio");    
    delay(2000);
   	lcd.clear();
}
void loop(){
    countTime();
}