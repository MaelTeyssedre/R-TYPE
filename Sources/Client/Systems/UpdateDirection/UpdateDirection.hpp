
#ifndef UPDATEDIRECTION_HPP_
    #define UPDATEDIRECTION_HPP_

    #include "Registry.hpp"
    #include "Components.hpp"

    namespace rtype {
        class UpdateDirection {
            public:
                explicit UpdateDirection() = default;
                virtual ~UpdateDirection() = default;
                void operator()(Registry &r, SparseArray<components::direction_s> &directions, SparseArray<components::keyState_s> &keys);
        };
    }

#endif /* !UPDATEDIRECTION_HPP_ */
