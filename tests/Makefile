# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 21:43:30 by abenamar          #+#    #+#              #
#    Updated: 2023/01/13 04:23:37 by abenamar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := test.out

INCLUDES := -I $(CURDIR)/..
INCLUDES += -I $(CURDIR)

SRCS := get_next_line.c
SRCS += get_next_line_utils.c

CC := cc

CFLAGS := -g3
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

ifdef BUFFER_SIZE
CFLAGS += -DBUFFER_SIZE=$(BUFFER_SIZE)
endif

ifneq (, $(findstring bonus, $(MAKECMDGOALS)))
SRCS += get_next_line_bonus.c
SRCS += get_next_line_utils_bonus.c

CFLAGS += -DBONUS
endif

SRCS := $(patsubst %,$(CURDIR)/../%,$(SRCS))

SRCS += get_next_line_test.c
SRCS += test.c

RM := rm -f

$(NAME): $(OBJS)
	@echo "\033[0;36m#################################### make get_next_line ####################################\033[0m"
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(INCLUDES)

test: $(NAME)
	@echo "\033[0;36m########################################### test ###########################################\033[0m"
	@./$(NAME)

valgrind-test: $(NAME)
	@echo "\033[0;36m#################################### test with valgrind ####################################\033[0m"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

norm:
	@echo "\033[0;36m######################################## norminette ########################################\033[0m"
	@cd $(CURDIR)/.. && norminette $$(ls | grep "\.c\|\.h")

bonus: $(NAME)

all: norm valgrind-test

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: re fclean clean all bonus so norm valgrind-test test
