# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 13:43:22 by mcauchy-          #+#    #+#              #
#    Updated: 2025/01/29 16:39:37 by mcauchy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

SRCS_FILES	=	pipex.c utils.c ft_error.c 

SRC_DIR		=	srcs

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRCS_FILES))

OBJS		=	$(addprefix $(SRC_DIR)/, $(SRCS_FILES:.c=.o))

LIB_DIR		=	libft

HEADER		=	-I include/pipex.h

CC			=	gcc

RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror

PURPLE		=	\033[1;35m

GREEN		=	\033[1;32m

RED			=	\033[1;31m

RESET		=	\033[0m

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIB_DIR)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIB_DIR) -lft
			@ echo "$(GREEN)Compilation done !$(RESET)"

%.o:		%.c $(HEADER)

clean:
			@make clean -C $(LIB_DIR)
			@$(RM) $(OBJS)
			@echo "$(RED)Objects deleted !$(RESET)"

fclean:		clean
			@make fclean -C $(LIB_DIR)
			@$(RM) $(NAME)
			@echo "$(PURPLE)Executable deleted !$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re