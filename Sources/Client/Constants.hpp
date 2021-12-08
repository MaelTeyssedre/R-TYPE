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

    #ifndef HELPER
        #define HELPER "USAGE:\n\t./rtype_client [IP] [PORT]\n"
    #endif
    
    #ifndef FRAME_RATE
        #define FRAME_RATE 60
    #endif
    
    #ifndef WINDOW_SIZE_X
        #define WINDOW_SIZE_X 1720
    #endif
    
    #ifndef WINDOW_SIZE_Y
        #define WINDOW_SIZE_Y 970
    #endif
    
    #ifndef WINDOW_NAME
        #define WINDOW_NAME "R-TYPE"
    #endif

    #ifndef BUF_SIZE
        #define BUF_SIZE 8192
    #endif

    #ifndef BUF_READ_SIZE
        #define BUF_READ_SIZE 4
    #endif

    #ifndef BACKGROUND_SELECT_ROOM
        #define BACKGROUND_SELECT_ROOM "ressources/MainMenu.jpg"
    #endif

    #ifndef LOGO_SELECT_ROOM
        #define LOGO_SELECT_ROOM "ressources/logo.png"
    #endif

    #ifndef BUTTON_1_SELECT_ROOM
        #define BUTTON_1_SELECT_ROOM "ressources/room1.png"
    #endif

    #ifndef BUTTON_2_SELECT_ROOM
        #define BUTTON_2_SELECT_ROOM "ressources/room2.png"
    #endif

    #ifndef BUTTON_3_SELECT_ROOM
        #define BUTTON_3_SELECT_ROOM "ressources/room3.png"
    #endif

    #ifndef BUTTON_4_SELECT_ROOM
        #define BUTTON_4_SELECT_ROOM "ressources/room4.png"
    #endif

    #ifndef BUTTON_5_SELECT_ROOM
        #define BUTTON_5_SELECT_ROOM "ressources/room5.png"
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

            enum SCENE {
                MAIN_MENU = 0,
                LOADING_MENU = 1,
                WAITING_ROOM = 2,
                SELECT_ROOM = 3
            };


            enum TYPE {
                SPRITE = 0,
                TEXT = 1,
                SOUND = 2,
                MUSIC = 3
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
                TIME_UPDATE = 0,
                NETWORK_UPDATE = 1,
                GRAPH_UPDATE = 2
            };
        }
    }

#endif /* !CONSTANTS_HPP_ */
