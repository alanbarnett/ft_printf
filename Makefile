# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarnett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 22:40:12 by abarnett          #+#    #+#              #
#    Updated: 2018/12/14 18:57:27 by abarnett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			libftprintf.a

INCLUDE_DIR :=	./includes
L_OBJS :=		$(patsubst %.c,%.o,$(wildcard ./srcs/*.c))
C_OBJS :=		$(patsubst %.c,%.o,$(wildcard ./srcs/ft_printf/*.c))

CFLAGS +=		-Wall -Wextra -Werror -I$(INCLUDE_DIR)
LDFLAGS +=		-L./ -lftprintf

.PHONY:			all clean fclean re

all: $(NAME)

$(NAME): $(L_OBJS) $(C_OBJS)
	ar rc $(NAME) $(L_OBJS) $(C_OBJS)
	ranlib $(NAME)

test: all main.o
	$(CC) $(CFLAGS) main.o -o test $(LDFLAGS)

clean:
	@- $(RM) $(C_OBJS) $(L_OBJS) main.o

fclean: clean
	@- $(RM) $(NAME) test

re: fclean all
