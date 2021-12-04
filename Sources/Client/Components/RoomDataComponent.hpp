/**
 * \file RoomDataComponent.hpp
 * 
 * \brief file for the RoomData component 
 */

#ifndef ROOMDATACOMPONENT_HPP_
    #define ROOMDATACOMPONENT_HPP_

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
             * \struct roomData_s
             * 
             * \brief the roomData component
             *
             */
            struct roomData_s {
                bool room; /*!< Is the room exist */
            };
        }
    }

#endif /* !ROOMDATACOMPONENT_HPP_ */
