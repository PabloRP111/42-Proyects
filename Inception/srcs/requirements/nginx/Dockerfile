FROM debian:bookworm

RUN apt -y update && apt install -y nginx && apt install openssl -y

RUN rm -f /etc/nginx/conf.d/default.conf

COPY ./conf/default.conf /etc/nginx/conf.d/default.conf

COPY ./tools/script.sh /tools/script.sh

RUN chmod +x /tools/script.sh

CMD ["/tools/script.sh"]
