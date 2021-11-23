#include "RtypeClient.hpp"
#include "Constants.hpp"

int main(int ac, char **av)
{
    if (ac != 3) {
        std::cout << HELPER << std::endl;
        return 0;
    } 
    RtypeClient rtype (av[1], av[2]);
    rtype.run();
    return 0;
}
