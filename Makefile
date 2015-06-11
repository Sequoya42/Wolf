#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/12 17:20:35 by rbaum             #+#    #+#              #
#    Updated: 2015/06/11 20:08:50 by rbaum            ###   ########.fr        #
#                                                                              #
#******************************************************************************#


.PHONY:			all, libft, clean, fclean, re

CC =			gcc

CFLAG =			-O0 -g -Wall -Wextra -Werror

NAME =			wolf

SRC_PATH =		./src/

OBJ_PATH =		./obj/

LIBFT_PATH =	./libft/

INC_PATH =		./inc/

SRC_NAME =		main.c 		get_map.c 	events.c 	raycast.c\
				short_func.c 			choose_map.c	draw.c\
				load_bmp.c 	texture.c\

# SDL_STUFF = 	./inc/SDL2.framework/SDL2

SDL_PATH = 		./SDL2/

LIBSDL_PATH_ROOT = 	./libSDL2/

LIBSDL_PATH = ./libSDL2/lib/

LIBSDL =		libSDL2.a

OBJ_NAME =		$(SRC_NAME:.c=.o)

LIBFT_NAME =	libft.a

INC_NAME =		wolf.h

SRC =			$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =			$(addprefix $(OBJ_PATH),$(OBJ_NAME))

LIBFT =			$(addprefix $(LIBFT_PATH),$(LIBFT_NAME))

INC =			$(addprefix $(INC_PATH),$(INC_NAME))

INCSDL = 		$(LIBSDL_PATH_ROOT)include/

INCLIBFT = 		$(LIBFT_PATH)inc

SDLBIN = 		$(addprefix $(LIBSDL_PATH),$(LIBSDL))

LIBSDL_FLAG = 	-L$(LIBSDL_PATH) -lSDL2

LIBFT_FLAG = 	-L$(LIBFT_PATH) -lft

all:			libft sdl $(NAME) 

$(NAME):		$(OBJ)
				@$(CC) $(LIBFT_FLAG) $(LIBSDL_FLAG) -o $@ $^
				@echo "Wolf initialised"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c $(INC)
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CFLAG) -I$(INC_PATH) -I$(INCLIBFT) -I $(INCSDL) -o $@ -c $<

libft:			$(LIBFT)

$(LIBFT):		$(LIBFT_PATH)
				@make -C $(LIBFT_PATH)

sdl:			$(SDLBIN)

$(SDLBIN): 		
				mkdir -p $(LIBSDL_PATH_ROOT)
				cd $(SDL_PATH) &&  ./configure --prefix=$(PWD)/$(LIBSDL_PATH_ROOT)
				make -C $(SDL_PATH)
				make install -C $(SDL_PATH)

clean:
				@make -C $(LIBFT_PATH) clean
				make -C $(SDL_PATH) clean
				@rm -f $(OBJ)

fclean:			
				@rm -f $(OBJ)
				@make -C $(LIBFT_PATH) fclean
				rm -rf $(LIBSDL_PATH_ROOT)
				@rm -f $(NAME)

re: 			fclean all
