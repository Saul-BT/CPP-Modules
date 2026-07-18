CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = main.cpp RPN.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = RPN

all: $(NAME)

re: fclean all

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJECTS): RPN.hpp

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJECTS)

.PHONY: all fclean clean re