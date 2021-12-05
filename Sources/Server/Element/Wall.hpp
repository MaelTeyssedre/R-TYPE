/**
 * \file Wall.hpp
 * \brief file for the Wall class
 */

#ifndef WALL_HPP_
    #define WALL_HPP_

    #include "IElement.hpp"

    /**
     * \namespace rtype
     * 
     * \brief namespace for the R-Type
     * 
     */
    namespace rtype {
        /**
         * \class Wall
         * 
         * \brief class for Wall that inherit of IElement
         */
        class Wall : public IElement {
            public:
                
                /**
                 * \fn explicit Wall() = default
                 * 
                 * \brief Construct a new Wall object
                 * 
                 */
                explicit Wall() = default;
                
                /**
                 * \fn virtual ~Wall() = default
                 * 
                 * \brief Destroy the Wall object
                 * 
                 */
                virtual ~Wall() = default;
                
                /**
                 * \fn auto init(Registry &) -> void override
                 * 
                 * \brief init the wall
                 * 
                 */
                auto init(Registry &r) -> void override;
                
                /**
                 * \fn auto update(void) -> void override
                 * 
                 * \brief update the Wall during the game
                 * 
                 */
                auto update(void) -> void override;
                
                /**
                 * \fn a setName(std::string &name) -> void
                 * 
                 * \brief Set the Name object
                 * 
                 * \param name name to set
                 */
                auto setName(std::string &name) -> void;
                
                /**
                 * \fn auto getName() -> std::string &
                 * 
                 * \brief Get the Name object
                 * 
                 * \return std::string& name
                 */
                auto getName() -> std::string &;

            private:

                Registry _registry; /*! registry */
                std::string _name; /*! name of the wall */
        };
    }
#endif /* !WALL_HPP_ */
