import serial
import time
import string
import MySQLdb

#insert port path to replace PORT
arduino = serial.Serial(PORT, 9000)
db = MySQLdb.connect("mysql.cc.puv.fi", "e1601128", "XkJuRzUxEPe5", "e1601128_smart_clothes")
cusor = db.cusor()

print ("UDOO System - Wearable Smart Devices")
print ("Start")

while True:
    reading = arduino.readLine()
    data = string.split(reading, "#")
    sql = "INSERT INTO DATA (TEMP, HUM, SPEED, DIS, CALO, STEP) VALUES(" + data[0]+ "." + data[1]+ "." + data[2]+ "." + data[3]+ "." + data[4]+ "." +data[5]+ ")"

    print("Temperature = ", data[0])
    print ("Hudminity = ", data[1])
    print ("Speed = ", data[1])
    print ("Distance = ", data[1])
    print ("Calories burnt = ", data[1])
    print ("Steps converted = ", data[1])

    cusor.execute(sql)
