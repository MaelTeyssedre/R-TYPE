
#ifndef NETWORKCOMPONENT_HPP_
    #define NETWORKCOMPONENT_HPP_

    #include <vector>

    namespace rtype {
        namespace components {
            struct network_s {
                std::vector<std::vector<uint8_t>> request5;
                std::vector<std::vector<uint8_t>> request6;
                std::vector<std::vector<uint8_t>> request16;
                std::vector<std::vector<uint8_t>> request17;
                std::vector<std::vector<uint8_t>> request18;
                std::vector<std::vector<uint8_t>> request19;
            }; 
        }
    }

#endif /*!NETWORKCOMPONENT_HPP_ */
