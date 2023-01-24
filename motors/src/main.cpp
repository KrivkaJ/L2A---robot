//program na projeti eska
#include "robotka.h"

int speed = 50;
float turn = 127.45; //vzdalenost co ma kazde kolo ujet pro otoceni o 90°

 void turn_left(){
       rkMotorsDriveAsync(turn*5,-turn*5,speed);
}
    void turn_right(){
        rkMotorsDriveAsync(-turn*5,turn*5,speed);
    }

// Funkce setup se zavolá vždy po startu robota.
void setup() {
    rkConfig cfg;
    // Upravte nastavení, například:
    // cfg.motor_max_power_pct = 30; // limit výkonu motorů na 30%
    rkSetup(cfg);          

        rkMotorsDriveAsync(950*5,950*5,speed);
         delay(8000);

         turn_right();
          delay(5000);

          rkMotorsDriveAsync(300*5,300*5,speed);
           delay(5000);

           turn_right();
            delay(5000);

            rkMotorsDriveAsync(500*5,500*5,speed);
             delay(5000);

              turn_left();
               delay(5000);

               rkMotorsDriveAsync(500,500,speed);
                delay(5000);

                turn_left();
                 delay(5000);

                 rkMotorsDriveAsync(1000,1000,speed);
                  delay(5000);
    
}
