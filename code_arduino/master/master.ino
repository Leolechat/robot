#include <Wire.h>
void setup() {
  Wire.begin();        // Rejoindre le bus I2C (Pas besoin d adresse pour le maitre)
  Serial.begin(9600);  // vitesse du bus
  pinMode(2,INPUT);    //"télécommande" test action marche
  pinMode(3,INPUT);
  pinMode(4,INPUT);
}

unsigned int temps_action_patte = 5000;   //attente à rectifier

void marche_tripode(){    // cycle complée
  char i;
  for(i=1; i<=5; i=i+2){
   Wire.beginTransmission(i); // Envoyer vers patte impaire
    Wire.write(1); // Envoi un l'ordre 1
    Wire.endTransmission(); // Arreter la transmission
  }
  delay(temps_action_patte);
  for(i=2; i<=6; i=i+2){
    Wire.beginTransmission(i); // Envoyer vers patte paire
    Wire.write(1); // Envoi un l'ordre 1
    Wire.endTransmission(); // Arreter la transmission
  }
  delay(temps_action_patte);
}

void marche_tetrapode(){
  Wire.beginTransmission(3); // Envoyer vers patte n°3
  Wire.write(1); // Envoi un l'ordre 1
  Wire.endTransmission(); // Arreter la transmission
  delay(temps_action_patte / 2);

  Wire.beginTransmission(4); // Envoyer vers patte n°4
  Wire.write(1); // Envoi un l'ordre 1
  Wire.endTransmission(); // Arreter la transmission
  delay(temps_action_patte / 2);

  Wire.beginTransmission(2); // Envoyer vers patte n°2
  Wire.write(1); // Envoi un l'ordre 1
  Wire.endTransmission(); // Arreter la transmission
  delay(temps_action_patte / 2);

  Wire.beginTransmission(6); // Envoyer vers patte n°6
  Wire.write(1); // Envoi un l'ordre 1
  Wire.endTransmission(); // Arreter la transmission
  delay(temps_action_patte / 2);

  Wire.beginTransmission(1); // Envoyer vers patte n°1
  Wire.write(1); // Envoi un l'ordre 1
  Wire.endTransmission(); // Arreter la transmission
  delay(temps_action_patte);
  
  Wire.beginTransmission(5); // Envoyer vers patte n°5
  Wire.write(1); // Envoi un l'ordre 1
  Wire.endTransmission(); // Arreter la transmission
  delay(temps_action_patte);
}

void marche_longue(){
  char i;
  for(i=1; i<=6; i++){
   Wire.beginTransmission(i); // Envoyer vers patte impaire
   Wire.write(1); // Envoi un l'ordre 1
   Wire.endTransmission(); // Arreter la transmission
  }
}

void loop(){
  if(digitalRead(2)==1){marche_longue();}
  if(digitalRead(3)==1){marche_tetrapode();}
  if(digitalRead(4)==1){marche_tripode();}
  delay(100); //anti-rebond  
}
