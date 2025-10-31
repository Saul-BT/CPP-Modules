
#include <iostream>
#include "Contact.hpp"

// Constructors / Destructors
Contact::Contact() {}
Contact::~Contact() {}

// Setters
void Contact::setFirstName(std::string value) {
    this->_firstName = value;
}

void Contact::setLastName(std::string value) {
    this->_lastName = value;
}

void Contact::setNickname(std::string value) {
    this->_nickname = value;
}

void Contact::setPhoneNumber(std::string value) {
    this->_phoneNumber = value;
}

void Contact::setDarkestSecret(std::string value) {
    this->_darkestSecret = value;
}

// Getters
std::string Contact::getFirstName() const {
    return this->_firstName;
}

std::string Contact::getLastName() const {
    return this->_lastName;
}

std::string Contact::getNickname() const {
    return this->_nickname;
}

std::string Contact::getPhoneNumber() const {
    return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return this->_darkestSecret;
}

// Other methods
void Contact::printInfo() const {
    std::cout << "- First name: " << this->_firstName << std::endl;
    std::cout << "- Last name: " << this->_lastName << std::endl;
    std::cout << "- Nickname: " << this->_nickname << std::endl;
    std::cout << "- Phone number: " << this->_phoneNumber << std::endl;
    std::cout << "- Darkest secret: " << this->_darkestSecret << std::endl;
}

void Contact::clean(Contact *c) {
    c->_firstName = "";
    c->_lastName = "";
    c->_nickname = "";
    c->_phoneNumber = "";
    c->_darkestSecret = "";
}


bool Contact::isFilled(const Contact &c) {
    std::string fields[] = {
        c._firstName,
        c._lastName,
        c._nickname,
        c._phoneNumber,
        c._darkestSecret
    };
    int fieldCount = sizeof(fields) / sizeof(std::string);

    for (int i = 0; i < fieldCount; i++)
        if (fields[i].empty() || fields[i] == "\n")
            return false;

    return true;
}
