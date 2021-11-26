
#ifndef UPDATEGRAPH_HPP_
    #define UPDATEGRAPH_HPP_

    #include <iostream>
    #include <map>
    #include "Registry.hpp"
    #include "Constants.hpp"
    #include "MouseStateComponent.hpp"
    #include "KeyStateComponent.hpp"
    #include <functional>
    #include "Zipper.hpp"
    #include "GraphicalLib.hpp"

    class UpdateGraph {
        public:
            UpdateGraph();
            ~UpdateGraph() = default;
            void operator()(Registry &r,  SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates);
            
        private:
            void updateEvent(SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates);
            void setupGraph(Registry &r);
            void displayGraph(Registry &r);

        private:
            void setupIsSetupNeeded();
            void setupSetupScene();
            void setupDisplayScene();

        private:
            void setupSetupLoadingMenuScene();
            void setupSetupLoadingGameScene();
            void setupSetupGameScene();
            void setupSetupParamsScene();
            void setupSetupMainMenuScene();
            
        private:
            void setupDisplayLoadingMenuScene();
            void setupDisplayLoadingGameScene();
            void setupDisplayGameScene();
            void setupDisplayParamsScene();
            void setupDisplayMainMenuScene();

        private:
            rtype::IGraphicalLib *_graphicalLib;
            std::map<rtype::constants::SCENE, bool> _isSetupNeeded;
            std::map<rtype::constants::SCENE, std::function<void(Registry &, UpdateGraph &)>> _setupScene;
            std::map<rtype::constants::SCENE, std::function<void(Registry &, UpdateGraph &)>> _displayScene;
    };

#endif /* !UPDATEGRAPH_HPP_ */
