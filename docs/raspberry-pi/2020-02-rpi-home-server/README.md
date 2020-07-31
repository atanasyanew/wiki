# Home server using RPI

Using raspberry pi for home server

**Table of contents:**

- [Home server using RPI](#home-server-using-rpi)
  - [Overview](#overview)
  - [Enable SSH and VNC](#enable-ssh-and-vnc)
  - [Configure DHCP](#configure-dhcp)
  - [Tools](#tools)
  - [Duck DNS](#duck-dns)
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
    - [Samba NAS](#samba-nas)
    - [MotionEye](#motioneye)
  - [Telegraf](#telegraf)
  - [References](#references)

## Overview

At the end of the day - home server using raspberry pi with the fallowing features:

- [x] **SSH**
- [x] **VNC**
- [x] **DHCP**
- [x] **htop**
- [x] **Git**
- [x] **Duck DNS** - Free service which will point a DNS (sub domains of duckdns.org) to an IP of your choice.
- [x] **PiVPN**
- [x] **Docker**
- [x] **Backups**
- [x] **Log2Ram** - Logging in RAM rather than on the SD card.
- [x] **Disable Swap** - By using a swap file, a computer can use more memory than what is physically installed, however pi uses sd card and this this can cause issues.
- [x] Containerized services:
  - [x] **Portainer** - Management UI for Docker.
  - [x] **Pi-hole** - Network-wide Ad Blocking.
  - [x] **Plex media server**
  - [x] **Node-RED**
  - [x] **Mosquitto** - Message broker that implements the MQTT protocol.
  - [x] **InfluxDb** - Time-series database.
  - [x] **Grafana** - Visualize data using dashboards.
  - [x] **Samba NAS** - Samba server as Network Attached Storage in home network.
  - [ ] **MotionEye** - A video surveillance OS.
- [x] **Telegraf** - Agent collecting data and sending it to InfluxDB.

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

## Duck DNS

1. Create [Duck DNS](https://www.duckdns.org/) account
2. Create domain name.
3. Go to install section, choose OS and the created domain, follow the steps.
   Summary of the guide: creates folder with ``duck.sh`` script which makes call to duck dns API in order to update the public IP address of the raspberry pi, then a crontab take care to executes the script each 5min

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

**Setup backups:**

1. [Get Your Dropbox API Access Token](https://www.dropbox.com/developers/apps/create)
2. Install Dropbox-Uploader from the script

    ```shell
    ./menu.sh
    # Navigate to Backup options and follow to the steps (DropBox)
    # Dropbox-Uploader will be installed while asking some configuration settings
    ```

3. Schedule backup execution.
   The script ``~/IOTstack/scripts/docker_backup.sh`` creates the backup for us.
   ``~/Dropbox-Uploader/dropbox_uploader.sh`` called from above, upload the files.
   Use cron to schedule script execution:

   ```shell
    crontab -e
    # Every day at 03:00am.
    0 03 * * * ~/IOTstack/scripts/docker_backup.sh >/dev/null 2>&1
   ```

**Restoring a backup:**

> The "volumes" directory contains all the persistent data necessary to recreate the container. The docker-compose.yml and the environment files are optional as they can be regenerated with the menu. Simply copy the volumes directory into the IOTstack directory, Rebuild the stack and start.

In case of SD card failure:

- Create a new SD card with Raspbian OS
- Add Docker and the stack (follow this guide)
- Stop the containers
- Restore the volumes directory from Dropbox
  In case influxDb does not works we should delete databases and restore the backup as shown in Gramps
- Restart the containers

More details - [IOTstack/wiki/Backups](https://github.com/gcgarner/IOTstack/wiki/Backups)

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

Check [Node-RED Projects docs](https://nodered.org/docs/user-guide/projects/) in order to link your flows from the remote repository or creating one.

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

### Samba NAS

Samba is not included in the [gcgarner/IOTstack](https://github.com/gcgarner/IOTstack) so we have to add the service manually by editing the ``docker-compose.yml``

Example of samba docker compose provided in my [GitHub Gist](https://gist.github.com/atanasyanew/5e1e5ba1af658aab5cd4f965919559ac):

[docker-compose-samba.yml](//gist.githubusercontent.com/atanasyanew/5e1e5ba1af658aab5cd4f965919559ac/raw/docker-compose-samba.yml ':include :type=code')

Volumes to share and configurations in ``command`` sections of the code snipped.

Additional can be made from within inside the container ``docker exec -it samba samba.sh``

References:

- [dperson/samba](https://hub.docker.com/r/dperson/samba) docker image.
- [Pi 4B NAS running Samba: 80MB/s Read and 110MB/s Write](https://www.reddit.com/r/raspberry_pi/comments/c9xhn1/pi_4b_nas_running_samba_80mbs_read_and_110mbs/)

### MotionEye

  TODO, [IOTstack/wiki/MotionEye](https://github.com/gcgarner/IOTstack/wiki/MotionEye)

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

# Permissions
sudo usermod -G video telegraf
sudo usermod -G docker telegraf
sudo usermod -aG docker telegraf

# Restart the service
sudo systemctl restart telegraf
sudo systemctl status telegraf
```

---

## References

- [VNC - raspberry pi documentation](https://www.raspberrypi.org/documentation/remote-access/vnc/README.md)
- [SSH - raspberry pi documentation](https://www.raspberrypi.org/documentation/remote-access/ssh/)
- [PiVPN - official page](https://pivpn.dev/)
- [PiVPN - GitHub](https://github.com/pivpn/pivpn)
- [PiVPN - medium.com, How to use PiVPN to create your own VPN.](https://medium.com/@jasonrigden/how-to-use-pivpn-b65a3a3f0759)
- [PiVPN - YouTube, HOW TO SETUP PiVPN ON THE RASPBERRY PI TUTORIAL](https://www.youtube.com/watch?v=9RSHSt4RuLk)
- [Static IP - How to set a Raspberry Pi with a static ip address](https://www.ionos.com/digitalguide/server/configuration/provide-raspberry-pi-with-a-static-ip-address/)
- [Static IP - piHut, How to give your Raspberry Pi a Static IP Address](https://thepihut.com/blogs/raspberry-pi-tutorials/how-to-give-your-raspberry-pi-a-static-ip-address-update)
