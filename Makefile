# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 19:38:27 by rkaufman          #+#    #+#              #
#    Updated: 2022/01/19 09:14:28 by rkaufman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:=	libftprintf.a
CC 			:=	gcc
HEADERFILES :=	libftprintf.h \
				libftprintf_bonus.h

SRCFILES 	:=	ft_printf.c \
				ft_conversation0.c \
				ft_conversation1.c \
				ft_hex.c \
				ft_output.c

SRCBONUS	:=	ft_printf_bonus.c \
				ft_conversation0.c \
				ft_conversation1.c \
				ft_hex.c \
				ft_output_bonus.c \
				ft_init_flags_bonus.c \
				ft_read_flags_bonus.c \
				ft_apply_flags_bonus.c \
				ft_apply_precision_bonus.c \
				ft_additional_tools_bonus.c

OBJFILES 	:=	$(SRCFILES:%.c=%.o)
OBJBONUS	:=	$(SRCBONUS:%.c=%.o)

CFLAGS 		:=	-Wall -Wextra -Werror

LIBFT_PATH	:=	libft
LIBFT_FILE	:=	libft.a
LIBFT_H		:=	libft.h

#%.o: %.c
#	$(CC) -c $(CFLAGS) -o $@ $<

all: $(NAME)

$(NAME): makelibft $(OBJFILES)
	$(AR) rcs $(NAME) $(OBJFILES)

bonus: makelibft $(OBJBONUS)
	$(AR) rcs $(NAME) $(OBJBONUS) 

makelibft: 
	make -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/$(LIBFT_FILE) $(NAME)

clean: cleanlibft
	rm -f $(OBJFILES) $(OBJBONUS)

cleanlibft:
	make -C $(LIBFT_PATH) clean

fclean: fcleanlibft clean
	rm -f $(NAME)

fcleanlibft:
	make -C $(LIBFT_PATH) fclean

re: relibft fclean all

relibft:
	make -C $(LIBFT_PATH) re

norminette:
	norminette -R CheckForbiddenSourceHeader $(SRCFILES) $(SRCBONUS) $(HEADERFILES)
	make -C $(LIBFT_PATH) norminette

git:
	git add **/*

.PHONY: clean fclean re