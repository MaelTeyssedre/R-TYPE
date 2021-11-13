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

    namespace composant {
        struct composant_s {
            int id;
            std::pair<int, int> pos;
            int strength;
            int hp;
            std::string type;
        };
    }
    class JsonWrapper : public IJsonWrapper {
        public:
            
            JsonWrapper(std::string filename);
            std::string jsonToString();
            void fillComposantList();
            composant::composant_s createComposant(int id, std::pair<int, int> pos, int strength, int hp, std::string &type);
            void addPlayer();
            void addMonster();
            void addWall();
            bool isNewElementType(std::vector<std::vector<composant::composant_s>> _composantList, std::string type);
            std::vector<std::vector<composant::composant_s>> getComposantList() const;
        private:
            std::string _filename;
            nlohmann::json _json;
            std::vector<std::vector<composant::composant_s>> _composantList;
    };

#endif /* !IJSONWRAPPER_HPP_ */
