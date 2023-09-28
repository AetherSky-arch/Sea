CC=cc
CFLAGS=-Wall -Wextra -Werror -I.

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o rush03.o ft_putchar.o ft_atoi.o
	$(CC) -o rush03 main.o rush03.o ft_putchar.o ft_atoi.o

clean:
	rm *.o
fclean:
	rm *.o rush03
