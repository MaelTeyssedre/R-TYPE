/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** BasicMonster
*/

#ifndef BASICMONSTER_HPP_
    #define BASICMONSTER_HPP_

    #include "IElement.hpp"

    class BasicMonster : public IElement {
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
            std::pair<size_t,size_t> _pos;
            bool _loot;
            
            /** 
             * TODO: Put property into structs
            */
    };

    IElement *Creator();
    void Deletor(IElement *);

#endif /* !BASICMONSTER_HPP_ */
