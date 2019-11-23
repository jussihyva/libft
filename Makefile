# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 09:54:35 by jkauppi           #+#    #+#              #
#    Updated: 2019/11/23 15:21:17 by jkauppi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
MAIN_NAME	=	libft
LIB_FOLDER	=	./
LIB_SUFFIX	=	ft
LIB_NAME	=	lib$(LIB_SUFFIX).a
SRCS		=	./
INCLUDES	=	./
C_FLAGS		=	-Wall -Werror -Wextra
C_FUNCTIONS	=	ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove \
				ft_memchr ft_memcmp ft_strlen ft_strdup ft_strcpy \
				ft_strncpy ft_strcat ft_strncat ft_strlcat ft_strchr \
				ft_strrchr ft_strstr ft_strnstr ft_strcmp ft_strncmp \
				ft_atoi ft_isalpha ft_isdigit ft_isalnum  ft_isascii \
				ft_isprint ft_toupper ft_tolower ft_memalloc ft_memdel \
				ft_strnew ft_strdel ft_strclr ft_striter ft_striteri \
				ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub \
				ft_strjoin ft_strtrim ft_strsplit ft_itoa ft_putchar \
				ft_putstr ft_putnbr ft_putchar_fd ft_putendl ft_putstr_fd \
				ft_putendl_fd ft_putnbr_fd \
				ft_lstnew ft_lstdelone ft_lstdel \
				ft_lstadd ft_lstadd_e ft_lstiter ft_lstmap \
				ft_isupper ft_islower ft_isspace \
				ft_get_fd_buf ft_get_next_line

C_PATHS		=	$(addprefix $(SRCS), $(addsuffix .c, $(C_FUNCTIONS)))
OBJ_FILES	=						 $(addsuffix .o, $(C_FUNCTIONS))
DEB_FILES	=						 $(addsuffix .d, $(C_FUNCTIONS))
CC			=	gcc

all:$(NAME)
.PHONY: all

$(NAME): $(OBJ_FILES)
	@ar -rcs $(LIB_NAME) $?

$(OBJ_FILES):%.o:$(SRCS)%.c $(INCLUDES)/libft.h
	@$(CC) $(C_FLAGS) -c $<

clean:
	@\rm -f $(OBJ_FILES)
	@\rm -f $(DEB_FILES)
.PHONY: clean

fclean: clean
	@\rm -f $(LIB_NAME)

re: fclean all
