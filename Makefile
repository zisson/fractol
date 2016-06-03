# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsina <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/29 03:15:19 by zsina             #+#    #+#              #
#    Updated: 2016/05/29 03:17:05 by zsina            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra -Werror

LIXDIR = minilibx_macos/libmlx.a -framework OpenGl -framework appkit

SRCDIR = src/

SRC = 	$(SRCDIR)fractol.c $(SRCDIR)parser.c $(SRCDIR)helper.c $(SRCDIR)init.c\
$(SRCDIR)event.c $(SRCDIR)algo.c

YELLOW	=	\033[1;33m
GREN	=	\033[32m
RED	=	\033[31m
BLACK	=	\033[1;30m
GREY	=	\033[1;37m

INC = inc

OBJ = $(SRC:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJ)
	@make -C minilibx_macos
	@echo "$(YELLOW) Creation du binaire $(NAME)..."
	@for i in {1..57}; do \
		sleep 0.0001; \
		echo "$(BLACK)-\c"; \
		done
	@echo ""
	@echo "$(GREN) [SUCCES]"
	@gcc $(FLAGS) $(LIXDIR) -o $(NAME) $(OBJ) -I $(INC) -I libftprintf -L libftprintf/ -lftprintf
%.o:%.c
	@echo "$(BLACK)-> Compilation du fichier $<..."
	@gcc $(FLAGS) -c -o $@ $< -I $(INC) -I libftprintf

lib:
	@echo "$(YELLOW)Compilation de la librairie"
	@for i in {1..57}; do \
		sleep 0.0001; \
		echo "$(BLACK)-\c"; \
		done
	@echo ""
	@make -C ./libftprintf

clean:
	@echo "$(RED) Suppression de tous les fichiers objets de" $(NAME)
	@for i in {1..57}; do \
		sleep 0.0001; \
		echo "$(BLACK)-\c"; \
		done
	@echo ""
	@echo "$(GREN) [SUCCES !!!]"
	@rm -f $(OBJ)
	@make clean -C ./libftprintf

fclean: clean
	@echo "$(RED) Suppression du binaire" $(NAME) "et des ~.o de la libft"
	@for i in {1..57}; do \
		sleep 0.0001; \
		echo "$(BLACK)-\c"; \
		done
	@rm -f $(NAME)
	@echo ""
	@make fclean -C ./libftprintf

help:
	@echo "$(GREN)			HELPER Makefile"
	@echo "$(RED)make:		$(GREY)Compiler le projet $(NAME)"
	@echo "$(RED)make re: 	$(GREY)Compiler a nouveau le projet $(NAME)"
	@echo "$(RED)fclean: 	$(GREY)Suppression de $(NAME) et ~.o de libft"
	@echo "$(RED)clean:	$(GREY)Suppression de ~.o du projet $(NAME)"

re:	fclean all

.PHONY: $(NAME) all lib clean fclean re
