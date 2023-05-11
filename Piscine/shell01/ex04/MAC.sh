#!/bin/sh
ifconfig | grep -F 'ether' | cut -c 15-31
