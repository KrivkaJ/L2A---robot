//program na projeti eska
#include "robotka.h"

int speed = 50;
float coefSpeed = 1.085; // pravy motor je pomalejsi, takze se jeho rychlost musi nasobit touto konstantou 
float ticksToMm = 4.65; // prepocet z tiku v enkoderech na mm 
byte state = 1;
float rozpeti_kol = 173;


void forward(int mm, byte state_x){
    rkConfig cfg;
    rkSetup(cfg); 
        rkMotorsDriveLeftAsync(mm*ticksToMm, speed);
        rkMotorsDriveRightAsync(mm*ticksToMm, speed);
}

void turn(int degrees, byte state_x){
    rkConfig cfg;
    rkSetup(cfg);
        rkMotorsDriveLeftAsync(3.141*rozpeti_kol*degrees/360*ticksToMm, speed);
        rkMotorsDriveRightAsync(3.141*rozpeti_kol*degrees/360*ticksToMm, speed);
}
// Funkce setup se zavolá vždy po startu robota.
void setup() {
    rkConfig cfg;
    // Upravte nastavení, například:
    // cfg.motor_max_power_pct = 30; // limit výkonu motorů na 30%
    rkSetup(cfg);          

    while(true){
        switch(state){
        case 1:
            state = 2;
                forward(450, 3);
            break;

        case 3: // otocka vpravo
            state = 4;
            turn(-90, 5);
            break;

        case 5:
            state = 6;
                forward(450, 7);
            break;

        case 7:
            state = 8;
                turn(-90, 9);
            break;

        case 9:
            state = 10;
                forward(500, 11);
            break;

        case 11:
            state = 12;
                turn(90, 13);
            break;

        case 13:
            state = 14;
                forward(500, 15);
            break;

        case 15:
            state = 16;
                turn(90, 17);
            break;

        case 17:
            state = 18;
                forward(1000, 19);
            break;

        default:
            break;
        }
    }
}
