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
     * \param velocyties Reference to an array of velocity component
     */
    void loggingSystem(Registry &r, SparseArray<component::position_s> &positions, SparseArray<component::velocity_s> &velocities);

    /**
     * \fn void controlSystem(Registry &r, SparseArray<component::position_s> &positions, SparseArray<component::velocity_s> &velocities, SparseArray<component::controllable_s> &controllable)
     * 
     * \brief System that handle update on the keyboard and update the related position component
     *
     * \param r Reference to the registry
     * \param positions Reference to an array of position component
     * \param velocoties Reference to an array of velocity component
     * \param controllable Reference to an array of controllable component
     */
    void controlSystem(Registry &r, SparseArray<component::position_s> &positions, SparseArray<component::velocity_s> &velocities, SparseArray<component::controllable_s> &controllable);

    /**
     * \fn void drawSystem(Registry &r, SparseArray<component::drawable_s> &drawables)
     * 
     * \brief System that draw the sprites of an entity on the screen
     *
     * \param r Reference to the registry
     * \param drawables Reference to an array of drawable component
     */
    void drawSystem(Registry &r, SparseArray<component::drawable_s> &drawables);

    /**
     * \fn void positionSystem(Registry &r, SparseArray<component::position_s> &positions, SparseArray<component::drawable_s> &sprite)
     * 
     * \brief System that update the position of the graphic element related to his coordonates
     *
     * \param r Reference to the registry
     * \param positions Reference to an array of position component
     * \param sprite Reference to an array of drawable component
     */
    void positionSystem(Registry &r, SparseArray<component::position_s> &positions, SparseArray<component::drawable_s> &sprite);

#endif
