NAME		:=	libftprintf.a
CC			:=	gcc
HEADERFILES :=	libftprintf.h 
				#libftprintf_bonus.h
SRCFILES 	:=	ft_printf.c \
				ft_conversation0.c \
				ft_conversation1.c \
				ft_hex.c \
				ft_output.c
				
SRCBONUS	:=	ft_printf_bonus.c \
				ft_read_flags_bonus.c \
				ft_conversation0.c \
				ft_conversation1.c \
				ft_apply_flags_bonus.c \
				ft_hex.c \
				ft_output.c

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
	ar rcs $(NAME) $(OBJFILES)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

bonus: makelibft $(OBJBONUS)
	ar rcs $(NAME) $(OBJBONUS)

%.o: %.c
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