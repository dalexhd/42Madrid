#!/bin/bash
FT_LINE1="7"
FT_LINE2="15"
cat /etc/passwd | grep -v '#' | awk 'NR%2==0' | awk -F ':*' '{print $1}' | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | awk 1 ORS=', ' | sed 's/.\{2\}$/./' | tr -d '\n'
