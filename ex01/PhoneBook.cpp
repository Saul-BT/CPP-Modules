#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactCount(0) {}

void PhoneBook::storeContact(
    std::string firstName,
    std::string lastName,
    std::string nickname,
    std::string phoneNumber,
    std::string darkestSecret
) {
    Contact &contact = this->_contacts[this->_contactCount % MAX_CONTACTS];
    if (this->_contactCount >= MAX_CONTACTS)
        print_msg(WARN, "Overwritting contact '" + contact.getFirstName() + "'!");

    contact.setFirstName(firstName);
    contact.setLastName(lastName);
    contact.setNickname(nickname);
    contact.setPhoneNumber(phoneNumber);
    contact.setDarkestSecret(darkestSecret);

    if (!Contact::isFilled(contact)) {
        Contact::clean(&contact);
        throw std::runtime_error("All the contact fields are mandatory, you should fill them.");
    }
    
    this->_contactCount++;
}

Contact PhoneBook::getContactByIdx(int idx) const {
    if (idx <= 0 || idx > this->_contactCount)
        throw std::runtime_error("The contact you are looking for doesn't exist.");

    return this->_contacts[idx - 1];
}

bool PhoneBook::printContacts() const {
    if (this->_contactCount == 0) {
        print_msg(WARN, "The book is empty.");
        return false;
    }

    std::cout << '|';
    printCell("Index");
    std::cout << '|';
    printCell("First Name");
    std::cout << '|';
    printCell("Last Name");
    std::cout << '|';
    printCell("Nickname");
    std::cout << '|' << std::endl;
    
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (!Contact::isFilled(this->_contacts[i]))
            break;
        std::cout << '|' << std::setfill(' ') << std::setw (10)  << i + 1;
        std::cout << '|';
        printCell(this->_contacts[i].getFirstName());
        std::cout << '|';
        printCell(this->_contacts[i].getLastName());
        std::cout << '|';
        printCell(this->_contacts[i].getNickname());
        std::cout << '|' << std::endl;
    }

    return true;
}
