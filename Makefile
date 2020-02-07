# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/08 13:46:11 by vkuikka           #+#    #+#              #
#    Updated: 2020/02/07 18:16:37 by vkuikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FILES = ft_printf.c floats.c putlong.c ft_putaddr.c printing.c length.c
OBJ = $(FILES:.c=.o)
LIBFT = libft/libft.a
INCLUDE = libft/includes
.PHONY: clean fclean re all

all: $(NAME)

$(NAME):
	make -C libft
	cp libft/libft.a $(NAME)
	gcc -c -Wall -Wextra -Werror $(FILES) -I $(INCLUDE)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

main:
	gcc -o test main.c libftprintf.a -I libft/includes

mainre:
	rm test
	gcc -o test main.c libftprintf.a -I libft/includes

real:
	gcc -o realtest real.c

realre:
	rm realtest
	gcc -o realtest real.c

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean
	make all
	make mainre
