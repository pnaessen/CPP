NAME := megaphone

SRC := megaphone.cpp
OBJ_DIR := .obj
OBJ := $(SRC:.cpp=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(OBJ)))
DEPS := $(OBJ:.o=.d)

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98
CPPFLAGS := -MMD -MP

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Compilation complete: $@"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned up object and dependency files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned up executable"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
