NAME		:=	ex01
CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -Iinc -std=c++98

SRCS		:=	src/main.cpp\
				src/RPN.cpp
OBJ_DIR		:=	obj
OBJS		=	$(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)


$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re