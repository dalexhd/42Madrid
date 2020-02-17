service php7.3-fpm start
service nginx start
service mysql start
mysql -u root -p$MYSQL_PASSWORD -e "CREATE USER '$MYSQL_USER'@'localhost' identified by '$MYSQL_PASSWORD';" ;\
mysql -u root -p$MYSQL_PASSWORD -e "CREATE DATABASE wordpress;"; \
mysql -u root -p$MYSQL_PASSWORD -e "CREATE DATABASE phpmyadmin;"; \
mysql -u root -p$MYSQL_PASSWORD -e "GRANT ALL PRIVILEGES ON wordpress.* TO '$MYSQL_USER'@'localhost';" ;\
mysql -u root -p$MYSQL_PASSWORD -e "GRANT ALL PRIVILEGES ON phpmyadmin.* TO '$MYSQL_USER'@'localhost';" ;\
mysql -u root -p$MYSQL_PASSWORD -e "FLUSH PRIVILEGES;";
mysql -u root -p${MYSQL_PASSWORD} phpmyadmin < /tmp/ft_server/databases/phpmyadmin.sql
SALT=$(curl -k -L -s https://api.wordpress.org/secret-key/1.1/salt/);
STRING='put your unique phrase here'
printf '%s\n' "g/$STRING/d" a "$SALT" . w | ed -s /var/www/wordpress/wp-config.php
curl -k -L -s --data "weblog_title=FT_SERVER&user_name=admin&admin_password=admin&admin_password2=admin&admin_email=eldalexhd@gmail.com&pw_weak=on" https://localhost/wp-admin/install.php?step=2 > /dev/null
rm -rf /tmp/ft_server
tail
