# Heimdall dashboard

*Modified 2021-11-14*

>Heimdall Application Dashboard is a dashboard for all your web applications.

Since too many applications running on the home server, decided to introduce Heimdall in order to have a dashboard to access them all easily.  

``docker-compose.yml``
```yaml
version: '3'

services:

  heimdall:
    image: ghcr.io/linuxserver/heimdall
    container_name: heimdall
    env_file:
      - ./services/heimdall/heimdall.env
    volumes:
      - ./volumes/heimdall/config/www:/config/www
    ports:
      - 8880:80
      - 8883:443
    restart: unless-stopped
```

``heimdall.env``
```env
PUID=1000
PGID=1000
TZ=Europe/Sofia
```

``.gitignore``
```gitignore
# Heimdall
volumes/heimdall/config/*
# !volumes/heimdall/config/www
```

Notice the volume section of the service is not as the same as the example from the docs, since I do not need to access the logs and related files from the host OS, but only the configuration for the dashboard.
This data is enough to create and restore a backup for the service later on.

Use gitignore to avoid pollution of the repository.

**Resources**

- [linuxserver/heimdall](https://docs.linuxserver.io/images/docker-heimdall)<br>
  Docs, linuxserver
- [Meet Heimdall, Your Homelab Application Dashboard](https://www.youtube.com/watch?v=PA01Z6-z8Qs)<br>
  YouTube