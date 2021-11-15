/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** BalkanyMonster
*/

/**
 * \file BalkanyMonster.hpp
 *
 * \brief file where BalkanyMonster class is defined, compile to make .so/.dll
 */
#ifndef BALKANYMONSTER_HPP_
    #define BALKANYMONSTER_HPP_

    #include "IElement.hpp"

    /**
     * \class BalkanyMonster BalkanyMonster.hpp
     * 
     * \brief Class that contain a monster in a .so/.dll
     */
    class BalkanyMonster : public IElement {
        public:
            /**
             * \fn BalkanyMonster() = default
             * 
             * \brief Default ctor
             */
            explicit BalkanyMonster() = default;

            /**
             * \fn BalkanyMonster(const BalkanyMonster&) = default
             * 
             * \brief Default copy ctor
             */
            explicit BalkanyMonster(const BalkanyMonster&) = default;

            /**
             * \fn ~BalkanyMonster() = default
             * 
             * \brief Default dtor
             */
            virtual ~BalkanyMonster() = default;

            /**
             * \fn BalkanyMonster& operator=(const BalkanyMonster &other) = default
             * 
             * \brief Default operator= overload
             */
            BalkanyMonster& operator=(const BalkanyMonster &other) = default;

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

        struct position_s {
            int x;
            int y;
        };

        private:
            Registry _registry; /*! registry*/
            std::string _name; /*! name of the monster */
            std::string _texturePath; /*! _texturePath of the monster */
            size_t _healPoint; /*! healpoint of the monster */
            size_t _fireFrequence; /*! firefrequence of the monster */
            size_t _weaponType; /*! WeaponType of the monster */
            size_t _damage; /*! Damage of the monster */
            size_t _id; /*! Id of the monster */
            position_s _pos;  /*! Position of the monster */
            bool _loot; /*! Is the monster looting something */
    };

#endif /* !BALKANYMONSTER_HPP_ */
