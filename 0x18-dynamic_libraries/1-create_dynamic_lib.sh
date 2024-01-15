#!/bin/bash

# Create a temporary directory
temp_dir=$(mktemp -d)

# Copy all .c files to the temporary directory
for file in *.c
do
    if [ ! -f "$file" ]; then
        echo "Error: $file not found"
        exit 1
    fi
    cp "$file" "$temp_dir"
done

# Change to the temporary directory
cd "$temp_dir"

# Compile the .c files into object files
if ! gcc -c *.c; then
    echo "Error: Failed to compile object files"
    exit 1
fi

# Create the dynamic library
if ! gcc -shared -o liball.so *.o; then
    echo "Error: Failed to create dynamic library"
    exit 1
fi

# Copy the dynamic library to the current directory
if ! cp liball.so .; then
    echo "Error: Failed to copy dynamic library to current directory"
    exit 1
fi

# Remove the temporary directory
if ! rm -rf "$temp_dir"; then
    echo "Error: Failed to remove temporary directory"
    exit 1
fi

echo "Dynamic library created successfully: liball.so"
