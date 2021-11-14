/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** IJsonWRAPPER
*/

/**
 * \file IJsonWrapper.hpp
 *
 * \class IJsonWrapper
 *
 * \brief Interface of JsonWrapper
 */
#ifndef IJSONWRAPPER_HPP_
#define IJSONWRAPPER_HPP_

    #include <string>
    #include <nlohmann/json.hpp>

    class IJsonWrapper {
        public:

            /**
             * \fn ~IJsonWrapper() = default
             * 
             * \brief Destruct an IJson object
             */
             ~IJsonWrapper() = default;

            /**
             * \fn virtual std::string &jsonToString() = 0
             * 
             * \brief Convert and return content of a json file as a string
             * 
             * \return std::string & Le contenu du file .json
             */ 
            virtual std::string jsonToString() = 0;
            
            /**
             * \fn virtual void fillComposantList() = 0
             * 
             * \brief Fill a object list with the content of a JSON file
             */
            virtual void fillComposantList() = 0;
            
             /**
              * \fn virtual void addPlayer() = 0
              * 
              * \brief Fill a object list with a player object
              */
            virtual void addPlayer() = 0;

            /**
             * \fn virtual void addMonster() = 0
             * 
             * \brief Fill a object list with a monster object
             */
            virtual void addMonster() = 0;
            
            /**
             * \fn virtual void addWall() = 0
             * 
             * \brief Fill a object list with a wall object
             */
            virtual void addWall() = 0;
    };

#endif /* !IJSONWRAPPER_HPP_ */
