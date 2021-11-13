#ifndef COMPONENTS_HPP_
    #define COMPONENTS_HPP_

    #include <SFML/Graphics.hpp>
    #include "Registry.hpp"

    /*!
     * \brief namespace for components
     */
    namespace component
    {
        /*!
        * \brief position component
        *
        * \param x x position of the element
        * \param y y position of the element
        */
        struct position_s {
            int x;
            int y;
        };

        /*!
        * \brief velocoty component
        *
        * \param x x velocity of the element
        * \param y y velocoty of the element
        */
        struct velocity_s {
            int vx;
            int vy;
        };

        /*!
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

        /*!
        * \brief controllable component
        *
        * \param isControllable boolean true if the element if controllable, false otherwise
        */
        struct controllable_s {
            bool isControllable;
        };
    }

#endif /* !COMPONENTS_HPP_ */
