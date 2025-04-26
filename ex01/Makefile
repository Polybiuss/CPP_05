NAME = form

SRC = main.cpp	\
	Bureaucrat.cpp	\
	Form.cpp	\

OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wall -Werror -Wextra
STD = -std=c++98

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) $(STD) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(STD) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re