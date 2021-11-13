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
             ~IJsonWrapper() = default;
            virtual std::string jsonToString() = 0;
            virtual void fillComposantList() = 0;
            virtual void addPlayer() = 0;
            virtual void addMonster() = 0;
            virtual void addWall() = 0;
    };

#endif /* !IJSONWRAPPER_HPP_ */
