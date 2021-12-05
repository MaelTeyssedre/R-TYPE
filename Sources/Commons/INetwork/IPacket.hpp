/**
 * \file IPacket.hpp
 * 
 * \brief file where IPacket class is defined
 * 
 */
#ifndef IPACKET_HPP_
  #define IPACKET_HPP_

  #include <vector>
  #include <memory>
  #include <iostream>
  #include <any>

  /**
   * \class IPacket.hpp
   * 
   * \brief file where inteface IPacket class is defined
   * 
   */
  class IPacket {
        public:

        /**
         * \fn virtual ~IPacket() = default;
         *
         * \brief Destroy the IPacket object
         */
        virtual ~IPacket() = default;

        /**
         * \fn virtual auto pack(std::vector<uint8_t> data) -> size_t = 0
         * 
         * \brief Serialize data
         * 
         * \param data data to serialize
         * \param size size of data to serialize
         * 
         * \return size of data serialized
         */
        virtual auto pack(std::vector<uint8_t> data) -> size_t = 0;

        /**
         * \fn virtual auto unpack() -> std::vector<uint8_t> = 0
         * 
         * \brief Unserialize data
         * 
         * \return the unserialized data
         */
        virtual auto unpack() -> std::vector<uint8_t> = 0;

        /**
         * \fn virtual auto setId(size_t id) -> void = 0
         * 
         * \brief set a packet id
         * 
         * \param the id we want to set
         */
        virtual auto setId(size_t id) -> void = 0;

        /**
         * \fn virtual auto getId(void) -> size_t = 0
         * 
         * \brief get a packet id
         * 
         * \return the id we want to get
         */
        virtual auto getId(void) -> size_t = 0;

  };

#endif /* !IPACKET_HPP_ */
