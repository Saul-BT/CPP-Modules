CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = main.cpp PmergeMe.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = PmergeMe

all: $(NAME)

re: fclean all

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJECTS): PmergeMe.hpp

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJECTS)

.PHONY: all fclean clean re
