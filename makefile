NAME		=	bot

# --   Directory   -- #
OBJ_DIR     =	objs

OBJ_SUB_DIR =	.

OBJ_TO_CREATE = $(addprefix $(OBJ_DIR)/, $(OBJ_SUB_DIR))

INC_DIR		=	inc

# --  Search All files in SRCS  -- #
SRC_DIR = src

SRCSS =	src/botclean.cpp\



SRCS = $(SRCSS:src/%.cpp=%.cpp)


# --  Redirection in OBJS  -- #
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))

CC			=	g++
# CFLAGS      =   -Wall -Wextra -Werror
CFLAGS      =

PARAM =

#Mandatory rules

all :
	@mkdir -p $(OBJ_TO_CREATE)
	@make $(NAME) --no-print-directory

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all


#My personal rules


git :
	git add --all
	git commit
	git push

get_src:
		@find $(SRC_DIR) -type f -name "*.cpp" | tr "\n" "|" | sed -r 's/["|"]+/\\ \n/g'

run: all
	cat infile | ./$(NAME) $(PARAM)

leaks: all
	 valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --leak-resolution=high --show-reachable=yes --trace-children=yes --verbose --log-file=valgrind.log ./push_swap 10 9 8 7 6 5

get_dir:
		@find $(SRC_DIR) -type d | tr "\n" "|" | sed -r 's/["|"]+/\\ \n/g' | sed -e 's/$(SRC_DIR)\///g'

header :
	@Headermaker $(SRC_DIR) $(INC_DIR)/prototypes.h -inc structs define


.PHONY: all clean fclean re
