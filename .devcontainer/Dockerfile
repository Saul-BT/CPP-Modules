FROM ubuntu:22.04

# Instala dependencias necesarias para los CPP-Modules
RUN apt-get update && apt-get install -y \
  build-essential \
  zlib1g-dev \
  libbsd-dev \
  git \
  pkg-config \
  && rm -rf /var/lib/apt/lists/*

WORKDIR /cpps
COPY . ./
