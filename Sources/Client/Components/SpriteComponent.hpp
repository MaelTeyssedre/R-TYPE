/**
 * \file Sprite.hpp
 * 
 * \brief file for the sprite component 
 */

#ifndef SPRITECOMPONENT_HPP_
    #define SPRITECOMPONENT_HPP_

    #include <string>

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
             * \struct sprite_s
             * 
             * \brief the sprite component
             *
             */
            struct sprite_s {
                float scaleX; /*!< The scale of the width of the sprite */
                float scaleY; /*!< The scale of the heigth of the sprite */
                int rectX; /*!< The X postion of the rectangle of the sprite */
                int rectY; /*!< The Y postion of the rectangle of the sprite */
                int rectWidth; /*!< The width of the rectangle of the sprite */
                int rectHeight; /*!< The heigth of the rectangle of the sprite */
                std::string path; /*!< Path of the source of the sprite */
            };
        }   
    }
    

#endif /* !SPRITECOMPONENT_HPP_ */
