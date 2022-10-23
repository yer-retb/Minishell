# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enja <enja@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 00:40:44 by yer-retb          #+#    #+#              #
#    Updated: 2022/10/23 12:58:00 by enja             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

CFLAG = -Wall -Wextra -Werror -lreadline -fsanitize=address -g

SRS = main/get_prompt.c parser/parser.c lexer/lexer.c main/main.c main/init_nodes.c lexer/token.c lexer/lexer_utils.c lexer/lexer_utils_ll.c \
	parser/expand_doller.c parser/parser_parse_tab2.c main/init_sh.c parser/test.c parser/test2.c\
	libft/ft_memmove.c libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c \
	libft/ft_isprint.c libft/ft_strlen.c libft/ft_memset.c libft/moded_strnstr.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_toupper.c \
	libft/ft_tolower.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_atoi.c parser/parser_exec_preparation.c \
	libft/ft_strnstr.c libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c \
	libft/ft_split.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_striteri.c libft/ft_strjoin_no_free.c \
	libft/ft_putchar_fd.c libft/ft_strcmp.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c main/error_msg.c parser/parser_parse_tab.c \
	builtins/builtins.c\

all : $(NAME)

$(NAME) : $(SRS)
	@$(CC) $(CFLAG) $(SRS) -o $(NAME)
	@echo "\033[42mMinishell Is Ready\033[0m"
	./minishell 

fclean : 
	@rm -rf $(NAME)
	@echo "\033[41mCleaning Minishell\033[0m"

clean : 
	@rm -rf $(NAME)
	@echo "\033[41mCleaning Minishell\033[0m"
	
re : fclean all ./minishell 

push : 
	rm -rf minishell.dSYM
	@git add .
	@git commit -m "builtins : cd and pwd"
	@git push -f
	