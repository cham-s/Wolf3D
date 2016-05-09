NAME = wolf3d 
CC = clang
LIB = lib/libft/libft.a
FLAGS = -Wall -Werror -Wextra -Ofast 
LIBGRPH = -Llib -lSDL2
INCLUDES = -I include -I lib/libft/includes -I include/SDL2
OBJS = main.o
.PHONY: all clean fclean re

VPATH = source

all: $(NAME)

$(NAME): $(LIB) $(OBJS) 
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIB) -o $(NAME) $(LIBGRPH)

$(LIB):
	make -C lib/libft/

%.o : %.c
	$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C lib/libft/
	rm -f $(NAME)

re: fclean all
