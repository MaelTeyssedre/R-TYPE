/**
 * \file components.hpp
 *
 * \brief file where all exemple components are defined
 */

#ifndef COMPONENTS_HPP_
    #define COMPONENTS_HPP_

    #include <SFML/Graphics.hpp>
    #include "Registry.hpp"
    #include "Constants.hpp"

    /**
     * \namespace component
     * 
     * \brief namespace for components
     */

    namespace rtype
    {
        namespace component
        {
            /**
             * \struct position_s components.hpp
             * 
             * \brief position component
             *
             * \param x x position of the element
             * \param y y position of the element
             */
            struct position_s {
                int x;
                int y;
            };

            /**
             * \struct position_s components.hpp
             * 
             * \brief velocity component
             *
             * \param x x velocity of the element
             * \param y y velocity of the element
             */
            struct velocity_s {
                int vx;
                int vy;
            };

            /**
             * \struct position_s components.hpp
             * 
             * \brief drawable component
             *
             * \param texture texture of the element
             * \param sprite sprite of the element
             * \param window RenderWindow where the component has to be draw
             */
            struct drawable_s {
                sf::Texture texture;
                sf::Sprite sprite;
                sf::RenderWindow *window = nullptr;
            };

            /**
             * \struct position_s components.hpp
             * 
             * \brief controllable component
             *
             * \param isControllable boolean true if the element if controllable, false otherwise
             */
            struct controllable_s {
                bool isControllable;
            };

            /**
             * \struct size_s components.hpp
             * 
             * \brief size component
             *
             * \param width width size of the element
             * \param heigth heigth size of the element
             */
            struct size_s {
                int width;
                int heigth;
            };

            /**
             * \struct callback_s components.hpp
             * 
             * \brief callback component
             *
             * \param callback callback of an action
             */
            struct callback_s {
                std::function<void(Registry &)> callback;
            };

            /**
             * \struct window_s components.hpp
             * 
             * \brief window component
             *
             * \param window window of the program
             */
            struct window_s {
                sf::RenderWindow *window = nullptr;
            };

            /**
             * \struct current_scene_s components.hpp
             * 
             * \brief current scene component 
             *
             * \param scene current scene display
             */
            struct current_scene_s {
                rtype::constants::SCENE scene;
            };

            /**
             * \struct entity_scene_s components.hpp
             * 
             * \brief scene component of an entity
             *
             * \param scene scene of an entity
             */
            struct entity_scene_s {
                rtype::constants::SCENE scene;
            };
        }
    }

#endif /* !COMPONENTS_HPP_ */
