NAME = libftprintf.a

CFLAGS =  -Wall -Werror -Wextra

SRC = ft_printf.c \
ft_char.c \
ft_string.c \
ft_int.c \
ft_unsigned.c \
ft_adress.c \
ft_hexa.c \
ft_len.c \
ft_putnbr.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

# run: $(NAME) main.c
# 	 cc $(CFLAGS) main.c -L. -lftprintf
# 	./a.out

clean:
	-rm -f *.o 

fclean:
	-rm -f *.o 
	-rm -f *.a 

re: clean all 

