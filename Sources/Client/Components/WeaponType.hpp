/**
 * \file WeaponType.hpp
 * 
 * \brief file for WeaponType component 
 */

#ifndef WEAPONTYPE_HPP_
    #define WEAPONTYPE_HPP_

    #include "Constants.hpp"

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
             * \struct weaponType_s
             * 
             * \brief the weapon type component
             *
             */
            struct weaponType_s {
                rtype::constants::WEAPON_TYPE weaponType; /*!< The type of the weapon of a player*/
            };
        }
    }

#endif /* !WEAPONTYPE_HPP_ */
