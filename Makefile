NAME		:= push_swap
.DEFAULT_GOAL := all

LIBFT		:= include/libft/libft.a
LIBFTPRINTF	:= include/libftprintf/libftprintf.a
LIBUTILS	:= include/libutils/libutils.a
INCS		:= include \
				include/libft/ \
				include/libftprintf/ \
				include/libutils/include/

BUILD_DIR	:= .build

VPATH		:= src/ src/io src/operations src/sorting src/utils

SRC			:= push_swap.c error.c
SRC_IO		:= input_handling.c build_stack.c free_stack.c
SRC_OP		:= push.c swap.c rotate.c rev_rotate.c
SRC_AB		:= calculations.c sorting.c sorting_utils.c sort_small.c sort_big.c
SRC_UT		:= checks.c printing.c

SRCS		:= $(SRC) $(SRC_IO) $(SRC_OP) $(SRC_AB) $(SRC_UT)
OBJS		:= $(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
DEPS		:= $(OBJS:.o=.d)

CC			:= clang
CFLAGS		?= -Wall -Wextra -Werror
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L, $(dir $(LIBFT)) $(dir $(LIBFTPRINTF)) $(dir $(LIBUTILS)))
LDLIB		:= $(addprefix -l, ft ftprintf utils)

# MAKEFLAGS	+= --silent --no-print-directory

DONE		= printf "\033[0;32m\xE2\x9C\x93\033[0m "

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBFTPRINTF) $(LIBUTILS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIB) -o $(NAME)
	$(info creating $(NAME) executable)
	printf "\033[0;32m\xE2\x9C\x93\n\033[0m"

$(LIBFT):
	$(MAKE) -C $(@D) -B

$(LIBFTPRINTF):
	$(MAKE) -C $(@D) -B

$(LIBUTILS):
	$(MAKE) -C $(@D) -B

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(DONE)
#info $($<)
	echo $(notdir $<)

$(BUILD_DIR):
	mkdir -p .build

clean:
	$(info Cleaning...)
	make -C $(dir $(LIBFT)) clean
	make -C $(dir $(LIBFTPRINTF)) clean
	make -C $(dir $(LIBUTILS)) clean
	rm -rf $(NAME)
	printf "\033[0;32m\xE2\x9C\x93\n\033[0m"

fclean: clean
	make -C $(dir $(LIBFT)) fclean
	make -C $(dir $(LIBFTPRINTF)) fclean
	make -C $(dir $(LIBUTILS)) fclean
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

vis:
	$(MAKE) all
	./push_swap_visualizer/build/bin/visualizer

run: re
	-./$(NAME)

norme:
	-norminette src/ | grep Error

check: norme
	time cd ./resources && sh ./tests.sh && cd ..

upgrade:
	-$(MAKE) update && $(MAKE) re

.PHONY: run update upgrade re vis fclean clean re
# .SILENT:
-include $(DEPS)