#!/bin/sh

mem_total=`free | grep ^Mem | awk '{print $2}'`
mem_free=`free | grep ^Mem | awk '{print $4}'`
mem_free_2=`free | grep ^-/+ | awk '{print $4}'`

echo $mem_total
echo $mem_free
echo $mem_free_2
