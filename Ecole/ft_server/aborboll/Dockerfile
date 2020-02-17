FROM debian:buster-slim

ENV MYSQL_USER	'admin'
ENV MYSQL_PASSWORD	'admin'

# Install main libraries
RUN apt-get update && \
  apt-get upgrade -y && \
  apt-get install -y --no-install-recommends \
    curl \
	wget \
	nginx \
	php \
	php-mysql \
	php-fpm \
	php-mbstring \
	vim \
	ed \
	mariadb-server

# Clear cache
RUN apt-get clean && rm -rf /var/lib/apt/lists/*
RUN apt-get update

COPY ./srcs/configs/nginx/*.conf /etc/nginx/sites-available/nginx
COPY ./srcs/configs/nginx/snippets /etc/nginx/snippets
RUN ln -s /etc/nginx/sites-available/nginx /etc/nginx/sites-enabled/

#Copy all scripts to home scripts folder
COPY srcs/scripts /tmp/ft_server/scripts
COPY srcs/databases /tmp/ft_server/databases

#Run start script
RUN sh /tmp/ft_server/scripts/start.sh

WORKDIR /usr/share
	#Download and setup phpmyadmin
	RUN wget --no-check-certificate -q -o /dev/null https://files.phpmyadmin.net/phpMyAdmin/4.9.2/phpMyAdmin-4.9.2-all-languages.tar.gz
	RUN tar xf phpMyAdmin-4.9.2-all-languages.tar.gz && rm -rf phpMyAdmin-4.9.2-all-languages.tar.gz
	RUN mv phpMyAdmin-4.9.2-all-languages phpmyadmin
	COPY ./srcs/configs/phpmyadmin/config.inc.php phpmyadmin
	#Give permissions to phpmyadmin folder
	RUN chown -R www-data:www-data phpmyadmin/*
	RUN chmod -R 755 phpmyadmin/*

#Switch working dir
WORKDIR /var/www/wordpress
	COPY srcs/configs/wordpress/wp-config.php wp-config.php
	#Give permissions to the folder
	RUN chown -R www-data:www-data *
	RUN chmod -R 755 *

CMD bash /tmp/ft_server/scripts/entry_point.sh
EXPOSE 80:80 443:443
