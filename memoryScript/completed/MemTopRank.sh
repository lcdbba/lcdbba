#!/bin/sh

echo USER %MEM COMMAND
top -b -n1 | awk '{print $2, $10,$12}'| grep -v 0.0 | tail -n +7 | sort -rk 2 |head -10

