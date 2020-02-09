# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 15:28:16 by gozsertt          #+#    #+#              #
#    Updated: 2020/02/09 13:09:47 by gozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC =		gcc

SRC_DIR = 	$(shell find srcs -type d)
INC_DIR = 	$(shell find includes -type d)
# LIB_DIR =
OBJ_DIR = 	obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

# # List de toute les library a linker au projet (le nom - le lib et - le .a)

SRC = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))

OBJ2 = $(OBJ1:%.m=%.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

#Compilation flag
CFLAGS = -Wall -Wextra -Werror

IFLAGS = $(foreach dir, $(INC_DIR), -I$(dir))

LFLAGS = $(foreach dir, $(LIB_DIR), -L $(dir) ) $(foreach lib, $(LIB), -l $(lib) ) $(foreach framework, $(FRAMEWORK), -framework $(framework) )

# Colors

_GREY=	$'\x1b[30m
_RED=	$'\x1b[31m
_GREEN=	$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=	$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=	$'\x1b[36m
_WHITE=	$'\x1b[37m

all:
				@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
				@make $(NAME)

show:
				@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
				@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
				@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
				@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
				@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)$(_WHITE)"

$(OBJ_DIR)/%.o : %.c
				@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

$(OBJ_DIR)/%.o : %.m
				@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

$(NAME): 		$(OBJ) Makefile
				@echo "-----\nCreating library $(_YELLOW)$@$(_WHITE) ... \c"
				@ar -rc $(NAME) $(OBJ)
				@ranlib $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

norme:
				norminette $(SRC_DIR)

re:				fclean all

clean:
				@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
				@$(foreach file, $(OBJ), rm -rf $(file))
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean
				@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
				@rm -f $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all clean flcean re show