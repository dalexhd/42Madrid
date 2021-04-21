FROM alpine:3.12

RUN apk update && \
	apk add openssh-server openssl openrc nginx && \
	apk add telegraf --repository http://dl-2.alpinelinux.org/alpine/edge/community && \
	rm -rf /var/cache/apk/*

WORKDIR /usr/share
	COPY start.sh .

COPY nginx.conf /etc/nginx/nginx.conf
COPY /telegraf.conf /etc/telegraf/telegraf.conf
COPY /website /var/www/website

RUN ls /var/www/

#Give permissions to phpmyadmin folder
RUN mkdir -p /run/nginx

RUN yes "" | openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/localhost.key -out /etc/ssl/certs/localhost.crt >/dev/null

## ensure www-data user exists (https://gist.github.com/briceburg/47131d8caf235334b6114954a6e64922)
RUN set -x ; \
	addgroup -g 82 -S www-data ; \
	adduser -u 82 -D -S -G www-data www-data && exit 0 ; exit 1

RUN chown -R www-data /var/www/website

EXPOSE 22 80 443

CMD ["sh", "/usr/share/start.sh"]