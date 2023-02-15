#!/bin/bash
dir=$(pwd)
###
# @Author: NEFU AB-IN
# @Date: 2023-02-15 17:14:07
 # @FilePath: \GPLT\script.sh
 # @LastEditTime: 2023-02-15 17:28:51
###
for file in `ls $dir`
do
    name=${file%.*}
    if [ -f "$file" ]
    # if [ ${file:0-3} == ".py" -o ${file:0-4} == ".exe" ]
    then
        if [ ! -d "$name" ]
        then
            mkdir $name
        fi
        mv $file $name
    fi
done