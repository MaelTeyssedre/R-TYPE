/**
 * \file Weapon.hpp
 * 
 * \brief file for Weapon component 
 */

#ifndef WEAPON_HPP_
    #define WEAPON_HPP_

    /**
     * \namespace rtype
     * 
     * \brief namespace for the R-Type
     * 
     */
    namespace rtype {
        /**
         * \namespace components
         * 
         * \brief namespace for ECS components
         * 
         */
        namespace components {
            /**
             * \struct weapon_s
             * 
             * \brief weapon component
             * 
             */
            struct weapon_s {
                size_t weapon;
            };
        }
    }

#endif /* !WEAPON_HPP_ */
