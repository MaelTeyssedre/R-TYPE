
#ifndef REQUEST_HPP_
#define REQUEST_HPP_

namespace rtype {

    class Request {
    public:


        explicit Request() = default;


        virtual ~Request() = default;


        auto pack(std::vector<uint8_t> data)->size_t override;


        auto unpack()->std::vector<uint8_t> override;


        auto setId(size_t id) -> void override;


        auto getId(void)->size_t override;

        auto getData()->std::vector<uint8_t>;

    private:

        std::vector<uint8_t> _rawData; 
        size_t _packetSize;
        size_t _id;
    };
}

#endif /* !PACKET_HPP_ */