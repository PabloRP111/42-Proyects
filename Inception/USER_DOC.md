*This project has been created as part of the 42 curriculum by prosas-p.*

# Description
This project uses three services: NGINX, MariaDB, and WordPress. The goal is to deploy a WordPress website accessible at https://prosas-p.42.fr. Each service runs in its own Docker container.

# Instructions
From the project root directory, run the following commands:

- `make host` to configure the /etc/hosts file.  
- `make` to build the images and start the full stack.

Other useful commands:

- `make build` builds the images without starting the containers.  
- `make up` starts the containers.  
- `make stop` stops all running containers.  
- `make down` stops and removes containers.  
- `make clean` removes containers and unused Docker data.  
- `make fclean` removes containers and volumes.  
- `make status` shows containers, images, and volumes.

# Accessing the website
Once the services are running, open the URL https://prosas-p.42.fr.  
Accept the browser warning if necessary.  
To access the WordPress admin panel, append `/wp-admin` to the URL.

# Secrets directory
The `secrets` directory is not included in the repository. You must create it manually in the project root. It must contain the following files:

- db_root_password.txt  
- db_user_password.txt  
- wp_admin_usr.txt  
- wp_admin_pwd.txt  
- wp_admin_email.txt  
- wp_user_pwd.txt  
- wp_user_email.txt  

Each file must contain one value and must not be empty.

# Verifying the stack
To check if everything is running correctly, use `make status`.  
You can also inspect logs with `docker logs wordpress`, `docker logs mariadb`, and `docker logs nginx`.  
Another way to verify everything works is by logging into WordPress and creating a new post.

# Notes
No credentials must appear in the repository. Docker secrets are required for handling sensitive information.
