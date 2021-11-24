
#ifndef UPDATEGRAPH_HPP_
    #define UPDATEGRAPH_HPP_

    #include "Registry.hpp"
    #include "Constants.hpp"
    #include "MouseStateComponent.hpp"
    #include "KeyStateComponent.hpp"
    #include "GraphicalLib.hpp"

    class UpdateGraph {
        public:
            UpdateGraph();
            ~UpdateGraph() = default;
            void operator()(Registry &r,  SparseArray<components::mouseState_t> &mouseStates, SparseArray<components::keyState_t> &keyStates);
        private:
            void updateEvent(SparseArray<components::mouseState_t> &mouseStates, SparseArray<components::keyState_t> &keyStates);
            rtype::GraphicalLib _graphicalLib;
    };

#endif /* !UPDATEGRAPH_HPP_ */
