# Using-cloud-with-ESP32
Sending  data to and receiving data from cloud using ESP32.

## Task number: 05

## Task name: sending and receiving data from the cloud using ESP32.

## Reference
https://iotdesignpro.com/projects/how-to-send-data-to-thingspeak-cloud-using-esp32

## Components used
ESP32, USB cable.
Connections: connect ESP32 to computer. Create an account on https://thingspeak.com/, create a new channel.
Go to API keys, copy the write API key, and store it.

## Theory
In this task we are going to measure temperature and hall voltage using ESP32, and observe its plot versus time on our thingspeak account.
Hall effect sensor: detects the presence and measures the magnitude of magnetic effect using Hall effect. Hall effect principle is, “output voltage is directly proportional to strength of the field.” Principle of working of this sensor: current is applied to a thin strip of metal. In the presence of magnetic field, perpendicular to the direction of current, charge carriers are deflected by Lorentz force, producing a difference in voltage between 2 sides of strips.”

## Code
In the first section of the code, we are measuring temperature by including temperature_sens_read() library. Next, we have added the necessary code to connect to Wi-Fi. 
https://github.com/meghana-23-7/using-cloud-with-ESP32/blob/main/sketch_task5.ino

## Problems faced
The values are printed on the serial monitor, but there is change on graphs in my channel on Thingspeak. There is some problem, due to which either ESP32 is not sending or the api is not receiving the values. Made some changes in code, this plotted perfectly.

## Output
The temperature and hall values were successfully printed on the serial monitor.

The graph was plotted on the thingspeak account page.




