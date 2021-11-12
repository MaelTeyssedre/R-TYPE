/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** AdvencedMonster
*/

#ifndef ADVENCEDMONSTER_HPP_
    #define ADVENCEDMONSTER_HPP_

    #include "IElement.hpp"

    namespace component {
        class AdvencedMonster : public component::IElement {
            public:
                AdvencedMonster() = default;
                ~AdvencedMonster() = default;

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

#endif /* !ADVENCEDMONSTER_HPP_ */
