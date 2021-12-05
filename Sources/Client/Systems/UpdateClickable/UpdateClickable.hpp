/**
 * \file UpdateClickable.hpp
 *
 * \brief file where the update clickable system is defined
 */
#ifndef UPDATEHANDLECLICK_HPP_
    #define  UPDATEHANDLECLICK_HPP_

    #include "Registry.hpp"
    #include "Components.hpp"

    /**
     * \namespace rtype
     * 
     * \brief namespace for the R-Type
     * 
     */
    namespace rtype {
        /**
         * \class UpdateClickable UpdateClickable.hpp 
         * 
         * \brief class that contain the system UpdateClickable
         */
        class UpdateClickable {
            public:
                /**
                 * \fn explicit UpdateClickable() = default
                 *
                 * \brief ctor UpdateClickable
                 */
                explicit UpdateClickable() = default;

                /**
                 * \fn virtual ~UpdateClickable() = default
                 *
                 * \brief dtor UpdateClickable
                 */
                virtual ~UpdateClickable() = default;

                /**
                 * \fn auto operator()(Registry& r, SparseArray<components::clickable_s>& clickables, SparseArray<components::mouseState_s>& mouseStates, SparseArray<components::position_s>& positions, SparseArray<components::mySize_s>& sizes, SparseArray<components::index_s>& indexes, SparseArray<components::scene_s>& scenes, SparseArray<components::currentScene_s>& current_scenes, SparseArray<components::sprite_s>& sprites) -> void
                 *
                 * \brief operator to be used by the ECS
                 * 
                 * \param r A reference to the registry
                 * 
                 * \param clickables reference to a sparseArray of clickable components
                 * 
                 * \param mouseStates reference to a sparseArray of mouseState components
                 * 
                 * \param positions reference to a sparseArray of position components
                 * 
                 * \param sizes reference to a sparseArray of mySizes components
                 * 
                 * \param indexs reference to a sparseArray of indexees components
                 */
                auto operator()(Registry& r, SparseArray<components::clickable_s>& clickables, SparseArray<components::mouseState_s>& mouseStates, SparseArray<components::position_s>& positions, SparseArray<components::mySize_s>& sizes, SparseArray<components::index_s>& indexes, SparseArray<components::scene_s>& scenes, SparseArray<components::currentScene_s>& current_scenes, SparseArray<components::sprite_s>& sprites) -> void;

        };
    }

#endif  /*! UPDATEHANDLECLICK_HPP_ */
