#ifndef WEAPON_CLASS_H
#define WEAPON_CLASS_H

#include <string>

class Weapon {
private:
    std::string _type;

public:
    // Constructors
    Weapon ( std::string const & type );

    // Setters
    void setType( std::string type );

    // Getters
    const std::string& getType( void ) const;
};

#endif
