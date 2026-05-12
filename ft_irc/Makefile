CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
EXEC = ircserv

SRCS = src/main.cpp src/commands.cpp src/aux1.cpp src/commands_admin.cpp \
		src/passive_commands.cpp 
OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: fclean clean re all