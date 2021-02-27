#!/bin/bash

WORKSPACE_DIR=$(cd .. && pwd)
DOCKER_IMAGE=single-robot/ev3rt-v850:v1.0.0

HAKONIWA_CORE_DIR=$(cd ../../hakoniwa-core && pwd)
HAKONIWA_PROXY_DIR=${HAKONIWA_CORE_DIR}/impl/asset/client/build/cpp
if [ -d ${HAKONIWA_PROXY_DIR} ]
then
	:
else
	echo "ERROR: can not find hakoniwa-core dir"
	exit 1
fi

sudo docker run \
	-v ${WORKSPACE_DIR}:/root/workspace/ev3rt-athrill-v850e2m \
	-v ${WORKSPACE_DIR}/docker/utils/config:/root/workspace/config \
	-v ${WORKSPACE_DIR}/docker/utils/make:/root/workspace/make \
	-v ${WORKSPACE_DIR}/docker/unity:/root/workspace/unity \
	-v ${WORKSPACE_DIR}/docker/proxy:/root/workspace/proxy \
	-v ${HAKONIWA_PROXY_DIR}:/root/workspace/proxy/bin \
	-it --rm --net host --name ev3rt-v850 ${DOCKER_IMAGE} 
