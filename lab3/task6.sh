#!/bin/bash

if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <filename> <start_line> <end_line>"
    exit 1
fi

filename=$1
start_line=$2
end_line=$3

sed -n "${start_line},${end_line}p" "$filename"
