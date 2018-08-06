# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarnett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 22:40:12 by abarnett          #+#    #+#              #
#    Updated: 2018/06/06 17:27:04 by abarnett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf
L_NAME := libft

SRC_DIR = srcs
INCLUDE_DIRS = includes $(L_NAME)/includes
C_OBJS := $(patsubst %.c,%.o,$(wildcard ./$(SRC_DIR)/*.c))
L_OBJS := $(patsubst %.c,%.o,$(wildcard ./$(L_NAME)/$(SRC_DIR)/*.c))

CFLAGS += -Wall -Wextra -Werror \
		  $(foreach includedir,$(INCLUDE_DIRS),-I$(includedir))
LDFLAGS += -L./$(L_NAME) -lft

.PHONY: all test clean fclean re

all: $(NAME).a

test: $(NAME).a $(L_NAME).a main.o
	$(CC) $(CFLAGS) -o test $(C_OBJS) main.o $(LDFLAGS)

$(NAME).a: $(L_NAME).a $(C_OBJS)
	ar rc $(NAME).a $(C_OBJS)
	ranlib $(NAME).a

$(L_NAME).a: $(L_OBJS)
	ar rc $(L_NAME)/$(L_NAME).a $(L_OBJS)
	ranlib $(L_NAME)/$(L_NAME).a

clean:
	@- $(RM) $(C_OBJS) main.o $(L_OBJS) test

fclean: clean
	@- $(RM) $(NAME).a $(L_NAME)/$(L_NAME).a

re: fclean all
