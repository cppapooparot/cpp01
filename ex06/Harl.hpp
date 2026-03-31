#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <system_error>

class Harl
{
    private:
        void debug();
        void info();
        void warning();
        void error();

        typedef void (Harl::*Action)();
        enum level
        {
            DEBUG,
            INFO,
            WARNING,
            ERROR
        };
        static const Action actions[4];
    public:
        void complain(std::string level);
};

#endif