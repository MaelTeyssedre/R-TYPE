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
     * \brief namespace for the R-Type
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
                 * \fn void init(Registry &) override
                 * 
                 * \brief init the Player
                 * 
                 */
                void init(Registry &) override;

                /**
                 * \fn void update(void) override
                 * 
                 * \brief update the player during the game
                 * 
                 */
                void update(void) override;

                /**
                 * \fn void setName(std::string &name)
                 * 
                 * \brief Set the Name object
                 * 
                 * \param name the name to set
                 */
                void setName(std::string &name);

                /**
                 * \fn std::string &getName()
                 * 
                 * \brief Get the Name object
                 * 
                 * \return std::string& the name of the player
                 */
                std::string &getName();

            private:

                Registry _registry; /*! registry*/
                std::string _name; /*! name of the player */
                size_t _idx; /*! Entity id of the player */
        };
    }

#endif /* !PLAYER_HPP_ */
