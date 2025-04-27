NAME = abstractForm

SRC = main.cpp	\
	Bureaucrat.cpp	\
	AForm.cpp	\
	ShruberryCreationForm.cpp	\
	RobotomyRequestForm.cpp	\
	PresidentialPardonForm.cpp	\

OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror
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

.PHONY: all clean fclean re