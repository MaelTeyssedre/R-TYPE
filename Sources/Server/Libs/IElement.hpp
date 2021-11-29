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
                 * \fn virtual void init(Registery &) = 0
                 *
                 * \param Registery of the ECS
                 * 
                 * \brief Pure virtual init 
                 */
                virtual void init(Registry &) = 0;

                /**
                 * \fn virtual void update(void) = 0
                 * 
                 * \brief Pure virtual update 
                 */
                virtual void update(void) = 0;
        };
    }

#endif /* !IELEMENT_HPP_ */
