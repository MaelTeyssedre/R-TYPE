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
            JsonWrapper(std::string filename);
            ~JsonWrapper();
            std::string jsonToString();
            void createJsonFromString(std::string &string);
            std::string getJsonValue(std::string &composantType, std::string &id, std::string &element);
        protected:
        private:
        std::string _filename;
        nlohmann::json _json;
    };

#endif /* !IJSONWRAPPER_HPP_ */
