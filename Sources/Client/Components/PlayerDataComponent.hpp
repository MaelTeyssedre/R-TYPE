/**
 * \file PlayerDataComponent.hpp
 * 
 * \brief file for the PlayerData component 
 */

#ifndef PLAYERDATACOMPONENT_HPP_
    #define PLAYERDATACOMPONENT_HPP_

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
             * \struct playerData_s
             * 
             * \brief the playerData component
             *
             */
            struct playerData_s {
                size_t id; /*!< id of the player */
                bool self; /*!< is this your player */
            };
        }
    }

#endif /* !PLAYERDATACOMPONENT_HPP_ */
