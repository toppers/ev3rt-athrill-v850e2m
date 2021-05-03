#/bin/bash

if [ $# -ne 1 -a $# -ne 2 ]
then
	echo "Usage: $0 <unity-proj> [simtime_filepath]"
	exit 1
fi

UNITY_PRJ=${1}
if [ $# -eq 2 ]
then
	TMPDIR=$(cd ${2} && pwd)
	DIR=${TMPDIR}/unity.csv
	export SYMTIME_MEASURE_FILEPATH=${DIR}
fi
UNITY_PRJ_PATH=unity/${UNITY_PRJ}

if [ -d ${UNITY_PRJ_PATH} ]
then
	:
else
	echo "ERROR: not found ${UNITY_PRJ_PATH}"
	exit 1
fi

export IFCONFIG_IPADDR=127.0.0.1
export RESOLVE_IPADDR=`ifconfig en0 | grep inet | grep -v inet6 | awk '{print $2}'`

UNITY_CFG_TMPL=utils/config/config_proxy_udp_json.mo
bash utils/config/mo ${UNITY_CFG_TMPL} > core_config.json
mv core_config.json ${UNITY_PRJ_PATH}/

