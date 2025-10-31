#ifndef PHONE_BOOK_CLASS_H
#define PHONE_BOOK_CLASS_H
#define MAX_CONTACTS 3

#include <string>
#include <cstdlib>
#include <iostream>
#include "Contact.hpp"
#include "utils.hpp"

class PhoneBook {
private:
    int _contactCount;
    Contact _contacts[MAX_CONTACTS];

public:
    PhoneBook();
    void storeContact(
        std::string firstName,
        std::string lastName,
        std::string nickname,
        std::string phoneNumber,
        std::string darkestSecret
    );
    bool printContacts() const;
    Contact getContactByIdx(int idx) const;
};

#endif
