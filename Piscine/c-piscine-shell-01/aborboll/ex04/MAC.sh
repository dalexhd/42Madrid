ifconfig | grep "ether " | sed -e 's/ether//g' | tr -d '\t'
