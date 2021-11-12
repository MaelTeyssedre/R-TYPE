/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** BasicMonster
*/

#ifndef BASICMONSTER_HPP_
    #define BASICMONSTER_HPP_

    //#include "../Server/Element/IElement.hpp"
    #include "IElement.hpp"

    namespace component {
        class BasicMonster : public component::IElement {
            public:
                BasicMonster() = default;
                ~BasicMonster() = default;

                void init(std::shared_ptr</*Registry*/int>) override;
                void update(void) override;

            private:
                std::shared_ptr<int> _registry;
                std::string _name;
                size_t _spriteId;
                size_t _healPoint;
                size_t _fireFrequence;
                size_t _weaponType;
                size_t _damage;
                
                /** 
                 * TODO: Put property into structs
                */
        };
    }

#endif /* !BASICMONSTER_HPP_ */
