# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzimaeva <rzimaeva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/10 18:15:42 by rzimaeva          #+#    #+#              #
#    Updated: 2026/01/10 19:02:46 by rzimaeva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER   = server
NAME_CLIENT   = client

CC            = gcc
CFLAGS        = -Wall -Wextra -Werror

SRC_SERVER    = server.c
SRC_CLIENT    = client.c

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

all : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SRC_SERVER)
	@make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(SRC_SERVER) $(FT_PRINTF_LIB) -I$(FT_PRINTF_DIR) -o $(NAME_SERVER)

$(NAME_CLIENT): $(SRC_CLIENT)
	@make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(FT_PRINTF_LIB) -I$(FT_PRINTF_DIR) -o $(NAME_CLIENT)

clean:
	@make clean -C $(FT_PRINTF_DIR)

fclean: clean
	@make fclean -C $(FT_PRINTF_DIR)
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re