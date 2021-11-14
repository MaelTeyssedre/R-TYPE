/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** IElement
*/

/**
 * \file IElement.hpp
 *
 * \brief Interface for dynlibs
 */

#ifndef IELEMENT_HPP_
    #define IELEMENT_HPP_

    #include <memory>
    #include <iostream>

    /**
     * \class IElement IElement.hpp
     * 
     * \brief Interface for dynlibs
     */
    class IElement { 
        public:
            /**
             * \fn ~IElement() = default
             * 
             * \brief Default dtor
             */
            ~IElement() = default;

            /**
             * \fn virtual void init(std::shared_ptr<Registery>) = 0
             *
             * \param Registery of the ECS
             * 
             * \brief Pure virtual init 
             */
            virtual void init(std::shared_ptr</*Registery*/int>) = 0;

            /**
             * \fn virtual void update(void) = 0
             * 
             * \brief Pure virtual update 
             */
            virtual void update(void) = 0;
    };

#endif /* !IELEMENT_HPP_ */
