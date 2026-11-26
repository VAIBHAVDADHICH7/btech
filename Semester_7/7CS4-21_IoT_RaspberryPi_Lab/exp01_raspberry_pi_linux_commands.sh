#!/usr/bin/env bash
# Exp 1: Raspberry Pi Linux Terminal Commands Reference
ls -la
mkdir -p rpi_demo && cd rpi_demo || exit 1
touch sensor.log
echo "temp=27.5C" > sensor.log
cat sensor.log
tar -czf sensor.tar.gz sensor.log
ps aux | head -n 5
cd .. && rm -rf rpi_demo
