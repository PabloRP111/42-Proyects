# Description
*This project has been created as part of the 42 curriculum by <tu_login>.*

**Inception** is a Docker project that deploys a WordPress website using three services, each running in its own container:

- **MariaDB** for the database
- **Nginx** as the web server
- **WordPress** as the website application

### Main Design Choices

- **Docker vs Virtual Machines**: Docker is used instead of full VMs for lightweight, fast deployment and isolated services.
- **Secrets vs Environment Variables**: Sensitive information (passwords, API keys) is stored as Docker secrets, while general configuration uses environment variables.
- **Docker Network vs Host Network**: A custom bridge network isolates containers; host network is avoided for security.
- **Docker Volumes vs Bind Mounts**: Persistent data is stored in Docker volumes to ensure container independence, while bind mounts are used carefully for local development.

# Instructions
To launch the project, run the following commands from the project directory:

- `make`  
  Builds and starts the entire stack. Once it is running, you can access the WordPress site at **https://prosas-p.42.fr**.

- `make build`  
  Builds all Docker images.

- `make up`  
  Starts all containers.

- `make stop`  
  Stops all containers.

- `make down`  
  Stops and removes all containers.

- `make start`  
  Starts containers that were previously stopped with `make stop`.

- `make clean`  
  Stops and removes containers, keeping volumes.

- `make fclean`  
  Stops and removes containers and volumes, and deletes all persistent data.

- `make host`  
  Updates your `/etc/hosts` file to map `prosas-p.42.fr` to your local machine.

In practice, you only need to run `make host` once and then use `make` to launch the project.

# Resources
- My friend Andrés (actual human)
- GPT for assistance  
  AI was used for debugging Docker issues, exploring documentation, and generating initial drafts for documentation files.

