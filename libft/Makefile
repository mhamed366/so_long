# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 13:51:51 by mkchikec          #+#    #+#              #
#    Updated: 2021/11/16 01:04:49 by mkchikec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC =	./ft_atoi.c \
./ft_bzero.c \
./ft_calloc.c \
./ft_isalnum.c \
./ft_isalpha.c \
./ft_isascii.c \
./ft_isdigit.c \
./ft_isprint.c \
./ft_itoa.c \
./ft_memccpy.c \
./ft_memchr.c \
./ft_memcmp.c \
./ft_memcpy.c \
./ft_memmove.c \
./ft_memset.c \
./ft_putchar_fd.c \
./ft_putendl_fd.c \
./ft_putnbr_fd.c \
./ft_putstr_fd.c \
./ft_split.c \
./ft_strchr.c \
./ft_strcpy.c \
./ft_strdup.c \
./ft_strjoin.c \
./ft_strlcat.c \
./ft_strlcpy.c \
./ft_strlen.c \
./ft_strmapi.c \
./ft_strncmp.c \
./ft_strnstr.c \
./ft_strrchr.c \
./ft_strtrim.c \
./ft_substr.c \
./ft_tolower.c \
./ft_toupper.c

OBJS = $(SRC:.c=.o)

SRC_BONUS = ./ft_lstadd_back_bonus.c \
./ft_lstadd_front_bonus.c \
./ft_lstclear_bonus.c \
./ft_lstdelone_bonus.c \
./ft_lstiter_bonus.c \
./ft_lstlast_bonus.c \
./ft_lstnew_bonus.c \
./ft_lstsize_bonus.c \
./ft_lstmap_bonus.c

OBJS_BONUS = $(SRC_BONUS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	gcc -Wall -Werror -Wextra -c $(SRC) -I ./libft.h
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean bonus_clean
	rm -rf $(NAME)

bonus : $(OBJS_BONUS)
	gcc -Wall -Werror -Wextra -c $(SRC_BONUS) -I ./libft.h
	ar rc $(NAME) $(OBJS_BONUS)
	ranlib $(NAME)

bonus_clean:
	rm -rf $(OBJS_BONUS)

re : fclean all
