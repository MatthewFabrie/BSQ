##
## EPITECH PROJECT, 2020
## Day10
## File description:
## Makefile
##

CC		= gcc
CFLAGS		= -W -Wall -Wextra
CPPFLAGS	= -I./include
LDFLAGS		= -L./ -lmy

SRC		= $(wildcard SRC/*.c)

OBJ		= $(SRC:.c=.o)

NAME		= bsq

all		: $(OBJ)
		$(MAKE) -C lib/my/ $@
		$(CC) -o $(NAME) $(SRC) $(LDFLAGS)

clean		:
		$(RM) $(OBJ)
		$(RM) $(NAME)
		$(RM) *~
		$(RM) /#*#/
		$(MAKE) -C lib/my $@

fclean		:	clean
		$(MAKE) -C lib/my $@

re		:	fclean all
