/**
 * \file CurrentSceneComponent.hpp
 * 
 * \brief file for the currentScene component 
 */

#ifndef CURRENTSCENECOMPONENT_HPP_
    #define CURRENTSCENECOMPONENT_HPP_

    #include "Constants.hpp"

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
             * \struct currentScene_s
             * 
             * \brief the currentScene component
             *
             */
            typedef struct currentScene_s {
                constants::SCENE scene; /*!< scene */
                bool isLoaded; /*!< is the scene loaded */
            } currentScene_t;
        }
    }

#endif /* !CURRENTSCENECOMPONENT_HPP_ */
