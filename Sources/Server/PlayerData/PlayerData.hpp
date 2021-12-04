/**
 * \file PlayerData.hpp
 * 
 * \brief file where the PlayerData class is defined 
 * 
 */

#ifndef PLAYERDATA_HPP_
    #define PLAYERDATA_HPP_

    #include <mutex>
    #include <memory>
    #include "Buffer.hpp"

    namespace rtype {
        class PlayerData {
            public:
                /**
                 * \fn explicit PlayerData() = default
                 * 
                 * \brief Construct a new Player Data object
                 * 
                 */
                explicit PlayerData() = default;


                explicit PlayerData(size_t id) 
                    : _mutexIn(new std::mutex()), _mutexOut(new std::mutex()), _bufferIn(new std::vector<std::vector<uint8_t>>{}), _bufferOut(new std::vector<std::vector<uint8_t>>), _id(id) {}

                /**
                 * \fn virtual ~PlayerData() = default
                 * 
                 * \brief Destroy the Player Data object
                 * 
                 */
                virtual ~PlayerData() = default;

            public:

                auto getId(void) const -> size_t;

                auto getBufIn() -> std::shared_ptr<std::vector<std::vector<uint8_t>>>;

                auto getBufOut() -> std::shared_ptr<std::vector<std::vector<uint8_t>>>;

            public:
                std::shared_ptr<std::mutex> _mutexIn; /*! mutex that protect the Input buffer of the player */
                std::shared_ptr<std::mutex> _mutexOut; /*! mutex that protect the Input buffer of the player */

            private:

                std::shared_ptr<std::vector<std::vector<uint8_t>>> _bufferIn; /*! Input buffer of the player */
                std::shared_ptr<std::vector<std::vector<uint8_t>>> _bufferOut; /*! output buffer of the player */
                size_t _id; /*! id of the client */
        };
    }

#endif /* !PLAYERDATA_HPP_ */
