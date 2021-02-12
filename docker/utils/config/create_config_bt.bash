#!/bin/bash

if [ $# -ne 3 ]
then
	echo "Usage: $0 <apl> <unity-proj> <eth>"
	exit 1
fi

export APL=${1}
UNITY_PRJ=${2}
ETH=${3}

UNITY_PRJ_PATH=unity/${UNITY_PRJ}
EV3RT_PRJ_PATH=ev3rt-athrill-v850e2m/sdk/workspace/${APL}

if [ -d ${UNITY_PRJ_PATH} ]
then
	:
else
	echo "ERROR: not found ${UNITY_PRJ_PATH}"
	exit 1
fi

if [ -d ${EV3RT_PRJ_PATH} ]
then
	:
else
	echo "ERROR: not found ${EV3RT_PRJ_PATH}"
	exit 1
fi


export IFCONFIG_IPADDR=`ifconfig | grep -A 1 ${ETH} | grep inet | awk '{print $2}'`
export RESOLVE_IPADDR=`cat /etc/resolv.conf | grep nameserver | awk '{print $2}'`

UNITY_CFG_TMPL=config/config_udp_json.mo
DEV_CFG_TMPL=config/device_config_udp_bt_txt.mo
DEV_CFG_FILE=device_config.txt

bash config/mo ${DEV_CFG_TMPL} > ${DEV_CFG_FILE}
bash config/mo ${UNITY_CFG_TMPL} > config.json

cp config.json ${UNITY_PRJ_PATH}/
mv config.json ${UNITY_PRJ_PATH}/Build/
mv ${DEV_CFG_FILE} ${EV3RT_PRJ_PATH}/
cp config/memory_bt.txt ${EV3RT_PRJ_PATH}/memory.txt
touch ${EV3RT_PRJ_PATH}/__ev3rt_bt_in
touch ${EV3RT_PRJ_PATH}/__ev3rt_bt_out

exit 0
