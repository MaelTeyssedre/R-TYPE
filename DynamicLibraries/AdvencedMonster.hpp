/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** AdvencedMonster
*/

/**
 * \file AdvencedMonster.hpp
 *
 * \brief file where AdvencedMonster class is defined, compile to make .so/.dll
 */

#ifndef ADVENCEDMONSTER_HPP_
    #define ADVENCEDMONSTER_HPP_

    #include "IElement.hpp"

    /**
     * \class AdvencedMonster AdvencedMonster.hpp
     * 
     * \brief Class that contain a monster in a .so/.dll
     */

    class AdvencedMonster : public IElement {
        public:
            /**
             * \fn AdvencedMonster() = default
             * 
             * \brief Default ctor
             */
            AdvencedMonster() = default;

            /**
             * \fn AdvencedMonster(const AdvencedMonster&) = default
             * 
             * \brief Default copy ctor
             */
            AdvencedMonster(const AdvencedMonster&) = default;

            /**
             * \fn ~AdvencedMonster() = default
             * 
             * \brief Default dtor
             */
            ~AdvencedMonster() = default;

            /**
             * \fn AdvencedMonster& operator=(const AdvencedMonster &other) = default
             * 
             * \brief Default operator= overload
             */
            AdvencedMonster& operator=(const AdvencedMonster &other) = default;

            /**
             * \fn void init(std::shared_ptr<Registery>) override
             *
             * \param Registery of the ECS
             * 
             * \brief Override init of the class
             */
            void init(std::shared_ptr</*Registry*/int>) override;

            /**
             * \fn void update(void) override
             * 
             * \brief Override update of the class
             */
            void update(void) override;

        private:
            std::shared_ptr<int> _registry; /*! regstry*/
            std::string _name; /*! name of the monster */
            size_t _spriteId; /*! spriteid of the monster*/
            size_t _healPoint; /*! healpoint of the monster */
            size_t _fireFrequence; /*! firefrequence of the monster*/
            size_t _weaponType; /*! WeaponType of the monster*/
            size_t _damage; /*! Damage of the monster*/
            std::pair<size_t,size_t> _pos;  /*! Position of the monster*/
            bool _loot; /*! Is the monster looting something*/
    };

#endif /* !ADVENCEDMONSTER_HPP_ */
