#ifndef WEAPON_CLASS_H
#define WEAPON_CLASS_H

#include <string>

class Weapon {

private:

    std::string _type;

public:

    Weapon ( std::string const & type );

    void setType( std::string type );

    const std::string& getType( void ) const;

};

#endif
