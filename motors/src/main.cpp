
#include "robotka.h"
 int speed = 100;
 float turn = 127.45; //vzdalenost co ma kazde kolo ujet pro otoceni o 90°

 void turn_left(){
        rkMotorsDriveLeft  (-turn,speed);
        rkMotorsDriveRight (turn,speed); 
}
    void turn_right(){
        rkMotorsDriveLeft  (turn,speed);
        rkMotorsDriveRight (-turn,speed); 
    }

// Funkce setup se zavolá vždy po startu robota.
void setup() {
    rkConfig cfg;
    // Upravte nastavení, například:
    // cfg.motor_max_power_pct = 30; // limit výkonu motorů na 30%
    rkSetup(cfg);          
    while(true){
        
        rkMotorsDriveLeft  (950,speed);
        rkMotorsDriveRight (950,speed);

         turn_right();
    
          rkMotorsDriveLeft (300,speed);
          rkMotorsDriveRight (300,speed);
         
           turn_right();

             rkMotorsDriveLeft (500,speed);
             rkMotorsDriveRight (500,speed);
         
              turn_left();

               rkMotorsDriveLeft (500,speed);
               rkMotorsDriveRight (500,speed);
         
                turn_left();
        
                 rkMotorsDriveLeft (1000,speed);
                 rkMotorsDriveRight (1000,speed);
         
    }
}
