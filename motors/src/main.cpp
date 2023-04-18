//program na projeti eska
#include "SmartServoBus.hpp"
#include "robotka.h"
#include <Arduino.h>

using namespace lx16a;

static int n = 0;
static SmartServoBus servoBus;

const int speed = 30;
float ticksToMm = 3.62; // prepocet z tiku v enkoderech na mm
byte state = 1;
float rozpeti_kol = 165;
float g_US = 1;

void forward(int mm) { //

    rkMotorsDrive(mm * ticksToMm, mm * ticksToMm, speed);
}

void turn(int degrees) { // + doprava - doleva
    rkMotorsDrive(3.141 * rozpeti_kol * degrees / 360 * ticksToMm, -3.141 * rozpeti_kol * degrees / 360 * ticksToMm, speed);
}

void encodery() {
    Serial.printf("L: %f, R: %f", rkMotorsGetPositionLeft(), rkMotorsGetPositionRight());
    // rkMotorsGetPositionLeft();
    // rkMotorsGetPositionRight();
}
void Skoback() {
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

void Sko() {
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

void update_sensors() {
    g_US = rkUltraMeasure(1);
    printf("n/ g_US: %f /n", g_US);
    //std::cout << " " << std::endl;
}
void Sko_reversed() {
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

    servoBus.begin(1, UART_NUM_2, GPIO_NUM_14);

    rkConfig cfg;
    // Upravte nastavení, například:
    // cfg.motor_max_power_pct = 30; // limit výkonu motorů na 30%
    rkSetup(cfg);

    Serial.begin(115200);
  

    while(true){
        if(rkButtonIsPressed(BTN_UP)){
                break;
        }
    }
    while(true){
    Serial.printf("pos: %f", rkServosGetPosition(1));
    rkServosSetPosition(1, 90);
    sleep(2000);
    Serial.printf("pos: %f", rkServosGetPosition(1));
    rkServosSetPosition(1,-90);
    sleep(2000);
    Serial.printf("pos: %f", rkServosGetPosition(1));
    }
    while(true){
        switch (state)
        {
        case 1: //projeti S
            Sko();
            state = 2;
            break;
        case 2: //hledani kostky
        //rameno nastavit do polohy u zeme
        //zahajit nahodnou jizdu a zaroven kontrola hodnoty ze senzoru na kostky
        case 3: //uchopeni kostky s poznanim barvy
        //barva check
        //ochopeni a vyzvednuti do vysky
        case 4: //polozeni kostky na spravnou barvu
        case 5: //cesta ke konci S
        case 6: //projeti S naopak
        Sko_reversed();
        state = 7;
        default:
            break;
        }
    }
}

void loop() {
    uint16_t angle = (n % 240);

    servoBus.set(0, Angle::deg(angle));
    printf("Move to %d \n", angle);

    delay(500);

    auto curPos = servoBus.pos(0);
    printf("Position at %f \n", curPos.deg());

    n += 15;
    delay(1000);
}