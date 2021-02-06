#!/bin/bash

WORKSPACE_DIR=$(cd .. && pwd)
ATHRILL_DEVICE_DIR=$(cd ../../athrill-device && pwd)
DOCKER_IMAGE=single-robot/ev3rt-v850:v1.0.0

sudo docker run \
	-v ${WORKSPACE_DIR}:/root/workspace/ev3rt-athrill-v850e2m \
	-v ${ATHRILL_DEVICE_DIR}:/root/athrill-device \
	-it --rm --net host --name ev3rt-v850 ${DOCKER_IMAGE} 
