mkdir ~/mkcert && \
 cd ~/mkcert && \
 wget --no-check-certificate -q -o /dev/null https://github.com/FiloSottile/mkcert/releases/download/v1.1.2/mkcert-v1.1.2-linux-amd64 && \
 mv mkcert-v1.1.2-linux-amd64 mkcert && \
 chmod +x mkcert
./mkcert -install 2>/dev/null
./mkcert localhost 2>/dev/null
cd /var/www/
wget --no-check-certificate -q -o /dev/null https://fr.wordpress.org/latest-es_ES.tar.gz
tar xzvf latest-es_ES.tar.gz  >/dev/null
rm latest-es_ES.tar.gz
