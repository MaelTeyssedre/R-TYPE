/**
 * \file DawableComponent.hpp
 * 
 * \brief file for the drawable component 
 */

#ifndef ISDRAWABLECOMPONEMT_HPP_
    #define ISDRAWABLECOMPONEMT_HPP_

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
             * \struct drawable_s
             * 
             * \brief the drawable component
             *
             */
            struct drawable_s {
                bool drawable; /*!< is the object drawable */
            };
        }
    }

#endif /* !ISDRAWABLECOMPONEMT_HPP_ */
