# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 22:57:02 by vgabovs           #+#    #+#              #
#    Updated: 2024/01/18 17:26:22 by vgabovs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC_DIR = src
OBJ_DIR = obj
SRC = $(wildcard src/*.c src/normal/*.c)
BONUS_SRC = $(wildcard src/*.c src/bonus/*.c)
OBJ	= $(SRC:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ = $(BONUS_SRC:%.c=$(OBJ_DIR)/%.o)
LIBFTDIR = ./inc/libft
LIBFTA = $(LIBFTDIR)/libftprintf.a
PIPEX_H = ./inc/pipex.h

CC = gcc
CCS = $(CC) -fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror -Iinc #-I$(LIBFTDIR) #-I$(MLX_DIR)

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
WARNING='\033[33m'
RED='\033[31m'

VALG = valgrind --leak-check=full #-s --show-leak-kinds=all --show-error-list=yes
AT = leaks -atExit --

USE_SANITIZER = 1

ifeq ($(USE_SANITIZER), 1)
	CCFLAGS = $(CCS)
else
	CCFLAGS = $(CC)
endif

define INTRO

'||''|.  '||' '||''|.  '||''''|  '||' '|'
 ||   ||  ||   ||   ||  ||  .      || |
 ||...|'  ||   ||...|'  ||''|       ||
 ||       ||   ||       ||         | ||
.||.     .||. .||.     .||.....| .|   ||.

endef
export INTRO


all: $(NAME)

$(NAME): $(OBJ) $(LIBFTA) $(SRC)
	@$(CCFLAGS) $(OBJ) $(LFLAGS) -g -o $@ $(LIBFTA)
	@echo $(GREEN)"     - Compiled -"$(NONE)
	@echo "$$INTRO"

$(OBJ_DIR)/%.o:%.c $(PIPEX_H) $(LIBFTA)
	@echo $(CURSIVE)$(GRAY) "    - Building $<" $(NONE)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/src
	@mkdir -p $(OBJ_DIR)/src/normal
	@mkdir -p $(OBJ_DIR)/src/bonus
	@if [ "$(USE_SANITIZER)" = "1" ]; then $(CCS) $(CFLAGS) -c $< -o $@ ; else $(CC) $(CFLAGS) -c $< -o $@ ; fi
#	@$(CC) $(CFLAGS) -c $< -o $@


$(LIBFTA):
	@make all -C $(LIBFTDIR)

bonus: $(BONUS_OBJ) $(LIBFTA) $(BONUS_SRC)
	@$(CCFLAGS) $(BONUS_OBJ) -g -o pipex $(LIBFTA)
	@echo $(GREEN)"     - Compiled with BONUS-"$(NONE)
	@echo "$$INTRO"

val: USE_SANITIZER = 0
val: fclean $(OBJ) $(LIBFTA) $(SRC)
	@$(CC) $(OBJ) $(LFLAGS) -o $(NAME) $(LIBFTA)
	$(VALG) ./$(NAME) deep.txt wc cat out
	@echo $(GREEN)"- Compiled with valgrind-"$(NONE)

at: USE_SANITIZER = 0
at: fclean $(OBJ) $(LIBFTA) $(SRC)
	@$(CC) $(OBJ) $(LFLAGS) -o $(NAME) $(LIBFTA)
	@$(AT) ./$(NAME) deep.txt wc cat out
	@echo $(GREEN)"- Compiled with atExit-"$(NONE)

clean:
	@make -C $(LIBFTDIR) clean
	@rm -rf $(OBJ_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Object files removed" $(NONE)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean
	@echo $(CURSIVE)$(GRAY) "     - $(NAME) removed" $(NONE)

re: fclean all

.PHONY: all bonus val at re clean fclean
