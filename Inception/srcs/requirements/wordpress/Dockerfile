FROM debian:bookworm

# 1. Instalar dependencias
RUN apt update -y && apt install -y \
    lsb-release apt-transport-https ca-certificates curl gnupg \
    php8.2-fpm php8.2-mysql mariadb-client wget unzip \
    less tar

# 2. Instalar WP-CLI
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

# 3. Directorio de trabajo
WORKDIR /var/www/html

# 4. Copiar scripts
COPY tools/script.sh /tools/script.sh
RUN chmod +x /tools/script.sh

# 5. CMD
CMD ["/tools/script.sh"]

