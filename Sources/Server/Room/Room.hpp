
#ifndef ROOM_HPP_
    #define ROOM_HPP_


    #include "Buffer.hpp"
    #include "Registry.hpp"
    #include "JsonWrapper.hpp"
    #include "NetworkComponent.hpp"
    #include "PlayerData.hpp"
    #include <thread>
    #include <vector>
    #include <memory>

    namespace rtype {
        class Room {
            public:
                explicit Room(std::vector<PlayerData> *players);
                virtual ~Room() = default;
            private:
                static auto _runThread(std::vector<PlayerData>* players) -> void;
            private:
                std::unique_ptr<std::thread> _threadPtr;
        };
    }

#endif /* !ROOM_HPP_ */
