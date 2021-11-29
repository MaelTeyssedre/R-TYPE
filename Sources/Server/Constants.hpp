/**
 * \file Constants.hpp
 * 
 * \brief file where constants are stocked 
 */

#ifndef CONSTANTS_HPP_
    #define CONSTANTS_HPP_

    #ifndef HELPER
        #define HELPER "USAGE:\n\t./rtype_server [PORT]\n"
    #endif
    
    #ifndef FRAME_RATE
        #define FRAME_RATE 244
    #endif

    #ifndef BUF_SIZE
        #define BUF_SIZE 8192
    #endif

    #ifndef BUF_READ_SIZE
        #define BUF_READ_SIZE 4
    #endif
    /**
     * \namespace rtype
     * 
     * \brief global namespace for the rtype project
     * 
     */
    namespace rtype {
        /**
         * \namespace constants
         * 
         * \brief namespace for all constants
         * 
         */
        namespace constants {
            
            enum RESERVED_ID {
                TIME_UPDATE = 0,
                NETWORK_UPDATE = 1,
            };
        }
    }

#endif /* !CONSTANTS_HPP_ */
