import numpy as np
#import control as cnt

# physical parameters
g = 9.8
theta1 = 0 #45.0*np.pi/180.0
theta2 = 0
phi1 = 0
phi2 = 0
maxAngle = 160 #abs(theta1+theta2) or abs(phi1 + phi2)
m1 = 0.5
m2 = 0.5
L1 = 0.158242 #This is the length for the interlock joint (6.23 in)
L2 = L1*2 #This is the length for the interlock joint
F_e = 0 # The stepper motors will hold firm in the position you've asked them to.
F_max = 2.0
b = 0.1 #Do we need a damping ratio for this?
kp = 0.2 #5 - F_e FIXME calculate later
zeta = 0.707
wn = 0 #FIXME
kd = 0 #2*m*zeta*wn - b FIXME calculate later
ki = 0
sigma = 0.05
degreesPerStep = 400/360
radiusOfPulley = 0.028575 #1.125in in meters
stringPulledPerStep = (degreesPerStep/360.0)*2.0*np.pi*radiusOfPulley

# modeling parameters
Ts = 0.01 # Use this for sampling rate
