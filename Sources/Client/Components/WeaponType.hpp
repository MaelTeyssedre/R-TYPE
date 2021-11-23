/**
 * \file WeaponType.hpp
 * 
 * \brief file for WeaponType component 
 */

#ifndef WEAPONTYPE_HPP_
    #define WEAPONTYPE_HPP_

    #include "Constants.hpp"

    /**
     * \namespace components
     * 
     * \brief namespace for ECS components
     * 
     */
    namespace components {
        /**
         * \struct weaponType
         * 
         * \brief weaponType component
         * 
         */
        struct weaponType {
            rtype::constants::WEAPON_TYPE weaponType;
        };
    }

#endif /* !WEAPONTYPE_HPP_ */
