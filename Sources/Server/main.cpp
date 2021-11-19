#include <iostream>
#include "NetworkManager.hpp"
#include "tcpServer.hpp"
#include "JsonWrapper.hpp"
#include "Registry.hpp"

int main()
{
  Registry registry;
  JsonWrapper wrapper(std::string("test.json"));
  std::vector<std::pair<std::shared_ptr<IElement>, std::string>> objectList = wrapper.getComposantList();

  for (int i = 0; i != objectList.size(); i++) {
    if (objectList[i].second == "monster")
      objectList[i].first->init(registry);
  }

  return (0);
}
