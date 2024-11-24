NAME = libftprintf.a
LIBFT = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibc
EXE = a.out
SOURCES = flag_functions.c ft_printf.c f_putch.c f_putstr_count.c \
	putp.c savec.c savehex.c saveun.c\
	savestr.c \

OBJ = $(SOURCES:.c=.o)
LIBSRCS =	libc/ft_atoi.c \
	libc/ft_bzero.c \
	libc/ft_calloc.c \
	libc/ft_isalnum.c \
	libc/ft_isalpha.c \
	libc/ft_isascii.c \
	libc/ft_isdigit.c \
    libc/ft_isprint.c \
    libc/ft_itoa.c \
    libc/ft_memchr.c \
    libc/ft_memcmp.c \
    libc/ft_memcpy.c \
    libc/ft_memmove.c \
    libc/ft_memset.c \
    libc/ft_putchar_fd.c \
    libc/ft_putendl_fd.c \
    libc/ft_putnbr_fd.c \
	libc/ft_putstr_fd.c \
    libc/ft_split.c \
	libc/ft_strchr.c \
    libc/ft_strdup.c \
    libc/ft_striteri.c \
    libc/ft_strjoin.c \
    libc/ft_strlcat.c \
    libc/ft_strlcpy.c \
    libc/ft_strlen.c \
    libc/ft_strmapi.c \
    libc/ft_strncmp.c \
    libc/ft_strnstr.c \
    libc/ft_strrchr.c \
    libc/ft_strtrim.c \
    libc/ft_substr.c \
    libc/ft_tolower.c \
    libc/ft_toupper.c \
	libc/ft_lstnew_bonus.c \
	libc/ft_lstadd_front_bonus.c \
	libc/ft_lstadd_back_bonus.c \
    libc/ft_lstclear_bonus.c \
    libc/ft_lstdelone_bonus.c \
    libc/ft_lstiter_bonus.c \
    libc/ft_lstlast_bonus.c \
    libc/ft_lstmap_bonus.c \
    libc/ft_lstsize_bonus.c \

LIBOBJ = $(LIBSRCS:.c=.o)


TEST = test.out

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(LIBFT): $(LIBOBJ)
	ar -rcs $(LIBFT) $(LIBOBJ)

run: $(EXE)
	./a.out

test: $(TEST)
	./test.out

$(TEST): $(NAME) $(LIBFT) test.c
	$(CC) $(CFLAGS) test.c -L. -lftprintf -lft -o $(TEST)

$(EXE):	$(NAME) $(LIBFT)
	$(CC) $(CFLAGS) -L. -lftprintf -lft -o $(EXE)

bonus: $(NAME) $(LIBFT)

clean:
	$(RM) $(OBJ) $(LIBOBJ) 

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(TEST) $(EXE)

re: fclean all
