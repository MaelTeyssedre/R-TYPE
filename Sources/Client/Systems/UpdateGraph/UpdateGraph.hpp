
#ifndef UPDATEGRAPH_HPP_
    #define UPDATEGRAPH_HPP_

    #include <iostream>
    #include <map>
    #include <chrono>
    #include <thread>
    #include "Registry.hpp"
    #include "Constants.hpp"
    #include <functional>
    #include "Zipper.hpp"
    #include "Components.hpp"
    #include "GraphicalLib.hpp"

    namespace rtype {
        class UpdateGraph {
            public:
                UpdateGraph();
                ~UpdateGraph() = default;
                void operator()(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes);
                
            private:
                void _updateEvent(SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates);
                void _updateGraph(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes);

            private:
                void _setupScenes();
                void _setupExecScene();
                void _setupDeleteScene();

            private: // * fill _setupScene map
                void _setupLoadingMenuScene();
                void _setupLoadingGameScene() {};
                void _setupGameScene() {};
                void _setupParamsScene() {};
                void _setupMainMenuScene();
                
            private: // * fill _execScene map
                void _setupExecLoadingMenuScene();
                void _setupExecLoadingGameScene() {};
                void _setupExecGameScene() {};
                void _setupExecParamsScene() {};
                void _setupExecMainMenuScene();
                
            private: // * fill _deleteScene map
                void _setupDeleteLoadingMenuScene();
                void _setupDeleteLoadingGameScene() {};
                void _setupDeleteGameScene() {};
                void _setupDeleteParamsScene() {};
                void _setupDeleteMainMenuScene();

            private:
                rtype::IGraphicalLib *_graphicalLib;

                std::map<rtype::constants::SCENE, std::function<void(Registry &, UpdateGraph &, SparseArray<components::currentScene_s> &)>> _setupScene;
                std::map<rtype::constants::SCENE, std::function<void(Registry &r, UpdateGraph &graph, SparseArray<components::currentScene_s> &currentScenes, GraphicalLib *lib)>> _execScene;
                std::map<rtype::constants::SCENE, std::function<void(Registry &, UpdateGraph &, GraphicalLib *lib)>> _deleteScene;


                size_t _background_id;
                size_t _switchId;
        };
    }

#endif /* !UPDATEGRAPH_HPP_ */