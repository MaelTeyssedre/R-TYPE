/**
 * \file systems.hpp
 *
 * \brief file where exemples systems are defined
 */

#ifndef SYSTEMS_HPP_
    #define SYSTEMS_HPP_

    #include "Registry.hpp"
    #include "components.hpp"

    /**
     * \fn void loggingSystem(Registry &r, SparseArray<component::position_s> &positions, SparseArray<component::velocity_s> &velocities)
     * 
     * \brief System for logging in real-time the values of positions and velocities components
     *
     * \param r Reference to the registry
     * \param positions Reference to an array of position component
     * \param velocities Reference to an array of velocity component
     */
    void loggingSystem(Registry &r, SparseArray<component::position_s> &positions, SparseArray<component::velocity_s> &velocities) {
        for (size_t i = 0; i < positions.size() && i < velocities.size(); i++) {
            const std::optional<component::position_s> &pos = positions[i];
            const std::optional<component::velocity_s> &vel = velocities[i];
            //if (pos && vel)
                //std::cerr << i << ": Position = { " << pos.value().x << ", " << pos.value().y << " }, Velocity = { " << vel.value().vx << ", " << vel.value().vy << " }" << std::endl;
        }
    }

    /**
     * \fn void controlSystem(Registry &r, SparseArray<component::position_s> &positions, SparseArray<component::velocity_s> &velocities, SparseArray<component::controllable_s> &controllable)
     * 
     * \brief System that handle update on the keyboard and update the related position component
     *
     * \param r Reference to the registry
     * \param positions Reference to an array of position component
     * \param velocities Reference to an array of velocity component
     * \param controllable Reference to an array of controllable component
     */
    void controlSystem(Registry &r, SparseArray<component::position_s> &positions, SparseArray<component::velocity_s> &velocities, SparseArray<component::controllable_s> &controllable) {
        for (size_t i = 0; i < positions.size() && i < velocities.size() && i < controllable.size(); i++) {
            std::optional<component::position_s> &pos = positions[i];
            std::optional<component::velocity_s> &vel = velocities[i];
            std::optional<component::controllable_s> &ctrl = controllable[i];
            if (ctrl && ctrl.value().isControllable && pos && vel) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    pos.value().x -= vel.value().vx;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    pos.value().x += vel.value().vx;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    pos.value().y += vel.value().vy;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    pos.value().y -= vel.value().vy;
            }
        }
    }

    /**
     * \fn void drawSystem(Registry &r, SparseArray<component::drawable_s> &drawables)
     * 
     * \brief System that draw the sprites of an entity on the screen
     *
     * \param r Reference to the registry
     * \param drawables Reference to an array of drawable component
     */
    void drawSystem(Registry &r, SparseArray<component::drawable_s> &drawables) {
        for (size_t i = 0; i < drawables.size(); i++) {
            std::optional<component::drawable_s> &draw = drawables[i];
            if (draw)
                draw.value().window->draw(draw.value().sprite);
        }
    }

    /**
     * \fn void positionSystem(Registry &r, SparseArray<component::position_s> &positions, SparseArray<component::drawable_s> &sprite)
     * 
     * \brief System that update the position of the graphic element related to his coordonates
     *
     * \param r Reference to the registry
     * \param positions Reference to an array of position component
     * \param sprite Reference to an array of drawable component
     */
    void positionSystem(Registry &r, SparseArray<component::position_s> &positions, SparseArray<component::drawable_s> &sprite) {
        for (size_t i = 0; i < positions.size() && i < sprite.size(); i++) {
            std::optional<component::drawable_s> &sprt = sprite[i];
            std::optional<component::position_s> &pos = positions[i];
            if (pos && sprt) {
                sprt.value().sprite.setPosition((float)pos.value().x, (float)pos.value().y);
                if (pos.value().x > 2000)
                    pos.value().x = -300;
            }
        }
    }

    /**
     * \fn void clickSystem(Registry &r, SparseArray<component::position_s> &positions, SparseArray<component::size_s> &sizes, SparseArray<component::callback_s> &callbacks)
     * 
     * \brief System that callback a function if the entity is clicked
     *
     * \param r Reference to the registry
     * \param positions Reference to an array of position component
     * \param sizes Reference to an array of size component
     * \param callbacks Reference to an array of callback component
     */
    void clickSystem(Registry &r, SparseArray<component::position_s> &positions, SparseArray<component::size_s> &sizes, SparseArray<component::callback_s> &callbacks, SparseArray<component::drawable_s> &window) {
        for (size_t i = 0; i < positions.size() && i < sizes.size() && i < callbacks.size() && i < window.size(); i++) {
            std::optional<component::position_s> &pos = positions[i];
            std::optional<component::size_s> &size = sizes[i];
            std::optional<component::callback_s> &callback = callbacks[i];
            std::optional<component::drawable_s> &win = window[i];
            if (pos && size && callback && win) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2i position = sf::Mouse::getPosition(*win.value().window);
                    if (position.x > pos.value().x && position.x < pos.value().x + size.value().width
                    && position.y > pos.value().y && position.y < pos.value().y + size.value().heigth)
                        //std::cout << "MouseX = " << position.y << " Pos = " << pos.value().y << " Size = " << pos.value().y + size.value().y << std::endl;
                        //std::cout << "Clicked" << std::endl;
                        callback.value().Callback();
                }
            }
        }
    }

#endif
