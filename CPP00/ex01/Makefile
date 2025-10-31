CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = Contact.cpp PhoneBook.cpp utils.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = phonebook

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