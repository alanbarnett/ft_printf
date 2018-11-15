# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarnett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 22:40:12 by abarnett          #+#    #+#              #
#    Updated: 2018/11/06 18:42:49 by abarnett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			libftprintf.a

SRC_DIR :=		srcs
INCLUDE_DIRS :=	./includes ./libft/includes
C_OBJS :=		$(patsubst %.c,%.o,$(wildcard ./$(SRC_DIR)/*.c))
L_OBJS :=		$(patsubst %.c,%.o,$(wildcard ./libft/$(SRC_DIR)/*.c))

CFLAGS +=		-Wall -Wextra -Werror $(foreach includedir,$(INCLUDE_DIRS),-I$(includedir))
LDFLAGS +=		-L./ -lftprintf

.PHONY: all clean fclean re

all: $(NAME)

test: $(NAME) main.o
	$(CC) $(CFLAGS) -o test $(C_OBJS) main.o $(LDFLAGS)

$(NAME): $(C_OBJS) $(L_OBJS)
	ar rc $(NAME) $(C_OBJS) $(L_OBJS)
	ranlib $(NAME)

clean:
	@- $(RM) $(C_OBJS) main.o $(L_OBJS) test

fclean: clean
	@- $(RM) $(NAME)

re: fclean all
