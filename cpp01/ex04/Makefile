# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 11:15:22 by pnaessen          #+#    #+#              #
#    Updated: 2025/05/08 11:15:23 by pnaessen         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME := Sed

SRC := 	main.cpp \
	  

OBJ_DIR := .obj
OBJ := $(SRC:.cpp=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(OBJ)))
DEPS := $(OBJ:.o=.d)

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
