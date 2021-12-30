NAME 		:=	libftprintf.a
CC 			:=	gcc
HEADERFILES :=	libftprintf.h
SRCFILES 	:=	ft_printf.c \
				ft_conversation.c \
				ft_hex.c
SRCBONUS	:=	ft_bonus.c
OBJFILES 	:=	$(SRCFILES:%.c=%.o)
OBJBONUS	:=	$(SRCBONUS:%.c=%.o)
LDFLAGS 	?=
CFLAGS 		?=	-Wall -Wextra -Werror

MAKE		:=	make
LIBFT_PATH	:=	libft/
LIBFT_FILE	:=	libft.a
LIBFT_H		:=	libft.h

all: $(NAME)

$(NAME): makelibft $(OBJFILES)
	ar rc $(NAME) $(OBJFILES)
	ranlib $(NAME)

%.o: %.c $(HEADERFILES)
	$(CC) -c $(CFLAGS) -o $@ $<

bonus: $(OBJBONUS)
	ar rc $(NAME) $(OBJBONUS)
	ranlib $(NAME)

%.o: %.c $(HEADERFILES)
	$(CC) -c $(CFLAGS) -o $@ $<

makelibft:
	$(MAKE) -C $(LIBFT_PATH)

clean: cleanlibft
	rm -f $(OBJFILES) $(OBJBONUS)

cleanlibft:
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: fcleanlibft clean
	rm -f $(NAME)

fcleanlibft:
	$(MAKE) -C $(LIBFT_PATH) fclean

re: relibft fclean all

relibft:
	$(MAKE) -C $(LIBFT_PATH) re

norminette:
	norminette -R CheckForbiddenSourceHeader $(SRCFILES) $(SRCBONUS)

.PHONY: clean fclean re

#gcc -Wall -Werror -Wextra libftprintf.h ft_printf.c ft_conversation.c ft_hex.c libft/libft.h libft/ft_strlen.c libft/ft_strlcpy.c libft/ft_itoa.c libft/ft_strdup.c