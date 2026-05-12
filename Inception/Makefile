COMPOSE = sudo docker-compose -f ./srcs/docker-compose.yml

all: up

build:
	@$(COMPOSE) build

up:
	@$(COMPOSE) up -d

down:
	@$(COMPOSE) down

stop:
	@$(COMPOSE) stop

start:
	@$(COMPOSE) start

status:
	@docker ps -a
	@docker images
	@docker volume ls

clean:
	@$(COMPOSE) down
	@docker system prune -af

fclean:
	@$(COMPOSE) down -v
	@docker system prune -af --volumes
	sudo rm -rf /home/prosas/data/wordpress/*
	sudo rm -rf /home/prosas/data/mariadb/*

re: fclean all

host:
	sudo sed -i 's|localhost|prosas-p.42.fr|g' /etc/hosts

.PHONY: all up build down stop start clean fclean status hosts re
