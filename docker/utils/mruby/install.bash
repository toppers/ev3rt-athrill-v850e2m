#!/bin/bash

cd /root/tools/mruby-2.0.1
make

cp /root/tools/mruby-2.0.1/build/EV3RT/lib/libmruby.a /root/workspace/mruby/
