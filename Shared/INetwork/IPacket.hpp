/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** IPacket
*/

#ifndef IPACKET_HPP_
  #define IPACKET_HPP_

  #include <vector>
  #include <memory>
  #include <iostream>
  #include <any>

  class IPacket {
      public:

          /**
           * @brief Destroy the IPacket object
           * 
           */
          virtual ~IPacket() = default;

          /**
           * @brief Serialize data
           * 
           * @param data data to serialize
           * @param size size of data to serialize
           * @return size of data serialized
           */
          virtual size_t pack(std::vector<uint8_t> &data) = 0;

          /**
           * @brief deserialize packet
           * 
           * @param size of packet to deserialize
           * @return data deserialised
           */
          virtual std::shared_ptr<std::vector<uint8_t>> unpack() = 0;
  };

#endif /* !IPACKET_HPP_ */