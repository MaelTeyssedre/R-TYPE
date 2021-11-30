
#ifndef GAME_HPP_
    #define GAME_HPP_


    #include "Buffer.hpp"
    #include "Registry.hpp"
    #include "JsonWrapper.hpp"
    #include "NetworkComponent.hpp"
    #include <vector>

    namespace rtype {
        class Game {
            public:
                explicit Game(std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> &roomBuffer);
                virtual ~Game() = default;
                void run();
            private:
                void waitForStartingGame();
                void setupGame();
                void registerMapObjectsComponents();
                void registerTimeComponent();
                void registerNetworkComponent();
                void addTimeSystem();
                void initMap(JsonWrapper &wrapper);
                void startGame();
                void sendMapRequest(JsonWrapper &wrapper);
                void setupUpdateTimeSystem();
                Registry _r;
                std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> _roomBuffer;
        };
    }

#endif /* !GAME_HPP_ */
