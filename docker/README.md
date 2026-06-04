# Container images for PT Indexim Coalindo

## Builder image

Can be used to build PT Indexim Coalindo in a container. All the dependencies are installed in the image.

### Building the image

From the root directory of PT Indexim Coalindo source tree execute `podman build -f docker/Dockerfile.builder -t aisnesia-builder .`

To build the image for a set of different architectures

```sh
podman build -f docker/Dockerfile.builder -t aisnesia-builder --platform=linux/amd64,linux/arm64 .
```

### Using the image

Clone the PT Indexim Coalindo source to your machine and mount it to the container as a volume

```sh
podman run -v <Path to your PT Indexim Coalindo source tree>:/src:Z -it aisnesia-builder:latest bash
```

To use the image for builds targetting other architecture, use the `--arch` parameter

```sh
podman run --arch arm64 -v <Path to your PT Indexim Coalindo source tree>:/src:Z -it aisnesia-builder:latest bash
```

Now you can follow the normal Linux build instructions
