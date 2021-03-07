#!/bin/bash

COUNT=0
while [ 1 ]
do
        echo "############ START CONNECT:${CONNECT} #################"
        ./bin/hakoniwa_proxy ./proxy_param.json 172.27.160.1 50051
        echo "############ SERVER DOWN :${CONNECT} #################"
        sleep 5
done
