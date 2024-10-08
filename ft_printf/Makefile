NAME =  libftprintf.a

INC = ft_printf.h

SRCS = ft_printf.c \
	ft_printf_ulti.c \
	ft_printf_ulti2.c

OBJS = ${SRCS:.c=.o}

LIBC = ar -rcs

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY : all clean fclean re