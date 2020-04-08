// %Tag(FULLTEXT)%
// %Tag(ROS_HEADER)%
#include "ros/ros.h"
// %EndTag(ROS_HEADER)%
// %Tag(MSG_HEADER)%
#include "std_msgs/String.h"
#include "std_msgs/Empty.h"
#include "std_msgs/Int32.h"
// %EndTag(MSG_HEADER)%

#include <sstream>
#include <iostream>

using namespace std;


/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  //create the publishers
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Publisher chatter_pub2 = n.advertise<std_msgs::Int32>("motor1", 1000);
  ros::Publisher chatter_pub3 = n.advertise<std_msgs::Int32>("motor2", 1000);
  ros::Publisher chatter_pub4 = n.advertise<std_msgs::Int32>("motor3", 1000);

  ros::Rate loop_rate(10);

  int count = 0;

  //allows for input to direct the motor either up or down
  while (ros::ok())
  {
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());


    chatter_pub.publish(msg);

    std_msgs::Int32 myMsg;
    std_msgs::Int32 myMsg1;
    std_msgs::Int32 myMsg2;
    std_msgs::Int32 myMsg3;



    int numFlashes;
    int line;
    cout << "1 = L/R, 2 = U/D, 3 = Box, 4 = Wipe Down, 5 = Pick/Drop, 6 = Range of Motion: ";


    cin >> line;
    cin.ignore();

    switch(line) {

      case 1:


        cout << "Enter number of steps: ";
        cin >> numFlashes;

        myMsg.data = numFlashes;

            chatter_pub2.publish(myMsg);
            break;

          myMsg1.data = -400;
          myMsg2.data = -800;

          chatter_pub2.publish(myMsg); //left for 100
          ros::Duration(.8).sleep(); // sleep for half a second

          chatter_pub2.publish(myMsg2); //left for 100
          ros::Duration(.8).sleep(); // sleep for half a second

          case 2:
              chatter_pub3.publish(myMsg);
              break;
          case 3:
            myMsg.data = 200;
            myMsg1.data = -200;
            myMsg2.data = 20;

            chatter_pub2.publish(myMsg); //left for 100
            ros::Duration(.8).sleep(); // sleep for half a second
            chatter_pub3.publish(myMsg);    //down 100
            ros::Duration(.8).sleep(); // sleep for half a second

            myMsg.data = 400;
            myMsg1.data = -400;


            chatter_pub2.publish(myMsg1);   //right
            ros::Duration(1.6).sleep(); // sleep for half a second

            chatter_pub3.publish(myMsg1);   //up
            ros::Duration(1.6).sleep(); // sleep for half a second


            myMsg.data = 200;
            myMsg1.data = -200;

            chatter_pub2.publish(myMsg);    //left
            ros::Duration(.8).sleep(); // sleep for half a second

            chatter_pub3.publish(myMsg);
            ros::Duration(.8).sleep(); // sleep for half a second

            myMsg.data = 200;
            myMsg1.data = -200;

            chatter_pub2.publish(myMsg); //left for 100
            ros::Duration(.8).sleep(); // sleep for half a second
            chatter_pub3.publish(myMsg);    //down 100
            ros::Duration(.8).sleep(); // sleep for half a second

            myMsg.data = 400;
            myMsg1.data = -400;


            chatter_pub2.publish(myMsg1);   //right
            ros::Duration(1.6).sleep(); // sleep for half a second

          ros::Duration(2.5).sleep(); // sleep for half a second
            chatter_pub3.publish(myMsg1);   //up
            ros::Duration(1.6).sleep(); // sleep for half a second


            myMsg.data = 200;
            myMsg1.data = -200;

            chatter_pub2.publish(myMsg);    //left
            ros::Duration(.8).sleep(); // sleep for half a second

            chatter_pub3.publish(myMsg);
            ros::Duration(.8).sleep(); // sleep for half a second

//            chatter_pub2.publish(myMsg1);
              break;
          case 4:
            myMsg.data = 200;
            myMsg1.data = -200;
            myMsg2.data = 20;

            chatter_pub2.publish(myMsg1);
            chatter_pub3.publish(myMsg1);

            myMsg.data = 400;
            myMsg1.data = -400;

            for (int i = 0; i < 10; i++) {
              chatter_pub3.publish(myMsg);
              ros::Duration(1.6).sleep();
              chatter_pub2.publish(myMsg2);
              ros::Duration(.8).sleep();
              chatter_pub3.publish(myMsg1);
              ros::Duration(1.6).sleep();
              chatter_pub2.publish(myMsg2);
              ros::Duration(.8).sleep();
            }

            myMsg.data = 200;
            myMsg1.data = -200;

            chatter_pub2.publish(myMsg1);
            chatter_pub3.publish(myMsg);
          break;
          case 5:
          myMsg.data = 200;
          myMsg1.data = -200;
          myMsg2.data = -400;

          for (int i = 0; i < 3; i++) {
            chatter_pub2.publish(myMsg); //left for 100
            ros::Duration(.8).sleep(); // sleep for half a second

            chatter_pub3.publish(myMsg); //left for 100
            ros::Duration(2).sleep(); // sleep for half a second

            chatter_pub3.publish(myMsg1); //left for 100
            ros::Duration(.8).sleep(); // sleep for half a second

            chatter_pub2.publish(myMsg2); //left for 100
            ros::Duration(1.6).sleep(); // sleep for half a second

            chatter_pub3.publish(myMsg); //left for 100
            ros::Duration(2).sleep(); // sleep for half a second

            chatter_pub3.publish(myMsg1); //left for 100
            ros::Duration(.8).sleep(); // sleep for half a second

            chatter_pub2.publish(myMsg); //left for 100
            ros::Duration(.8).sleep(); // sleep for half a second
          }
          break;

          case 6:
          myMsg.data = 400;
          myMsg1.data = -400;
          myMsg2.data = -800;
          myMsg3.data = 800;

          chatter_pub2.publish(myMsg); //left for 100
          ros::Duration(1.6).sleep(); // sleep for half a second

          chatter_pub2.publish(myMsg2); //left for 100
          ros::Duration(2.5).sleep(); // sleep for half a second

          chatter_pub2.publish(myMsg3); //left for 100
          ros::Duration(2.5).sleep(); // sleep for half a second

          chatter_pub2.publish(myMsg2); //left for 100
          ros::Duration(2.5).sleep(); // sleep for half a second

          chatter_pub2.publish(myMsg); //left for 100
          ros::Duration(4).sleep(); // sleep for half a second

          chatter_pub3.publish(myMsg); //left for 100
          ros::Duration(1.6).sleep(); // sleep for half a second

          chatter_pub3.publish(myMsg2); //left for 100
          ros::Duration(2.5).sleep(); // sleep for half a second

          chatter_pub3.publish(myMsg3); //left for 100
          ros::Duration(2.5).sleep(); // sleep for half a second

          chatter_pub3.publish(myMsg2); //left for 100
          ros::Duration(2.5).sleep(); // sleep for half a second

          chatter_pub3.publish(myMsg); //left for 100
          ros::Duration(1.6).sleep(); // sleep for half a second

          break;

          case 7:
            myMsg.data = 200;
            myMsg1.data = -200;
            chatter_pub4.publish(myMsg); //left for 100
            ros::Duration(1.6).sleep(); // sleep for half a second
            chatter_pub4.publish(myMsg1); //left for 100
            ros::Duration(1.6).sleep(); // sleep for half a second
          break;

    }
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
// %EndTag(FULLTEXT)%
