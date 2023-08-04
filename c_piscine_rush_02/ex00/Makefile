# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cogata <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 22:25:14 by cogata            #+#    #+#              #
#    Updated: 2023/06/11 22:25:16 by cogata           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

SRC = ft_atoi.c ft_data.c ft_compare.c ft_look_for.c ft_str.c rush-02.c

all : ${NAME}

${NAME} :
	cc -Wall -Werror -Wextra -o ${NAME} ${SRC}

clean:
	rm -f *.o

fclean:
	rm -f ${NAME}

re: fclean all ${NAME}
