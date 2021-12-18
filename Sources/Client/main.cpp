#include "RtypeClient.hpp"
#include "Constants.hpp"

bool is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

std::vector<std::string> split(const std::string& str, char delim)
{
	size_t i = 0;
	std::vector<std::string> list{};
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
	for (auto& it : list)
		if (!is_number(it) || stoi(it) > 255 || stoi(it) < 0)
			return false;
	return true;
}

int main(int ac, char** av)
{
	std::string host{ "127.0.0.1" };
	if (ac != 3 || !is_number(av[2]) || (!validateIP(av[1]) && strcmp(av[1], "localhost")))
		return std::cout << HELPER << std::endl, 0;
	if (strcmp(av[1], "localhost") && strcmp(av[1], "127.0.0.1"))
		host = av[1];
	rtype::RtypeClient the_rtype(host, av[2]);
	if (the_rtype.checkStatus())
		the_rtype.run();
	return 0;
}