import serial
import time

# set up the serial line
ser = serial.Serial('/dev/ttyACM0', 115200)
time.sleep(2)

# Read and record the data
data =[]                       # empty list to store the data
while 1:
    b = ser.readline()         # read a byte string
    string_n = b.decode()  # decode byte string into Unicode  
    string = string_n.rstrip() # remove \n and \r
    #flt = float(string)        # convert string to float
    print(string)
    data.append(string)           # add to the end of data list


ser.close()


