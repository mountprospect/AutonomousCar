
int trigPin = 2;
int echoPin = 3;





void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);




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
   duration = pulseIn(echoPin, HIGH);
   return duration * 0.034 / 2;
}
