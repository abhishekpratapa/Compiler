#!/bin/bash

# Output file
output_file="consolidated_files.txt"

# Directories to search
directories=("include")

# Function to check if a file should be ignored based on .gitignore rules
should_ignore() {
    local file="$1"
    local dir="$(dirname "$file")"
    local filename="$(basename "$file")"
    
    # Check all .gitignore files from the file's directory up to the root
    while [[ "$dir" != "." && "$dir" != "/" ]]; do
        if [[ -f "$dir/.gitignore" ]]; then
            if grep -q "^$filename$" "$dir/.gitignore" || grep -q "^$(realpath --relative-to="$dir" "$file")$" "$dir/.gitignore"; then
                return 0  # Should ignore
            fi
        fi
        dir="$(dirname "$dir")"
    done
    
    return 1  # Should not ignore
}

# Function to process each file
process_file() {
    local file="$1"
    
    # Check if the file should be ignored
    if should_ignore "$file"; then
        return
    fi
    
    echo "file://$file" >> "$output_file"
    echo >> "$output_file"
    cat "$file" >> "$output_file"
    echo >> "$output_file"
}

# Clear the output file if it exists
> "$output_file"

# Iterate through directories
for dir in "${directories[@]}"; do
    if [ -d "$dir" ]; then
        # Use find to recurse through directories and process each file
        find "$dir" -type f | while read -r file; do
            process_file "$file"
        done
    else
        echo "Warning: Directory '$dir' not found." >&2
    fi
done

echo "Files have been consolidated into $output_file"