# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 18:13:39 by vgabovs           #+#    #+#              #
#    Updated: 2023/12/06 13:25:35 by vgabovs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c itoa_base.c put_d.c helper.c put_hcsp.c put_ux.c flags_bonus.c

BONUS_SRC = flags_bonus.c

CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

B_OBJ = $(addprefix $(OBJ_DIR)/,$(BONUS_SRC:.c=.o))

CC = cc

LIBFT = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp ./libft/libft.a .
	@mv libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJ) $(B_OBJ)

bonus: all

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
	@make re -C $(LIBFT)
