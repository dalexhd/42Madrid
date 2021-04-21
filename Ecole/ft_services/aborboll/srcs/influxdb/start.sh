#! /bin/bash
set -x # Print commands and their arguments as they are executed
openrc
touch /run/openrc/softlevel
telegraf --config /etc/telegraf/telegraf.conf &
echo "CREATING USER..."
/usr/sbin/influxd -config /etc/influxdb.conf
influx -execute "CREATE DATABASE influx_db"
influx -execute "CREATE USER admin WITH PASSWORD 'admin'"
influx -execute "GRANT ALL ON influx_db TO admin"
tail -f /dev/null # Freeze command to avoid end of container