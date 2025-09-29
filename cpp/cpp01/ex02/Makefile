# Variables
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = references
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

# Regla principal
all: $(TARGET)

# Regla para construir el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regla para compilar archivos .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Reglas de limpieza
clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(TARGET)

re: fclean all

# Phony targets
.PHONY: all clean fclean re 
