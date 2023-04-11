//program na projeti eska
#include "robotka.h"
#include <lx16a-servo.h>
LX16ABus servoBus;
LX16AServo servo(&servoBus, 1);

const int speed = 30;
float ticksToMm = 3.62; // prepocet z tiku v enkoderech na mm 
byte state = 1;
float rozpeti_kol = 165;
float g_US = 1;


void forward(int mm){ // 
    rkConfig cfg;
    rkSetup(cfg); 
        rkMotorsDrive(mm*ticksToMm, mm*ticksToMm, speed);
}

void turn(int degrees){ // + doprava - doleva
    rkConfig cfg;
    rkSetup(cfg);
        rkMotorsDrive(3.141*rozpeti_kol*degrees/360*ticksToMm, -3.141*rozpeti_kol*degrees/360*ticksToMm, speed);
}

void encodery(){
    Serial.printf("L: %f, R: %f",rkMotorsGetPositionLeft(), rkMotorsGetPositionRight() );
    // rkMotorsGetPositionLeft();
    // rkMotorsGetPositionRight();

}
void Skoback(){
    forward(1000); 
    turn(90);
    forward(450);
    turn(90);
    forward(500);
    turn(-90);
    forward(400);
    turn(-90);
    forward(850);
}

void Sko(){
    forward(850);
    turn(90);
    forward(450);
    turn(90);
    forward(500);
    turn(-90);
    forward(500);
    turn(-90);
    forward(1000); 
}

void update_sensors(){
    g_US = rkUltraMeasure(1);
    printf("n/ g_US: %f /n", g_US);
    //std::cout << " " << std::endl;
}
void Sko_reversed(){
    forward(1000); 
    turn(90);
    forward(500);
    turn(90);
    forward(500);
    turn(-90);
    forward(450);
    turn(-90);
    forward(850);
}

// Funkce setup se zavolá vždy po startu robota.
void setup() {
    rkConfig cfg;
    // Upravte nastavení, například:
    // cfg.motor_max_power_pct = 30; // limit výkonu motorů na 30%
    rkSetup(cfg);   
           
    Serial.begin(115200);
    servoBus.beginOnePinMode(&Serial2, 8); // 8 is the pin number
	servoBus.debug(true);
	servoBus.retry=0;
            
            
    //while(true){
    //    if(rkButtonIsPressed(BTN_UP)){
    //            break;
    //    }
    //}
    //    while(true){
    //        update_sensors();
    //    }

    Sko();
    turn(180);
    Skoback();

    Sko_reversed();
}

void loop() {
	int divisor =4;
	for (int i = 0; i < 1000/divisor; i++) {
		long start = millis();
		uint16_t angle = i * 24*divisor;
		int16_t pos = 0;
		pos = servo.pos_read();
		Serial.printf("\n\nPosition at %d -> %s\n", pos,
				servo.isCommandOk() ? "OK" : "\n\nERR!!\n\n");

		do {
			servo.move_time(angle, 10*divisor);
		} while (!servo.isCommandOk());
		Serial.printf("Move to %d -> %s\n", angle,
				servo.isCommandOk() ? "OK" : "\n\nERR!!\n\n");
		Serial.println("Voltage = " + String(servo.vin()));
		Serial.println("Temp = " + String(servo.temp()));
		Serial.println("ID  = " + String(servo.id_read()));
		Serial.println("Motor Mode  = " + String(servo.readIsMotorMode()));
		long took = millis()-start;
		long time = (10*divisor)-took;
		if(time>0)
			delay(time);
		else{
			Serial.println("Real Time broken, took: "+String(took));
		}
	}

	servo.move_time(0, 3000);
	delay(3000);
}
