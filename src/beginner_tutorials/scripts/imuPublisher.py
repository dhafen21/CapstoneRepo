#!/usr/bin/env python
import rospy
import sys
import serial
import time
import math
from std_msgs.msg import Int32
from std_msgs.msg import String
from sensor_msgs.msg import Imu
from sensor_msgs.msg import MagneticField


ser = serial.Serial('/dev/ttyACM0', 57600)
time.sleep(2)

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + 'I heard %s', data.data)

def talker():
    # data =[]                       # empty list to store the data
    # b = ser.readline()         # read a byte string
    # string_n = b.decode()  # decode byte string into Unicode
    # string = string_n.rstrip() # remove \n and \r
    # #flt = float(string)        # convert string to float
    # print(string)
    # data.append(string)           # add to the end of data list
    pub_raw = rospy.Publisher('imu/data_raw', Imu, queue_size=10)
    pub_mag = rospy.Publisher('imu/mag', MagneticField, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(50) # 10hz
    while not rospy.is_shutdown():
        rospy.Time(secs=0, nsecs=0)
        now = rospy.get_rostime()

        msg = Imu()
        msg_mag = MagneticField()
        seq = 1
        #data =[]                       # empty list to store the data
        b = ser.readline()         # read a byte string
        string_n = b.decode()  # decode byte string into Unicode
        string = string_n.rstrip() # remove \n and \r
        #flt = float(string)        # convert string to float
        list = string.split(',')
        msg.header.frame_id = "map"
        msg_mag.header.frame_id = "map"
        msg.header.seq = seq
        msg_mag.header.seq = seq
        i = now.nsecs
        iSecs = now.to_sec()
        msg.header.stamp.secs = iSecs
        msg.header.stamp.nsecs = i
        msg_mag.header.stamp.secs = iSecs
        msg_mag.header.stamp.nsecs = i


        seq = seq + 1

        # msg.angular_velocity.x = (float(list[0]) * 180) / math.pi
        # msg.angular_velocity.y = (float(list[1]) * 180) / math.pi
        # msg.angular_velocity.z = (float(list[2]) * 180) / math.pi
        #
        # msg.linear_acceleration.x = float(list[3]) * 9.80665
        # msg.linear_acceleration.y = float(list[4]) * 9.80665
        # msg.linear_acceleration.z = float(list[5]) * 9.80665
        #
        # msg_mag.magnetic_field.x = float(list[6])
        # msg_mag.magnetic_field.y = float(list[7])
        # msg_mag.magnetic_field.z = float(list[8])

        msg.linear_acceleration.x = float(list[0]) * 9.80665
        msg.linear_acceleration.y = float(list[1]) * 9.80665
        msg.linear_acceleration.z = float(list[2]) * 9.80665

        msg.angular_velocity.x = (float(list[3]))
        msg.angular_velocity.y = (float(list[4]))
        msg.angular_velocity.z = (float(list[5]))

        msg_mag.magnetic_field.x = float(list[6])
        msg_mag.magnetic_field.y = float(list[7])
        msg_mag.magnetic_field.z = float(list[8])


        #msg_mag.header.stamp.nsecs = i
        #msg_mag.header.frame_id = "imuFrame"

        # for temp in list:
        #     print temp
        #print(string)
        #data.append(string)           # add to the end of data list
        #hello_str = "hello world %s" % rospy.get_time()
        #rospy.loginfo("Current time %i %i", now.secs, now.nsecs)
        #rospy.loginfo(string)
        pub_raw.publish(msg)
        pub_mag.publish(msg_mag)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
