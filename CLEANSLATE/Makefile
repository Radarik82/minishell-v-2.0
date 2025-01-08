# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 15:21:33 by ariazano          #+#    #+#              #
#    Updated: 2024/02/07 14:37:12 by vgabovs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#VALGRIND		=	@valgrind --leak-check=full --show-leak-kinds=all \
#					--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

NAME			=	minishell
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -O3 -Isrc -I./readline -I./libft -g -fsanitize=address
LIBFT_FILE		=	$(LIBFT)/libft.a
LIBFT			=	./libft
MAKE			=	make
RM				=	rm -rf
SRC				= 	$(wildcard src/*.c src/token/*.c)
#					src/parse/parse.c \
#					src/parse/parse_utils1.c \
#					src/parse/parse_tree_utils1.c
OBJ_DIR			=	obj
SUBDIRS			=	src src/token
OBJ				=	$(SRC:%.c=$(OBJ_DIR)/%.o)
RL_CFLAGS		=	-I$(READLINE_PATH)/include/readline -L$(READLINE_PATH)/lib -lreadline -lhistory -ltermcap
READLINE_PATH	=	$(PWD)/readline
MINISHELL_H		=	src/minishell.h



all				: $(NAME)
$(NAME):		$(OBJ) $(LIBFT_FILE) $(SRC)
				@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_FILE) $(RL_CFLAGS)
				@echo "$(GREEN)$(NAME) MAKE'ed\n$(DEFAULT)"
$(LIBFT_FILE):
				@make all -C $(LIBFT)
				@echo "$(GREEN)libft completed\n$(END)"

$(OBJ_DIR)/%.o:%.c $(MINISHELL_H) $(LIBFT_FILE)
				@mkdir -p $(OBJ_DIR)
				$(foreach dir,$(SUBDIRS),$(shell mkdir -p $(OBJ_DIR)/$(dir)))
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				@make clean -C libft
				@$(RM) mandatory/libft.a
				@$(RM) $(OBJ_DIR)
				@echo "$(RED)Clean completed$(END)"
fclean: clean
				@echo ""
				@$(RM) $(NAME)
				@make fclean -C libft
				@echo "$(RED)Fclean completed$(END)"

re:				fclean all

.PHONY: all clean fclean re $(LIBFT)

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m
