NAME = wolf3d 
CC = clang
LIB = libft/libft.a
FLAGS = -Wall -Werror -Wextra -Ofast 
LIBGRPH = -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit \
		  -D_REENTRANT -lpthread
INCLUDES = -I includes -I libft/includes -I minilibx_macos
INC	= includes/fractol.h
OBJS = main.o parsing.o draw.o init.o fractals.o handler.o init_fractals.o \
	   worker.o event.o event2.o
.PHONY: all clean fclean re

VPATH = sources/:minilibx_macos

all: $(NAME)

$(NAME): $(LIB) $(OBJS) 
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIB) -o $(NAME) $(LIBGRPH)

$(LIB):
	make -C libft/
	make -C minilibx_macos

%.o : %.c $(INC)
	$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	make clean -C minilibx_macos
	rm -f $(NAME)
	rm -rf $(NAME).dsym

re: fclean all
