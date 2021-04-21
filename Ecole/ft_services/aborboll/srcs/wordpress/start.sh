set -x # Print commands and their arguments as they are executed
openrc
touch /run/openrc/softlevel
service php-fpm7 start
service nginx start
if [ ! -f ./wordpress_configured ]; then
	echo "=> WordPress is not configured yet, configuring WordPress ..."
	SALT=$(curl -k -L -s https://api.wordpress.org/secret-key/1.1/salt/);
	printf '%s\n' "g/put your unique phrase here/d" a "$SALT" . w | ed -s /var/www/wordpress/wp-config.php
	curl -k -L -s --data "weblog_title=FT_CONTAINERS&user_name=admin&admin_password=admin&admin_password2=admin&admin_email=aborboll@student.42.fr&pw_weak=on" http://localhost:5050/wp-admin/install.php?step=2
	touch ./wordpress_configured
else
	echo "=> WordPress is already configured"
fi
telegraf --config /etc/telegraf/telegraf.conf
tail -f /dev/null # Freeze command to avoid end of container
