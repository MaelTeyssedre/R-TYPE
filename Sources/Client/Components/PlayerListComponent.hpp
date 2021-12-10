/**
 * \file PlayerListComponent.hpp
 * 
 * \brief file for the PlayerList component 
 */

#ifndef PLAYERLISTCOMPONENT_HPP_
    #define PLAYERLISTCOMPONENT_HPP_

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
             * \struct playerList_s
             * 
             * \brief the player list component
             *
             */
            typedef struct playerList_s {
                size_t players; /*!< number of player */
                size_t self; /*!< position of your player */
            } playerList_t;
        }
    }

#endif /* !PLAYERLISTCOMPONENT_HPP_ */
