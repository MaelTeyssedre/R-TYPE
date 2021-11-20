/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** AMonster
*/

#ifndef AMONSTER_HPP_
    #define AMONSTER_HPP_

    #include "IElement.hpp"
    #include "component.hpp"

    class AMonster : public IElement {
        public:
            explicit AMonster();
            virtual ~AMonster() = default;
        
            /**
             * \fn virtual void init(Registery &) = 0
             *
             * \param r of the ECS
             * 
             * \brief Pure virtual init 
             */
            virtual void init(Registry &r) = 0;

            /**
             * \fn virtual void update(void) = 0
             * 
             * \brief Pure virtual update 
             */
            virtual void update(void) = 0;

            virtual void setHealPoint(size_t healPoint) = 0;
            virtual rtype::healPoint_s getHealPoint() const = 0;
            virtual void setFireFrequence(size_t firefrequence) = 0;
            virtual rtype::fireFrequence_s getFireFrequence() const = 0;
            virtual void setWeapon(size_t weapon) = 0;
            virtual rtype::weapon_s getWeapon() const = 0;
            virtual void setVelocity(std::pair<int, int> vel) = 0;
            virtual rtype::velocity_s getVelocity() const = 0;
            virtual void setPosition(std::pair<int, int> pos) = 0;
            virtual rtype::position_s getPosition() const = 0;
            virtual void setName(std::string &name) = 0;
            virtual std::string getName() = 0;
        public:

    };

#endif /* !AMONSTER_HPP_ */
