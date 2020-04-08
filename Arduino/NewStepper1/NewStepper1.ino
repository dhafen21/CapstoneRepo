/*
 * rosserial Subscriber Example
 * Blinks an LED on callback?
 * I switched steps1 with steps2
 */

#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Int32.h>

ros::NodeHandle nh;
int dir1 = 10;    //The direction pin for motor 1
int steps1 = 6;   //the pin that outpus the PWM for motor 2
int dir2 = 9;     //Direction pin for motor 2
int steps2 = 5;   //PWM pin for motor 2


//function that is called after getting a message
void messageCb( const std_msgs::Int32& toggle_msg){
  int x = toggle_msg.data;
  
  if (x < 0) {
    x = x * (-1);
    for (int i = 0; i < x; i++) {
      digitalWrite(dir2, HIGH);
      digitalWrite(dir1, LOW);
  
      digitalWrite(steps1, HIGH);
      digitalWrite(steps2, HIGH);
      delay(2);
      digitalWrite(steps1, LOW);
      digitalWrite(steps2, LOW);
      delay(2);

    }
  } else {
    for (int i = 0; i < x; i++) {
      digitalWrite(dir2, LOW);
      digitalWrite(dir1, HIGH);
  
      digitalWrite(steps1, HIGH);
      digitalWrite(steps2, HIGH);
      delay(2);
      digitalWrite(steps1, LOW);
      digitalWrite(steps2, LOW);
      delay(2);
    }
  }
}
  

ros::Subscriber<std_msgs::Int32> sub("motor1", &messageCb );
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(steps1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(steps2, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);    //Subscribe to the topics

}

void loop()
{
  nh.spinOnce();
  delay(1);
}
