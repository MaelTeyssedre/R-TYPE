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
            virtual void createJsonFromString(std::string &string) = 0;
            virtual std::string getJsonValue(std::string &composantType, std::string &id, std::string &element) = 0;
        protected:
        private:
    };

#endif /* !IJSONWRAPPER_HPP_ */
