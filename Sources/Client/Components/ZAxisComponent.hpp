/**
 * \file ZAxisComponent.hpp
 * 
 * \brief file for the ZAxis component 
 */

#ifndef ZAXISCOMPONENT_HPP_
    #define ZAXISCOMPONENT_HPP_

    /**
     * \namespace rtype
     * 
     * \brief namespace for rtype project
     * 
     */
    namespace rtype
    {
        /**
         * \namespace components
         * 
         * \brief namespace for ECS components
         * 
         */
        namespace components {
            /**
             * \struct zaxis_s
             * 
             * \brief the zaxis component
             *
             */
            typedef struct zaxis_t {
                size_t zAxis; /*!< Zaxis of the object */
            } zaxis_t;
        }   
    }
    

#endif /* !ZAXISCOMPONENT_HPP_ */
