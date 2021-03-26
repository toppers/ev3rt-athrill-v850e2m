#!/bin/bash

bash config/create_config.bash base_practice_1 eth0

cd proxy

bash hakoniwa_proxy.bash
