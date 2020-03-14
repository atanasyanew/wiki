# Home server using RPI

Using raspberry pi for home server

**Table of contents:**

- [Home server using RPI](#home-server-using-rpi)
  - [Overview](#overview)
  - [Enable SSH and VNC](#enable-ssh-and-vnc)
  - [Configure DHCP](#configure-dhcp)
  - [Tools](#tools)
  - [PiVPN](#pivpn)
  - [Docker](#docker)
  - [Backups](#backups)
  - [Log2Ram](#log2ram)
  - [Disable Swap](#disable-swap)
  - [Containers](#containers)
    - [Portainer](#portainer)
    - [Pi-hole](#pi-hole)
    - [Plex](#plex)
    - [Node-RED](#node-red)
    - [Mosquitto](#mosquitto)
    - [InfluxDb](#influxdb)
    - [Grafana](#grafana)
  - [Telegraf](#telegraf)
    - [Samba](#samba)

## Overview

At the end of the day

- [x] SSH [^SSH]
- [x] VNC [^VNC]
- [x] DHCP [^DHCP]
- [x] htop [^htop]
- [x] Git [^Git]
- [x] PiVPN [^PiVPN]
- [x] Docker [^Docker]
- [x] Log2Ram [^Log2Ram]
- [x] Disable Swap [^swap]
- [x] Plex media server [^Plex]
- [x] Node-RED [^Node-RED]
- [x] Mosquitto [^Mosquitto]
- [x] Pi-hole [^Pi-hole]
- [x] Portainer [^Portainer]
- [x] InfluxDb [^InfluxDB]
- [ ] Samba NAS [^Samba]
  
TODO:

- [ ] backups
- [ ] nodered projects test ?
- [ ] samba
- [ ] duck dns

## Enable SSH and VNC

```shell
sudo raspi-config
# Select Interfacing Options
# Enable SSH
# Enable VNC
```

## Configure DHCP

**Assign a static private IP address to Raspberry Pi with a router** - configuration depends on router's brand

**Assign a static private IP address to Raspberry Pi with DHCPCD**
The Raspbian OS have a DHCP client daemon (DHCPCD) that can communicate with the DHCP servers from routers.

Check whether DHCPCD is already activated, and enable it if not.

```bash
sudo service dhcpcd status
# To enable:
# sudo service dhcpcd start
# sudo systemctl enable dhcpcd
```

Edit the ``dhcpcd.conf`` file

```shell
sudo nano /etc/dhcpcd.conf

# Example config settings
interface eth0
static ip_address=192.168.0.100/24
static routers=192.168.0.1
static domain_name_servers=192.168.0.1

interface wlan0
static ip_address=192.168.0.101/24
static routers=192.168.0.1
static domain_name_servers=192.168.0.1

# To exit the editor press "ctrl + x"
# Save changes by press the letter "Y" then hit enter
# Reboot the system
sudo reboot

# Check the configuration, look for the interfaces eth0 and wlan0
ifconfig
```

```shell
ping raspberrypi.local
```

## Tools

```shell
# Install Git and htop
sudo apt-get install git
sudo apt-get install htop
```

## PiVPN

```bash
curl -L https://install.pivpn.dev | bash

pivpn help

# You should create a new profile for each device that will connect
# Create a profile that requires password with:
pivpn add

# List the profiles with:
pivpn list

# Delete profiles with:
pivpn revoke nameOfTheClient
```

Check [Duck DNS](https://www.duckdns.org/), if no static IP address.

## Docker

The [IOTstack](https://github.com/gcgarner/IOTstack) provides easy way of installing docker as well as creating a compose file for our services and a lot more.

```shell
# Make sure you are in /home/pi/ directory
git clone https://github.com/gcgarner/IOTstack.git && cd IOTstack/

./menu.sh
# Execute Install Docker
```

Creating ``docker-compose.yml`` file.

```shell
./menu.sh
# Select Build Stack

# Run the containers in detach mode
docker-compose up -d
```

Updating docker images

```shell
# Stop the containers
docker-compose down

# Pull new versions of the images
docker-compose pull

# Or use the script
./scripts/update.sh
```

## Backups

Uploading docker containers valuable data to cloud (dropbox).

```shell
./menu.sh
# Navigate to Backup options and follow to the steps
```

To do: [project wiki - Backups](https://github.com/gcgarner/IOTstack/wiki/Backups)

## Log2Ram

```shell
./menu.sh
# Navigate to Miscellaneous Commands
# Install log2ram
```

## Disable Swap

Disabling swap is done by the same way as shown above

## Containers

### Portainer

Web UI is available at [192.168.0.xxx:9000](http://192.168.0.100:9000/)

### Pi-hole

Web UI is available at [192.168.0.xxx:8089/admin](http://192.168.0.100:8089/admin)

In order to use Pi-hole, edit each device network settings and point RPI IP as DNS server. Or do it in router level.

### Plex

For the initial setup of the application go to [192.168.0.xxx:32400/web](192.168.0.100:32400/web)

Mount media directories, edit volumes section for plex in ``docker-compose.yml``.

```yml
volumes:
  - /media/pi:/data
  #- ~/media/pi:/data   #This will mount /home/pi/media/pi
```

>When using volumes (-v flags) permissions issues can arise between the host OS and the container, we avoid this issue by allowing you to specify the user PUID and group PGID.

Find ``PUID`` and ``PGID`` type ``id`` as below:

```shell
$ id
  uid=1000(dockeruser) gid=1000(dockergroup) groups=1000(dockergroup)
```

```yml
environment:
     - PUID=1000
     - PGID=1000
```

### Node-RED

Web UI is available at [192.168.0.xxx:1880](http://192.168.0.100:1880/)

Enable project feature, add the following env variable to the ``./services/nodered/nodered.env``

```env
NODE_RED_ENABLE_PROJECTS=true
```

or edit the shared setting file

```shell
sudo nano volumes/nodered/data/settings.js
docker restart nodered
```

### Mosquitto

The broker is available at ``192.168.0.xxx:1883``, no password by default.
Check [IOTstack/wiki/Mosquitto](https://github.com/gcgarner/IOTstack/wiki/Mosquitto) for more information.

### InfluxDb

Key Concepts

- Database - Collection of tables
- Measurement - like tables in SQL
- Tags & Fields - In a SQL world, data are stored in columns, but in InfluxDB we have two other terms tags & fields. Tags are indexed and values are not

```shell
docker exec -it influxdb influx
```

```sql
# Useful commands
HELP
# Create admin user, for example user from the telegraf config file
CREATE USER telegraf WITH PASSWORD 'metricsmetricsmetricsmetrics' WITH ALL PRIVILEGES
SHOW DATABASES
CREATE DATABASE home
USE DATABASE home
SHOW MEASUREMENTS
SELECT * FROM measurementName
```

To do - check retention policy

### Grafana

Web UI is available at [192.168.0.xxx:3000](192.168.0.100:3000)
To configure InfluxDb as data source, access server URL is ``http://influxdb:8086``

Dashboards I'm using:

- [Docker Dashboard](https://grafana.com/grafana/dashboards/10585)
- [Telegraf system overview](https://grafana.com/grafana/dashboards/914)
- [Raspberry Pi Monitoring (modified version of the above one)](https://grafana.com/grafana/dashboards/10578)
- [Home metrics DIY IoT sensor](https://grafana.com/grafana/dashboards/11734)

## Telegraf

It is possible to install the service via IOTStack, but I prefer installing it directly on the Raspberry Pi's OS, since I want to collecting metrics from the RPI and if its installed under docker I should mess with mounting directories and volumes, permissions, writing scripts for querying data, such as CPU and memory usage, temperature etc..

```shell
# Identify which version of Raspbian you're running. In my case is buster
cat /etc/os-releases

# Add the repo's GPG key and add the repo itself
curl -sL https://repos.influxdata.com/influxdb.key | sudo apt-key add -

# Add the repository
echo "deb https://repos.influxdata.com/debian buster stable" | sudo tee /etc/apt/sources.list.d/influxdb.list

sudo apt-get update
sudo apt-get install telegraf

sudo systemctl start telegraf
sudo systemctl status telegraf
```

Telegraf configuration widely depends on your needs. Configurations file location is ``/etc/telegraf/telegraf.conf``

Links for the dashboards in grafana section provides Collector Configuration Details, check them for more information.

The whole configuration file for the mentioned dashboards - [gist.github.com/atanasyanew - telegraf.conf](https://gist.github.com/atanasyanew/5c5db975a7179fc271daea43b6592b5b)

```shell
# Download the configuration from the GitHub Gist
curl https://gist.githubusercontent.com/atanasyanew/5c5db975a7179fc271daea43b6592b5b/raw/telegraf.conf -O

# Replace the configuration file with your own
sudo cp telegraf.conf /etc/telegraf/telegraf.conf

# Fix permissions
sudo usermod -G video telegraf
sudo usermod -G docker telegraf
sudo usermod -aG docker telegraf

# Restart the service
sudo systemctl restart telegraf
sudo systemctl status telegraf
```

### Samba

Samba is not included in the [gcgarner/IOTstack](https://github.com/gcgarner/IOTstack) so we have to add the service manually by editing the ``docker-compose.yml`` using [dperson/samba](https://hub.docker.com/r/dperson/samba) docker image.

[Pi 4B NAS running Samba: 80MB/s Read and 110MB/s Write](https://www.reddit.com/r/raspberry_pi/comments/c9xhn1/pi_4b_nas_running_samba_80mbs_read_and_110mbs/)

docker exec -it samba samba.sh

```yml
version: '3.4'

services:
  samba:
    image: dperson/samba:armhf
    container_name: samba
    environment:
      TZ: EET
    networks:
      - default
    ports:
      - "137:137/udp"
      - "138:138/udp"
      - "139:139/tcp"
      - "445:445/tcp"
    read_only: true
    tmpfs:
      - /tmp
    restart: unless-stopped
    stdin_open: true
    tty: true
    volumes:
      - /media/pi:/mnt:z
      # - /mnt2:/mnt2:z
    command: '-s "usbhub;/mnt;yes;no;yes;" -p' # USB Hub should have access to anyone for anything
    # command: '-s "usbhub;/mnt" -s "Bobs Volume;/mnt2;yes;no;no;bob" -u "bob;bobspasswd"'
    #                           -s "<name;/path>[;browse;readonly;guest;users;admins;writelist;comment]"

networks:
  default:
```

Adding permissions and volumes to share:

---

References:

- [vnc - raspberry pi documentation](https://www.raspberrypi.org/documentation/remote-access/vnc/README.md)
- [ssh - raspberry pi documentation](https://www.raspberrypi.org/documentation/remote-access/ssh/)
- [PiVPN - official page](https://pivpn.dev/)
- [PiVPN - GitHub](https://github.com/pivpn/pivpn)
- [PiVPN - medium.com, How to use PiVPN to create your own VPN.](https://medium.com/@jasonrigden/how-to-use-pivpn-b65a3a3f0759)
- [PiVPN - YouTube, HOW TO SETUP PiVPN ON THE RASPBERRY PI TUTORIAL](https://www.youtube.com/watch?v=9RSHSt4RuLk)
- [static ip - How to set a Raspberry Pi with a static ip address](https://www.ionos.com/digitalguide/server/configuration/provide-raspberry-pi-with-a-static-ip-address/)
- [static ip - piHut, How to give your Raspberry Pi a Static IP Address](https://thepihut.com/blogs/raspberry-pi-tutorials/how-to-give-your-raspberry-pi-a-static-ip-address-update)

<!-- Footnotes -->
[^SSH]: **SSH (Secure Shell)** is a cryptographic network protocol for operating network services securely over an unsecured network.

[^DHCP]: **DHCP (The Dynamic Host Configuration Protocol)** is a network management protocol used on UDP/IP networks whereby a DHCP server dynamically assigns an IP address and other network configuration parameters to each device on a network so they can communicate with other IP networks.

[^VNC]: **VNC (Virtual Network Computing)** is a graphical desktop-sharing system that uses the Remote Frame Buffer protocol to remotely control another computer.

[^htop]: **htop** is an interactive system-monitor process-viewer and process-manager.

[^Git]: **[Git](https://git-scm.com/)** is a distributed version-control system for tracking changes in source code during software development.

[^Docker]: **[Docker](https://www.docker.com/)** is a set of platform as a service products that use OS-level virtualization to deliver software in packages called containers. Containers are isolated from one another and bundle their own software, libraries and configuration files; they can communicate with each other through well-defined channels

[^PiVPN]: **[PiVPN](https://pivpn.dev/)** - Simplest OpenVPN setup and configuration, designed for Raspberry Pi.
**VPN (Virtual private network)** A virtual private network extends a private network across a public network, and enables users to send and receive data across shared or public networks as if their computing devices were directly connected to the private network.

[^Samba]: **Samba** project is one of the most popular ways to turn your Pi into a NAS.
**NAS (Network-attached storage)** is a file-level computer data storage server connected to a computer network providing data access to a heterogeneous group of clients. NAS is specialized for serving files either by its hardware, software, or configuration

[^Plex]: **[Plex](https://www.plex.tv/)** is a client–server media player system and software suite comprising two main components. The Plex Media Server desktop application runs on Windows, macOS and Linux, including some types of NAS devices.

[^Node-RED]: **[Node-RED](https://nodered.org/)** is a programming tool for wiring together hardware devices, APIs and online services in new and interesting ways. It provides a browser-based editor. Node-RED is widely used in IoT.

[^Mosquitto]: **[Eclipse Mosquitto](https://mosquitto.org/)** is an open source (EPL/EDL licensed) message broker that implements the MQTT protocol.
**The MQTT protocol** provides a lightweight method of carrying out messaging using a publish/subscribe model. This makes it suitable for Internet of Things messaging such as with low power sensors or mobile devices such as phones, embedded computers or microcontrollers.

[^Pi-hole]: **[Pi-hole](https://pi-hole.net/)** is a Linux network-level advertisement and Internet tracker blocking application which acts as a DNS sinkhole, intended for use on a private network.
**DNS (Domain Name System)** DNS is the protocol that provides the framework for web browsing. In other words, DNS is a system of computers that provides the infrastructure that allows us to browse the Internet by making the Internet a more human-friendly place.

[^Portainer]: **[Portainer](https://www.portainer.io/)** is a lightweight management UI which allows you to easily manage your Docker stacks, containers, images, volumes, networks and more.

[^Log2Ram]: Log2Ram is a simple Unix shell script that sets up a mount point for logging in RAM rather than on the SD card. The idea is that any application or service sending log entries to /var/log will actually be writing them to virtual log files, which won't rack up any activity on the SD card.

[^swap]: A swap file, sometimes called a page file or paging file, is space on a hard drive used as a temporary location to store information when RAM is fully utilized. By using a swap file, a computer can use more memory than what is physically installed in the computer. However, if the computer is low on drive space, the computer can run slower because of the inability of the swap file to grow.

[^Grafana]: Grafana is a tool to visualize data using dashboard. Is supports, InfluxDB as a data source, amongst many others.

[^InfluxDB]: InfluxDB is a time-series database

[^telegraf]: Telegraf is an agent collecting data and sending it to InfluxDB.
Telegraf is an agent for collecting, processing, aggregating, and writing metrics. It supports various output plugins such as influxdb, Graphite, Kafka, OpenTSDB etc. Grafana is an open source data visualization and monitoring suite

[^Chronograf]: Chronograf is the complete interface for the InfluxDB 1.x Platform
