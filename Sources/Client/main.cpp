#include "RtypeClient.hpp"
#include "Constants.hpp"

int main(int ac, char **av)
{
    if (ac != 3) {
        std::cout << HELPER << std::endl;
        return 0;
    }
    (void)ac;
    rtype::RtypeClient the_rtype(av[1], av[2]);
    if (the_rtype.checkStatus() == true)
        the_rtype.run();
    return 0;
}