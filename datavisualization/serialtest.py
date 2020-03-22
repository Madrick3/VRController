import serial

com = '/dev/ttyACM0'
speed = 115200
#start = time.time()
serie = serial.Serial(com, speed)

"""
try:
    serie = serial.Serial(com,speed)
except:
    print("An error occured: unable to open the specified port " +com)
    exit(0)
"""
