FROM alpine:3.12

#	Install system packages
RUN apk update && \
	apk add openrc ed curl nginx && \
	apk add telegraf --repository http://dl-2.alpinelinux.org/alpine/edge/community

#	Install php 7
RUN apk add php7 php7-fpm php7-json php7-zlib php7-xml php7-pdo php7-phar php7-openssl \
    php7-pdo_mysql php7-mysqli php7-mysqlnd \
    php7-gd php7-mcrypt \
    php7-curl php7-opcache php7-ctype  \
    php7-intl php7-bcmath php7-dom php7-xmlreader --update-cache --repository http://dl-4.alpinelinux.org/alpine/edge/testing/ 

#	Remove cache
RUN	rm -rf /var/cache/apk/*

COPY /telegraf.conf /etc/telegraf/telegraf.conf

WORKDIR /usr/share
	COPY start.sh .

COPY nginx.conf /etc/nginx/nginx.conf

WORKDIR /var/www
	#Download and setup wordpress
	RUN wget --no-check-certificate -q -o /dev/null https://fr.wordpress.org/latest-es_ES.tar.gz &&  \
	tar xzvf latest-es_ES.tar.gz >/dev/null && \
	rm latest-es_ES.tar.gz

RUN set -x ; \
	addgroup -g 82 -S www-data ; \
	adduser -u 82 -D -S -G www-data www-data && exit 0 ; exit 1


#Give permissions to wordpress folder
WORKDIR /var/www/wordpress
COPY wp-config.php wp-config.php
RUN chown -R www-data:www-data *
RUN chown -R www-data /var/lib/nginx
RUN mkdir -p /run/nginx

EXPOSE 5050

CMD ["sh", "/usr/share/start.sh"]