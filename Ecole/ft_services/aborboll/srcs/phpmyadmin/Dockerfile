FROM alpine:3.12

#	Install system packages
RUN apk update && \
	apk add openrc curl nginx && \
	apk add telegraf --repository http://dl-2.alpinelinux.org/alpine/edge/community

#	Install php 7
RUN apk add php7 php7-fpm php7-mysqli php7-mbstring php7-session php7-json

#	Remove cache
RUN rm -rf /var/cache/apk/*

WORKDIR /usr/share
	COPY start.sh .

COPY nginx.conf /etc/nginx/nginx.conf

COPY /telegraf.conf /etc/telegraf/telegraf.conf

WORKDIR /var/www/phpmyadmin
	#Download and setup phpmyadmin
	RUN wget --no-check-certificate -q -o /dev/null https://files.phpmyadmin.net/phpMyAdmin/4.9.2/phpMyAdmin-4.9.2-all-languages.tar.gz && \
	tar xf phpMyAdmin-4.9.2-all-languages.tar.gz && rm -rf phpMyAdmin-4.9.2-all-languages.tar.gz && \
	mv phpMyAdmin-4.9.2-all-languages/* . && \
	rmdir phpMyAdmin-4.9.2-all-languages
	COPY ./config.inc.php .
	RUN mkdir tmp && chmod 777 tmp
	## ensure www-data user exists (https://gist.github.com/briceburg/47131d8caf235334b6114954a6e64922)

RUN set -x ; \
	addgroup -g 82 -S www-data ; \
	adduser -u 82 -D -S -G www-data www-data && exit 0 ; exit 1

#Give permissions to phpmyadmin folder
RUN chown -R www-data:www-data *
RUN chown -R www-data /var/lib/nginx
RUN mkdir -p /run/nginx

EXPOSE 5000

CMD ["sh", "/usr/share/start.sh"]