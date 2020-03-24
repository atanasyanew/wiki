# Raspberry Pi Enviro+ indoor monitoring station

- [Raspberry Pi Enviro+ indoor monitoring station](#raspberry-pi-enviro-indoor-monitoring-station)
  - [Description](#description)
  - [Show case](#show-case)
  - [References](#references)
  - [TODOs](#todos)

## Description

Using Raspberry Pi Zero W and Pimoron's Enviro+ hat for indoor monitoring station.

The station push data to the ``MQTT broker`` where is consumed by the ``Node-Red`` which take care for writing the data to the ``InfluxDb``.
Metrics are visualized with the help of the ``Grafana`` dashboards.

Files and parts:

- STL files for the station - [thing:3818372](https://www.thingiverse.com/thing:3818372)
- [Enviro+ hat for Raspberry Pi – Enviro + Air Quality](https://shop.pimoroni.com/products/enviro?variant=31155658457171)
- Raspberry Pi Zero W with microSD card

Run the application on start-up (examples from the pimoroni's guide)

```bash
sudo contab -e
# Add the following in order to execute the script on start-up
@reboot python /home/pi/enviroplus-python/examples/all-in-one.py &

```

## Show case

|![IMG_20200322_132942.jpg](./assets/IMG_20200322_132942.jpg)|![IMG_20200322_132947.jpg](./assets/IMG_20200322_132947.jpg)|
|:-:|:-:|
|![IMG_20200322_132518.jpg](./assets/IMG_20200322_132518.jpg)|![IMG_20200322_132525.jpg](./assets/IMG_20200322_132525.jpg)|
|![IMG_20200321_153340.jpg](./assets/IMG_20200321_153340.jpg)|![IMG_20200321_153358.jpg](./assets/IMG_20200321_153358.jpg)|

## References

- [Getting Started with Enviro+](https://learn.pimoroni.com/tutorial/sandyj/getting-started-with-enviro-plus)
- [Grafana Pimoroni Enviroplus Dashboard](https://grafana.com/grafana/dashboards/11605)
- [How to run a script at start-up on a Raspberry Pi using crontab](https://www.raspberrypi.org/blog/how-to-run-a-script-at-start-up-on-a-raspberry-pi-using-crontab/)

## TODOs

- source code of the station
- JSON model of the data
- Node-red flow for consume from the mqtt and write to the influxDB
