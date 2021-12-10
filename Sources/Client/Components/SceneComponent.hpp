/**
 * \file SceneComponent.hpp
 * 
 * \brief file for the Scene component 
 */

#ifndef SCENECOMPONENT_HPP_
    #define SCENECOMPONENT_HPP_

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
             * \struct scene_s
             * 
             * \brief the scene component
             *
             */
            typedef struct scene_s {
                rtype::constants::SCENE scene; /*!< Scene of the entity */
            } scene_t;
        }
    }

#endif /* !SCENECOMPONENT_HPP_ */
