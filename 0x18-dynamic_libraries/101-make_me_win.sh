#!/bin/bash
wget -P .. https://raw.githubusercontent.com/ahmedmkamal313/alx-low_level_programming/master/0x18-dynamic_libraries/libcust.so
export LD_PRELOAD="$PWD/../libcust.so"
