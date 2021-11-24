
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
            void setupGame(Registry &r);
            void setupMenu(Registry &r);

        private:
            void updateEvent(SparseArray<components::mouseState_t> &mouseStates, SparseArray<components::keyState_t> &keyStates);
            rtype::IGraphicalLib *_graphicalLib;
    };

#endif /* !UPDATEGRAPH_HPP_ */
