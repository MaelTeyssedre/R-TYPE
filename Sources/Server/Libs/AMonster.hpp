/**
 * \file AMonster.hpp
 * 
 * \brief file for Abstract class AMonster 
 */

#ifndef AMONSTER_HPP_
    #define AMONSTER_HPP_

    #include "IElement.hpp"
    #include "FireFrequence.hpp"
    #include "HealPoint.hpp"
    #include "Loot.hpp"
    #include "Position.hpp"
    #include "Velocity.hpp"
    #include "Weapon.hpp"

    /**
     * \class AMonster
     * 
     * \brief Abstract class for every type of monsters
     * 
     */
    class AMonster : public IElement {
        public:
            /**
             * \fn 
             * 
             * \brief Construct a new AMonster object
             * 
             * \param name 
             * \param texturePath 
             */
            AMonster(std::string name, std::string texturePath)
                : _name(name), _texturePath(texturePath) {}
            
            /**
             * \fn 
             * 
             * \brief Destroy the AMonster object
             * 
             */
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

            /**
             * \fn virtual void setHealPoint(size_t healPoint)
             * 
             * \brief Set the Heal Point object
             * 
             * \param healPoint amount of healpoint to set
             */
            virtual void setHealPoint(size_t healPoint);
            
            /**
             * \fn virtual rtype::healPoint_s getHealPoint() const
             * 
             * \brief Get the Heal Point object
             * 
             * \return rtype::healPoint_s  healpoints of the player
             */
            virtual rtype::healPoint_s getHealPoint() const;
            
            /**
             * \fn virtual void setFireFrequence(size_t firefrequence)
             * 
             * \brief Set the Fire Frequence object
             * 
             * \param firefrequence fire frequence to set
             */
            virtual void setFireFrequence(size_t firefrequence);
            
            /**
             * \fn virtual rtype::fireFrequence_s getFireFrequence() const
             * 
             * \brief Get the Fire Frequence object
             * 
             * \return rtype::fireFrequence_s fireFrequence of the monster
             */
            virtual rtype::fireFrequence_s getFireFrequence() const;
            
            /**
             * \fn virtual void setWeapon(size_t weapon)
             * 
             * \brief Set the Weapon object
             * 
             * \param weapon weapon to set
             */
            virtual void setWeapon(size_t weapon);
            
            /**
             * \fn virtual rtype::weapon_s getWeapon() const
             * 
             * \brief Get the Weapon object
             * 
             * \return rtype::weapon_s weapon of the player
             */
            virtual rtype::weapon_s getWeapon() const;
            
            /**
             * \fn virtual void setVelocity(std::pair<int, int> vel)
             * 
             * \brief Set the Velocity object
             * 
             * \param vel velocoti to set
             */
            virtual void setVelocity(std::pair<int, int> vel);
            
            /**
             * \fn virtual rtype::velocity_s getVelocity() const
             * 
             * \brief Get the Velocity object
             * 
             * \return rtype::velocity_s velocity of the player
             */
            virtual rtype::velocity_s getVelocity() const;
            
            /**
             * \fn virtual void setPosition(std::pair<int, int> pos)
             * 
             * \brief Set the Position object
             * 
             * \param pos position to set
             */
            virtual void setPosition(std::pair<int, int> pos);
            
            /**
             * \fn virtual rtype::position_s getPosition() const
             * 
             * \brief Get the Position object
             * 
             * \return rtype::position_s position of the monster
             */
            virtual rtype::position_s getPosition() const;
            
            /**
             * \fn virtual void setName(std::string &name)
             * 
             * \brief Set the Name object
             * 
             * \param name name to set
             */
            virtual void setName(std::string &name);
            
            /**
             * \fn virtual std::string getName()
             * 
             * \brief Get the Name object
             * 
             * \return std::string name of the monster 
             */
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
