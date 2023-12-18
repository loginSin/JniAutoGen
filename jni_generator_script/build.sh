#!/bin/bash

#####################################################################
#
#  Copyright 2023 The Beem Authors
#
#  The jni autogenerate script
#  Usage:
#  Copy Java files to the folder of `java_dir`, then execute build.sh
#  
#####################################################################

java_dir="./java_dir/"
out_dir="./out_dir/"
jni_generator_dir="./src/base/android/jni_generator"
jni_suffix="_jni.h"
include_header="sdk/android/api/jni/jni_generator_helper.h"
namespace="RongCloud"

files=($(ls "$java_dir"))

rm -rf ${out_dir}*
for file in "${files[@]}"
do
    if ! grep -q "\.java$" <<< "$file"; then
    continue
    fi
    filename=$(basename "$file" .java)
    mkdir $out_dir$filename
    echo ">>>>>>> begin generating" $filename${jni_suffix}
    ${jni_generator_dir}/jni_generator.py --input_file ${java_dir}$file --output_dir ${out_dir}$filename \
    --output_name $filename${jni_suffix} --includes $include_header -n $namespace
done
