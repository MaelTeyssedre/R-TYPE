/**
 * \file NetworkComponent.hpp
 * 
 * \brief file for the client network component 
 */
#ifndef NETWORKCOMPONENT_HPP_
    #define NETWORKCOMPONENT_HPP_

    /**
     * \namespace rtype
     * 
     * \brief namespace forthe R-Type
     * 
     */
    namespace rtype {
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
            struct network_s {
                std::vector<std::vector<uint8_t>> request1; /*!< Request with opcode 1 */
                std::vector<std::vector<uint8_t>> request2; /*!< Request with opcode 2 */
                std::vector<std::vector<uint8_t>> request3; /*!< Request with opcode 3 */
                std::vector<std::vector<uint8_t>> request4; /*!< Request with opcode 4 */
                std::vector<std::vector<uint8_t>> request7; /*!< Request with opcode 7 */
                std::vector<std::vector<uint8_t>> request8; /*!< Request with opcode 8 */
                std::vector<std::vector<uint8_t>> request9; /*!< Request with opcode 9 */
                std::vector<std::vector<uint8_t>> request10; /*!< Request with opcode 10 */
                std::vector<std::vector<uint8_t>> request11; /*!< Request with opcode 11 */
                std::vector<std::vector<uint8_t>> request12; /*!< Request with opcode 12 */
                std::vector<std::vector<uint8_t>> request13; /*!< Request with opcode 13 */
                std::vector<std::vector<uint8_t>> request14; /*!< Request with opcode 14 */
                std::vector<std::vector<uint8_t>> request15; /*!< Request with opcode 15 */
                std::vector<std::vector<uint8_t>> sendRequest; /*!< list of sended requests */
            };
        }
    }

#endif /*!NETWORKCOMPONENT_HPP_ */
