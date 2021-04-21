FROM alpine:3.12

RUN apk update && \
	apk add openrc libc6-compat influxdb && \
	apk add telegraf --repository http://dl-2.alpinelinux.org/alpine/edge/community && \
	rm -rf /var/cache/apk/*

RUN wget --no-check-certificate -q -o /dev/null https://dl.grafana.com/oss/release/grafana-7.4.5.linux-amd64.tar.gz && \
	tar -zxvf grafana-7.4.5.linux-amd64.tar.gz >/dev/null && \
	mv grafana-7.4.5 grafana && \
	rm grafana-7.4.5.linux-amd64.tar.gz

COPY start.sh .
COPY telegraf.conf /etc/telegraf/telegraf.conf
COPY grafana.db /grafana/data/grafana.db

EXPOSE 3000

CMD ["sh", "start.sh"]