EXEC = so_long
CC=clang
CFLAGS= -Wall -Werror -Wextra -g
LIBMLX_FLAGS = -ldl -lglfw -pthread -lm
SRCS = so_long.c val_maps.c utils.c val_way.c load_images.c utils_extra.c \
		move_character.c place_extras.c take_collec.c credits_screen.c
OBJS = $(SRCS:.c=.o)
LIB = ../LIBDEF
LIBE = $(LIB)/libdef.a
LIBMLX = ../MLX42/build
LIBMLXE = $(LIBMLX)/libmlx42.a

all: $(EXEC)

$(LIBE):
	make -C $(LIB)

$(LIBMLXE):
	make -C $(LIBMLX)

$(EXEC): $(OBJS) $(LIBE) $(LIBMLXE)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC) -L$(LIB) -ldef -L$(LIBMLX) -lmlx42 $(LIBMLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(EXEC)
	make -C $(LIB) fclean
	make -C $(LIBMLX) clean

clean:
	rm -f $(OBJS)
	make -C $(LIB) clean

re: fclean all

.PHONY: fclean clean re all
