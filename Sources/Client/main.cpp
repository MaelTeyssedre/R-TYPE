#include "RtypeClient.hpp"
#include "Constants.hpp"

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

std::vector<std::string> split(const std::string &str, char delim)
{
    size_t i = 0;
    std::vector<std::string> list;
    auto pos = str.find(delim);
 
    while (pos != std::string::npos)
    {
        list.push_back(str.substr(i, pos - i));
        i = ++pos;
        pos = str.find(delim, pos);
    }
    list.push_back(str.substr(i, str.length()));
    return list;
}

bool validateIP(std::string ip)
{
    std::vector<std::string> list = split(ip, '.');
    if (list.size() != 4)
        return false;
    for (auto &it: list)
        if (!is_number(it) || stoi(it) > 255 || stoi(it) < 0)
            return false;
    return true;
}

int main(int ac, char **av)
{
    if (ac != 3 || !is_number(av[2]) || (!validateIP(av[1]) && strcmp(av[1], "localhost"))) {
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