*This document explains how to set up and work on the Inception project from scratch.*

---

## 1. Prepare the environment from scratch

### Install Docker

1. Update your system:
```bash
sudo apt update
sudo apt upgrade -y
```

2. Install Docker
```bash
sudo apt install -y docker.io
```

3. Enable and start Docker service
```bash
sudo systemctl enable docker
sudo systemctl start docker
```

### Install Docker Compose

1. On Debian Bookworm, Docker Compose comes as a separate package:
```bash
sudo apt update
sudo apt upgrade -y
```

2. docker-compose --version
```bash
sudo apt install -y docker.io
```

### Create .env and secrets
1. In the project root, create the .env file to store environment variables:

```bash
    touch .env
```
Example content:
DB_NAME=inception
DB_USER=wp_user
WP_TITLE="Inception Project"
DOMAIN_NAME=prosas-p.42.fr
WP_USER=author

2. Create the secrets/ folder for sensitive data:
```bash
    mkdir secrets
```
Files to include (all the text files, non empty):
db_root_password.txt
db_user_password.txt
wp_admin_usr.txt
wp_admin_pwd.txt
wp_admin_email.txt
wp_user_pwd.txt
wp_user_email.txt

---

## 3. Build and launch the project using the Makefile

### 1. Mount project
```bash
    make host
    make
```

### 2. Makefile useful commands
| Target        | Description                                                                                     |
| ------------- | ----------------------------------------------------------------------------------------------- |
| `make build`  | Builds all Docker images.                                                                       |
| `make up`     | Launches all containers in detached mode.                                                       |
| `make stop`   | Stops all running containers.                                                                   |
| `make start`  | Starts previously stopped containers.                                                           |
| `make down`   | Stops and removes containers.                                                                   |
| `make clean`  | Stops and removes containers, prunes Docker system (images, networks, dangling volumes).        |
| `make fclean` | Stops/removes containers, prunes system **including volumes**, clears `/home/<login>/data/...`. |
| `make re`     | Equivalent to `fclean` followed by `all` (rebuild everything).                                  |
| `make status` | Shows running containers, images, and volumes.                                                  |
| `make host`   | Updates `/etc/hosts` with your custom domain pointing to localhost.                             |

#### Additional docker commands:
```bash
docker logs <container>      # Check container logs
docker exec -it <container> bash  # Open a shell inside a container
docker system prune -af      # Remove unused images, containers, networks
docker volume ls             # List volumes
```

### 3. Persistent data location
All project data is stored on your host machine for persistence:
- /home/<login>/data/wordpress
- /home/<login>/data/mariadb
WordPress files and database contents remain intact even if containers are recreated.

### 4.Reseting or deleting volumes
To fully reset the proyect:
``` bash
make fclean
```
To remove only docker without volumenes
``` bash
make clean
```

### 5. Extra tips
- Nginx is the only entrypoint; the project runs exclusively on port 443 with TLSv1.2/1.3.

- Use make status frequently to verify that containers are running correctly.

- Do not use the latest Docker tag. Always specify versions or build images locally.
