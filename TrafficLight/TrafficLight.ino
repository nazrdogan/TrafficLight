#define trigPin 12
#define echoPin 13
//--------
#define trigPin1 11
#define echoPin1 10
//--------------
#define trigPin2 9
#define echoPin2 8
//--------------
#define trigPin3 7
#define echoPin3 6



void setup() {
  Serial.begin (115200);
  //--------------------------
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   //---------------------------
   pinMode(trigPin1, OUTPUT);
   pinMode(echoPin1, INPUT);
   //---------------------------
   pinMode(trigPin2, OUTPUT);
   pinMode(echoPin2, INPUT);
   //---------------------------
   pinMode(trigPin3, OUTPUT);
   pinMode(echoPin3, INPUT);
  
   
  
  
  
}

void loop() {
  int duration, distance;
  int duration1,distance1;
  int duration2,distance2;
  int duration3,distance3;
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin1,HIGH);
  digitalWrite(trigPin2,HIGH);
  digitalWrite(trigPin3,HIGH);
  //----------------------------------
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin1,LOW);
  digitalWrite(trigPin2,LOW);
  digitalWrite(trigPin3,LOW);
  //---------------------------------
  duration = pulseIn(echoPin, HIGH);
  duration1=pulseIn(echoPin1,HIGH);
  duration2=pulseIn(echoPin2,HIGH);
  duration=pulseIn(echoPin3,HIGH);
  distance = (duration/2) / 29.1;
  distance1=(duration1/2)/29.1;
  distance2=(duration2/2)/29.1;
  distance3=(duration3/3)/29.1;
  
    Serial.print(distance);
    Serial.println(" cm");
    Serial.print(distance1);
    Serial.println(" cm");
    Serial.print(distance2);
    Serial.println(" cm");
    Serial.print(distance2);
    Serial.println(" cm");
    Serial.print(distance3);
    Serial.println(" cm");
     
    
  
  delay(500);
}  
