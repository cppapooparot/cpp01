#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
    private:
        Weapon* weapon;
        std::string name;
    public:
        HumanB(const std::string& name);
        void attack() const;
        void setWeapon(Weapon& weapon);
};

#endif