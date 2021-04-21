FROM alpine:3.12



EXPOSE 8086

RUN apk update && \
	apk add openrc influxdb && \
	apk add telegraf --repository http://dl-2.alpinelinux.org/alpine/edge/community && \
	rm -rf /var/cache/apk/*

COPY /telegraf.conf /etc/telegraf/telegraf.conf

COPY start.sh /start.sh
RUN chmod +x start.sh

CMD ["sh", "start.sh"]