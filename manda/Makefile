NAME = server
NAME2 = client
NAME3 = ./ft_printf/libftprintf.a

src1 = server.c
src2 = client.c checkarg.c

CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f

obj1 = $(src1:.c=.o)
obj2 = $(src2:.c=.o)

all: $(NAME) $(NAME2)

$(NAME): $(obj1) $(NAME3)
	@$(CC) $(CFLAGS) $(obj1) -o $@ $(NAME3)

$(NAME2): $(obj2) $(NAME3)
	@$(CC) $(CFLAGS) $(obj2) -o $@ $(NAME3)

$(NAME3):
	@cd ft_printf && make
	@echo "ft_printf ready"

%.o: %.c minitalk.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(obj1) $(obj2)
	@cd ft_printf && make clean

fclean: clean
	@$(RM) $(NAME) $(NAME2)
	@cd ft_printf && make fclean

re: fclean all

PHONY: clean

