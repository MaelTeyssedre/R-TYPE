/**
 * \file BasicMonster.hpp
 *
 * \brief file where BasicMonster class is defined, compile to make .so/.dll
 */
#ifndef BASICMONSTER_HPP_
    #define BASICMONSTER_HPP_

    #include "AMonster.hpp"
    #include "Registry.hpp"
    #include "FireFrequence.hpp"
    #include "HealPoint.hpp"
    #include "Loot.hpp"
    #include "Position.hpp"
    #include "Velocity.hpp"
    #include "Weapon.hpp"

    namespace rtype {
        /**
         * \class BasicMonster BasicMonster.hpp
         * 
         * \brief Class that contain a monster in a .so/.dll
         */
        class BasicMonster : public AMonster {
            public:
            
                /**
                 * \fn BasicMonster() = default
                 * 
                 * \brief Default ctor
                 */
                explicit BasicMonster();

                /**
                 * \fn BasicMonster(const BasicMonster&) = default
                 * 
                 * \brief Default copy ctor
                 */
                explicit BasicMonster(const BasicMonster&) = default;

                /**
                 * \fn ~BasicMonster() = default
                 * 
                 * \brief Default dtor
                 */
                virtual ~BasicMonster() = default;

                /**
                 * \fn BasicMonster& operator=(const BasicMonster &other) = default
                 * 
                 * \brief Default operator= overload
                 */
                BasicMonster& operator=(const BasicMonster &other) = default;

                /**
                 * \fn void init(Registery &) override
                 *
                 * \param Registery of the ECS
                 * 
                 * \brief Override init of the class
                 */
                void init(Registry &r) override;

                /**
                 * \fn void update(void) override
                 * 
                 * \brief Override update of the class
                 */
                void update(void) override;

        };
    }

#endif /* !BASICMONSTER_HPP_ */
