/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** components
*/

#ifndef COMPONENTS_HPP_
#define COMPONENTS_HPP_

#include <SFML/Graphics.hpp>
#include "Registry.hpp"

namespace component
{
    struct position_s {
        int x;
        int y;
    };

    struct velocity_s {
        int x;
        int y;
    };

    struct drawable_s {
        sf::Texture texture;
        sf::Sprite sprite;
    };
}

#endif /* !COMPONENTS_HPP_ */
