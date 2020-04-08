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
int pos = 0;


//function that is called after getting a message
void messageCb( const std_msgs::Int32& toggle_msg){
  if (toggle_msg.data < 0 && pos <= 0) {
    for (int i = 0; i < toggle_msg.data / 5; i++) {
      digitalWrite(dir2, HIGH);
      digitalWrite(dir1, LOW);
  
      digitalWrite(steps1, HIGH);
      digitalWrite(steps2, HIGH);
      delay(5);
      digitalWrite(steps1, LOW);
      digitalWrite(steps2, LOW);
      delay(5);
      digitalWrite(steps1, HIGH);
      digitalWrite(steps2, HIGH);
      delay(5);
      digitalWrite(steps1, LOW);
      digitalWrite(steps2, LOW);
      delay(5);
      digitalWrite(steps2, HIGH);
      delay(5);
      digitalWrite(steps2, LOW);
      delay(5);
      digitalWrite(steps1, HIGH);
      digitalWrite(steps2, HIGH);
      delay(5);
      digitalWrite(steps1, LOW);
      digitalWrite(steps2, LOW);
      delay(5);
  }
    pos--;
  } else if (toggle_msg.data > 0 && pos < 0) {
    for (int i = 0; i < toggle_msg.data / 5; i++) {
    digitalWrite(dir2, LOW);
    digitalWrite(dir1, HIGH);

    digitalWrite(steps1, HIGH);
    digitalWrite(steps2, HIGH);
    delay(5);
    digitalWrite(steps1, LOW);
    digitalWrite(steps2, LOW);
    delay(5);
    digitalWrite(steps1, HIGH);
    digitalWrite(steps2, HIGH);
    delay(5);
    digitalWrite(steps1, LOW);
    digitalWrite(steps2, LOW);
    delay(5);
    digitalWrite(steps2, HIGH);
    delay(5);
    digitalWrite(steps2, LOW);
    delay(5);
    digitalWrite(steps1, HIGH);
    digitalWrite(steps2, HIGH);
    delay(5);
    digitalWrite(steps1, LOW);
    digitalWrite(steps2, LOW);
    delay(5);
  }
    pos++;
  } else if (toggle_msg.data < 0 && pos > 0) {
    for (int i = 0; i < toggle_msg.data / 5; i++) {
    digitalWrite(dir2, HIGH);
    digitalWrite(dir1, LOW);

    digitalWrite(steps1, HIGH);
    digitalWrite(steps2, HIGH);
    delay(5);
    digitalWrite(steps1, LOW);
    digitalWrite(steps2, LOW);
    delay(5);
    digitalWrite(steps1, HIGH);
    digitalWrite(steps2, HIGH);
    delay(5);
    digitalWrite(steps1, LOW);
    digitalWrite(steps2, LOW);
    delay(5);
    digitalWrite(steps1, HIGH);
    delay(5);
    digitalWrite(steps1, LOW);
    delay(5);
    digitalWrite(steps1, HIGH);
    digitalWrite(steps2, HIGH);
    delay(5);
    digitalWrite(steps1, LOW);
    digitalWrite(steps2, LOW);
    delay(5);
  }
    pos--;
  } else {
    for (int i = 0; i < toggle_msg.data / 5; i++) {
    digitalWrite(dir2, LOW);
    digitalWrite(dir1, HIGH);

    digitalWrite(steps1, HIGH);
    digitalWrite(steps2, HIGH);
    delay(5);
    digitalWrite(steps1, LOW);
    digitalWrite(steps2, LOW);
    delay(5);
    digitalWrite(steps1, HIGH);
    digitalWrite(steps2, HIGH);
    delay(5);
    digitalWrite(steps1, LOW);
    digitalWrite(steps2, LOW);
    delay(5);
    digitalWrite(steps1, HIGH);
    delay(5);
    digitalWrite(steps1, LOW);
    delay(5);
    digitalWrite(steps1, HIGH);
    digitalWrite(steps2, HIGH);
    delay(5);
    digitalWrite(steps1, LOW);
    digitalWrite(steps2, LOW);
    delay(5);
  }
    pos++;
  }
  
//  int numSteps = toggle_msg.data;
//    digitalWrite(dir1, LOW);    //opposing motors move in opposite directions
//    digitalWrite(dir2, HIGH);
//  for (int i = 0; i < numSteps; i++) {
//    digitalWrite(steps1, HIGH);   
//    digitalWrite(steps2, HIGH);
//    delay(5);
//    digitalWrite(steps2,LOW);
//    digitalWrite(steps1, LOW);
//    delay(5);
//  }
}

//void messageCb1( const std_msgs::Int32& toggle_msg){
//  int numSteps = toggle_msg.data;
//    digitalWrite(dir2, LOW);
//    digitalWrite(dir1, HIGH);
//  for (int i = 0; i < numSteps; i++) {
//    digitalWrite(steps1, HIGH);
//    digitalWrite(steps2, HIGH);
//    delay(5);
//    digitalWrite(steps2, LOW);
//    digitalWrite(steps1, LOW);
//    delay(5);
//  }
//}

ros::Subscriber<std_msgs::Int32> sub("motor3", &messageCb );
void setup()
{
  pinMode(dir1, OUTPUT);
  pinMode(steps1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(steps2, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);    //Subscribe to the topics
///  nh.subscribe(sub1);
}

void loop()
{
  nh.spinOnce();
  delay(1);
}
