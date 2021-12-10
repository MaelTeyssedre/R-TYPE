/**
 * \file request.hpp
 * 
 * \brief file for request component 
 */

#ifndef REQUEST_HPP_
    #define REQUEST_HPP_

    #include <vector>

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
            typedef struct request_s {
                std::vector<std::vector<uint8_t>> request5; /*! Request with opcode 5 */
                std::vector<std::vector<uint8_t>> request6; /*! Request with opcode 6 */
                std::vector<std::vector<uint8_t>> request16; /*! Request with opcode 16 */
                std::vector<std::vector<uint8_t>> request17; /*! Request with opcode 17 */
                std::vector<std::vector<uint8_t>> request18; /*! Request with opcode 18 */
                std::vector<std::vector<uint8_t>> request19; /*! Request with opcode 19 */
                std::vector<std::vector<uint8_t>> requestSend; /*! Request with opcode 19 */
            } request_t;
        }
    }

#endif /*!REQUEST_HPP_ */
