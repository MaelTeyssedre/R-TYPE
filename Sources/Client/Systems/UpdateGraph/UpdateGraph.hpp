
#ifndef UPDATEGRAPH_HPP_
    #define UPDATEGRAPH_HPP_

    #include <iostream>
    #include <map>
    #include <chrono>
    #include <thread>
    #include "Registry.hpp"
    #include "Constants.hpp"
    #include "MouseStateComponent.hpp"
    #include "KeyStateComponent.hpp"
    #include "SceneComponent.hpp"
    #include <functional>
    #include "Zipper.hpp"
    #include "GraphicalLib.hpp"
    #include "CurrentSceneComponent.hpp"

    namespace rtype {
        class UpdateGraph {
            public:
                UpdateGraph();
                ~UpdateGraph() = default;
                void operator()(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes);
                
            private:
                void _updateEvent(SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates);
                void _setupGraph(Registry &r);
                void _execGraph(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes);

            private:
                void _setupSetupScene();
                void _setupExecScene();

            private: // * fill _setupScene map
                void _setupSetupLoadingMenuScene();
                void _setupSetupLoadingGameScene();
                void _setupSetupGameScene();
                void _setupSetupParamsScene();
                void _setupSetupMainMenuScene();
                
            private: // * fill _execScene map
                void _setupExecLoadingMenuScene();
                void _setupExecLoadingGameScene();
                void _setupExecGameScene();
                void _setupExecParamsScene();
                void _setupExecMainMenuScene();

            private:
                rtype::IGraphicalLib *_graphicalLib;

                std::map<rtype::constants::SCENE, std::function<void(Registry &, UpdateGraph &, SparseArray<components::currentScene_s> &)>> _setupScene;
                std::map<rtype::constants::SCENE, std::function<void(Registry &, UpdateGraph &,  SparseArray<components::mouseState_s> &, SparseArray<components::keyState_s> &, SparseArray<components::currentScene_s> &)>> _execScene;

                size_t _background_id;
        };
    }

#endif /* !UPDATEGRAPH_HPP_ */
