#!/bin/bash
set -e

# Leer secrets
MYSQL_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
MYSQL_DATABASE=${DB_NAME}
MYSQL_USER=${DB_USER}
MYSQL_PASSWORD=$(cat /run/secrets/db_user_password)

# Función para ejecutar comandos MySQL como root
run_mysql_root() {
    mysql -u root -p"$MYSQL_ROOT_PASSWORD" -e "$1"
}

# Inicializa MariaDB solo si no existe
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Primer arranque: inicializando MariaDB..."
    mysqld --initialize-insecure --user=mysql

    # Arranca MariaDB temporalmente
    mysqld_safe --skip-networking &
    until mysqladmin ping --silent; do
        sleep 1
    done

    # Crear root y usuario WordPress
    mysql -u root <<-EOSQL
        ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
        CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
        CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
        GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
        FLUSH PRIVILEGES;
EOSQL

    # Apagar MariaDB temporal
    mysqladmin -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown
else
    echo "Base de datos ya inicializada. Verificando usuario WordPress..."

    # Arranca MariaDB temporalmente
    mysqld_safe --skip-networking &
    until mysqladmin ping -u root -p"$MYSQL_ROOT_PASSWORD" --silent; do
        sleep 1
    done

    # Asegurarse de que root y usuario WordPress existen y tienen permisos correctos
    run_mysql_root "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"
    run_mysql_root "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;"
    run_mysql_root "CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
    run_mysql_root "GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';"
    run_mysql_root "FLUSH PRIVILEGES;"

    # Apagar MariaDB temporal
    mysqladmin -u root -p"$MYSQL_ROOT_PASSWORD" shutdown
fi

# Arrancar MariaDB en primer plano (modo Docker)
exec mysqld_safe

