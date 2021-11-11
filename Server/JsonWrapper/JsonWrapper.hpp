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

    class JsonWrapper{
        public:
            struct composant_s {
                int id;
                std::pair<int, int> pos;
                int strength;
                int hp;
                bool loot;
                std::string type;
            };
            JsonWrapper(std::string filename);
            ~JsonWrapper();
            std::string jsonToString();
            std::string getJsonValue(std::string &composantType, std::string &id, std::string &element);
            void fillComposantList();
            composant_s createComposant(int id, std::pair<int, int> pos, int strength, int hp, bool loot, std::string &type);
            void addPlayer();
            void addMonster();
            void addWall();
            virtual bool isNewElementType(std::vector<std::vector<composant_s>> _composantList, std::string type);
        protected:
        private:
        std::string _filename;
        nlohmann::json _json;
        std::vector<std::vector<composant_s>> _composantList;
    };

#endif /* !IJSONWRAPPER_HPP_ */
