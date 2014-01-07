import requests
import serial
import time

ser = serial.Serial('/dev/tty.usbmodemfd1331', baudrate=9600)
time.sleep(2)

if ser.isOpen():
  while (True):
    r = requests.get('http://data.mtgox.com/api/2/BTCUSD/money/ticker_fast')
    r = r.json()
    buy = r['data']['buy']['value']
    sell = r['data']['sell']['value']
    ser.write(str(buy))
    ser.write('\n')
    ser.write(str(sell))
    time.sleep(25)