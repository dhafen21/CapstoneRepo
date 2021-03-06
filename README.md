# Team 14 Softech Code Repository


## Overview
The CapstoneRepo holds all the necessary code for running all the hardware we have created
for the capstone project. It is a combination of original work we have created and also
open source code. This document explains how to initialize and run everything.

Before getting started with the code, you will need to configure your computer operating
system and download some necessary software.

1. We found that ROS, the open-source robot operating system software, is easiest to use
on a computer using a linux based operating system. We used Ubuntu 18.04 To read more about
ROS, you can learn about it [here](http://wiki.ros.org/ROS/Introduction)

2. Following the instructions on the [ROS Tutorials Website](http://wiki.ros.org/ROS/Tutorials),
Follow steps 1 and 2 to download and get familiar with using ROS. The distribution
of ROS used for this project is called Melodic. Do not download kinetic.

3. Download the latest Arduino coding environment

Once you have finished, clone the Capstone Repo to your catkin folder using

## Running the Ros software

1. Open a terminal and begin Ros by typing `roscore`
2. program the IMU and Arduino
  * Open the Razor_AHRS.ino file located in CapstoneRepo/src/razor_imu_9dof/src/Razor_AHRS, and upload
  the code to the IMU
  * Open the newTest.ino file in Arduino folder and program the arduino connected to the motor driver
3. Open a new tab in the terminal, cd to the catkin folder, and
 make all the files by typing `catkin_make`
4. To start the IMU, open a new tab in the terminal and cd to the catkin folder
 and type `source ./devel/setup.bash` then `rosrun beginner_tutorials imuPublisher.py`
5. Start the conversion nodeOpen a new tab in the terminal, source the files, then type
`rosrun imu_filter_madgwick imu_filter`
6. Start the PID loop by opening a separate tab in the terminal, sourcing the files
  then running `rosrun beginner_tutorials listener.py`
7. Open the connection to the arduinos by opening a newe tab in the terminal, sourcing
  the code, then running `rosrun rosserial_arduino serial_node.py`
8. Lastly, run the node that allows for communication from the user by opening a new tab in the
  terminal, sourcing the code, then running `rosrun beginner_tutorials talker`
