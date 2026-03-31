#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
    private:
        void debug();
        void info();
        void warning();
        void error();

        typedef void (Harl::*Action)();
        static const char* const levels[4];
        static const Action actions[4];
    public:
        void complain(std::string level);
};

#endif