/**
 * \file IElement.hpp
 *
 * \brief Interface for dynlibs
 */

#ifndef IELEMENT_HPP_
    #define IELEMENT_HPP_

    #include <memory>
    #include <iostream>
    #include "Registry.hpp"

    /**
     * \namespace rtype
     * 
     * \brief global namespace for the rtype project
     * 
     */
    namespace rtype {
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
                virtual ~IElement() = default;

                /**
                 * \fn virtual auto init(Registry &) -> void = 0
                 *
                 * \param Registery of the ECS
                 * 
                 * \brief Pure virtual init 
                 */
                virtual auto init(Registry &) -> void = 0;

                /**
                 * \fn virtual auto update(void) -> void = 0
                 * 
                 * \brief Pure virtual update 
                 */
                virtual auto update(void) -> void = 0;
        };
    }

#endif /* !IELEMENT_HPP_ */
