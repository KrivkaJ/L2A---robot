
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


        rkMotorsDriveAsync(950,950,speed);
         delay(1);

         turn_right();
          delay(1);

          rkMotorsDriveAsync(300,300,speed);
           delay(1);

           turn_right();
            delay(1);

            rkMotorsDriveAsync(500,500,speed);
             delay(1);

              turn_left();
               delay(1);

               rkMotorsDriveAsync(500,500,speed);
                delay(1);

                turn_left();
                 delay(1);

                 rkMotorsDriveAsync(1000,1000,speed);
                  delay(1);
    
}
