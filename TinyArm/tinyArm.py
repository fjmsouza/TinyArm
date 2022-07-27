import time

import serial
ser = serial.Serial()  # open serial port
ser.baudrate = 9600
ser.port = 'COM5'
ser.open()
print(ser.name)
# ser.open()
# print(ser.name)         # check which port was really used
ser.write(b'1234567134567234')
time.sleep(1000)
# ser.close()
ser.close()             # close port