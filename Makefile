NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
EXE = a.out
SOURCES = ft_put_p.c ft_putc.c ft_putnbr.c ft_printf.c ft_put_us_hex.c ft_putstr_fd.c

OBJ = $(SOURCES:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

run: $(EXE)
	./a.out

$(EXE):	$(NAME)
	cc $(CFLAGS) $(SOURCES) -o $(EXE)


clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
