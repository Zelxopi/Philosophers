# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 17:07:45 by mtrembla          #+#    #+#              #
#    Updated: 2022/10/13 13:59:29 by mtrembla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

SRC = main.c \
	parsing.c \
	utils.c \
	actions.c \

OBJ = $(SRC:.c=.o)

SDIR = src
ODIR = obj
SFIX = $(addprefix $(SDIR)/, $(SRC))
OFIX = $(addprefix $(ODIR)/, $(OBJ))

CC = gcc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -fr

LIBFT = ./libft/libft.a

$(ODIR)/%.o: $(SDIR)/%.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[92m.\033[0m\c"

$(NAME): $(ODIR) $(OFIX)
	@$(MAKE) lib -C libft
	@$(CC) $(CFLAGS) $(OFIX) -o $(NAME) $(LIBFT)

$(ODIR):
	@mkdir -p $(ODIR)

all: $(NAME)

clean:
	@$(RM) $(OFIX) $(ODIR)
	@echo "🧹"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re