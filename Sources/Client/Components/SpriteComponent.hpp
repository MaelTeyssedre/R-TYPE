/**
 * \file SpriteComponent.hpp
 * 
 * \brief file for the Sprite component 
 */

#ifndef SPRITECOMPONENT_HPP_
    #define SPRITECOMPONENT_HPP_

    #include <string>

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
             * \struct sprite_s
             * 
             * \brief the sprite component
             *
             */
            typedef struct sprite_s {
                float scaleX; /*!< Scale X of the sprite */
                float scaleY; /*!< Scale Y of the sprite */
                int rectX; /*!< Position X of the texture */
                int rectY; /*!< Position Y of the texture */
                int rectWidth; /*!< Width of the texture */
                int rectHeight; /*!< Height of the texture */
                std::string path; /*!< Path of the texture */
            } sprite_t;
        }   
    }
    
#endif /* !SPRITECOMPONENT_HPP_ */
