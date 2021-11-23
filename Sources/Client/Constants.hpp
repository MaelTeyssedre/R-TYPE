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

    #ifndef HELPER
        #define HELPER "USAGE:\n\t./rtype_client [IP] [PORT]\n"
    #endif
    
    #ifndef FRAME_RATE
        #define FRAME_RATE 244
    #endif
    
    #ifndef WINDOW_SIZE_X
        #define WINDOW_SIZE_X 1720
    #endif
    
    #ifndef WINDOW_SIZE_Y
        #define WINDOW_SIZE_Y 970
    #endif
    
    #ifndef WINDOW_NAME
        #define WINDOW_NAME "RPR-TYPE"
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

            enum EVENT {
                KEY_UP,
                KEY_DOWN,
                KEY_LEFT,
                KEY_RIGHT,
                KEY_ENTER,
                KEY_SPACE,
                MOUSE_POS_X,
                MOUSE_POS_Y,
                MOUSE_RIGHT_CLICK,
                MOUSE_LEFT_CLICK
            };

            enum WEAPON_TYPE {
                WEAPON_1,
                WEAPON_2,
                WEAPON_3
            };

            enum ENTITY_TYPE {
                PLAYER,
                MONSTER,
                BOSS,
                WALL,
                PROJECTILE
            };
            
            enum RESERVED_ID {
                TIME_UPDATE,
                NETWORK_UPDATE,
                EVENT_UPDATE,
                GRAPH_UPDATE
            };
        }
    }

#endif /* !CONSTANTS_HPP_ */
