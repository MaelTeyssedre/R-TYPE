/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** IJsonWRAPPER
*/

#ifndef IJSONWRAPPER_HPP_
#define IJSONWRAPPER_HPP_

    #include <string>
    #include <nlohmann/json.hpp>

    class IJsonWrapper {
        public:
            virtual ~IJsonWrapper() = 0;
            virtual std::string jsonToString() = 0;
            virtual std::string getJsonValue(std::string &composantType, std::string &id, std::string &element) = 0;
            virtual void fillComposantList() = 0;
            virtual void addPlayer() = 0;
            virtual void addMonster() = 0;
            virtual void addWall() = 0;
        protected:
        private:
    };

#endif /* !IJSONWRAPPER_HPP_ */
