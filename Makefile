# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 16:08:32 by pzaw              #+#    #+#              #
#    Updated: 2024/10/08 16:20:56 by pzaw             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = libft
LIBFT = ./libft/libft.a
FTPF_DIR = ft_printf
FTPF = ./ft_printf/libftprintf.a
RM = rm -rf
SRCS = main.c
SRC = $(addprefix ./src/,$(SRCS))
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(FTPF) $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(FTPF):
	@make -s -C $(FTPF_DIR)

$(NAME): $(LIBFT) $(FTPF) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(FTPF_DIR) -lftprintf

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBFT_DIR) -I$(FTPF_DIR)

clean:
	@$(RM) $(OBJ)
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(FTPF_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(FTPF_DIR) fclean

re: fclean all
