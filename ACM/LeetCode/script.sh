###
# @Author: NEFU AB-IN
# @Date: 2023-02-15 17:45:24
# @FilePath: \LeetCode\script.sh
# @LastEditTime: 2023-02-15 17:48:33
###
#!/bin/bash
dir=$(pwd)
for file in `ls $dir`
do
    name=${file%.*}
    if [ -f "$file" -a ${file:0-3} != ".sh" ]
    # if [ ${file:0-3} == ".py" -o ${file:0-4} == ".exe" ]
    then
        if [ ! -d "$name" ]
        then
            mkdir $name
        fi
        mv $file $name
    fi
done