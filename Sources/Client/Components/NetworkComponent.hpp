/**
 * \file NetworkComponent.hpp
 * 
 * \brief file for the network component 
 */
#ifndef NETWORKCOMPONENT_HPP_
    #define NETWORKCOMPONENT_HPP_

    /**
     * \namespace components
     * 
     * \brief namespace for ECS components
     * 
     */
    namespace components {
        /**
         * \struct network_s
         * 
         * \brief network component
         * 
         */
        typedef struct network_s {
            std::vector<std::vector<uint8_t>> request1;
            std::vector<std::vector<uint8_t>> request2;
            std::vector<std::vector<uint8_t>> request3;
            std::vector<std::vector<uint8_t>> request4;
            std::vector<std::vector<uint8_t>> request7;
            std::vector<std::vector<uint8_t>> request8;
            std::vector<std::vector<uint8_t>> request9;
            std::vector<std::vector<uint8_t>> request10;
            std::vector<std::vector<uint8_t>> request11;
            std::vector<std::vector<uint8_t>> request12;
            std::vector<std::vector<uint8_t>> request13;
            std::vector<std::vector<uint8_t>> request14;
            std::vector<std::vector<uint8_t>> request15;
        } network_t; 
    }

#endif /*!NETWORKCOMPONENT_HPP_ */