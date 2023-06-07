NAME		:= push_swap

LIB		:= ft
LIB_FT		:= include/libft/libft.a
INCS		:= include \
	include/libft/include

BUILD_DIR	:= .build
DIR_MK		 = mkdir -p $(@D)

SRC_DIR		:= src
SRC			:= push_swap.c
SRCS		:= $(addprefix $(SRC_DIR)/,$(SRC))

OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(dir $(LIB_FT)))
LDLIB		:= $(addprefix -l,$(LIB))

MAKEFLAGS	+= --silent --no-print-directory

all: $(NAME)

$(NAME): $(OBJS) $(LIB_FT)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIB) -o $(NAME)

$(LIB_FT):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(info Compiling...)
	$(DIR_MK)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info Done!)

-include $(DEPS)

clean:
	$(info Cleaning...)
	rm -rf $(NAME)
	$(info Done!)

fclean: clean
	rm -rf $(BUILD_DIR)

update:
	git submodule update --init --recursive

re:
	$(MAKE) fclean
	$(MAKE) all

run: re
	-./$(NAME)

upgrade:
	$(MAKE) update
	$(MAKE) run

.PHONY: run update re
.SILENT: