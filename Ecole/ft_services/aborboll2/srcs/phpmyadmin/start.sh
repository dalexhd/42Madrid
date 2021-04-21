#! /bin/bash
openrc
touch /run/openrc/softlevel
service php-fpm7 start
service nginx start
telegraf --config /etc/telegraf/telegraf.conf