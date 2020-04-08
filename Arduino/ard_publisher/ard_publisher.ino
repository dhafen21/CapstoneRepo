/*
 * rosserial Subscriber Example
 * Blinks an LED on callback?
 */

#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

std_msgs:String str_msg


//void messageCb( const std_msgs::Int32& toggle_msg){
//  
//  int numSteps = toggle_msg.data;
//    digitalWrite(dir1, LOW);
//    digitalWrite(dir2, HIGH);
//  for (int i = 0; i < numSteps; i++) {
//    digitalWrite(steps1, HIGH);
//    digitalWrite(steps2, HIGH);
//    delay(5);
//    digitalWrite(steps2,LOW);
//    digitalWrite(steps1, LOW);
//    delay(5);
//  }
//}
//
//void messageCb1( const std_msgs::Int32& toggle_msg){
//  int numSteps = toggle_msg.data;
//    digitalWrite(dir2, LOW);
//    digitalWrite(dir1, HIGH);
//  for (int i = 0; i < numSteps; i++) {
//    digitalWrite(steps1, HIGH);
//    digitalWrite(steps2, HIGH);
//    delay(5);
//    digitalWrite(steps2, LOW);
//    digitalWrite(steps1, LOW);cd 
//    delay(5);
//  }
//}

ros::Publisher imu("data_raw", &str_msg );
//ros::Subscriber<std_msgs::Int32> sub1("motor2", &messageCb1 );
void setup()
{
  Serial.begin(115200);
  nh.initNode();
  nh.advertise(imu);
}

void loop()
{
  
  nh.spinOnce();
  delay(100);
}
