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
     * \namespace rtype
     * 
     * \brief global namespace for the rtype project
     * 
     */
    namespace rtype {
        /**
         * \class AMonster
         * 
         * \brief Abstract class for every type of monsters, inherit from IEleement
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
                 * \fn virtual auto init(Registry &r) -> void = 0
                 *
                 * \param r of the ECS
                 * 
                 * \brief Pure virtual init 
                 */
                virtual auto init(Registry &r) -> void = 0;

                /**
                 * \fn virtual auto update(void) -> void = 0
                 * 
                 * \brief Pure virtual update 
                 */
                virtual auto update(void) -> void = 0;

                /**
                 * \fn virtual auto setHealPoint(size_t healPoint) -> virtual
                 * 
                 * \brief Set the Heal Point object
                 * 
                 * \param healPoint amount of healpoint to set
                 */
                virtual auto setHealPoint(size_t healPoint) -> void;
                
                /**
                 * \fn virtual auto getHealPoint() const -> components::healPoint_s
                 * 
                 * \brief Get the Heal Point object
                 * 
                 * \return rtype::healPoint_s  healpoints of the player
                 */
                virtual auto getHealPoint() const -> components::healPoint_s;
                
                /**
                 * \fn virtual auto setFireFrequence(size_t firefrequence) -> void
                 * 
                 * \brief Set the Fire Frequence object
                 * 
                 * \param firefrequence fire frequence to set
                 */
                virtual auto setFireFrequence(size_t firefrequence) -> void;
                
                /**
                 * \fn virtual auto getFireFrequence() const -> components::fireFrequence_s
                 * 
                 * \brief Get the Fire Frequence object
                 * 
                 * \return rtype::fireFrequence_s fireFrequence of the monster
                 */
                virtual auto getFireFrequence() const -> components::fireFrequence_s;
                
                /**
                 * \fn virtual auto setWeapon(size_t weapon) -> void
                 * 
                 * \brief Set the Weapon object
                 * 
                 * \param weapon weapon to set
                 */
                virtual auto setWeapon(size_t weapon) -> void;
                
                /**
                 * \fn virtual auto getWeapon() const -> components::weapon_s
                 * 
                 * \brief Get the Weapon object
                 * 
                 * \return rtype::weapon_s weapon of the player
                 */
                virtual auto getWeapon() const -> components::weapon_s;
                
                /**
                 * \fn virtual auto setVelocity(std::pair<int, int> vel) -> void
                 * 
                 * \brief Set the Velocity object
                 * 
                 * \param vel velocoti to set
                 */
                virtual auto setVelocity(std::pair<int, int> vel) -> void;
                
                /**
                 * \fn virtual auto getVelocity() const -> components::velocity_s
                 * 
                 * \brief Get the Velocity object
                 * 
                 * \return rtype::velocity_s velocity of the player
                 */
                virtual auto getVelocity() const -> components::velocity_s;
                
                /**
                 * \fn virtual auto setPosition(std::pair<int, int> pos) -> void
                 * 
                 * \brief Set the Position object
                 * 
                 * \param pos position to set
                 */
                virtual auto setPosition(std::pair<int, int> pos) -> void;
                
                /**
                 * \fn virtual auto getPosition() const -> components::position_s
                 * 
                 * \brief Get the Position object
                 * 
                 * \return position of the player
                 */
                virtual auto getPosition() const -> components::position_s;
                
                /**
                 * \fn virtual auto setName(std::string &name) -> void
                 * 
                 * \brief Set the Name object
                 * 
                 * \param name name to set
                 */
                virtual auto setName(std::string &name) -> void;
                
                /**
                 * \fn virtual auto getName() -> std::string
                 * 
                 * \brief Get the Name object
                 * 
                 * \return std::string name of the monster 
                 */
                virtual auto getName() -> std::string;

            protected:

                Registry _registry; /*! registry */
                std::string _name; /*! name of the monster */
                std::string _texturePath; /*! _texturePath of the monster */
                components::healPoint_s _healPoint; /*! healpoint of the monster */
                components::fireFrequence_s _fireFrequence; /*! firefrequence of the monster */
                components::weapon_s _weapon; /*! WeaponType of the monster */
                components::position_s _position;  /*! Position of the monster */
                components::velocity_s _velocity;  /*! velocity of the monster */
                components::loot_s _loot; /*! Is the monster looting something */
        };
    }

#endif /* !AMONSTER_HPP_ */
