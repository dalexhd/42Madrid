#! /bin/bash
openrc
touch /run/openrc/softlevel
telegraf --config /etc/telegraf/telegraf.conf &
echo "CREATING USER..."
influx -execute "CREATE DATABASE influx_db"
influx -execute "CREATE USER admin WITH PASSWORD 'admin'"
influx -execute "GRANT ALL ON influx_db TO admin"
/usr/sbin/influxd -config /etc/influxdb.conf
