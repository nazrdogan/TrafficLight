// birinci direk
int led1=22;
int led2=23;
int led3=24;
//ikinci direk
int led4=25;
int led5=26;
int led6=27;
//üçüncü direk
int led7=28;
int led8=29;
int led9=30;
// dördüncü direk
int led10=31;
int led11=32;
int led12=33;


#include <NewPing.h>

#define SONAR_NUM     4 // Number or sensors.
#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.
#define PING_INTERVAL 33 // Milliseconds between sensor pings (29ms is about the min to avoid cross-sensor echo).

unsigned long pingTimer[SONAR_NUM]; // Holds the times when the next ping should happen for each sensor.
unsigned int cm[SONAR_NUM];         // Where the ping distances are stored.
uint8_t currentSensor = 0;          // Keeps track of which sensor is active.

NewPing sonar[SONAR_NUM] = {     // Sensor object array.
  //1. direk
  NewPing(12, 13, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping.
  // 2. direk
  NewPing(10, 11, MAX_DISTANCE),
  // 3. direk
  NewPing(8, 9, MAX_DISTANCE),
  // 4. direk
  NewPing(7, 6, MAX_DISTANCE),
  
};

void setup() {
  Serial.begin(115200);
  pingTimer[0] = millis() + 75;           // First ping starts at 75ms, gives time for the Arduino to chill before starting.
  for (uint8_t i = 1; i < SONAR_NUM; i++) // Set the starting time for each sensor.
    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;
}

void loop() {
  for (uint8_t i = 0; i < SONAR_NUM; i++) { // Loop through all the sensors.
    if (millis() >= pingTimer[i]) {         // Is it this sensor's time to ping?
      pingTimer[i] += PING_INTERVAL * SONAR_NUM;  // Set next time this sensor will be pinged.
      if (i == 0 && currentSensor == SONAR_NUM - 1) oneSensorCycle(); // Sensor ping cycle complete, do something with the results.
      sonar[currentSensor].timer_stop();          // Make sure previous timer is canceled before starting a new ping (insurance).
      currentSensor = i;                          // Sensor being accessed.
      cm[currentSensor] = 0;                      // Make distance zero in case there's no ping echo for this sensor.
      sonar[currentSensor].ping_timer(echoCheck); // Do the ping (processing continues, interrupt will call echoCheck to look for echo).
    }
  }
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  
}

void echoCheck() { // If ping received, set the sensor distance to array.
  if (sonar[currentSensor].check_timer())
    cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;
}

void oneSensorCycle() { // Sensor ping cycle complete, do something with the results.
  for (uint8_t i = 0; i < SONAR_NUM; i++) {
    Serial.print(i);
    Serial.print("=");
    Serial.print(cm[i]);
    Serial.print("cm ");
    if(i==0){
      
    if(cm[0]<5)
    {
       digitalWrite(led1, HIGH);
       digitalWrite(led2, HIGH);
       digitalWrite(led3, HIGH);
       digitalWrite(led4, HIGH);
       digitalWrite(led5, HIGH);
       digitalWrite(led6, HIGH);
       digitalWrite(led7, HIGH);
       digitalWrite(led8, HIGH);
       digitalWrite(led9, HIGH);
       digitalWrite(led10, HIGH);
       digitalWrite(led11, HIGH);
       digitalWrite(led12, HIGH); 
    }
    
   }
  if(i==1)
  {
    if(cm[1]<5)
    {
       digitalWrite(led1, HIGH);
       digitalWrite(led2, HIGH);
       digitalWrite(led3, HIGH);
       digitalWrite(led4, HIGH);
       digitalWrite(led5, HIGH);
       digitalWrite(led6, HIGH);
       digitalWrite(led7, HIGH);
       digitalWrite(led8, HIGH);
       digitalWrite(led9, HIGH);
       digitalWrite(led10, HIGH);
       digitalWrite(led11, HIGH);
       digitalWrite(led12, HIGH);
    }
  }
  if(i==2)
  {
   if(cm[2]<5)
   {
      digitalWrite(led1, HIGH);
       digitalWrite(led2, HIGH);
       digitalWrite(led3, HIGH);
       digitalWrite(led4, HIGH);
       digitalWrite(led5, HIGH);
       digitalWrite(led6, HIGH);
       digitalWrite(led7, HIGH);
       digitalWrite(led8, HIGH);
       digitalWrite(led9, HIGH);
       digitalWrite(led10, HIGH);
       digitalWrite(led11, HIGH);
       digitalWrite(led12, HIGH);
   }
  }
  if(i==3)
  {
    if(cm[3]<5){
    {
       digitalWrite(led1, HIGH);
       digitalWrite(led2, HIGH);
       digitalWrite(led3, HIGH);
       digitalWrite(led4, HIGH);
       digitalWrite(led5, HIGH);
       digitalWrite(led6, HIGH);
       digitalWrite(led7, HIGH);
       digitalWrite(led8, HIGH);
       digitalWrite(led9, HIGH);
       digitalWrite(led10, HIGH);
       digitalWrite(led11, HIGH);
       digitalWrite(led12, HIGH);
    }
  }
  }
  }
 Serial.println();
}
