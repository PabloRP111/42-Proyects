#!/bin/bash
set -e

# 1. Crear carpeta para SSL
SSL_DIR="/etc/nginx/ssl"
mkdir -p $SSL_DIR

# 2. Generar certificados autofirmados
if [ ! -f "$SSL_DIR/server.crt" ] || [ ! -f "$SSL_DIR/server.key" ]; then
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -keyout "$SSL_DIR/server.key" \
        -out "$SSL_DIR/server.crt" \
        -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=Inception/CN=prosas-p.42.fr/UID=prosas-p"
fi

# 3. Ajustar permisos
chmod 600 "$SSL_DIR/server.key"
chmod 644 "$SSL_DIR/server.crt"

chown -R www-data /var/www
chmod -R 777 /var/www

# 4. Verificar configuración antes de arrancar
nginx -t

# 5. Iniciar NGINX en primer plano (modo Docker-friendly)
exec nginx -g "daemon off;"
