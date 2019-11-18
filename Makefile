# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 15:28:16 by gozsertt          #+#    #+#              #
#    Updated: 2019/11/18 20:09:02 by gozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

CC          =   gcc
CFLAGS      =   -Wall -Wextra -Werror -g #$(DEBUG_FLAGS)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

DEBUG_FLAGS =   -O0 -g                                                      \
                                                                            \
                -fsanitize=address                                          \
                -fsanitize=undefined                                        \
                -fsanitize=bounds                                           \
                -fsanitize=nullability-arg                                  \
                -fsanitize=nullability-return                               \
                -fsanitize=nullability-assign                               \
                -fsanitize=undefined                                        \
                -fsanitize-address-use-after-scope                          \
                # -fsanitize=integer                                        \
                # -fsanitize=object-size                                    \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

NAME        =   libft.a

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

OBJECTS			=   $(SOURCES:.c=.o)
BONUSOBJECTS	=	$(BONUS:.c=.o)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

HEADERS     =   libft.h                                                       \


SOURCES =	ft_atoi.c\
			ft_bzero.c\
			ft_count_elems.c\
			ft_is_white_space.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_lstfold.c\
			ft_memalloc.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memset.c\
			ft_calloc.c\
			ft_intlen.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_seglen.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_split.c\
			ft_strsplit_list.c\
			ft_strstr.c\
			ft_substr.c\
			ft_strtrim.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_strrev.c\
			ft_strpbrk.c\
			ft_lstfold.c\
			ft_strcspn.c\
			ft_gnl_lstdel.c\
			ft_gnl_lstpush.c\
			ft_get_next_line.c\
			ft_ischarset.c\
			ft_strndup.c\
			ft_strnlen.c\
			ft_strjoinfre.c\
			ft_strprepend.c\
			ft_strappend.c\
			ft_padding.c\
			ft_utoa_base.c\
			ft_valid_base.c\
			ft_uintmaxlen_base.c\

BONUS = 	ft_lstadd_front_bonus.c\
			ft_lstadd_back_bonus.c\
			ft_lstnew_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstmap_bonus.c\
# Main — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

all: $(NAME)

$(NAME): $(OBJECTS) bonus
	@ar -rcs $(NAME) $(OBJECTS)
	@echo && echo $(GREEN) "[√]     [Basic Library Successfully Compiled!]"
	@echo $(WHITE)

bonus: fclean $(BONUSOBJECTS)
	@ar -rcs $(NAME) $(BONUSOBJECTS)
	@echo && echo $(GREEN) "[√]     [Basic && Bonus Library Successfully Compiled!]"
	@echo $(WHITE)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling => " $<

# House Keeping — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

DEL = /bin/rm -rf

clean:
	@$(DEL) $(shell find . -name '*.o')

fclean: clean
	@$(DEL) $(NAME)

re: fclean all

# Text Colorization — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

GREEN = "\033[1;32m"
WHITE = "\033[1;37m"

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

.PHONY: all clean fclean re nc nh na