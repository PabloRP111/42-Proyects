CC = clang
CFLAGS = -Wall -Wextra -Werror -pthread
EXEC = philo
SRCS = philosophers.c val_args.c aux1.c thread.c aux2.c lonely_boy.c
OBJS = $(SRCS:.c=.o)

all: $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

fclean: clean
	rm -f $(EXEC)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: fclean clean re all

#-fsanitize=thread
# -fsanitize=address
#-g -O0 -pthread