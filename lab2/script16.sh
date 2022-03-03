#!/bin/bash
file="myfile"
for var in $(cat $file)
do
echo " $var"
done