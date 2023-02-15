#!/bin/bash
dir=$(pwd)
###
# @Author: NEFU AB-IN
# @Date: 2023-02-15 17:14:07
 # @FilePath: \GPLT\script.sh
 # @LastEditTime: 2023-02-15 17:17:49
###
for file in `ls $dir`
do
    name=${file%.*}
    if [ -f "$file" -o ${file:0-3} == ".py" -o ${file:0-4} == ".exe" ]
    then
        if [ ! -d "$name" ]
        then
            mkdir $name
        fi
    fi
    mv $file $name
done