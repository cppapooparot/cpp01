#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : name(name){}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << weapon.get_type() << std::endl;
}

void HumanB::setWeapon(const Weapon& weapon_) { weapon = weapon_;}