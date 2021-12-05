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
     * \brief global namespace for the rtype project
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
                 * \fn virtual auto jsonToString() -> std::string = 0
                 * 
                 * \brief Convert and return content of a json file as a string
                 * 
                 * \return std::string & Le contenu du file .json
                 */ 
                virtual auto jsonToString() -> std::string = 0;
                
                /**
                 * \fn virtual auto fillComposantList() -> void = 0
                 * 
                 * \brief Fill a object list with the content of a JSON file
                 */
                virtual auto fillComposantList() -> void = 0;
                
                /**
                 * \fn virtual auto addPlayer() -> void = 0
                 * 
                 * \brief Fill a object list with a player object
                 */
                virtual auto addPlayer() -> void = 0;

                /**
                 * \fn virtual auto addMonster() -> void = 0
                 * 
                 * \brief Fill a object list with a monster object
                 */
                virtual auto addMonster() -> void = 0;
                
                /**
                 * \fn virtual auto addWall() -> void = 0
                 * 
                 * \brief Fill a object list with a wall object
                 */
                virtual auto addWall() -> void = 0;
        };
    }

#endif /* !IJSONWRAPPER_HPP_ */
