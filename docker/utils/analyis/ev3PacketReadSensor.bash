#1/bin/bash

HAKONIWA_CORE_PATH=../../../../hakoniwa-core

while [ 1 ]
do
	./packetReader 54003 | protoc --decode=hakoniwa.Ev3PduSensor -I${HAKONIWA_CORE_PATH}/spec/ev3 hakoniwa_ev3.proto
done
