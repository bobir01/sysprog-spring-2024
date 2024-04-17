#!/bin/bash

echo "Enter the directory name:"
read directory

if [ -d "$directory" ]; then
    echo "Files in directory '$directory':"
    for file in "$directory"/*; do
        if [ -f "$file" ]; then
            echo "$(basename "$file")"
        fi
    done
else
    echo "Directory '$directory' does not exist."
fi