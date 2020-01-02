# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcase <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 11:31:10 by tcase             #+#    #+#              #
#    Updated: 2019/11/12 20:41:21 by tcase            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NM				:=	ft_nm
OT				:=	ft_otool

CC				:=	gcc
FLAGS			:=	# -Wall -Werror -Wextra

NM_DIR			:=	./nm
OT_DIR			:=	./otool
LIB_DIR			:=	./libft
OBJ_DIR			:=	./obj
INC_PATH		:=	./includes

NM_SRC_FILES	:=	nm.c

OT_SRC_FILES	:=	otool.c

NM_HEAD 		:=	ft_nm.h
NM_INC			:=	$(INC_PATH)/nm.h
NM_SRC			:=	$(addprefix $(NM_DIR), $(NM_SRC_FILES))
NM_OBJ 			:=	$(addprefix $(OBJ_DIR)/, $(NM_SRC_FILES:.c=.o))

OT_HEAD			:=	ft_otool.h
OT_INC			:=	$(INC_PATH)/otool.h
OT_SRC			:=	$(addprefix $(OT_DIR), $(OT_SRC_FILES))
OT_OBJ 			:=	$(addprefix $(OBJ_DIR)/, $(OT_SRC_FILES:.c=.o))

INC 			:=	-I ./includes -I $(LIB_DIR)/includes

all:	$(NM) $(OT)

$(NM): 			$(NM_OBJ)
	@make -s -C $(LIB_DIR)
	@$(CC) $(NM_OBJ) $(FLAGS) $(LIB_DIR)/libft.a $(INC) -o $@ 

$(OT): 			$(OT_OBJ) 
	@make -s -C $(LIB_DIR)
	@$(CC) $(OT_OBJ) $(FLAGS) $(LIB_DIR)/libft.a $(INC) -o $@ 

$(OBJ_DIR)/%.o: 	$(NM_DIR)/%.c
	@mkdir -p obj
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@echo "\033[0m\033[36m$(notdir $<)\033[1m\033[34m OK\033[0m"

$(OBJ_DIR)/%.o: 	$(OT_DIR)/%.c
	@mkdir -p obj
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@echo "\033[0m\033[36m$(notdir $<)\033[1m\033[34m OK\033[0m"

clean:
	@make clean -s -C $(LIB_DIR)
	@rm -f $(OT_OBJ) $(NM_OBJ)

fclean: clean
	@make fclean -s -C $(LIB_DIR)
	@find . -type f -name ".*.swp" -exec rm -f {} \;
	@rm -rf *test*
	@rm -rf $(NM) $(OT)

re:	fclean all

.PHONY: all, clean, fclean, re
