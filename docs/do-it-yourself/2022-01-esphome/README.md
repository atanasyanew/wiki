# ESPHome 101

*Modified 2022-01-10*

>ESPHome is a system to control your ESP8266/ESP32 by simple yet powerful configuration files and control them remotely through Home Automation systems.

- [ESPHome 101](#esphome-101)
  - [Environment setup](#environment-setup)
  - [Add new device](#add-new-device)
  - [Device flashing](#device-flashing)
  - [Backup and restore](#backup-and-restore)
  - [References](#references)

## Environment setup

There are serval available ways to install ``ESPHome``, such as:
- Native installation (python)
- Addon within Home Assistant
- Docker

For most of the articles I read, using the ``ESPHome`` as addon within the ``Home Assistant`` its probably the easiest way.
Having an instance of HA, but decided to try with a docker.

``docker-compose-esphome.yml``
```yml
version: '3'

services:

  esphome:
    image: esphome/esphome:latest
    container_name: esphome
    environment:
      - ESPHOME_DASHBOARD_USE_PING=true
      - TZ=Europe/Sofia
    volumes:
      - ./volumes/esphome:/config:rw
      # Use local time for logging timestamps
      - /etc/localtime:/etc/localtime:ro
    ports:
      - 6052:6052
    restart: always
    #network_mode: host
```

The web ui available at [http://localhost:6052/](http://localhost:6052/)

## Add new device

Its all about ``yaml`` files.<br>
Adding a new device from the web interface will ask a few questions, so the result is scaffold structure of an yaml file with the given name.<br>
Another option is to add a new edited version of an existing configuration and upload into the configurations folder.<br>
The content of the configuration strongly depends of the features you want to implement, so a full working configuration is not described here, but a few guidelines.<br>
- Use secrets<br>
  For all the required credentials you need to pass, such as WIFI, MQTT, etc..<br>
  On top right corner of the UI a tab called ``SECRETS`` where you can add them, behind the scenes this will add a ``secrets.yaml`` file to store the variables.
- Use substitutions on top of the file, in order to reference repeatable values
  ```yaml
  substitutions:
    device_name: ble-gateway
    mqtt_main_topic: gateway-ble/sensor
  ```
- Use naming conventions<br>
  Good practice is to define a naming convention for a devices and follow it along.<br>
  Also applicable, if you intend to use MQTT topics.

## Device flashing

There are many available options, you may check the WEB UI.<br>
One of the options it to download a ``.bin`` file, so you could use tools such as:
- [esphome-flasher](https://github.com/esphome/esphome-flasher/releases)
- [tasmotizer](https://github.com/tasmota/tasmotizer/releases)

I had problems with some of the ``ESP8266`` boards (could not connect to WIFI), bought from AliExpress.<br>
Arduino IDE serial monitor its also a good option for a troubleshooting.

## Backup and restore

The backups are all about export/import ``.yaml`` files.<br>
In case of using Home assistant, location of the files are in ``config/esphome`` folder.<br>
For docker, you may map a volume as its in the described docker-compose above.

For more details, check:

>[Make a existing ESP Device visible in HA](https://community.home-assistant.io/t/make-a-existing-esp-device-visible-in-ha/133295/6) <br>
>Yaml files are stored at /config/esphome/ so i used file editor instalable from addons and u just download your esphome yaml and upload them on new hassio instance to the same folder.

>[Allow to add existing Esphome nodes to a new Hassio instance for future OTA updates #541](https://github.com/esphome/feature-requests/issues/541)

## References

- [How to use ESPHome without Home Assistant](https://www.youtube.com/watch?v=a3iay-g1AsI)<br>
  YouTube, well defined and structured content, explains how to natively install ESPHome using python, yaml skeleton configurations, secrets for the environment and a lot more.
- [Defining home automation devices in YAML with ESPHome and Home Assistant, no programming required!](https://blog.christophersmart.com/2020/03/31/defining-home-automation-devices-in-yaml-with-esphome-and-home-assistant-no-programming-required/)<br>
  Article, good reading about the yaml configurations and how to use MQTT communication instead of HA API.
- [#354 Tasmota vs ESPhome: Who wins? (DIY Sensors, ESP32, Deep-Sleep, etc.)](https://www.youtube.com/watch?v=nHaFM0tKOvY)<br>
  YouTube, comparison between the two, ESPhome alternative.
- [This is SO Much Better! Getting Started with ESPHome 2021](https://www.youtube.com/watch?v=iufph4dF3YU&t=0s)<br>
  YouTube, installation as addon in Home Assistant.
