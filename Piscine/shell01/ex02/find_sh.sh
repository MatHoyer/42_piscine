#!/bin/sh
find -type f -name '*.sh' | rev | cut -d'/' -f 1 | cut -c 1-3 --complement | rev 
