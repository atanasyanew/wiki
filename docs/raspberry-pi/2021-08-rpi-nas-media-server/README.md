# Raspberry Pi NAS server with OpenMediaVault and Plex

Initially had only one ``raspberry pi`` that act as a main server with a lot of containers (more than 10), it worked pretty decent, but I realized that would be better to separate some of the services used.

Having one for IoT, Home Automation, Monitoring, etc.. and another one for NAS and Media services.

As a result, the performance is more than enough for me, speed about ``100-120 MB/s`` upload/download.

For now OpenMediaVault and Plex fit my needs as a services, but in future considering add some of the mentioned at [Additional futures](#additional-futures-optional) section.

- [Raspberry Pi NAS server with OpenMediaVault and Plex](#raspberry-pi-nas-server-with-openmediavault-and-plex)
  - [Preparing the Pi](#preparing-the-pi)
  - [Installing OpenMediaVault](#installing-openmediavault)
  - [Docker, Portainer and Plex](#docker-portainer-and-plex)
  - [Additional futures (optional)](#additional-futures-optional)
  - [Remote development (optional)](#remote-development-optional)
  - [Issues and troubleshooting](#issues-and-troubleshooting)
  - [References](#references)
  - [TODO](#todo)

## Preparing the Pi

1. The OS
   - Download [Raspberry Pi OS Lite](https://www.raspberrypi.org/software/operating-systems/) and burn the image, you may use [Raspberry Pi Imager](https://www.raspberrypi.org/software/) or something else of your choice.
   - Place an empty file named ``ssh`` in the boot partition before you eject the card.
2. Connect and run the ``RPI``, should also wire Ethernet cable.
3. Configurations
   - ssh using the default password ``raspberry``
     ```bash
     ssh pi@rasppberry.local
     ```
   - Change the ``Password`` and ``Hostname``, located in ``1 System Options``, consider using ``omv`` as hostname :)
     ```bash
     sudo raspi-config
     ```
   - Update and reboot
     ```bash
     sudo apt update
     sudo apt upgrade
     sudo reboot
     ```
  4. Disable swap and log2ram <br>
     - Disable swap 
       ```bash
       curl https://gist.githubusercontent.com/atanasyanew/017e0d73005de50c82dab31806a4bb98/raw/disable-swap.sh -O
       sudo bash ./disable-swap.sh uninstallswap
       ``` 
     - log2ram <br> 
     You will need a git for installing log2ram
     ```bash
     sudo apt install git
     curl https://gist.githubusercontent.com/atanasyanew/017e0d73005de50c82dab31806a4bb98/raw/log2ram.sh -O
     sudo bash ./log2ram.sh
     sudo reboot
     ```

## Installing OpenMediaVault

>This script will install openmediavault, omv-extras, and flashmemory

You may check and verify the content of this script at the following repository [OpenMediaVault-Plugin-Developers/installScript](https://github.com/OpenMediaVault-Plugin-Developers/installScript).

```bash
sudo wget -O - https://github.com/OpenMediaVault-Plugin-Developers/installScript/raw/master/install | sudo bash
sudo apt update
sudo apt upgrade
sudo reboot
```

Web UI accessible at port 80, [omv.local](http://omv.local/) with the default credential ``admin:openmediavault``

A few things more to be done are:
- Changing the default credential - ``System``/``General settings``
- Setup Date & Time - ``System``
- Storage initialize - ``Storage``/``Disks``, consider wipe the disk
- Creating a file system - ``Storage``/``File Systems``, using the default ``ext4``
- Creating a Users and Shares from ``Access Rights Management``
- Enable SMB/CIFS from ``Services``, then map the folders from the sub tab ``Shares``
- Using the shares from rest of the devices within ``WORKGROUP`` - you should be able to visit the NAS as device in Network section 

## Docker, Portainer and Plex

Docker and portainer can be enabled from the interface, look for ``OMV-Extras`` menu, sub tab - docker.
Portainer web UI serves at port [:9000](http://omv.local:9000)

Installing the Plex done from the portainer UI, using the compose file and the environment variables, provided from the GitHub Gist

1. Download the files from the gist - [atanasyanew/docker-compose.omvstack.yml](https://gist.github.com/atanasyanew/e444150ded1683a093b01683ea71cdc0)
2. Change the environment variables
   - ``PUID`` and ``PGID`` can be evaluated using ``id`` command in terminal
     ```bash
     id
     uid=1000(pi) gid=100(users) groups=100(users),1000(pi)...
     ```
   - Change volume paths
     ```yaml
     volumes:
      - /srv/dev-disk-by-uuid-af5a8eb6-0258-4501-b933-57d646cf7f70/Media:/media-content
     ```
3. Using the Portainer UI, go to ``Stacks``, ``Add stack`` button, ``Upload from your computer`` tab and then upload the compose file and env file.
4. Configure Plex from the UI, [:32400/web](http://omv.local:32400/web/)

## Additional futures (optional)

Optional, but nice to have futures

- [ ] qbittorrent <br>
  [web - www.qbittorrent.org](https://www.qbittorrent.org/) <br>
  [docker - hub.docker.com/r/linuxserver/qbittorrent](https://hub.docker.com/r/linuxserver/qbittorrent) <br>
  Torrent client

- [ ] Sonarr <br>
  [sonarr.tv](https://sonarr.tv/) <br>
  [hub.docker.com/r/linuxserver/sonarr](https://hub.docker.com/r/linuxserver/sonarr) <br>
  Same as radarr but for TV shows
  > Sonarr (formerly NZBdrone) is a PVR for usenet and bittorrent users. It can monitor multiple RSS feeds for new episodes of your favorite shows and will grab, sort and rename them. It can also be configured to automatically upgrade the quality of files already downloaded when a better quality format becomes available.

- [ ] Radarr <br>
  [radarr.video](https://radarr.video/) <br>
  [hub.docker.com/r/linuxserver/radarr](https://hub.docker.com/r/linuxserver/radarr) <br>
  A fork of Sonarr to work with movies. <br>
  Automated movie management and integration with torrent client <br>

- [ ] Lidarr <br>
  [lidarr.audio](https://lidarr.audio/) <br>
  [hub.docker.com/r/linuxserver/lidarr](https://hub.docker.com/r/linuxserver/lidarr) <br>
  Same as radarr but for Music
  > Lidarr is a music collection manager for Usenet and BitTorrent users. It can monitor multiple RSS feeds for new tracks from your favorite artists and will grab, sort and rename them. It can also be configured to automatically upgrade the quality of files already downloaded when a better quality format becomes available.
  > Music collection manager for Usenet and BitTorrent users. It can monitor multiple RSS feeds for new albums from your favorite artists and will interface with clients and indexers to grab, sort, and rename them.

- [ ] Jackett <br>
  [https://github.com/Jackett/Jackett](https://github.com/Jackett/Jackett) <br>
  [hub.docker.com/r/linuxserver/jackett](https://hub.docker.com/r/linuxserver/jackett) <br>
  Torrent indexers proxy <br>
  > Jackett works as a proxy server: it translates queries from apps (Sonarr, SickRage, CouchPotato, Mylar, etc) into tracker-site-specific http queries, parses the html response, then sends results back to the requesting software. <br>
  > This allows for getting recent uploads (like RSS) and performing searches. Jackett is a single repository of maintained indexer scraping & translation logic - removing the burden from other apps. <br>
  > Is a program available for OSX, Windows, and Linux that works as a proxy server to translate queries from apps (Sonarr, Radarr, Lidarr, SickRage, CouchPotato, etc.) into tracker-site-specific HTTP queries, parses the HTML response, and then sends results back to the requesting software. This allows for getting recent uploads (like RSS) and performing searches. Jackett is a single repository of maintained indexer scraping & translation logic – removing the burden from other apps.

## Remote development (optional)

Found it very useful to edit files on the ``RPI``

My main motivation was when I had to edit OpenMediaVault ``config.xml``.

VS code has extension so called [Remote - SSH](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-ssh).

Using of the extension is straight forward, ``ctr + shift + p`` and type/choose ``Remote-SSH: Connect to Host...``, then follow the guide.

## Issues and troubleshooting

The problems I faced.

- **Creating a file system too much time.**
  
  I was having to trouble creating a file system from ``Storage/File Systems`` (using a brand new HDD), it was take hours of time and then crashes.
  The solution - I forgot to ``apt update`` and ``apt upgrade`` after installing the OMV.
<br>

- **Cannot SSH after reboot**
  Tick ``Permit root login`` on, located in ``Services/SSH``. 
  In my case it was on, but still should be turned ``of`` and ``on`` with the apply changes to take effect.
<br>

- **Unable to use remote development**  
  Tick ``TCP Forwarding`` on, located in Services/SSH.
<br>

- **Cannot delete shared folder**
  In order to delete the shared folder from ``Access Rights Management/Shared Folders``, the folder should not be referenced, you may check If so under the sub tab ``Shared Folder In Use`` or for some of the services such as ``Services/SMB`` the sub tab ``Shares``.
  
  In my case it was not, but still cannot delete a specific folder, the reboot and unassign permissions didn't help.
  
  The solution is to deal with the ``config.xml``, VS Code remote development used to edit the xml file.
  ```bash
  cd /etc/openmediavault
  cp config.xml config.bk
  ```
  Find and delete the section for the folder, the structure look like this:
  ```xml 
  <sharedfolder>
    <uuid>9e633982-8aeb-4d00-95e4-bc19fd6965fb</uuid>
    <name>FolderName</name>
  </sharedfolder>
  ```

## References

- [Installing OpenMediaVault to a Raspberry Pi](https://pimylifeup.com/raspberry-pi-openmediavault/)
- [Raspberry Pi 2.5 Gbps 16 TB OMV NAS - Setup and Performance](https://www.jeffgeerling.com/blog/2021/raspberry-pi-25-gbps-16-tb-omv-nas-setup-and-performance)
- [Build a Raspberry Pi 4 NAS with Open Media Vault 5](https://linuxhint.com/raspberry_pi_open_media_vault/)
- [YouTube - Raspberry Pi OMV 5 NAS](https://www.youtube.com/watch?v=LOg4xfDQafc)
- [YouTube - Openmediavault 5 (OMV5) Stable Complete Install and Setup including Portainer](https://www.youtube.com/watch?v=M_oxzpvMPTE)
- [YouTube - INSTALL PLEX ON RASPBERRY PI 4 USING PORTAINER DOCKER EPISODE 23](https://www.youtube.com/watch?v=XudbMJ_3NRc)

<!-- 
Easy Automated Home Media Server: VPN, Radarr, Sonarr, Lidarr, Librarian in 10 Minutes.
https://www.youtube.com/watch?v=5rtGBwBuzQE

Setup and Configure Sonarr Radarr Lidarr and Jackett with Torrents or Usenet
https://www.youtube.com/watch?v=momNnMYkmtQ

Transmission, Docker and Openmediavault
https://www.youtube.com/watch?v=rwovJ9kUSoA

Monitor Transmission Downloads in Home Assistant!!
https://www.youtube.com/watch?v=2bBoHjqCEa8 
-->

## TODO

- [ ] Monitoring
  - Should install and create a telegraf configuration to collect server stats and send metrics to the main server
  - Attach metrics to Grafana dashboard