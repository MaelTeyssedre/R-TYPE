#include "RtypeClient.hpp"
#include "Constants.hpp"

int main(int ac, char **av)
{
    if (ac != 3) {
        std::cout << HELPER << std::endl;
        return 0;
    }
    (void)ac;
    std::string host;
    if (strcmp(av[1], "localhost") == 0)
        host = "127.0.0.1";
    else
        host = av[1];
    rtype::RtypeClient the_rtype(host, av[2]);
    if (the_rtype.checkStatus() == true)
        the_rtype.run();
    return 0;
}