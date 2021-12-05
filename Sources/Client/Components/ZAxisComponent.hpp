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
            struct zaxis_s {
                size_t zAxis; /*!< Zaxis of the object */
            };
        }   
    }
    

#endif /* !ZAXISCOMPONENT_HPP_ */
