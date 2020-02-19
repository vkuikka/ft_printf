# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/08 13:46:11 by vkuikka           #+#    #+#              #
#    Updated: 2020/02/12 20:34:42 by vkuikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FILES = ft_printf.c floats.c printing.c output_num_char.c output_hex_octal_ptr.c length.c input.c
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

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean
	make all
