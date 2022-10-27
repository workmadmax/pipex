# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 13:43:52 by mdouglas          #+#    #+#              #
#    Updated: 2022/10/26 15:27:16 by mdouglas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
MFLAG = ./ft/libft.a

CC = cc -g3
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf
OBJS = $(SRCS:.c=.o)

SRCS = checker.c create_process.c exec_command.c get_paths.c main.c utils.c

all: $(MFLAG) $(NAME)

$(MFLAG):
		make -C ./ft
		make -C ./ft_printf

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(MFLAG) -o $(NAME)

fclean: clean
		make fclean -C ./ft
		$(RM) $(NAME)

clean:
		make clean -C ./ft
		$(RM) $(OBJS)

re: fclean all

.PHONY : all fclean clean re

re: fclean all

.PHONY: all clean fclean re