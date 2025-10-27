#!/bin/bash

# Check if PID argument is given
if [ -z "$1" ]; then
    echo "Usage: $0 <PID>"
    exit 1
fi

PID=$1

echo "Inspecting process: $PID"

# Show process stats
ps -o pid,vsz,rss -p $PID

# Show memory mapping from /proc
echo "Memory map of process:"
cat /proc/$PID/maps
