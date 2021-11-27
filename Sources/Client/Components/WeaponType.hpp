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
         * \struct weaponType_s
         * 
         * \brief weapon type component
         * 
         */
        typedef struct weaponType_s {
            rtype::constants::WEAPON_TYPE weaponType;
        } weaponType_t;
    }

#endif /* !WEAPONTYPE_HPP_ */
