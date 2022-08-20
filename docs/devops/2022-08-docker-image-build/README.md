# Docker image build

*Modified 2022-08-20*

Cheat sheet for build and publish a a docker image.


- [Docker image build](#docker-image-build)
  - [Build and publish docker image](#build-and-publish-docker-image)
  - [Troubleshooting](#troubleshooting)
  - [References](#references)

## Build and publish docker image

Note that a ``Dockerfile`` is required to follow the next steps.

```bash
# Lists all builder instances
docker buildx ls

# Make a new builder instance with the given name and supported platforms
docker buildx create --name yourBuilderName --platform linux/arm,linux/arm64,linux/amd64,linux/s390x

# Use the newly created builder instance
docker buildx use yourBuilderName

# Shows information about the current or specified builder
docker buildx inspect --bootstrap

# Build docker image and publish it to docker hub
docker buildx build --platform linux/arm,linux/arm64,linux/amd64,linux/s390x -t dockerHubUsrName/imageName . --push

# You may pull and run the image by the following command.
docker run -p 1880:1880 -e ENV_NAME="ENV_VALUE" dockerHubUsrName/imageName
```

<!-- 
docker buildx ls
docker buildx create --name aqualinks --platform linux/arm,linux/arm64,linux/amd64,linux/s390x
docker buildx use aqualinks
docker buildx inspect --bootstrap
docker buildx build --platform linux/arm,linux/arm64,linux/amd64,linux/s390x -t ayanew/aqualinks . --push
docker run -p 1880:1880 -e MQTT_URL="192.168.0.100" ayanew/aqualinks 
-->

## Troubleshooting

- The command ``docker buildx ls `` returns error ``invalid character '\x00' looking for beginning of value``
  How to fix?: Fixed the issue by deleting the ``config.json`` file, then restart the docker, located in personal folder .docker windows

## References

- [How to Build Multi-Architecture Docker Images with BuildX | Deploy containers to x86 and ARM!](https://www.youtube.com/watch?v=hWSHtHasJUI)<br>
  Source of content - YouTube
- [Docker 101: Multi-arch Docker container building with BuildX - Docker for Windows - part 1](https://www.youtube.com/watch?v=4iOVYyzIyTA)<br>
  Source of content - YouTube
