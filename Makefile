# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 09:54:35 by jkauppi           #+#    #+#              #
#    Updated: 2021/07/08 10:49:34 by jkauppi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS				=	$(shell uname -s)

NAME		=	libft.a
LIB_SUFFIX	=	ft
A_NAME		=	lib$(LIB_SUFFIX).a
SO_NAME		=	lib$(LIB_SUFFIX).so

# Folders
LIB				=	.
OBJ				=	obj
OBJ_SO			=	obj_so
SRC				=	.
INCLUDE			=	.
FOLDERS			=	$(OBJ) $(OBJ_SO)
INCLUDES		=	-I $(INCLUDE)

# Compiler and linking parameters
CC				=	clang
C_FLAGS			=	-fPIE -std=gnu17 -g -Wall -Wextra -Werror $(INCLUDES)

# C (Source code) and H (Header) files
TARGET_NAME		=	../$(NAME)
SRC_C_FILES		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
					ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
					ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
					ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
					ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
					ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
					ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
					ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
					ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
					ft_putstr.c ft_putnbr.c ft_putchar_fd.c ft_putendl.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c \
					ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
					ft_lstadd.c ft_lstadd_e.c ft_lstiter.c ft_lstmap.c \
					ft_isupper.c ft_islower.c ft_isspace.c \
					ft_get_fd_buf.c ft_get_next_line.c \
					ft_step_args.c ft_abs.c

SRC_H_FILES		=	libft.h

# Path folders for H, C, O and APP files
H_FILES			=	$(addprefix $(INCLUDE)/, $(SRC_H_FILES))
C_FILES			=	$(addprefix $(SRC)/, $(SRC_C_FILES))
O_FILES			=	$(addprefix $(OBJ)/, $(patsubst %.c, %.o, $(SRC_C_FILES)))
SO_FILES		=	$(addprefix $(OBJ_SO)/, $(patsubst %.c, %.o, $(SRC_C_FILES)))

# Colours for printouts
RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
END				=	\033[0m

.PHONY: all
all: $(TARGET_NAME)
	@echo "$(GREEN)Done!$(END)"

$(TARGET_NAME): ../%: % $(FOLDERS) $(O_FILES)
	cp $< $@

$(O_FILES): $(OBJ)/%.o: $(SRC)/%.c $(H_FILES) Makefile
	$(CC) -c -o $@ $< $(C_FLAGS)
	ar -rcs $(NAME) $@

.PHONY: so
so: $(SO_FILES)
	$(CC) -shared -fPIC -o $(SO_NAME) $(SO_FILES)

$(SO_FILES): $(OBJ_SO)/%.o: $(SRC)/%.c $(H_FILES) Makefile
	$(CC) -fPIC -c -o $@ $< $(C_FLAGS)

$(FOLDERS):
	mkdir $@

.PHONY: clean
clean:
	rm -f $(O_FILES)
	rm -f $(SO_FILES)

.PHONY: fclean
fclean: clean
	rm -f $(A_NAME)
	rm -f $(SO_NAME)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: all

.PHONY: norm
norm:
ifeq ($(OS), Darwin)
	norminette-beta $(SRC)/* $(INCLUDE)/*
else
	norminette $(SRC)/* $(INCLUDE)/*
endif
