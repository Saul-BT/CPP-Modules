#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact();
    ~Contact();
    
    void setFirstName(std::string value);
    void setLastName(std::string value);
    void setNickname(std::string value);
    void setPhoneNumber(std::string value);
    void setDarkestSecret(std::string value);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    void printInfo() const;
    static void clean(Contact *c);
    static bool isFilled(const Contact &c);
};

#endif