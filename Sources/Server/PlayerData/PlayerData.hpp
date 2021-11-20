/**
 * @file PlayerData.hpp
 * 
 * @brief file where the PlayerData class is defined 
 * 
 */

#ifndef PLAYERDATA_HPP_
    #define PLAYERDATA_HPP_

    #include <mutex>
    #include <vector>
    #include <memory>
    #include "Buffer.hpp"

    class PlayerData {
        public:
            /**
             * \fn explicit PlayerData() = default
             * 
             * \brief Construct a new Player Data object
             * 
             */
            explicit PlayerData() = default;
      
            explicit PlayerData(size_t id, std::shared_ptr<Buffer> buffIn, std::shared_ptr<Buffer> buffOut, std::shared_ptr<std::mutex> mutexIn,std::shared_ptr<std::mutex> mutexOut) 
                : _mutexIn(mutexIn), _mutexOut(mutexOut), _bufferIn(buffIn), _bufferOut(buffOut), _id(id) {}

            //PlayerData(PlayerData &) = delete;

            /**
             * \fn virtual ~PlayerData() = default
             * 
             * \brief Destroy the Player Data object
             * 
             */
            virtual ~PlayerData() = default;

            /**
             * \fn size_t getId(void) const
             * 
             * \brief Get the Id object
             * 
             * \return id of the player
             */
            size_t getId(void) const;
            // ! issue julian
            //PlayerData& operator=(PlayerData &PlayerData) = delete;
            std::shared_ptr<std::mutex> _mutexIn; /*! mutex that protect the Input buffer of the player */
            std::shared_ptr<std::mutex> _mutexOut; /*! mutex that protect the Input buffer of the player */
            std::shared_ptr<Buffer> _bufferIn; /*! Input buffer of the player */
            std::shared_ptr<Buffer> _bufferOut; /*! output buffer of the player */
        private:
            size_t _id; /*!  */
    };

#endif /* !PLAYERDATA_HPP_ */
