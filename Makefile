NAME		:= push_swap

LIB			:= ft
LIB_FT		:= include/libft/libft.a
INCS		:= include \
	include/libft/include

BUILD_DIR	:= .build
DIR_MK		 = mkdir -p .build

SRC_DIR		:= src
DIRS		:= io operations sorting utils
VPATH		:= $(addprefix $(SRC_DIR)/,$(DIRS))

SRC_IO		:= push_swap.c input_handling.c build_stack.c error.c free_stack.c
SRC_OP		:= push.c swap.c rotate.c rev_rotate.c
SRC_AB		:= calculations.c sorting.c sorting_utils.c sort_small.c sort_big.c
SRC_UT		:= checks.c printing.c indexing.c find.c

SRCS		:= $(SRC_IO) $(SRC_OP) $(SRC_AB) $(SRC_UT)
OBJS		:= $(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
DEPS		:= $(OBJS:.o=.d)

CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror -g
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(dir $(LIB_FT)))
LDLIB		:= $(addprefix -l,$(LIB))

MAKEFLAGS	+= --silent --no-print-directory

DONE		= printf "\033[0;32m\xE2\x9C\x93\033[0m "

all: $(NAME)

$(NAME): $(OBJS) $(LIB_FT)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LDFLAGS) $(LDLIB) -o $(NAME)
	$(info creating $(NAME) executable)
	printf "\033[0;32m\xE2\x9C\x93\n\033[0m"

$(LIB_FT):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: %.c
	$(DIR_MK)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(DONE)
#info $($<)
	echo $(notdir $<)


clean:
	$(info Cleaning...)
	make -C $(dir $(LIB_FT)) clean
	rm -rf $(NAME)
	printf "\033[0;32m\xE2\x9C\x93\n\033[0m"

fclean: clean
	make -C $(dir $(LIB_FT)) fclean
	rm -rf *.d
	rm -rf $(BUILD_DIR)

update:
	git stash
	git pull
	git submodule update --init
	git stash pop

re:
	$(MAKE) fclean
	$(MAKE) all

run: re
	-./$(NAME)

norme:
	-norminette src/ | grep Error

check: norme
	time cd ./resources && sh ./tests.sh && cd ..

upgrade:
	-$(MAKE) update && $(MAKE) re

.PHONY: run update upgrade re
.SILENT:
-include $(DEPS)