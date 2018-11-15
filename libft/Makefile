# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarnett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/17 14:22:04 by abarnett          #+#    #+#              #
#    Updated: 2018/11/14 18:03:05 by abarnett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			libft.a

C_OBJS :=		$(patsubst %.c,%.o,$(wildcard ./srcs/*.c))
INCLUDE_DIR :=	./includes

CFLAGS +=		-Wall -Wextra -Werror -I$(INCLUDE_DIR)

.PHONY:			all clean fclean re

all: $(NAME)

$(NAME): $(C_OBJS)
	ar rc $(NAME) $(C_OBJS)
	ranlib $(NAME)

clean:
	@- $(RM) $(C_OBJS)

fclean: clean
	@- $(RM) $(NAME)

re: fclean all
