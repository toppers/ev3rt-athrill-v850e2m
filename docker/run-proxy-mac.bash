#!/bin/bash

if [ $# -ne 1 -a $# -ne 2 ]
then
	echo "Usage: $0 <aplname> [dbg]"
	exit 1
fi

export APLNAME=${1}
export RESOLVE_IPADDR=`ifconfig en0 | grep inet | grep -v inet6 | awk '{print $2}'`
if [ -d ../sdk/workspace/${APLNAME} ]
then
	:
else
	echo "ERROR: can not found ${APLNAME} on ../sdk/workspace/"
	exit 1
fi

if [ $# -eq 1 ]
then
	bash utils/config/mo utils/config/start_proxy_mac_bash.mo > proxy/start_proxy.bash
else
	bash utils/config/mo utils/config/start_proxy_mac_dbg_bash.mo > proxy/start_proxy.bash
fi
chmod +x proxy/start_proxy.bash
chmod +x proxy/start_athrill.bash
bash utils/config/mo utils/config/proxy_param_json.mo > proxy/proxy_param.json


WORKSPACE_DIR=$(cd .. && pwd)
DOCKER_IMAGE=single-robot/ev3rt-v850:v1.0.0

docker run \
	-v ${WORKSPACE_DIR}:/root/workspace/ev3rt-athrill-v850e2m \
	-v ${WORKSPACE_DIR}/docker/utils/config:/root/workspace/config \
	-v ${WORKSPACE_DIR}/docker/utils/make:/root/workspace/make \
	-v ${WORKSPACE_DIR}/docker/unity:/root/workspace/unity \
	-v ${WORKSPACE_DIR}/docker/proxy:/root/workspace/proxy \
	--add-host=localhost:192.168.11.58 \
	-P -p 54002:54002/udp \
	-it --rm  --name ev3rt-v850 ${DOCKER_IMAGE} 
