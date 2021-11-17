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
            if (pos && vel)
                std::cerr << i << ": Position = { " << pos.value().x << ", " << pos.value().y << " }, Velocity = { " << vel.value().vx << ", " << vel.value().vy << " }" << std::endl;
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

    void moveMonsterSystem(Registry &r, SparseArray<component::position_s> &positions, SparseArray<component::velocity_s> &velocity)
    {
        for (size_t i = 0; i < positions.size(); i++) {
            std::optional<component::velocity_s> &vel = velocity[i];
            std::optional<component::position_s> &pos = positions[i];
            if (vel && pos) {
                pos.value().x -= vel.value().vx;
                pos.value().y -= vel.value().vy;
            }
        }
    }

    void monsterLoseHealthSystem(Registry &r, SparseArray<component::healPoint_s> &healPoint, SparseArray<component::weapon_s> &weapon)
    {
        for (size_t i = 0; i < healPoint.size(); i++) {
            std::optional<component::healPoint_s> &hp = healPoint[i];
            std::optional<component::weapon_s> &damage = weapon[i];
            if (hp && damage)
                hp.value().healPoint -= damage.value().weaponType;
        }
    }
#endif
