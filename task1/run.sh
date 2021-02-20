#!/bin/bash

path_to_dir=$(realpath $1)
file_extension=$2
backup_dir_name=$3
archieve_name=$4

file_pattern="*.$file_extension"

mkdir $backup_dir_name

recursive_search() {
    local path=$1
    for x in $(ls $path); do
        if [[ $(realpath $path/$x) != $(realpath $backup_dir_name) ]]; then 
            if [[ $x == $file_pattern ]]; then
                mkdir -p $backup_dir_name/$path
                cp $path/$x $backup_dir_name/$path
            elif [[ -d $path/$x ]]; then
                recursive_search $path/$x
            fi
        fi
    done
}

recursive_search $path_to_dir

tar -czf $archieve_name $backup_dir_name

echo "done"
