#include "Zombie.hpp"


int main() {
    Zombie* h = newZombie("HeapZombie");
    h->announce();
    delete h; //here we need to delete by hand

    randomChump("StackZombie"); //zombie will be destroyed automatically here
    return 0;
}
