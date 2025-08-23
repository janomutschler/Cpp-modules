NAME		:=	ex05
CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98 -g

SRCS		:=	main.cpp\
				Harl.cpp
OBJ_DIR		:=	obj
OBJS		=	$(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)


$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re