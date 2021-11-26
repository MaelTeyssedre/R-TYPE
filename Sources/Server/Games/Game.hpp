
#ifndef GAME_HPP_
    #define GAME_HPP_


    #include <memory>
    #include "Buffer.hpp"
    #include "Registry.hpp"
    #include <vector>
    #include <thread>
    #include <chrono>

    class Game {
        public:
            explicit Game(std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> &roomBuffer);
            virtual ~Game() = default;
            void run();
        private:
            void waitPlayer();
            void startGame();
            Registry _r;
            std::shared_ptr<std::vector<std::pair<Buffer, Buffer>>> _roomBuffer;
    };

#endif /* !GAME_HPP_ */
