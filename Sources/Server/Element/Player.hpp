/**
 * \file Player.hpp
 * 
 * \brief file for Player class 
 */

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include "IElement.hpp"

    /**
     * \namespace rtype
     * 
     * \brief global namespace for the rtype project
     * 
     */
    namespace rtype {
        /**
         * \class Player
         * 
         * \brief class Player that inherit of IElement
         */
        class Player : public IElement {
            public:

                /**
                 * \fn explicit Player() = default
                 * 
                 * \brief Construct a new Player object
                 * 
                 */
                explicit Player() = default;

                /**
                 * \fn virtual ~Player() = default
                 * 
                 * \brief Destroy the Player object
                 * 
                 */
                virtual ~Player() = default;

                /**
                 * \fn auto init(Registry &) -> void override
                 * 
                 * \brief init the Player
                 * 
                 */
                auto init(Registry &) -> void override;

                /**
                 * \fn auto update(void) -> void override
                 * 
                 * \brief update the player during the game
                 * 
                 */
                auto update(void) -> void override;

                /**
                 * \fn auto setName(std::string &name) -> void
                 * 
                 * \brief Set the Name object
                 * 
                 * \param name the name to set
                 */
                auto setName(std::string &name) -> void;

                /**
                 * \fn auto getName() -> std::string &
                 * 
                 * \brief Get the Name object
                 * 
                 * \return std::string& the name of the player
                 */
                auto getName() -> std::string &;

            private:

                Registry _registry; /*! registry*/
                std::string _name; /*! name of the player */
        };
    }

#endif /* !PLAYER_HPP_ */
