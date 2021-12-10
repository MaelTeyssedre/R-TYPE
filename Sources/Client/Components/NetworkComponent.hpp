/**
 * \file NetworkComponent.hpp
 * 
 * \brief file for the network component 
 */

#ifndef NETWORKCOMPONENT_HPP_
    #define NETWORKCOMPONENT_HPP_

    /**
     * \namespace rtype
     * 
     * \brief namespace for rtype project
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
             * \brief the network component
             *
             */
            typedef struct network_s {
                std::vector<std::vector<uint8_t>> request1; /*!< request 1 vector */
                std::vector<std::vector<uint8_t>> request2; /*!< request 2 vector */
                std::vector<std::vector<uint8_t>> request3; /*!< request 3 vector */
                std::vector<std::vector<uint8_t>> request4; /*!< request 4 vector */
                std::vector<std::vector<uint8_t>> request7; /*!< request 7 vector */
                std::vector<std::vector<uint8_t>> request8; /*!< request 8 vector */
                std::vector<std::vector<uint8_t>> request9; /*!< request 9 vector */
                std::vector<std::vector<uint8_t>> request10; /*!< request 10 vector */
                std::vector<std::vector<uint8_t>> request11; /*!< request 11 vector */
                std::vector<std::vector<uint8_t>> request12; /*!< request 12 vector */
                std::vector<std::vector<uint8_t>> request13; /*!< request 13 vector */
                std::vector<std::vector<uint8_t>> request14; /*!< request 14 vector */
                std::vector<std::vector<uint8_t>> request15; /*!< request 15 vector */
                std::vector<std::vector<uint8_t>> request16; /*!< request 16 vector */
                std::vector<std::vector<uint8_t>> request17; /*!< request 17 vector */
                std::vector<std::vector<uint8_t>> request22; /*!< request 22 vector */
                std::vector<std::vector<uint8_t>> sendRequest; /*!< send request vector */
            } network_t;
        }
    }

#endif /*!NETWORKCOMPONENT_HPP_ */
