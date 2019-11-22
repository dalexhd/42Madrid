#!/bin/bash
FT_LINE1=6
FT_LINE2=9
cat /etc/passwd | grep -v '#' | awk 'NR%2==0' | awk -F ':*' '{print $1}' | rev | sort | awk "NR>=$FT_LINE1 && NR<=$FT_LINE2" | awk 1 ORS=', ' | sed 's/.\{2\}$/./'
