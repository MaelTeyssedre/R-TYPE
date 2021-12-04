
#ifndef UPDATEHANDLECLICK_HPP_
    #define  UPDATEHANDLECLICK_HPP_

    #include "Registry.hpp"
    #include "Components.hpp"

    namespace rtype {
        class UpdateClickable {
            public:
                explicit UpdateClickable() = default;
                virtual ~UpdateClickable() = default;
                void operator()(Registry& r, SparseArray<components::clickable_s>& clickables, SparseArray<components::mouseState_s>& mouseStates, SparseArray<components::position_s>& positions, SparseArray<components::mySize_s>& sizes, SparseArray<components::index_s>& indexes, SparseArray<components::scene_s>& scenes, SparseArray<components::currentScene_s>& current_scenes, SparseArray<components::sprite_s>& sprites);

        };
    }

#endif  /*! UPDATEHANDLECLICK_HPP_ */
