# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cattouma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 13:59:55 by cattouma          #+#    #+#              #
#    Updated: 2016/05/20 00:20:32 by cattouma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

CC = clang

AR = ar rc

OBJ = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o \
	ft_isascii.o ft_isdigit.o ft_isprint.o ft_memccpy.o \
	ft_memcpy.o ft_memmove.o ft_memset.o ft_putchar.o \
	ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o \
	ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strclr.o \
	ft_strcmp.o ft_strcpy.o ft_strdup.o ft_strlen.o \
	ft_strncmp.o ft_strncpy.o ft_strnstr.o ft_striteri.o \
	ft_strstr.o ft_tolower.o ft_toupper.o ft_strcat.o ft_strncat.o \
	ft_strlcat.o ft_memcmp.o ft_memchr.o ft_strchr.o ft_strrchr.o \
	ft_memalloc.o ft_memdel.o  ft_strnew.o ft_strdel.o ft_striter.o \
	ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o \
	ft_strsub.o ft_strjoin.o ft_strjoinfree.o ft_strnjoin.o ft_strsplit.o ft_itoa.o ft_strtrim.o \
	ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o \
	ft_lstmap.o ft_lstnewref.o ft_strsplitspc.o ft_strndup.o ft_memdup.o \
	ft_strlenchr.o ft_lstappend.o ft_lstprint.o  ft_lstlen.o ft_lstinsertafter.o \
 	ft_lstremove.o ft_swap.o ft_stronlyhas.o ft_size_to_allocate.o ft_splitspaces.o \
	ft_isspace.o ft_lstdelmem.o get_next_line.o ft_strjoinfree.o ft_tablen.o tab_len.o \
	tab_free.o

CFLAGS = -Wall -Wextra -Werror -I includes
.PHONY: all clean fclean re

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)
		@ranlib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ 

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
