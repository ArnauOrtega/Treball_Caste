from playsound import playsound
import serial
pista = ["pista1", "pista2", "pista3","pista4"]
ser = serial.Serial('/dev/ttyACM0',baudrate = 9600, timeout=1)
while 1:
    try:
         num = (int(ser.readline().decode("UTF-8").strip()))-1
    except:continue
    for x in range(4):
        if num == x:
            playsound("/home/ubuntu/pistes/"+pista[x]+".mp3")
