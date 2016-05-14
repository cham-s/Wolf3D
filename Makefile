NAME		= wolf3d 
CC			= clang
LIBDIR		= lib
SDLIBDIR	= libsdl
EXPECTED	=" 	lib/libsdl/libSDL2-2.0.0.dylib (compatibility version 5.0.0, current version 5.0.0)"
OUTPUT		:= "$(shell otool -L  $(NAME)| awk NR==2)"
INC			= include/wolf3d.h


OBJDIR		= obj
LIBSDL		= -L$(LIBDIR)/$(SDLIBDIR) -lSDL2
LIB 		:= lib/libft/libft.a
FLAGS 		:= -Wall -Werror -Wextra -O3 
LIBGRPH 	:= -framework OpenGL
INCLUDES 	:= -I include -I lib/libft/includes -I include/SDL2
SDLDYLIB	:= $(LIBDIR)/$(SDLIBDIR)/libSDL2-2.0.0.dylib
SDLIMG		:= $(LIBDIR)/$(SDLIBDIR)/SDL2_image
SDL2		:= $(LIBDIR)/$(SDLIBDIR)/SDL2
OBJS 		:=	$(OBJDIR)/main.o \
				$(OBJDIR)/init.o \
				$(OBJDIR)/init2.o \
				$(OBJDIR)/map.o \
				$(OBJDIR)/init_map.o \
				$(OBJDIR)/move_events.o \
				$(OBJDIR)/colors.o \

.PHONY: all clean fclean re

VPATH = source

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(FLAGS) $(LIB) $(LIBSDL) $(INCLUDES) $(OBJS)  -o $(NAME) $(LIBGRPH) $(SDLIMG)
	@install_name_tool -change /usr/local/lib/libSDL2-2.0.0.dylib $(SDLDYLIB) $(NAME)
	@install_name_tool -change @rpath/SDL2_image.framework/Versions/A/SDL2_image $(SDLIMG) $(NAME)
	@install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 $(SDLDYLIB) $(SDLIMG)

$(LIB):
	make -C lib/libft/

$(OBJDIR)/%.o : %.c $(INC)
	@mkdir -p $(OBJDIR) 
	$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJDIR) 

fclean: clean
	make fclean -C lib/libft/
	rm -f $(NAME)

re: fclean all
