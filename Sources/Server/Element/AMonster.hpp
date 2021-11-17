/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** AMonster
*/

#ifndef AMONSTER_HPP_
    #define AMONSTER_HPP_

    #include "IElement.hpp"

    class AMonster : public IElement {
        public:

                AMonster() = default;
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

                // void setHealPoint(component::healPoint_s &healPoint);
                // component::healPoint_s getHealPoint() const;
                // void setFireFrequence(component::fireFrequence_s &healPoint);
                // component::fireFrequence_s getFireFrequence() const;
                // void setWeapon(component::weapon_s &weapon);
                // component::weapon_s getWeapon() const;
                // void setVelocity(component::velocity_s &velocity);
                // component::velocity_s getVelocity() const;
                // void setPosition(component::position_s &position) override;
                // component::position_s getPosition() const override;
                void setName(std::string &name) override;
                std::string getName() const override;

        protected:
            Registry _registry; /*! registry */
            std::string _name; /*! name of the monster */
            std::string _texturePath; /*! _texturePath of the monster */
            // component::healPoint_s _healPoint; /*! healpoint of the monster */
            // component::fireFrequence_s _fireFrequence; /*! firefrequence of the monster */
            // component::weapon_s _weapon; /*! WeaponType of the monster */
            size_t _idx; /*! Entity id of the monster */
            // component::position_s _position;  /*! Position of the monster */
            // component::velocity_s _velocity;  /*! velocity of the monster */
            // component::loot_s _loot; /*! Is the monster looting something */
    };

#endif /* !AMONSTER_HPP_ */
