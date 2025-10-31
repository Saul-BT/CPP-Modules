CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = Zombie.cpp zombieHorde.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = ex01

all: $(NAME)

re: fclean all

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJECTS)

.PHONY: all fclean clean