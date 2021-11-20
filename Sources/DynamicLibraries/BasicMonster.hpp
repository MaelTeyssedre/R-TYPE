/**
 * \file BasicMonster.hpp
 *
 * \brief file where BasicMonster class is defined, compile to make .so/.dll
 */
#ifndef BASICMONSTER_HPP_
    #define BASICMONSTER_HPP_

    #include "AMonster.hpp"
    #include "Registry.hpp"
    #include "component.hpp"

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

            void setHealPoint(size_t healPoint) override;
            rtype::healPoint_s getHealPoint() const override;
            void setFireFrequence(size_t firefrequence) override;
            rtype::fireFrequence_s getFireFrequence() const override;
            void setWeapon(size_t weapon) override;
            rtype::weapon_s getWeapon() const override;
            void setVelocity(std::pair<int, int> vel) override;
            rtype::velocity_s getVelocity() const override;
            void setPosition(std::pair<int, int> pos) override;
            rtype::position_s getPosition() const override;
            void setName(std::string &name) override;
            std::string getName() override;
        private:
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

#endif /* !BASICMONSTER_HPP_ */
