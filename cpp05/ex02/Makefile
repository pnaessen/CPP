NAME := Program

SRC := main.cpp \
	   Bureaucrat.cpp\
	   AForm.cpp \
	   ShrubberyCreationForm.cpp \

OBJ_DIR := .obj
OBJ := $(SRC:.cpp=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(OBJ)))
DEPS := $(OBJ:.o=.d)

HEADERS := Bureaucrat.hpp\
		   AForm.hpp \
		   ShrubberyCreationForm.hpp \

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98
CPPFLAGS := -MMD -MP

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "\033[32mCompilation complete: $@\033[0m"

$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[33mCleaned object files\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[33mRemoved executable\033[0m"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
