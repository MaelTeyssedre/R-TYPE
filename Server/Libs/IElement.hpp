/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** IElement
*/

#ifndef IELEMENT_HPP_
    #define IELEMENT_HPP_

    #include <memory>
    #include <iostream>

    class IElement { 
        public:
            ~IElement() = default;

            virtual void init(std::shared_ptr</*Registery*/int>) = 0;
            virtual void update(void) = 0;
    };

#endif /* !IELEMENT_HPP_ */
