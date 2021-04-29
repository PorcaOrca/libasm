# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 12:37:36 by lodovico          #+#    #+#              #
#    Updated: 2021/04/29 13:19:33 by lodovico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# to make it work for mac os change flags from elf to macho and add underscore in the sources definition of the function

SRCS	=	./srcs/ft_strlen.s\
			./srcs/ft_strcmp.s\
			./srcs/ft_strcpy.s\
			./srcs/ft_write.s\
			./srcs/ft_read.s\
			./srcs/ft_strdup.s

NA		=	nasm

OBJCS	=	$(SRCS:.s=.o)

FLAGS	=	-f elf64

NAME	=	libasm.a

%.o		:	%.s
			@$(NA) $(FLAGS) $<

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

test	:	re delete
			@echo "\033[0;33mCompiling test program..."
			@gcc ./main.c $(NAME) -o test
			@echo "\033[0m"
			@echo "\033[0;33mRUNNIG TEST PROGRAM"
			@echo "\033[0m"
			@./test
			@chmod 775 it_s_my_file this_is_the_file

delete	:
			@rm -rf this_is_the_file it_s_my_file
			
.PHONY	:	all clean fclean re test delete