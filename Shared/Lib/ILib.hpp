/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** ILib
*/

#ifndef ILIB_HPP_
    #define ILIB_HPP_

    #include <iostream>

    /** 
     * TODO: Add doxygen comments 
     * ? How to set the pattern inside that?
     * ? FireFrequence or FireCooldown?
    */

    class ILib { 
        public:
            ~ILib() = default;

            virtual void setName(std::string) = 0;
            virtual std::string getName() = 0;

            virtual void setSpriteId(size_t) = 0;
            virtual size_t getSpriteId() = 0;

            virtual void setHealPoint(size_t) = 0;
            virtual size_t getHealPoint() = 0;


            virtual void setFireFrequence(size_t) = 0;
            virtual size_t getFireFrequence() = 0;

            virtual void setWeaponType(size_t) = 0;
            virtual size_t getWeaponType() = 0;

            virtual void setDamage(size_t) = 0;
            virtual size_t getDamage() = 0;

    };

#endif /* !ILIB_HPP_ */
