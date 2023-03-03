#define led1 7
#define led2 6
#define led3 5
#define buzzer 13
#define echoPin 11
#define trigPin 12

long duration;
int distance;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance >= 30){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else if(distance <= 29 && distance >= 20){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    tone1();
  }
  else if(distance <= 19 && distance >= 10){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    tone2();
  }
  else {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    tone3();
  } 
}

void tone1(){
  tone(buzzer, 1000);
  delay(700);
  noTone(buzzer);
  delay(700);
}

void tone2(){
  tone(buzzer, 1500);
  delay(350);
  noTone(buzzer);
  delay(350);
}

void tone3(){
  tone(buzzer, 2000);
  delay(200);
  noTone(buzzer);
  delay(200);
}
