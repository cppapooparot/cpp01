#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(const std::string name) : name_(name) {}

Zombie::~Zombie()
{
    std::cout << "Zombie " << name_ << " destroyed" << std::endl;
}
void Zombie::announce(void) const 
{
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(const std::string name)
{
    this->name_ = name;
}

Zombie *newZombie(const std::string name)
{
    return new Zombie(name);
}

void randomChump(const std::string name)
{
    Zombie z(name);
    z.announce();
}

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
    {
        std::cerr << "N must be natural integer" << std::endl;
        return NULL;
    }
    Zombie* horde = new Zombie[N];
    for(int i = 0; i < N; i++)
        horde[i].set_name(name);
    return horde;
}