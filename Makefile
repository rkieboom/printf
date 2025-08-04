NAME =	printf.a

CC := gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR =	src
INCDIR =	inc
OBJDIR =	obj

SRCS_PRINT_FILES := print_char.c print_string.c print_int.c\
		print_uint.c print_hex.c print_pointer.c print_percent.c

SRCS_FILES := ft_printf.c utils.c utils2.c utils3.c\
		ft_itoa.c ft_uitoa.c checkprint.c\
		checkprint2.c checkflags.c

SRCS_PRINT_FILES := $(addprefix ${SRCDIR}/, $(SRCS_PRINT_FILES))
SRCS_FILES := $(addprefix ${SRCDIR}/, $(SRCS_FILES))

SRCS := $(SRCS_FILES) $(SRCS_PRINT_FILES)
OBJS := $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	gcc $(CFLAGS) -c $< -o $@ -I$(INCDIR)


build-objects: $(OBJS)

print-objects:
	@echo "$(OBJS)"

clean:
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all build-objects print-objects clean fclean re