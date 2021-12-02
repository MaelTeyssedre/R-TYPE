/**
 * \file IJsonWrapper.hpp
 *
 * \brief Interface of JsonWrapper
 */

#ifndef IJSONWRAPPER_HPP_
#define IJSONWRAPPER_HPP_

    #include <string>
    #include "AMonster.hpp"
    #include "LibLoader.hpp"
    #include "Wall.hpp"
    #include "Player.hpp"
    #include <iostream>
    #include <fstream>
    #include <memory>
    #include <iomanip>
    #include <utility>
    #include <nlohmann/json.hpp>
    #include <vector>

    /**
     * \namespace rtype
     * 
     * \brief namespace for the R-Type
     * 
     */
    namespace rtype {
        /**
         * \class IJsonWrapper
         * 
         * \brief interface for JSonWrapper
         * 
         */
        class IJsonWrapper {
            public:

                /**
                 * \fn virtual ~IJsonWrapper() = default
                 * 
                 * \brief Destruct an IJson object
                 */
                virtual ~IJsonWrapper() = default;

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
    }

#endif /* !IJSONWRAPPER_HPP_ */
