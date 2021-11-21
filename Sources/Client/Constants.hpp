/**
 * \file Constants.hpp
 * 
 * \brief file where constants are stocked 
 */

#ifndef CONSTANTS_HPP_
    #define CONSTANTS_HPP_

    /**
     * \namespace rtype
     * 
     * \brief global namespace for the rtype project
     * 
     */
    namespace rtype {
        /**
         * \namespace constants
         * 
         * \brief namespace for all constants
         * 
         */
        namespace constants {
            /**
             * \enum SCENE
             * 
             * \brief enum for all scenes of the game
             */
            enum SCENE {
                MAIN_MENU,
                PARAMS,
                GAME,
                LOADING_MENU
            };
        }
    }

#endif /* !CONSTANTS_HPP_ */
