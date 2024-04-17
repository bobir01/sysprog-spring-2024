#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <file1> <file2>"
    exit 1
fi

if [ ! -f "$1" ] || [ ! -f "$2" ]; then
    echo "Both files must exist."
    exit 1
fi

if cmp -s "$1" "$2"; then
    rm "$2"
    echo "Files have the same contents. Second file removed."
else
    echo "Files have different contents."
fi
