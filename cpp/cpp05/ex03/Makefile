CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
EXEC = interns
SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp Intern.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: fclean clean re all