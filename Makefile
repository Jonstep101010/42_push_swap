NAME		:= push_swap

LIB			:= ft
LIB_FT		:= libft/libft.a
INCS		:= include \
	libft/include

BUILD_DIR	:= .build
DIR_MK		 = mkdir -p $(@D)

SRC_DIR		:= src
SRC			:= push_swap.c input_handling.c basic_stack.c rotate_stack.c list_tools.c list_checks.c error.c print_return.c sorting.c free_stack.c printing.c build_stack.c
SRCS		:= $(addprefix $(SRC_DIR)/,$(SRC))

OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(SRCS:.c=.d)

CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror -fsanitize=address -g
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(dir $(LIB_FT)))
LDLIB		:= $(addprefix -l,$(LIB))

MAKEFLAGS	+= --silent --no-print-directory

DONE		+= printf "\033[0;32m\xE2\x9C\x93\n\033[0m"

all: $(NAME)

$(NAME): $(SRCS) $(LIB_FT)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRCS) $(LDFLAGS) $(LDLIB) -o $(NAME)
	$(info creating $(NAME) executable)$(DONE)

$(LIB_FT):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(info Compiling...)
	$(DIR_MK)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
# $(info Done)
	$(DONE)

-include $(DEPS)

clean:
	$(info Cleaning...)
	make -C $(dir $(LIB_FT)) clean
	rm -rf $(NAME)
	$(DONE)

fclean: clean
	make -C $(dir $(LIB_FT)) fclean
	rm -rf *.d
	rm -rf $(BUILD_DIR)

update:
	cd ./include && git submodule update --init --recursive && cd ..

re:
	$(MAKE) fclean
	$(MAKE) all

run: re
	-./$(NAME)

three:
	$(MAKE)
	-./$(NAME) "1 2 3" && echo "- - -"
	-./$(NAME) "3 2" 1 && echo "- - -"
	-./$(NAME) "3" 1 2 && echo "- - -"
	-./$(NAME) 1 3 2 && echo "- - -"
	-./$(NAME) 2 1 3 && echo "- - -"
	-./$(NAME) 2 3 1 && echo "- - -"
	-./$(NAME) 2 3 1 4 && grep "error"
	

upgrade:
	$(MAKE) update
	$(MAKE) run

.PHONY: run update re
.SILENT: