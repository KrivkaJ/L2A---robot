
#include "robotka.h"
 int speed = 100;
 float turn = 127.45; //vzdalenost co ma kazde kolo ujet pro otoceni o 90°

 void turn_left(){
       rkMotorsDriveAsync(turn,-turn,speed);
}
    void turn_right(){
        rkMotorsDriveAsync(-turn,turn,speed);
    }

// Funkce setup se zavolá vždy po startu robota.
void setup() {
    rkConfig cfg;
    // Upravte nastavení, například:
    // cfg.motor_max_power_pct = 30; // limit výkonu motorů na 30%
    rkSetup(cfg);          
    rkMotorsDrive(4000, 4000, 30000);
}
