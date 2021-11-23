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

    #ifndef RESERVED_TIME_INDEX
        #define RESERVED_TIME_INDEX 0
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

            enum TYPE {
                SPRITE,
                TEXT,
                SOUND,
                MUSIC
            };

            enum KEY {
                KEY_UP,
                KEY_DOWN,
                KEY_LEFT,
                KEY_RIGHT,
                KEY_ENTER,
                KEY_SPACE
            };

            enum ENTITY_TYPE {
                PLAYER,
                MONSTER,
                BOSS,
                WALL,
                PROJECTILE
            };
        }
    }

#endif /* !CONSTANTS_HPP_ */
