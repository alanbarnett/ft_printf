# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarnett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 22:40:12 by abarnett          #+#    #+#              #
#    Updated: 2018/12/07 22:48:17 by alan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			libftprintf.a

SRC_DIR :=		srcs
INCLUDE_DIRS :=	./includes ./libft/includes
C_OBJS :=		$(patsubst %.c,%.o,$(wildcard ./$(SRC_DIR)/*.c))
L_OBJS :=		$(patsubst %.c,%.o,$(wildcard ./libft/$(SRC_DIR)/*.c))

CFLAGS +=		-Wall -Wextra -Werror $(foreach includedir,$(INCLUDE_DIRS),-I$(includedir))
LDFLAGS +=		-L./ -lftprintf

.PHONY:			all clean fclean re

all: $(NAME)

$(NAME): $(C_OBJS) $(L_OBJS)
	ar rc $(NAME) $(C_OBJS) $(L_OBJS)
	ranlib $(NAME)

clean:
	@- $(RM) $(C_OBJS) $(L_OBJS)

fclean: clean
	@- $(RM) $(NAME)

re: fclean all
