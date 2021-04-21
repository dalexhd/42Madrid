#! /bin/bash
set -x # Print commands and their arguments as they are executed
openrc
touch /run/openrc/softlevel
service php-fpm7 start
service nginx start
telegraf --config /etc/telegraf/telegraf.conf

tail -f /dev/null # Freeze command to avoid end of container