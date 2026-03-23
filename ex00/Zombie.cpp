#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : name_(name) {}

Zombie::~Zombie()
{
    std::cout << "Zombie" << name_ << " destroyed" << std::endl;
}
void Zombie::announce(void) const 
{
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *newZombie(std::string name)
{
    return new Zombie(name);
}

void randomChump(std::string name)
{
    Zombie z(name);
    z.announce();
    
}