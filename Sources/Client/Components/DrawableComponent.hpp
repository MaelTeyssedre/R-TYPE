/**
 * \file DrawableComponent.hpp
 * 
 * \brief file for the drawable component 
 */
#ifndef ISDRAWABLECOMPONEMT_HPP_
    #define ISDRAWABLECOMPONEMT_HPP_

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
             * \struct drawable_s
             * 
             * \brief drawable component
             *
             */
            struct drawable_s {
                bool drawable; /*!< To check if it is drawable */
            };
        }
    }

#endif /* !ISDRAWABLECOMPONEMT_HPP_ */
