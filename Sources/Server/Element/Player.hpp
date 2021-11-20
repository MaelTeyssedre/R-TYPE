/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include "IElement.hpp"
    class Player : public IElement {
        public:
            explicit Player() = default;
            virtual ~Player() = default;
            void init(Registry &) override;
            void update(void) override;
            // void setHealPoint(component::healPoint_s &healPoint);
            // component::healPoint_s getHealPoint() const;
            // void setFireFrequence(component::fireFrequence_s &healPoint);
            // component::fireFrequence_s getFireFrequence() const;
            // void setWeapon(component::weapon_s &weapon);
            // component::weapon_s getWeapon() const;
            // void setPosition(component::position_s &position) override;
            // component::position_s getPosition() const override;
            void setName(std::string &name);
            std::string &getName();
        private:
            Registry _registry; /*! registry*/
            std::string _name; /*! name of the player */
            // component::healPoint_s _healPoint; /*! healpoint of the player */
            // component::fireFrequence_s _fireFrequence; /*! firefrequence of the player */
            // component::weapon_s _weapon; /*! WeaponType of the player */
            // component::position_s _position;  /*! Position of the player */
            size_t _idx; /*! Entity id of the player */
    };

#endif /* !PLAYER_HPP_ */
