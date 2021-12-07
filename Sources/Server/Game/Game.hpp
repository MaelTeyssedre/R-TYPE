/**
 * \file GAME.hpp
 *
 * \brief file where the GAME class is defined
 *
 */

#ifndef GAME_HPP_
    #define GAME_HPP_


    #include "Buffer.hpp"
    #include "Registry.hpp"
    #include "JsonWrapper.hpp"
    #include "RequestComponent.hpp"
    #include "PlayerData.hpp"
    #include <thread>
    #include <vector>
    #include <memory>

     /**
      * \namespace rtype
      *
      * \brief namespace for rtype project
      *
      */
    namespace rtype {

        /**
         * \class GAME GAME.hpp
         *
         * \brief class that containt GAME
         */
        class Game {
        public:

            /**
             * \fn explicit GAME(std::vector<PlayerData> *players)
             *
             * \brief Construct a GAME
             *
             */
            explicit Game(std::vector<PlayerData>* players);

            /**
             * \fn virtual ~GAME() = default
             *
             * \brief Destroy the GAME
             *
             */
            virtual ~Game() = default;
        
            auto runGame() -> void;


        //private:
            //auto _initGame() -> void;

        private:
            auto _registerComponents() ->void;
            //auto _registerMonster(rtype::AMonster *monster) ->void;
            auto _setupComponents() ->void;
            //auto _sendRequestsToAll() -> void;
        
        private:
            auto _setupTimeComponent() -> void;

        private:
            JsonWrapper _jsonWrapper;
            std::vector<PlayerData> *_players;
            Registry _r;
        };
    }

#endif /* !GAME_HPP_ */
