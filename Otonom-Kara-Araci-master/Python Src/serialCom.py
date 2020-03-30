
import serial

ser = serial.Serial("/dev/ttyACM0",9600)
data = []

def getData():
     
     serialdata = ser.readline()

     startData = serialdata[0:1]
     finishData = serialdata[7:8]
     if startData is "#" and finishData is ",":
         wheelCar = int(serialdata[1:4])
         recordData = int(serialdata[5:6])
         return wheelCar,recordData
     else:
         return -1,-1
