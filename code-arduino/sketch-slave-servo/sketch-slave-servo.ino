//Louis Latreille
//Robot araignée dont le but est faire des relevés en forêt ou autre milieu où le terrain n'est pas praticable.
//  21/02/2017
//_____________________________________________________________________________________________________________

/* SDA sur la pin 4
   SDL    //      5
   servo X  sur pin 9
   servo Y          10  */

#include <Servo.h>
#include <Wire.h>

Servo servo_x;
Servo servo_y;

int *position_x = 0;    //{0,90,180};
int *position_y = 0;    //{0,45,90,135,180};

void receiveEvent(int howMany){
  
 int ordre = Wire.read(); // recevoir un chiffre
  
 switch(ordre){
  case 1 : {    //ordre n°1 etc...
   marche();
   break;}
  case 2 : {
   break;}
  //...
  default : {//message d'erreur à voir
   break;}
 }
}

void marche(){
  
  *position_x = 0;    //RAZ
  *position_y = 45;
  
  servo_x.write(*position_x);
  delay(1000);
  servo_y.write(*position_y);
  delay(1000);

  *position_x = *position_x + 90;
  servo_x.write(*position_x);
  delay(1000);

  *position_y = *position_y + 90;
  servo_y.write(*position_y);
  delay(1000);  
}

void setup() {
  servo_x.attach(9);
  servo_y.attach(10);
  pinMode(4, OUTPUT); //Pin communication
  pinMode(5, OUTPUT);
  
  Wire.begin(1);                // join i2c bus with address #1
  Wire.OnRequest(receiveEvent); // register event
  Serial.begin(9600);
}

void loop(){
  delay(100);
}
