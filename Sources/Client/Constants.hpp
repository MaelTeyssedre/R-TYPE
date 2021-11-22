/**
 * \file Constants.hpp
 * 
 * \brief file where constants are stocked 
 */

#ifndef CONSTANTS_HPP_
    #define CONSTANTS_HPP_

    #ifndef  VIEW_Y
        #define VIEW_Y 485.f
    #endif
    #ifndef VIEW_WIDTH
        #define VIEW_WIDTH 1720.f
    #endif
    #ifndef VIEW_HEIGHT
        #define VIEW_HEIGHT 970.f
    #endif

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

            /**
             * \enum TYPE
             * 
             * \brief enum for all type of the game
             */
            enum TYPE {
                SPRITE,
                TEXT,
                SOUND,
                MUSIC
            };
            
            /**
             * \enum KEY
             * 
             * \brief enum for all key used in the game
             */
            enum KEY {
                KEY_UP,
                KEY_DOWN,
                KEY_LEFT,
                KEY_RIGHT,
                KEY_ENTER,
                KEY_SPACE
            };
        }
    }

#endif /* !CONSTANTS_HPP_ */
