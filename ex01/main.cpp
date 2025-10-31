#include "PhoneBook.hpp"
#include <sstream>
#include <cctype>

static void addContact(PhoneBook &book) {
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    print_msg(READ, "< Type the first name:");
    getline(std::cin, firstName);
    print_msg(READ, "< Type the last name:");
    getline(std::cin, lastName);
    print_msg(READ, "< Type the nickname:");
    getline(std::cin, nickname);
    print_msg(READ, "< Type the phone number:");
    getline(std::cin, phoneNumber);
    print_msg(READ, "< Type the darkest secret:");
    getline(std::cin, darkestSecret);

    try {
        book.storeContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    } catch (std::runtime_error& e) {
        print_msg(ERROR, e.what());
    }
}

static void searchContact(PhoneBook &book) {
    std::string input;
    int idx = 0;

    while (1) {
        std::cout << std::endl;
        print_msg(READ, "< Type an index:");
        getline(std::cin, input);
    
        if (input.size() > 1 || !isdigit(input[0])){
            print_msg(ERROR, "The index must be numeric digit.");
            continue;
        }

        idx = std::atoi(input.c_str());
        if (idx > MAX_CONTACTS) {
            std::stringstream ss;
            ss << MAX_CONTACTS;
            print_msg(ERROR, "The index must be greater than 0 and less or equal than " + ss.str() + ".");
            continue;
        }

        try {
            Contact match = book.getContactByIdx(idx);

            match.printInfo();
            break;
        } catch (std::runtime_error& e) {
            print_msg(ERROR, e.what());
        }
    }
}

void printOptions() {
    std::cout << "=== Crappy PhoneBook ==" << std::endl;
    std::cout << "Commands:" << std::endl;
    std::cout << "- ADD: Add a new contact" << std::endl;
    std::cout << "- SEARCH: Get contact info by index" << std::endl;
    std::cout << "- EXIT: Stop the program" << std::endl;
    std::cout << "=======================" << std::endl;
}

int main () {
    std::string command;
    PhoneBook book;

    while (true)
    {
        printOptions();
        print_msg(READ, "< Enter a command: ");
        getline(std::cin, command);

        std::cout << std::endl;
        if (command == "ADD")
            addContact(book);
        else if (command == "SEARCH") {
            if (book.printContacts())
                searchContact(book);
        } else if (command == "EXIT")
            break;
        std::cout << std::endl;
    }

    std::cout << "Goodby!" << std::endl;
    return 0;
}