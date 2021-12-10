/**
 * \file FireFrequence.hpp
 * 
 * \brief file for fire frequence component 
 */

#ifndef FIREFREQUENCE_HPP_
    #define FIREFREQUENCE_HPP_

    /**
     * \namespace rtype
     * 
     * \brief namespace for the R-Type
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
             * \struct fireFrequence_s
             * 
             * \brief fireFrequence component
             * 
             */
            typedef struct fireFrequence_s {
                size_t fireFrequence;
            } fireFrequence_t;
        }
    }

#endif /* !FIREFREQUENCE_HPP_ */
