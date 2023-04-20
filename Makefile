# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 13:45:17 by sbenes            #+#    #+#              #
#    Updated: 2023/04/20 12:44:02 by sbenes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), operations_push.c operations_rev_rotate.c operations_rotate.c operations_swap.c\
		sort_to10.c sort_crossroad.c sort_utils.c sort_utils2.c stacks_free.c stacks_init_num.c stacks_init_string.c\
		stacks_init_utils.c stacks_printing.c sort_radix_utils.c sort_radix.c push_swap.c)
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBFT_DIR = libft/
NAME = push_swap

.PHONY: all clean fclean re libft

all: libft $(NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
