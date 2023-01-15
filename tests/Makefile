# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 21:43:30 by abenamar          #+#    #+#              #
#    Updated: 2023/01/15 04:46:53 by abenamar         ###   ########.fr        #
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

TESTSRCS += gnl_no_file_test.c
TESTSRCS += gnl_empty_test.c
TESTSRCS += gnl_simple_test.c
TESTSRCS += gnl_multiple_test.c
TESTSRCS += gnl_no_ascii_test.c
TESTSRCS += gnl_horizontal_test.c
TESTSRCS += gnl_vertical_test.c
TESTSRCS += test.c

RM := rm -f

$(NAME): .FORCE
	@echo "\033[0;36m#################################### make get_next_line ####################################\033[0m"
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(TESTSRCS) $(INCLUDES)

.FORCE:

stdin-all:
	@$(MAKE) stdin 
	@$(MAKE) stdin-1
	@$(MAKE) stdin-42
	@$(MAKE) stdin-9999
	@$(MAKE) stdin-10M

stdin-10M: CFLAGS += -DBUFFER_SIZE=10000000
stdin-10M: stdin

stdin-9999: CFLAGS += -DBUFFER_SIZE=9999
stdin-9999: stdin

stdin-42: CFLAGS += -DBUFFER_SIZE=42
stdin-42: stdin

stdin-1: CFLAGS += -DBUFFER_SIZE=1
stdin-1: stdin

stdin: TESTSRCS := stdin.c
stdin: $(NAME)
	@echo "\033[0;36m###################################### test with stdin ######################################\033[0m"
	@./$(NAME)

test-all:
	@$(MAKE) test
	@$(MAKE) test-1
	@$(MAKE) test-42
	@$(MAKE) test-9999
	@$(MAKE) test-10M

test-10M: CFLAGS += -DBUFFER_SIZE=10000000
test-10M: test

test-9999: CFLAGS += -DBUFFER_SIZE=9999
test-9999: valgrind-test

test-42: CFLAGS += -DBUFFER_SIZE=42
test-42: test

test-1: CFLAGS += -DBUFFER_SIZE=1
test-1: test

test: $(NAME)
	@echo "\033[0;36m########################################### test ###########################################\033[0m"
	@./$(NAME)

valgrind-test-all:
	@$(MAKE) valgrind-test
	@$(MAKE) valgrind-test-1
	@$(MAKE) valgrind-test-42
	@$(MAKE) valgrind-test-9999
	@$(MAKE) valgrind-test-10M

valgrind-test-10M: CFLAGS += -DBUFFER_SIZE=10000000
valgrind-test-10M: valgrind-test

valgrind-test-9999: CFLAGS += -DBUFFER_SIZE=9999
valgrind-test-9999: valgrind-test

valgrind-test-42: CFLAGS += -DBUFFER_SIZE=42
valgrind-test-42: valgrind-test

valgrind-test-1: CFLAGS += -DBUFFER_SIZE=1
valgrind-test-1: valgrind-test

valgrind-test: $(NAME)
	@echo "\033[0;36m#################################### test with valgrind ####################################\033[0m"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

norm:
	@echo "\033[0;36m######################################## norminette ########################################\033[0m"
	@cd $(CURDIR)/.. && norminette $$(ls | grep "\.c\|\.h")

bonus: $(NAME)

all: norm valgrind-test-all

clean:
	$(RM) $(NAME)

fclean: clean

re: all

.PHONY: re clean all bonus so norm valgrind-test valgrind-test-1 valgrind-test-42 valgrind-test-10M valgrind-test-all test test-1 test-42 test-10M test-all stdin stdin-1 stdin-42 stdin-9999 stdin-10M stdin-all .FORCE
