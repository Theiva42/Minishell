# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjoseph <rjoseph@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 15:35:31 by rjoseph           #+#    #+#              #
#    Updated: 2025/01/10 17:02:58 by rjoseph          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = main.c ft_strcat.c initialize_struct.c tokenize.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -g -Wall -Werror -Wextra

# Default target
all: $(LIBFT) $(NAME)

# Build the main project
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Rule to build .o files from .c files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Clean object files in the main project
clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

# Clean everything including the library
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
