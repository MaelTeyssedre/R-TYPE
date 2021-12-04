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
         * \fn virtual size_t pack(std::vector<uint8_t> &data) = 0;
         * 
         * \brief Serialize data
         * 
         * \param data data to serialize
         * \param size size of data to serialize
         * 
         * \return size of data serialized
         */
        virtual size_t pack(std::vector<uint8_t> data) = 0;

        virtual std::vector<uint8_t> unpack() = 0;

        virtual void setId(size_t id) = 0;

        virtual size_t getId(void) = 0;

  };

#endif /* !IPACKET_HPP_ */
