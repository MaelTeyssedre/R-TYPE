/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** BasicMonster
*/

/**
 * \file BasicMonster.hpp
 *
 * \brief file where BasicMonster class is defined, compile to make .so/.dll
 */
#ifndef BASICMONSTER_HPP_
    #define BASICMONSTER_HPP_

    #include "IElement.hpp"

    /**
     * \class BasicMonster BasicMonster.hpp
     * 
     * \brief Class that contain a monster in a .so/.dll
     */
    class BasicMonster : public IElement {
        public:
            /**
             * \fn BasicMonster() = default
             * 
             * \brief Default ctor
             */
            explicit BasicMonster() = default;

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
            void init(Registry &) override;

            /**
             * \fn void update(void) override
             * 
             * \brief Override update of the class
             */
            void update(void) override;

        private:
            //Registry _registry; /*! registry*/
            std::string _name; /*! name of the monster */
            std::string _texturePath; /*! _texturePath of the monster*/
            size_t _healPoint; /*! healpoint of the monster */
            size_t _fireFrequence; /*! firefrequence of the monster*/
            size_t _weaponType; /*! WeaponType of the monster*/
            size_t _damage; /*! Damage of the monster*/
            std::pair<size_t,size_t> _pos;  /*! Position of the monster*/
            bool _loot; /*! Is the monster looting something*/
    };

#endif /* !BASICMONSTER_HPP_ */
