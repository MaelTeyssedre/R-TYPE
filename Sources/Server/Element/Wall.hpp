/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** Wall
*/

#ifndef WALL_HPP_
    #define WALL_HPP_

    #include "IElement.hpp"

    class Wall : public IElement {
        public:
            explicit Wall() = default;
            virtual ~Wall() = default;
            void init(Registry &) override;
            void update(void) override;
            // void setPosition(component::position_s &position) override;
            // component::position_s getPosition() const override;
            void setName(std::string &name) override;
            std::string &getName() const override;
        protected:
        private:
            Registry _registry; /*! registry */
            std::string _name; /*! name of the wall */
            // component::position_s _position;  /*! Position of the wall */
            size_t _idx; /*! Entity id of the Wall */
    };

#endif /* !WALL_HPP_ */
