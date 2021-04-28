# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 12:37:36 by lodovico          #+#    #+#              #
#    Updated: 2021/04/28 11:04:06 by lodovico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# to make it work for mac os change flags from elf to macho and add underscore in the sources definition of the function

SRCS	=	./srcs/ft_strlen.s\
			./srcs/ft_strcmp.s

NA		=	nasm

OBJCS	=	$(SRCS:.s=.o)

FLAGS	=	-f elf64

NAME	=	libasm.a

%.o		:	%.s
			@echo "\033[0;33mCreating objects..."
			@$(NA) $(FLAGS) $<
			@echo "\033[0m"

all		:	$(NAME)

$(NAME)	:	$(OBJCS)
			@echo "\033[0;33mCreating library..."
			@ar rcs $(NAME) $(OBJCS)
			@ranlib $(NAME)
			@echo "\033[0m"

clean	:	
			@echo "\033[0;33mRemoving objects..."
			@rm -rf $(OBJCS)
			@echo "\033[0m"


fclean	:	clean
			@echo "\033[0;33mRemoving library..."
			@rm -rf $(NAME)
			@echo "\033[0m"

re		:	fclean $(NAME)

test	:	re
			@echo "\033[0;33mCompiling test program..."
			@gcc -Wall -Wextra -Werror ./main.c $(NAME) -o test
			@echo "\033[0m"
			@echo "\033[0;33mrunning test program"
			@echo "\033[0m"
			@./test
			@echo "\033[0m"
			
.PHONY	:	all clean fclean re