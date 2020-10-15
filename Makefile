
## Created by cayako

NAME = libftprintf.a
NAMETEST = ft_printf
CC = gcc
CFLAGS = ##-Wall -Wextra -Werror -g

SRCDIR  = ./src/
INCDIR  = ./inc/
OBJDIR  = ./obj/
FTDIR   = ./libft/

SRC = main.c ft_printf.c ft_parsing.c ft_putarg.c ft_pf_utils.c ft_put_digit.c \
		ft_put_src.c ft_put_oxup.c ft_put_f.c
OBJ	= $(addprefix $(OBJDIR),$(SRC:.c=.o))
LIBFT = $(FTDIR)libft.a

.PHONY: all clean fclean count

all: obj $(LIBFT) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -I $(FTDIR) -o $@ -c $<

$(LIBFT):
	make -C $(FTDIR)

$(NAME): $(LIBFT) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
## 	$(CC) -c $(OBJ) $(LIBFT)

test:
	$(CC) $(NAME) $(LIBFT) -o $(NAMETEST)

count:
	wc ./src/*.c ./inc/*.h

clean:
	rm -f $(OBJDIR)*.o
	make -C $(FTDIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAMETEST)
	make -C $(FTDIR) fclean

re: fclean all
