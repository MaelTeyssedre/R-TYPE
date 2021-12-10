/**
 * \file RoomListComponent.hpp
 * 
 * \brief file for the RoomList component 
 */

#ifndef ROOMLISTCOMPONENT_HPP_
    #define ROOMLISTCOMPONENT_HPP_

    /**
     * \namespace rtype
     * 
     * \brief namespace for rtype project
     * 
     */
    namespace rtype
    {
        /**
         * \namespace components
         * 
         * \brief namespace for ECS components
         * 
         */
        namespace components {
            /**
             * \struct RoomList
             * 
             * \brief the roomList component
             *
             */
            typedef struct roomList_s {
                bool room1; /*!< Is the room exist */
                bool room2; /*!< Is the room exist */
                bool room3; /*!< Is the room exist */
                bool room4; /*!< Is the room exist */
                bool room5; /*!< Is the room exist */
            } roomList_t;
        }   
    }
    
#endif /* !ROOMLISTCOMPONENT_HPP_ */
