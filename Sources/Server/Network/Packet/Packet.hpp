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
                * \fn size_t pack(std::vector<uint8_t> &data)
                *
                * \brief pack data
                * 
                * \param data to pack
                * 
                * \return size readed
                */
                size_t pack(std::vector<uint8_t> &data) override;

                /**
                * \fn std::shared_ptr<std::vector<uint8_t>> unpack()
                *
                * \brief unpack the data
                * 
                * \return vector of data
                */
                std::vector<uint8_t> unpack() override;     

                void setId(size_t id) override;

                size_t getId() const;

                std::vector<uint8_t> getData();   

            private:

                std::vector<uint8_t> _rawData; /*! data */
                size_t _packetSize; /*! size of the packet */
                size_t _id;
        };
    }

#endif /* !PACKET_HPP_ */
