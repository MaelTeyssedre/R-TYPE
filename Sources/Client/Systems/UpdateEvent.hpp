
#ifndef UPDATEEVENT_HPP_
    #define UPDATEEVENT_HPP_

    #include "Registry.hpp"
    #include "Constants.hpp"
    #include "MouseStateComponent.hpp"
    #include "KeyStateComponent.hpp"
    #include "GraphicalLib.hpp"

    class UpdateEvent {
        public:
            UpdateEvent() = default;
            ~UpdateEvent() = default;
            void operator()(Registry &r,  SparseArray<components::mouseState_t> &mouseStates, SparseArray<components::keyState_t> &keyStates);
        protected:
        private:
            //rtype::GraphicalLib _graphicalLib;
    };

#endif /* !UPDATEEVENT_HPP_ */
