/**
 * Autonomous Car
 * Created by Maalv on 5/22/2021 @ 4:15PM
 * Uses Arduino Nano and Ultrasonic Sensors to guide RC car Autonomously
 */


int trigPin = 2;
int echoPin = 3;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
  Serial.println("Program Running...\n");




}

void loop() {
  // put your main code here, to run repeatedly:

}


float distance() {
   long duration;
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH); //Reads length of HIGH signal recieved by echoPin in microseconds
   return duration * 0.034 / 2;
}
