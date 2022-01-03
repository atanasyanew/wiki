# WireGuard VPN

*Modified 2022-01-03*

>WireGuard is an extremely simple yet fast and modern VPN that utilizes state-of-the-art cryptography.<br>
>It aims to be faster, simpler, leaner, and more useful than IPsec, while avoiding the massive headache.<br>
>It intends to be considerably more performant than OpenVPN.<br>

``docker-compose.yml``
```yaml
version: '3'

services:

  wireguard:
    image: lscr.io/linuxserver/wireguard
    container_name: wireguard
    cap_add:
      - NET_ADMIN
      - SYS_MODULE
    env_file:
      - ./services/wireguard/wireguard.env
    volumes:
      - ./volumes/wireguard/config:/config
      - ./volumes/wireguard/modules:/lib/modules
    ports:
      - 51820:51820/udp
    restart: unless-stopped
```

``wireguard.env``
```env
TZ=Europe/Sofia
SERVERPORT=51820 #optional
SERVERURL=YourDNS/IP #optional
PUID=1000
PGID=1000
PEERS=2 #optional
PEERDNS=auto #optional
INTERNAL_SUBNET=10.13.13.0 #optional
ALLOWEDIPS=0.0.0.0/0 #optional
```

Use gitignore to avoid pollution of the repository.
``.gitignore``
```gitignore
# wireguard
volumes/wireguard/
```

Make sure you forward a port on your router down to the server.

WireGuard support ``Full and Split Tunneling`` connections, by default configurations are generated as a ``Full tunnel``.<br>
The way you know that is in the ``AllowedIPs`` sections for the peer, if you see ``0.0.0.0`` that means that all traffic will be routed through your wireguard server.<br>
For ``Split tunnel`` in the ``AllowedIPs`` section enter your local lan, this tells wireguard only route traffic to these ip addresses through this vpn vpn server.<br>

Keeping a connection alive.<br>
Can be managed from the ``wg0.conf`` by adding ``PersistentKeepalive = 25`` for the specific peer (every 25 seconds a packet gets sent to that vpn server), for example:
```conf
[Interface]
Address = 10.13.13.1
ListenPort = 51820
PrivateKey = sensitiveInformation
PostUp = iptables -A FORWARD -i %i -j ACCEPT; iptables -A FORWARD -o %i -j ACCEPT; iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
PostDown = iptables -D FORWARD -i %i -j ACCEPT; iptables -D FORWARD -o %i -j ACCEPT; iptables -t nat -D POSTROUTING -o eth0 -j MASQUERADE

[Peer]
# peer1
PublicKey = hiddenInformation
AllowedIPs = 10.13.13.2/32
PersistentKeepalive = 25
```

Clients naming convention.<br>
You may suffix/prefix clients with ``ClientName_ST`` оr ``ClientName_FT`` in order to distinguish between ``full tunnel`` and ``split tunnel`` configurations. 

Adding a profiles to a devices.<br>
Can be done via scanning a QR code, importing a .config file or manual entering the required information.

**Useful commands.**
```bash
# Get wireguard information, such as clients, connected devices, etc..
docker exec -it wireguard wg

# Show QR config for the peer 1
docker exec -it wireguard app/show-peer 1
```

**Resources**

- [linuxserver/wireguard](https://docs.linuxserver.io/images/docker-wireguard)<br>
  Container docs, linuxserver.io
- [HOME VPN USING WIREGUARD DOCKER ON A RASPBERRY PI 4 - EPISODE 28](https://www.youtube.com/watch?v=52djV9CrUzI&t=1049s), YouTube
- [Setup WireGuard on a Raspberry Pi! (VPN Setup Tutorial)](https://www.youtube.com/watch?v=DUpIOSbbvKk&t=598s)
- [Meet WireGuard, the new hotness in VPN](https://www.youtube.com/watch?v=xlyTCuWqDOg)
- [WireHole: WireGuard, Pi-Hole and Unbound in Docker](https://www.youtube.com/watch?v=DOJ39lyx6Js)
