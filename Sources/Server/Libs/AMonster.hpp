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
            AMonster(std::string name, std::string texturePath)
                : _name(name), _texturePath(texturePath) {
                    std::cout << "in AMonster ctor" << std::endl;
                }
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

            virtual void setHealPoint(size_t healPoint);
            virtual rtype::healPoint_s getHealPoint() const;
            virtual void setFireFrequence(size_t firefrequence);
            virtual rtype::fireFrequence_s getFireFrequence() const;
            virtual void setWeapon(size_t weapon);
            virtual rtype::weapon_s getWeapon() const;
            virtual void setVelocity(std::pair<int, int> vel);
            virtual rtype::velocity_s getVelocity() const;
            virtual void setPosition(std::pair<int, int> pos);
            virtual rtype::position_s getPosition() const;
            virtual void setName(std::string &name);
            virtual std::string getName();

        protected:
            Registry _registry; /*! registry */
            std::string _name; /*! name of the monster */
            std::string _texturePath; /*! _texturePath of the monster */
            rtype::healPoint_s _healPoint; /*! healpoint of the monster */
            rtype::fireFrequence_s _fireFrequence; /*! firefrequence of the monster */
            rtype::weapon_s _weapon; /*! WeaponType of the monster */
            size_t _idx; /*! Entity id of the monster */
            rtype::position_s _position;  /*! Position of the monster */
            rtype::velocity_s _velocity;  /*! velocity of the monster */
            rtype::loot_s _loot; /*! Is the monster looting something */
    };

#endif /* !AMONSTER_HPP_ */
