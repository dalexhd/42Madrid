#! /bin/bash
set -x # Print commands and their arguments as they are executed
telegraf --config /etc/telegraf/telegraf.conf &
cd /grafana/bin/
./grafana-server

