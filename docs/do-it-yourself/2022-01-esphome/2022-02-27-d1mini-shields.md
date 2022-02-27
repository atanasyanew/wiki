# ESP8266 D1 mini shields

*Modified 2022-02-27*

WIP!

- [ESP8266 D1 mini shields](#esp8266-d1-mini-shields)
  - [BOM](#bom)
  - [References](#references)

## BOM

## References

<!-- 
D1 Mini Triple Base

2022-02-d1mini-triple-shield-mount.md


2022-02-27-d1mini-shields-showcase

- d1 mini
- battery shield
- sd card shield
- oled display shield 0.66" 64 x 48
- photoresistor shield (diy)
- dht22
- sht30
- bmp180 shield


BOM

triple base boards

connectors

pilars 30mm


d1mini-showcase.yaml
weatherstation-esp32.yaml



template:

id
name
state_topic
unit_of_measurement
icon
update_interval


https://esphome.io/components/display/index.html


 // Print "Mitt Smarta Hus" in top center.
      it.printf(64, 0, id(font1), TextAlign::TOP_CENTER, "Mitt Smarta Hus");

      // Print time in HH:MM format
      it.strftime(0, 60, id(font2), TextAlign::BASELINE_LEFT, "%H:%M", now().timestamp());

      // Print inside temperature (from homeassistant sensor)
      if (id(dht_temperature).has_state()) {
        it.printf(127, 23, id(font2), TextAlign::BASELINE_LEFT , "%.1f°", id(dht_temperature).state);
      }


``secrets.yaml``
```yaml
wifi_ssid: ""
wifi_password: ""
ap_password: ""
ota_password: ""
mqtt_broker: ""
mqtt_port: 1883
mqtt_username: ""
mqtt_password: ""
web_server_password: ""
```


``d1mini-showcase.yaml`` -->
