NAME		= wolf3d 
CC			= clang
LIBDIR		= lib
SDLIBDIR	= libsdl
expected	=" 	lib/libsdl/libSDL2-2.0.0.dylib (compatibility version 5.0.0, current version 5.0.0)"
out			:= "$(shell otool -L  $(NAME)| awk NR==2)"

OBJDIR		= obj
LIBSDL		= -L$(LIBDIR)/$(SDLIBDIR) -lSDL2
LIB 		:= lib/libft/libft.a
FLAGS 		:= -Wall -Werror -Wextra -O3 
LIBGRPH 	:= -framework OpenGL
INCLUDES 	:= -I include -I lib/libft/includes -I include/SDL2
SDLDYLIB	:= $(LIBDIR)/$(SDLIBDIR)/libSDL2-2.0.0.dylib
OBJS 		:= $(OBJDIR)/main.o \


.PHONY: all clean fclean re

VPATH = source

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(FLAGS) -rpath 'lib/libsdl/' $(LIB) $(LIBSDL) $(INCLUDES) $(OBJS)  -o $(NAME) $(LIBGRPH)
	@echo "Replacing /usr/local/lib with ./lib ..."
	install_name_tool -change /usr/local/lib/libSDL2-2.0.0.dylib $(SDLDYLIB) $(NAME)
ifeq ($(expected), $(out))
@echo "✓ The the new dynamic lib path is $(expected)"
else
@echo "✕ Error while trying to change dynamic lib path is still  $(out)"
endif


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
