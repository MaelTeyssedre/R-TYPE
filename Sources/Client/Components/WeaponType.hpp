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
     * \brief namespace for rtype project
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
             * \brief the weaponType component component
             *
             */
            typedef struct weaponType_s {
                rtype::constants::WEAPON_TYPE weaponType; /*!< weapon type */
            } weaponType_t;
        }
    }

#endif /* !WEAPONTYPE_HPP_ */
