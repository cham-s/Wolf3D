SDLDYL      = LD_LIBRARY_PATH=lib/libsdl/
export SDLDYL 
NAME		= wolf3d 
CC			= clang

OBJDIR		= obj
LIBSDL		= -Llib/libsdl -lSDL2
LIB 		:= lib/libft/libft.a
FLAGS 		:= -Wall -Werror -Wextra -O3 
LIBGRPH 	:= -framework OpenGL
INCLUDES 	:= -I include -I lib/libft/includes -I include/SDL2
OBJS 		:= $(OBJDIR)/main.o \

.PHONY: all clean fclean re

VPATH = source

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIB) $(LIBSDL) -o $(NAME) $(LIBGRPH)

$(LIB):
	make -C lib/libft/

$(OBJDIR)/%.o : %.c
	@mkdir -p $(OBJDIR) 
	$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@ 

clean:
	rm -rf $(OBJDIR) 

fclean: clean
	make fclean -C lib/libft/
	rm -f $(NAME)

re: fclean all
