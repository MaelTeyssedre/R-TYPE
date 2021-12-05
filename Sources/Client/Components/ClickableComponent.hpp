/**
 * \file ClickableComponent.hpp
 * 
 * \brief file for the clickable component 
 */

#ifndef CLICKABLECOMPONENT_HPP_
    #define CLICKABLECOMPONENT_HPP_

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
             * \struct clickable_s
             * 
             * \brief the clickable component
             *
             */
            struct clickable_s {
                bool isPressed; /*! is the object pressed */
                bool prevState; /*! was the object pressed */
                std::function<void(Registry &r, size_t index)> callbackClick; /*! The callback to do on click */
                std::function<void(Registry &r, size_t index)> callbackReleased; /*! The callback to do on realesed */
            };
        }   
    }
    
#endif /* !CLICKABLECOMPONENT_HPP_ */
