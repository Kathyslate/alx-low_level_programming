#!/bin/bash

temp_dir=$(mktemp -d)

for file in *.c
do
    cp "$file" "$temp_dir"
done

cd "$temp_dir"

gcc -c *.c

gcc -shared -o liball.so *.o

cp liball.so ..

rm -rf "$temp_dir"
