FROM alpine:3.12

RUN apk update && \
	apk add mariadb mariadb-client openrc && \
	apk add telegraf --no-cache --repository http://dl-2.alpinelinux.org/alpine/edge/community && \
	rm -rf /var/cache/apk/*

COPY /phpmyadmin.sql /
COPY /wp_db.sql /
COPY /telegraf.conf /etc/telegraf/telegraf.conf

COPY  mariadb-server.cnf  /etc/my.cnf.d
# datadir It is the directory where your database files are stored.
COPY start.sh /start.sh
RUN chmod +x start.sh

EXPOSE 3306

CMD ["sh", "start.sh"]