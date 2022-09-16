# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 00:40:44 by yer-retb          #+#    #+#              #
#    Updated: 2022/09/16 08:43:49 by yer-retb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = CC

CFLAG = -Wall -Werror -Wextra

SRS = lexer/lexer.c main.c lexer/token.c\
	Libft/ft_memmove.c Libft/ft_isalpha.c Libft/ft_isdigit.c Libft/ft_isalnum.c Libft/ft_isascii.c \
	Libft/ft_isprint.c Libft/ft_strlen.c Libft/ft_memset.c Libft/ft_bzero.c Libft/ft_memcpy.c Libft/ft_toupper.c \
	Libft/ft_tolower.c Libft/ft_strlcpy.c Libft/ft_strlcat.c Libft/ft_strchr.c Libft/ft_strrchr.c Libft/ft_atoi.c \
	Libft/ft_strnstr.c Libft/ft_strncmp.c Libft/ft_memchr.c Libft/ft_memcmp.c Libft/ft_calloc.c Libft/ft_strdup.c Libft/ft_substr.c \
	Libft/ft_split.c Libft/ft_strjoin.c Libft/ft_strtrim.c Libft/ft_itoa.c Libft/ft_strmapi.c Libft/ft_striteri.c \
	Libft/ft_putchar_fd.c Libft/ft_putstr_fd.c Libft/ft_putendl_fd.c Libft/ft_putnbr_fd.c

all : $(NAME)

$(NAME) : $(SRS)
	@$(CC) $(CFLAG) $(SRS) -o $(NAME)
	@echo "\033[42mMinishell Is Ready"

clean : 
	@rm $(NAME)
	@echo "\033[41mCleaning Minishell"

fclean : clean
	
re : fclean all