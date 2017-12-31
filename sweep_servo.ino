#include <Servo.h>

Servo myservo;


int pos = 0;    // variable to store the servo position
unsigned long time_total; //ms
unsigned long time_wait;
unsigned long delay_interval = 500;
int start_angle = 60;
int stop_angle = 0;
void setup() {
  Serial.begin(9600);
  time_total = (long)60000 * (long)180;
  time_wait = (long)60000 * (long)210;
  delay_interval = time_total/(start_angle-stop_angle);
  Serial.println("time_total");
  Serial.println(time_total);
  Serial.println("delay_interval");
  Serial.println(delay_interval);
  Serial.println("time_wait");
  Serial.println(time_wait);
  Serial.println("start_angle");
  Serial.println(start_angle);
  Serial.println("stop_angle");
  Serial.println(stop_angle);
  pinMode(LED_BUILTIN, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(start_angle);
  blink(3);
  delay(10000);
  myservo.write(stop_angle);
  blink(3);
  delay(10000);
  blink(10);
  delay(time_wait);
  for (pos = start_angle; pos >= stop_angle; pos -= 1)
  {
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(delay_interval);                       
  }
}
void blink(int time)
{
  for (int i = 0; i < time; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);   
    delay(300);                       
    digitalWrite(LED_BUILTIN, LOW);    
    delay(300);
  }
  return;
}
void loop() {

}

