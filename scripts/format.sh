#!/bin/bash

# Directories to search
directories=("include" "src" "test" "cli")

# File extensions to process
extensions=("c" "cpp" "cxx" "h" "hpp")

# Build the find command
find_cmd="find ${directories[@]} -type f \("

# Add file extensions to the find command
for i in "${!extensions[@]}"; do
    if [ $i -gt 0 ]; then
        find_cmd+=" -o"
    fi
    find_cmd+=" -name \"*.${extensions[$i]}\""
done

find_cmd+=" \)"

# Run clang-format on the found files using Google style
eval $find_cmd | xargs clang-format -i -style=Google

echo "Clang-format has been applied to all matching files using Google style."