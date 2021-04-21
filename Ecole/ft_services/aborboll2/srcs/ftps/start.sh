#! /bin/bash
set -x # Print commands and their arguments as they are executed
openrc
telegraf --config /etc/telegraf/telegraf.conf &
touch /run/openrc/softlevel
/usr/sbin/vsftpd /etc/vsftpd.conf