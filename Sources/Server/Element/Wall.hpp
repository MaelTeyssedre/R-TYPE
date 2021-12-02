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
                 * \fn void init(Registry &) override
                 * 
                 * \brief init the wall
                 * 
                 */
                void init(Registry &) override;
                
                /**
                 * \fn void update(void) override
                 * 
                 * \brief update the Wall during the game
                 * 
                 */
                void update(void) override;
                
                /**
                 * \fn void setName(std::string &name)
                 * 
                 * \brief Set the Name object
                 * 
                 * \param name name to set
                 */
                void setName(std::string &name);
                
                /**
                 * \fn std::string &getName()
                 * 
                 * \brief Get the Name object
                 * 
                 * \return std::string& name
                 */
                std::string &getName();

            private:

                Registry _registry; /*! registry */
                std::string _name; /*! name of the wall */
                size_t _idx; /*! Entity id of the Wall */
        };
    }
#endif /* !WALL_HPP_ */
