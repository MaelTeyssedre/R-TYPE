/**
 * \file SceneComponent.hpp
 * 
 * \brief file for the scene component 
 */

#ifndef SCENECOMPONENT_HPP_
    #define SCENECOMPONENT_HPP_

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
             * \struct scene_s
             * 
             * \brief scene component
             *
             */
            struct scene_s {
                rtype::constants::SCENE scene; /*!< The scene */
            };
        }
    }

#endif /* !SCENECOMPONENT_HPP_ */
