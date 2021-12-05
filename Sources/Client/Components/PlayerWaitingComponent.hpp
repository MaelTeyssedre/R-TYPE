/**
 * \file PlayerWaitingComponent.hpp
 * 
 * \brief file for the PlayerWaiting component 
 */

#ifndef PLAYERWAITINGCOMPONENT_HPP_
    #define PLAYERWAITINGCOMPONENT_HPP_

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
             * \struct playerWaiting_s
             * 
             * \brief the playerWaiting component
             *
             */
            struct playerWaiting_s {
                size_t nb; /*!< number of player */
                size_t self;  /*!< position of your player */
            };
        }
    }

#endif /* !PLAYERWAITINGCOMPONENT_HPP_ */
