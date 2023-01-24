//program na projeti eska
#include "robotka.h"

int speed = 50;
float coefSpeed = 1.085; // pravy motor je pomalejsi, takze se jeho rychlost musi nasobit touto konstantou 
float ticksToMm = 4.65; // prepocet z tiku v enkoderech na mm 
byte state = 1;
float rozpeti_kol = 173;


void forward(int mm){ // 
    rkConfig cfg;
    rkSetup(cfg); 
        rkMotorsDrive(mm*ticksToMm, mm*ticksToMm, speed);
}

void turn(int degrees){
    rkConfig cfg;
    rkSetup(cfg);
        rkMotorsDrive(3.141*rozpeti_kol*degrees/360*ticksToMm, -3.141*rozpeti_kol*degrees/360*ticksToMm, speed);
}

// Funkce setup se zavolá vždy po startu robota.
void setup() {
    rkConfig cfg;
    // Upravte nastavení, například:
    // cfg.motor_max_power_pct = 30; // limit výkonu motorů na 30%
    rkSetup(cfg);          
    while(true){
        if(rkButtonIsPressed(BTN_UP)){
                break;
        }
    }

    forward(1000);

}
