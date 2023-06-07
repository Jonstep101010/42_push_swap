NAME		:= push_swap

INCS		:= -I libft/include -I include

BUILD_DIR	:= .build

DEPS		:= $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.d))

OBJ			:= $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
# Path: srcs/
SRCS_DIR	:= src/
SRCS		:= push_swap.c

all: $(NAME)

$(NAME):
	@echo "Compiling..."
	@cc -Wall -Wextra -Werror -MMD -MP $(INCS) -L./libft -lft $(addprefix $(SRCS_DIR), $(SRCS)) -o $(NAME)
	@echo "Done!"

clean:
	@echo "Cleaning..."
	@rm -rf $(NAME)
	@echo "Done!"

fclean: clean
	rm -rf $(BUILD_DIR)/%.o

update:
	git submodule update --init --recursive