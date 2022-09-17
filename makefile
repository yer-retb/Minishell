# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enja <enja@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 00:40:44 by yer-retb          #+#    #+#              #
#    Updated: 2022/09/17 01:55:24 by enja             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = CC

CFLAG = -Wall -Werror -Wextra -lreadline 

SRS = lexer/lexer.c main.c lexer/token.c get_prompt.c \
	libft/ft_memmove.c libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c \
	libft/ft_isprint.c libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_toupper.c \
	libft/ft_tolower.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_atoi.c \
	libft/ft_strnstr.c libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c \
	libft/ft_split.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_striteri.c \
	libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c

all : $(NAME)

$(NAME) : $(SRS)
	@$(CC) $(CFLAG) $(SRS) -o $(NAME)
	@echo "\033[42mMinishell Is Ready"

fclean : 
	@rm $(NAME)
	@echo "\033[41mCleaning Minishell"

clean : 
	@rm $(NAME)
	@echo "\033[41mCleaning Minishell"
	
re : fclean all