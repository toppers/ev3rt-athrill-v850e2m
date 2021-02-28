FROM ubuntu:20.04 as single-robot-v850

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
	git \
	vim \
	gem \
	net-tools \
	build-essential \
	libssl-dev libreadline-dev zlib1g-dev \
	wget 

RUN git clone https://github.com/sstephenson/rbenv.git ~/.rbenv
RUN echo 'export PATH=${HOME}/.rbenv/bin:${PATH}' >> ~/.bashrc
RUN git clone https://github.com/sstephenson/ruby-build.git ~/.rbenv/plugins/ruby-build
RUN ${HOME}/.rbenv/bin/rbenv install  2.6.5
RUN ${HOME}/.rbenv/bin/rbenv global  2.6.5
RUN echo 'export PATH=${HOME}/.rbenv/versions/2.6.5/bin:${PATH}' >> ~/.bashrc

WORKDIR /root
RUN mkdir -p downloads 
RUN mkdir -p tools 
RUN mkdir -p workspace

WORKDIR /root/downloads 
RUN wget https://github.com/toppers/athrill-gcc-v850e2m/releases/download/v1.1/athrill-gcc-package.tar.gz 

WORKDIR /root/tools
RUN tar xzvf ../downloads/athrill-gcc-package.tar.gz 

WORKDIR /root/tools/athrill-gcc-package
RUN tar xzvf athrill-gcc.tar.gz
RUN echo 'export PATH=/root/tools/athrill-gcc-package/usr/local/athrill-gcc/bin/:${PATH}' >> /root/.bashrc

WORKDIR /root
RUN git clone --depth 1 https://github.com/toppers/athrill.git && \
    git clone --depth 1 https://github.com/toppers/athrill-target-v850e2m.git
WORKDIR /root/athrill-target-v850e2m/build_linux
RUN make clean && \
    make timer32=true skip_clock_bugfix=true supress_detect_error=true etrobo_optimize=true

RUN echo 'export PATH=/root/athrill/bin/linux:${PATH}' >> ~/.bashrc
RUN mkdir workspace

WORKDIR /root/workspace
RUN  mkdir -p /root/workspace/ev3rt-athrill-v850e2m
RUN  ln -s  /root/athrill /root/workspace/athrill
RUN ln -s /root/workspace/ev3rt-athrill-v850e2m/docker/utils/start-athrill.bash .
RUN ln -s  /root/workspace/ev3rt-athrill-v850e2m/docker/utils/start-athrill-mmap.bash .
RUN ln -s /root/workspace/ev3rt-athrill-v850e2m/docker/utils/clean_build.bash .
RUN ln -s /root/workspace/ev3rt-athrill-v850e2m/docker/utils/rebuild.bash .
RUN ln -s /root/workspace/ev3rt-athrill-v850e2m/docker/utils/Makefile.workspace .
ENV RUBYOPT -EUTF-8

