#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : weapon(NULL), name(name) {}

void HumanB::attack() const
{
    if (!weapon)
    {
        std::cout << name << " attacks with their bare hands" << std::endl;
        return;
    }
    std::cout << name << " attacks with their " << weapon->get_type() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon_) { weapon = &weapon_; }