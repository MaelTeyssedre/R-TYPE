/**
 * \file ColorComponent.hpp
 * 
 * \brief file for the color component 
 */

#ifndef COLORCOMPONENT_HPP_
    #define COLORCOMPONENT_HPP_

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
             * \struct color_s
             * 
             * \brief the color component
             *
             */
            struct color_s {
                int colorRed; /*! Red color */
                int colorGreen; /*! Green color */
                int colorBlue; /*! Blue color */
                int colorAlpha; /*! Alpha color */
            };
        }   
    }

#endif /* !COLORCOMPONENT_HPP_ */
