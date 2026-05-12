NAME = libftprintf.a
CC=cc
CFLAGS= -Wall -Werror -Wextra
SRCS = ft_printf.c ft_printvar.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
LIB = libft

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIB) bonus

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME)
	make -C $(LIB) fclean

clean:
	rm -f $(OBJS)
	make -C $(LIB) clean

re: fclean all

.PHONY: fclean clean re all LIB 