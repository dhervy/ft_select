# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhervy <dhervy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 12:17:01 by dhervy            #+#    #+#              #
#*   Updated: 2015/12/12 06:14:33 by dhervy           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = ft_select

CC = clang
CFLAG = -Wall -Werror -Wextra

CPATH = srcs/
CFILES = \
	main.c \
	count.c \
	init.c \
	print.c \
	cursor.c \
	keys.c \
	return.c \
	add.c \
	signal.c

OPATH = obj/
OFILES = $(CFILES:.c=.o)
OBJ = $(addprefix $(OPATH), $(OFILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling \"$(NAME)\"..."
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME) -lncurses
	@echo "Successful compilation!\n---"

$(OPATH)%.o: $(CPATH)%.c
	@mkdir -p $(OPATH)
	$(CC) $(CFLAGS) -I includes -c -o $@ $<

clean:
	@echo "Deleting the directory /obj..."
	make -C libft clean
	@rm -f $(OBJ)
	@echo "Deletion complete !"

fclean: clean
	@echo "Deleting binary "$(NAME)"..."
	make -C libft fclean
	@rm -f $(NAME)
	@echo "Deletion complete !"/

re: fclean all
