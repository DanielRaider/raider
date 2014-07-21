#include <Servo.h>
#include "raider_motion.h"

    Robot raider;
    bool manual_mode=false;

int command;

    
void setup() {
    Serial2.begin(9600); //Bluetooth
   // Serial3.begin(9600); //Beaglebone
    pinMode(BOARD_LED_PIN, OUTPUT);

      raider.init();


}

void loop() {
//    SerialUSB.begin();
//    SerialUSB.println("ok");


       digitalWrite(BOARD_LED_PIN, HIGH);

  if(Serial2.available()){
    command=Serial2.read();
    SerialUSB.println(command);
   digitalWrite(BOARD_LED_PIN, LOW);
   switch (command){ 
     case 70:
     break; 
   } 
   Serial2.flush();
  }
       raider.setTargetPosition(512,0,462,562,212,812,962,62,512,512,512,512,452,572,512,512,512,512,512,512);
     raider.movVertical(-120,-120);
          /*raider.move(3);
  raider.walk(20);
  raider.turnL();
  raider.turnL();
  raider.turnL();
  raider.turnL();
  raider.turnL();
  raider.turnL();*/

                     
                            //   P  T   1   2   3   4   5 6 7 8 9 10 11 12 13 14 15 16 17 18
     raider.setTargetPosition(512,0,462,562,212,812,962,62,512,512,512,512,452,572,512,512,512,512,512,512);
     raider.movVertical(-120,-120);
          raider.move(3);
          
          delay(500);
          float t=3;
     //raider.movVertical(-50,-50);
                             //P  T  1   2   3   4   5  6   7   8   9   10  11  12  13  14  15  16  17  18
     raider.setTargetPosition(512,0,732,282,212,812,962,62,512,512,512,512,82,942,112,912,712,312,512,512); raider.move(0.5*t);  
   
          raider.setTargetPosition(512,0,732,282,212,812,962,62,512,512,512,512,82,942,112,912,712,312,512,512); raider.move(0.5*t);  


     raider.setTargetPosition(512,0,822,202,202,822,512,512,512,512,512,512,82,942,62,962,712,312,512,512); raider.move(1*t);  

     //raider.setTargetPosition(512,0,822,202,202,822,512,512,612,412,512,512,82,942,82,942,712,312,512,512); raider.move(1*t); 
     
     raider.setTargetPosition(512,0,822,202,462,812,812,512,512,512,512,512,82,942,82,942,712,312,512,512); raider.move(2*t);while(1);

     raider.setTargetPosition(762,0,822,202,412,512,512,512,512,512,512,512,82,942,82,942,712,312,512,512); raider.move(0.2*t); 
     raider.setTargetPosition(762,0,822,202,412,512,512,512,512,512,512,512,82,942,82,942,662,362,512,512); raider.move(1*t);
     raider.setTargetPosition(512,0,822,202,212,812,512,512,512,512,512,512,82,942,82,942,662,362,512,512); raider.move(1*t);
     raider.setTargetPosition(512,0,822,202,212,812,512,512,512,512,512,512,182,842,82,942,662,362,512,512); raider.move(0.5*t);
     
     raider.setTargetPosition(512,0,462,562,212,812,962,62,512,512,512,512,452,572,512,512,512,512,512,512);
     raider.movVertical(-120,-120);
     raider.move(1);
          while(1);
  /*        
     raider.walk(5);
     
     raider.turnL();
     raider.turnL();
     raider.turnL();
 */
}
