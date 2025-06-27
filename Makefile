NAME =	printf.a

CFLAGS = -Wall -Wextra -Werror

SRCDIR =	srcs
INCDIR =	includes
OBJDIR =	objs

SRCS_PRINT_FILES := printchar.c\
		printhex.c printhex2.c printhex3.c\
		printint.c printint2.c printint3.c\
		printint4.c printpnter.c printprocent.c\
		printstring.c printstring2.c printstring3.c\
		printuint.c printuint2.c printuint3.c

SRCS_FILES := ft_printf.c utils.c utils2.c utils3.c\
		ft_itoa.c ft_uitoa.c checkprint.c\
		checkprint2.c checkflags.c

SRCS_PRINT_FILES := $(addprefix ${SRCDIR}print/, $(SRCS_PRINT_FILES))
SRCS_FILES := $(addprefix ${SRCDIR}/, $(SRCS_FILES))

SRCS := $(SRCS_FILES) $(SRCS_PRINT_FILES)
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	gcc $(CFLAGS) -c $< -o $@ -I$(INCDIR)

$(OBJDIR)/%.o: $(SRCDIR)/print/%.c
	@mkdir -p $(OBJDIR)
	gcc $(CFLAGS) -c $< -o $@ -I$(INCDIR)

objects:
	@echo "${OBJS}"

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re objects