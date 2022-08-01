import serial

# while True:
try:
    ser = serial.Serial()  # open serial port
    ser.baudrate = 9600
    ser.port = 'COM3'
    ser.open()
    print("serial opened!")
    ser.write(b'CGCGCG453534535411SH')
except:
    print("error to open serial port!")
ser.close()             # close port