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

    #include "AMonster.hpp"
    #include "Registry.hpp"

    /**
     * \class BalkanyMonster BalkanyMonster.hpp
     * 
     * \brief Class that contain a monster in a .so/.dll
     */
    class BalkanyMonster : public AMonster {
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
            void init(Registry &r) override;

            /**
             * \fn void update(void) override
             * 
             * \brief Override update of the class
             */
            void update(void) override;

            // void setPosition(component::position_s &position) override;
            // component::position_s getPosition() const override;
            // void setName(std::string &name) override;
            // std::string getName() const override;

        private:
            // Registry _registry; /*! registry */
            // std::string _name; /*! name of the monster */
            // std::string _texturePath; /*! _texturePath of the monster */
            // component::healPoint_s _healPoint; /*! healpoint of the monster */
            // component::fireFrequence_s _fireFrequence; /*! firefrequence of the monster */
            // component::weapon_s _weapon; /*! WeaponType of the monster */
            // size_t _idx; /*! Entity id of the monster */
            // component::position_s _pos;  /*! Position of the monster */
            // component::velocity_s _vel;  /*! velocity of the monster */
            // component::loot_s _loot; /*! Is the monster looting something */
    };

#endif /* !BALKANYMONSTER_HPP_ */
