# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rkieboom <rkieboom@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/27 17:40:05 by rkieboom       #+#    #+#                 #
#    Updated: 2020/01/30 16:46:47 by rkieboom      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRC =	ft_printf.c srcs/utils.c srcs/utils2.c srcs/utils3.c\
		srcs/ft_itoa.c srcs/ft_uitoa.c srcs/checkprint.c\
		srcs/checkprint2.c srcs/checkflags.c print/printchar.c\
		print/printhex.c print/printhex2.c print/printhex3.c\
		print/printint.c print/printint2.c print/printint3.c\
		print/printint4.c print/printpnter.c print/printprocent.c\
		print/printstring.c print/printstring2.c print/printstring3.c\
		print/printuint.c print/printuint2.c print/printuint3.c

OFILES = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OFILES)
	ar rc $(NAME) $(OFILES)

%.o: %.c
	gcc $(CFLAGS) -c $? -o $@

bonus: $(NAME)

clean:
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
