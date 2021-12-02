/**
 * \file Game.hpp
 * 
 * \brief file for Game class 
 */

#ifndef GAME_HPP_
    #define GAME_HPP_


    #include <memory>
    #include "Buffer.hpp"
    #include "Registry.hpp"
    #include "JsonWrapper.hpp"
    #include "NetworkComponent.hpp"
    #include <vector>
    #include <thread>
    #include <chrono>

    /**
     * \namespace rtype
     * 
     * \brief namespace for the R-Type
     * 
     */
    namespace rtype {
        /**
         * \class Game
         * 
         * \brief class Game that execute the game server side
         */
        class Game {
            public:
                /**
                 * \fn explicit Game(std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> &roomBuffer)
                 * 
                 * \brief Construct a new Game object
                 * 
                 * \param roomBuffer a reference to the buffer for communication
                 * 
                 */
                explicit Game(std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> &roomBuffer);

                /**
                 * \fn virtual ~Game() = default
                 * 
                 * \brief Destroy the Game object
                 * 
                 */
                virtual ~Game() = default;

                /**
                 * \fn void run()
                 * 
                 * \brief run the game
                 * 
                 */
                void run();
            private:
                /**
                 * \fn void waitForStartingGame()
                 * 
                 * \brief wait before starting the game
                 * 
                 */
                void waitForStartingGame();

                /**
                 * \fn void setupGame()
                 * 
                 * \brief setup the game
                 * 
                 */
                void setupGame();

                /**
                 * \fn void registerMapObjectsComponents()
                 * 
                 * \brief register the object of the map used by the game
                 * 
                 */
                void registerMapObjectsComponents();

                /**
                 * \fn void registerTimeComponent()
                 * 
                 * \brief register the time component used by the game
                 * 
                 */
                void registerTimeComponent();

                /**
                 * \fn voidregisterNetworkComponent()
                 * 
                 * \brief register the Network component used by the game
                 * 
                 */
                void registerNetworkComponent();

                /**
                 * \fn void addTimeSystem()
                 * 
                 * \brief add the time component used by the game
                 * 
                 */
                void addTimeSystem();

                /**
                 * \fn void initMap(JsonWrapper &wrapper)
                 * 
                 * \brief init the map used by the game
                 * 
                 * \param wrapper Wrapper used to get the map
                 * 
                 */
                void initMap(JsonWrapper &wrapper);

                /**
                 * \fn void startGame()
                 * 
                 * \brief start the game
                 * 
                 */
                void startGame();

                /**
                 * \fn void sendMapRequest(JsonWrapper &wrapper)
                 * 
                 * \brief send the request containing the map
                 * 
                 * \param wrapper Wrapper used to get the map
                 * 
                 */
                void sendMapRequest(JsonWrapper &wrapper);

                /**
                 * \fn void setupUpdateTimeSystem()
                 * 
                 * \brief setup the time component used by the game
                 * 
                 */
                void setupUpdateTimeSystem();

                Registry _r;
                std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> _roomBuffer;
        };
    }

#endif /* !GAME_HPP_ */
