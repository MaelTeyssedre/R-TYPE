/**
 * \file Packet.hpp
 * 
 * \brief file where Packet class is defined
 * 
 */

#ifndef PACKET_HPP_
#define PACKET_HPP_

    #include "IPacket.hpp"

    namespace rtype {
        /**
         * \class Packet Packet.hpp 
         * 
         * \brief class that contain packet
         */
        class Packet : public IPacket {
            public:

                /**
                 * \fn explicit Packet() = default
                 *
                 * \brief ctor packet
                 */
                explicit Packet() = default;

                /**
                 * \fn virtual ~Packet() = default
                 *
                 * \brief dtor packet
                 */
                virtual ~Packet() = default;

                /**
                * \fn auto pack(std::vector<uint8_t> data) -> size_t override
                *
                * \brief pack data
                * 
                * \param data to pack
                * 
                * \return size readed
                */
                auto pack(std::vector<uint8_t> data) -> size_t  override;

                /**
                * \fn auto unpack() -> std::vector<uint8_t> override
                *
                * \brief unpack the data
                * 
                * \return vector of data
                */
                auto unpack() -> std::vector<uint8_t> override;

                /**
                 * \fn auto setId(size_t id) -> void override
                 * 
                 * \brief set a packet id
                 * 
                 * \param the id we want to set
                 */
                auto setId(size_t id) -> void override;

                /**
                 * \fn auto getId(void) -> size_t override
                 * 
                 * \brief get a packet id
                 * 
                 * \return the id we want to get
                 */
                auto getId(void) -> size_t override;

            private:

                std::vector<uint8_t> _rawData; /*! data */
                size_t _packetSize; /*! size of the packet */
                size_t _id;
        };
    }

#endif /* !PACKET_HPP_ */
