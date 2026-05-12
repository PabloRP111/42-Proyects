EXEC = cub3d
CC=clang
CFLAGS= -g -Wall -Werror -Wextra -Wunreachable-code -Ofast
LIBMLX_FLAGS = -ldl -lglfw -pthread -lm
SRCS = source/cub3d.c source/parsing.c source/parsing_map.c source/draw_img.c \
	source/parsing_map2.c source/parsing_map3.c source/draw_img2.c \
	source/utils.c source/erros_and_frees.c source/cam.c source/ray_casting.c
OBJS = $(SRCS:.c=.o)
LIB = ./Libft
LIBE = $(LIB)/libdef.a
LIBMLX = MLX42/build
LIBMLXE = $(LIBMLX)/libmlx42.a

all: $(EXEC) $(LIBMLXE) $(LIBE)

$(LIBE):
	make -C $(LIB)

$(LIBMLXE):
	make -C $(LIBMLX)

$(EXEC): $(OBJS) $(LIBE) $(LIBMLXE)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC) -L$(LIB) -lft -L$(LIBMLX) -lmlx42 $(LIBMLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(EXEC)
	make -C $(LIB) fclean

clean:
	rm -f $(OBJS)
	make -C $(LIB) clean

re: fclean all

.PHONY: fclean clean re all libmlx42 libdef
