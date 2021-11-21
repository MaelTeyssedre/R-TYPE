/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Constants
*/

#ifndef CONSTANTS_HPP_
    #define CONSTANTS_HPP_

    namespace rtype {
        namespace constants {

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

        }
    }

#endif /* !CONSTANTS_HPP_ */
