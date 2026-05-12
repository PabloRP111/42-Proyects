#!/bin/bash
set -e

# Variables y secrets
MYSQL_HOST=mariadb
MYSQL_DATABASE=${DB_NAME}
MYSQL_USER=${DB_USER}
MYSQL_PASSWORD=$(cat /run/secrets/db_user_password)
DOMAIN_NAME=${DOMAIN_NAME}
WP_TITLE=${WP_TITLE}
WP_ADMIN_USR=$(cat /run/secrets/wp_admin_usr)
WP_ADMIN_PWD=$(cat /run/secrets/wp_admin_pwd)
WP_ADMIN_EMAIL=$(cat /run/secrets/wp_admin_email)
WP_USER=${WP_USER}
WP_USER_PWD=$(cat /run/secrets/wp_user_pwd)
WP_USER_EMAIL=$(cat /run/secrets/wp_user_email)

# Esperar a que MariaDB esté disponible
until mysqladmin ping -h"$MYSQL_HOST" -u"$MYSQL_USER" -p"$MYSQL_PASSWORD" --silent; do
    echo "Esperando a que MariaDB esté disponible..."
    sleep 2
done

# Instalar WP-CLI si no existe
command -v wp >/dev/null 2>&1 || {
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp
}

# Instalar WordPress si no existe
if [ ! -f wp-config.php ]; then
    echo "Instalando WordPress..."
    wp core download --allow-root
    wp config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=$MYSQL_HOST --allow-root
    wp core install --url=$DOMAIN_NAME --title="$WP_TITLE" --admin_user=$WP_ADMIN_USR --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
fi

# Crear usuario adicional si no existe
if ! wp user get "$WP_USER" --allow-root &>/dev/null; then
    wp user create "$WP_USER" "$WP_USER_EMAIL" --role=author --user_pass="$WP_USER_PWD" --allow-root
fi

# Instalar tema y plugins
wp theme install astra --activate --allow-root
wp plugin install redis-cache --activate --allow-root
wp plugin update --all --allow-root

# Crear post "Inception Project" si no existe
if ! wp post list --post_type=post --fields=post_title --allow-root | grep -q "Inception Project"; then
    echo "Creando post 'Inception Project'..."
    wp post create \
      --post_title="Inception Project" \
      --post_content="<h2>“A dream within a dream.”</h2>
      <p>This WordPress site runs entirely inside Docker — the <strong>Inception</strong> project from 42 School.</p>
      <p>Like the movie, each container (Nginx, WordPress, MariaDB) is a dream within another dream.</p>
      <img src='https://upload.wikimedia.org/wikipedia/en/7/7f/Inception_ver3.jpg' alt='Inception movie poster' style='max-width:400px;border-radius:8px;' />
      <p><em>Welcome to your own dream within Docker.</em></p>" \
      --post_status=publish --allow-root
    echo "Post 'Inception Project' creado correctamente."
fi

# Preparar PHP-FPM
mkdir -p /run/php
PHP_VERSION=$(php -r 'echo PHP_MAJOR_VERSION.".".PHP_MINOR_VERSION;')
sed -i "s|listen = /run/php/php${PHP_VERSION}-fpm.sock|listen = 9000|g" /etc/php/${PHP_VERSION}/fpm/pool.d/www.conf

exec /usr/sbin/php-fpm${PHP_VERSION} -F

