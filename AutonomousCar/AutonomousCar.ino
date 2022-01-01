/**
   Autonomous Car
   Created by Maalv on 5/22/2021 @ 4:15PM
   Uses Arduino Nano and Ultrasonic Sensors to guide RC car Autonomously
*/


int trigPinFront = 2;
int echoPinFront = 3;

int speedDrive = 6; //This pin controls the speed of the drive motor (ENB pin on IC)
int speedSteer = 9; //This pin controls the speed of the steering motor (ENA pin on IC)

int driveDirOne = 4; //This pin controls the H-Bridge to change motor direction on the drive motor (IN3 on IC)
int driveDirTwo = 5; //This pin controls the H-Bridge to change motor direction on the drive motor (IN4 on IC)
int steerDirOne = 7; //This pin controls the H-Bridge to change motor direction on the steering motor (The Yellow wire) (IN1 on IC)
int steerDirTwo = 8; //This pin controls the H-Bridge to change motor direction on the steering motor (The Gray wire) (IN2 on IC)


void setup() {

  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);

  pinMode(speedDrive, OUTPUT);
  pinMode(speedSteer, OUTPUT);
  pinMode(driveDirOne, OUTPUT);
  pinMode(driveDirTwo, OUTPUT);
  pinMode(steerDirOne, OUTPUT);
  pinMode(steerDirTwo, OUTPUT);

  digitalWrite(speedDrive, LOW);
  digitalWrite(speedSteer, LOW);
  digitalWrite(driveDirOne, LOW);
  digitalWrite(driveDirTwo, LOW);
  digitalWrite(steerDirOne, LOW);
  digitalWrite(steerDirTwo, LOW);

  Serial.begin(9600);
  Serial.println("Program Running...\n");




}

void loop() {
  //  while (getDistance() >= 10) {
  //    drive(255);
  //    Serial.println(getDistance());
  //  }
  //  brake();
  //  delay(1500);
  //  while (getDistance() <= 20) {
  //    reverse(255);
  //    Serial.println(getDistance());
  //  }
  //  brake();
  drive(355);
  delay(2000);
  steerRight(255);
  delay(1000);
  drive(355);
  delay(2000);
  steerLeft(255);
  delay(1000);
  drive(355);
  delay(2000);
  steerNeutral();
  delay(1000);
}


long getDistance() {
  long duration, distance;
  digitalWrite(trigPinFront, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinFront, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFront, LOW);
  duration = pulseIn(echoPinFront, HIGH); //Reads length of HIGH signal recieved by echoPinFront in microseconds
  distance = ((duration * 0.034) / 2) / 2.54; //Dividing by final 2.54 to convert from cm -> in
  Serial.println(distance);
  return distance;
}

void drive(int speed) {
  analogWrite(speedDrive, speed);
  digitalWrite(driveDirOne, LOW);
  digitalWrite(driveDirTwo, HIGH);
}

void reverse(int speed) {
  analogWrite(speedDrive, speed);
  digitalWrite(driveDirOne, HIGH);
  digitalWrite(driveDirTwo, LOW);
}

void brake() {
  digitalWrite(driveDirOne, HIGH);
  digitalWrite(driveDirTwo, LOW);
  delay(100);
  analogWrite(speedDrive, 0);
  digitalWrite(driveDirOne, LOW);
  digitalWrite(driveDirTwo, LOW);
}

void coast() { //Cut power to wheels and let car coast to a stop
  digitalWrite(driveDirOne, LOW);
  digitalWrite(driveDirTwo, LOW);
}

void steerRight(int speed) {
  analogWrite(speedSteer, speed);
  digitalWrite(steerDirOne, LOW);
  digitalWrite(steerDirTwo, HIGH);
}

void steerLeft(int speed) {
  analogWrite(speedSteer, speed);
  digitalWrite(steerDirOne, HIGH);
  digitalWrite(steerDirTwo, LOW);
}

void steerNeutral() {
  digitalWrite(steerDirOne, LOW);
  digitalWrite(steerDirTwo, LOW);
}
