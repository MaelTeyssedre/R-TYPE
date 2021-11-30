/**
 * \file CurrentSceneComponent.hpp
 * 
 * \brief file for the current scene component 
 */
#ifndef CURRENTSCENECOMPONENT_HPP_
    #define CURRENTSCENECOMPONENT_HPP_

    #include "Constants.hpp"

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
             * \struct currentScene_s
             * 
             * \brief current scene component
             *
             */
            struct currentScene_s {
                constants::SCENE scene; /*!< the current scene */
                bool isLoaded; /*!< To check if the scene is loaded */
            };
        }
    }

#endif /* !CURRENTSCENECOMPONENT_HPP_ */
