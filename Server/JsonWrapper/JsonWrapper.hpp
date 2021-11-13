/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** JsonWRAPPER
*/

#ifndef JSONWRAPPER_HPP_
#define JSONWRAPPER_HPP_

    #include <vector>
    #include "IJsonWrapper.hpp"

    namespace object {
    }
    class JsonWrapper : public IJsonWrapper {
        public:
            struct object_s {
            int id;
            std::pair<int, int> pos;
            int strength;
            int hp;
            std::string type;
        };
            JsonWrapper(std::string &filename);
            std::string &jsonToString();
            void fillComposantList();
            JsonWrapper::object_s createComposant(int id, std::pair<int, int> pos, int strength, int hp, std::string &type);
            JsonWrapper::object_s createComposant(std::pair<int, int> pos, std::string &type);
            void addPlayer();
            void addMonster();
            void addWall();
            bool isNewElementType(std::vector<std::vector<JsonWrapper::object_s>> _objectList, std::string type);
            std::vector<std::vector<JsonWrapper::object_s>> getComposantList() const;
        private:
            std::string _filename;
            nlohmann::json _json;
            std::vector<std::vector<JsonWrapper::object_s>> _objectList;
    };

#endif /* !IJSONWRAPPER_HPP_ */
