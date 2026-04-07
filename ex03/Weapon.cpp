#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(const std::string& type) : type(type) {}

const std::string& Weapon::get_type() const { return type;}

void Weapon::setType(const std::string& type_) { type = type_;}