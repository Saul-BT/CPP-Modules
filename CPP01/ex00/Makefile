CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = ex00

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