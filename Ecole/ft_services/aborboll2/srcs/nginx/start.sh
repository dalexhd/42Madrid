#! /bin/bash
openrc
touch /run/openrc/softlevel
service nginx start
telegraf --config /etc/telegraf/telegraf.conf