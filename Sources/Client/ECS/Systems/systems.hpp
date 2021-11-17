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
    void loggingSystem(Registry &r, SparseArray<rtype::component::position_s> &positions, SparseArray<rtype::component::velocity_s> &velocities) {
        for (size_t i = 0; i < positions.size() && i < velocities.size(); i++) {
            const std::optional<rtype::component::position_s> &pos = positions[i];
            const std::optional<rtype::component::velocity_s> &vel = velocities[i];
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
    void controlSystem(Registry &r, SparseArray<rtype::component::position_s> &positions, SparseArray<rtype::component::velocity_s> &velocities, SparseArray<rtype::component::controllable_s> &controllable, SparseArray<rtype::component::current_scene_s> &current_scenes, SparseArray<rtype::component::entity_scene_s> &entity_scenes) {
        for (size_t i = 0; i < positions.size() && i < velocities.size() && i < controllable.size() && i < current_scenes.size() && i < entity_scenes.size(); i++) {
            std::optional<rtype::component::position_s> &pos = positions[i];
            std::optional<rtype::component::velocity_s> &vel = velocities[i];
            std::optional<rtype::component::controllable_s> &ctrl = controllable[i];
            std::optional<rtype::component::current_scene_s> &current_scene = current_scenes[i];
            std::optional<rtype::component::entity_scene_s> &entity_scene = entity_scenes[i];
            if (ctrl && ctrl.value().isControllable && pos && vel && current_scene && entity_scene) {
                if (current_scene.value().scene == entity_scene.value().scene) {
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
    }

    /**
     * \fn void drawSystem(Registry &r, SparseArray<component::drawable_s> &drawables)
     * 
     * \brief System that draw the sprites of an entity on the screen
     *
     * \param r Reference to the registry
     * \param drawables Reference to an array of drawable component
     */
    void drawSystem(Registry &r, SparseArray<rtype::component::drawable_s> &drawables, SparseArray<rtype::component::current_scene_s> &current_scenes, SparseArray<rtype::component::entity_scene_s> &entity_scenes) {
        for (size_t i = 0; i < drawables.size() && i < current_scenes.size() && i < entity_scenes.size(); i++) {
            std::optional<rtype::component::drawable_s> &draw = drawables[i];
            std::optional<rtype::component::current_scene_s> &current_scene = current_scenes[i];
            std::optional<rtype::component::entity_scene_s> &entity_scene = entity_scenes[i];
            if (draw && current_scene && entity_scene)
                if (current_scene.value().scene == entity_scene.value().scene)
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
    void positionSystem(Registry &r, SparseArray<rtype::component::position_s> &positions, SparseArray<rtype::component::drawable_s> &sprite, SparseArray<rtype::component::current_scene_s> &current_scenes, SparseArray<rtype::component::entity_scene_s> &entity_scenes) {
        for (size_t i = 0; i < positions.size() && i < sprite.size() && current_scenes.size() && entity_scenes.size(); i++) {
            std::optional<rtype::component::drawable_s> &sprt = sprite[i];
            std::optional<rtype::component::position_s> &pos = positions[i];
            std::optional<rtype::component::current_scene_s> &current_scene = current_scenes[i];
            std::optional<rtype::component::entity_scene_s> &entity_scene = entity_scenes[i];
            if (pos && sprt && current_scene && entity_scene) {
                if (current_scene.value().scene == entity_scene.value().scene) {
                    sprt.value().sprite.setPosition((float)pos.value().x, (float)pos.value().y);
                    if (pos.value().x > 2000)
                        pos.value().x = -300;
                }
            }
        }
    }

    /**
     * \fn clickSystem(Registry &r, SparseArray<rtype::component::position_s> &positions, SparseArray<rtype::component::size_s> &sizes, SparseArray<rtype::component::callback_s> &callbacks, SparseArray<rtype::component::drawable_s> &window)
     * 
     * \brief System that callback a function if the entity is clicked
     *
     * \param r Reference to the registry
     * \param positions Reference to an array of position component
     * \param sizes Reference to an array of size component
     * \param callbacks Reference to an array of callback component
     * \param window Reference to an array of window component
     */
    void clickSystem(Registry &r, SparseArray<rtype::component::position_s> &positions, SparseArray<rtype::component::size_s> &sizes, SparseArray<rtype::component::callback_s> &callbacks, SparseArray<rtype::component::window_s> &window, SparseArray<rtype::component::current_scene_s> &current_scenes, SparseArray<rtype::component::entity_scene_s> &entity_scenes) {
        for (size_t i = 0; i < positions.size() && i < sizes.size() && i < callbacks.size() && i < window.size(); i++) {
            std::optional<rtype::component::position_s> &pos = positions[i];
            std::optional<rtype::component::size_s> &size = sizes[i];
            std::optional<rtype::component::callback_s> &callback = callbacks[i];
            std::optional<rtype::component::window_s> &win = window[i];
            std::optional<rtype::component::current_scene_s> &current_scene = current_scenes[i];
            std::optional<rtype::component::entity_scene_s> &entity_scene = entity_scenes[i];
            if (pos && size && callback && win && current_scene && entity_scene) {
                if (current_scene.value().scene == entity_scene.value().scene) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        sf::Vector2i position = sf::Mouse::getPosition(*win.value().window);
                        if (position.x > pos.value().x && position.x < pos.value().x + size.value().width
                        && position.y > pos.value().y && position.y < pos.value().y + size.value().heigth) {
                            callback.value().callback(r);
                        }
                    }
                }
            }
        }
    }


#endif
