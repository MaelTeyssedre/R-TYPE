/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** AdvancedMonster
*/

/**
 * \file AdvancedMonster.hpp
 *
 * \brief file where AdvancedMonster class is defined, compile to make .so/.dll
 */

#ifndef ADVANCEDMONSTER_HPP_
    #define ADVANCEDMONSTER_HPP_

    #include "IElement.hpp"

    /**
     * \class AdvancedMonster AdvancedMonster.hpp
     * 
     * \brief Class that contain a monster in a .so/.dll
     */
    class AdvancedMonster : public IElement {
        public:
            /**
             * \fn AdvancedMonster() = default
             * 
             * \brief Default ctor
             */
            explicit AdvancedMonster() = default;

            /**
             * \fn AdvancedMonster(const AdvancedMonster&) = default
             * 
             * \brief Default copy ctor
             */
            explicit AdvancedMonster(const AdvancedMonster&) = default;

            /**
             * \fn ~AdvancedMonster() = default
             * 
             * \brief Default dtor
             */
            virtual ~AdvancedMonster() = default;

            /**
             * \fn AdvancedMonster& operator=(const AdvancedMonster &other) = default
             * 
             * \brief Default operator= overload
             */
            AdvancedMonster& operator=(const AdvancedMonster &other) = default;

            /**
             * \fn void init(Registery &) override
             *
             * \param Registery of the ECS
             * 
             * \brief Override init of the class
             */
            void init(Registry &) override;

            /**
             * \fn void update(void) override
             * 
             * \brief Override update of the class
             */
            void update(void) override;

        private:
            Registry _registry; /*! registry*/
            std::string _name; /*! name of the monster */
            std::string _texturePath; /*! _texturePath of the monster*/
            size_t _healPoint; /*! healpoint of the monster */
            size_t _fireFrequence; /*! firefrequence of the monster*/
            size_t _weaponType; /*! WeaponType of the monster*/
            size_t _damage; /*! Damage of the monster*/
            std::pair<size_t,size_t> _pos;  /*! Position of the monster*/
            bool _loot; /*! Is the monster looting something*/
    };

#endif /* !ADVANCEDMONSTER_HPP_ */
