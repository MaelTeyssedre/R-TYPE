
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
                UpdateGraph(UpdateGraph &&other) noexcept;
                ~UpdateGraph() = default;
                auto operator()(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes) -> void;
                
            private:
                auto _updateEvent(SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates) -> void;
                auto _updateGraph(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes) -> void;
                struct intCmp {
                    bool operator() (int i, int j) {return i<j;}
                } myCmp;

            private:
                auto _setupScenes() -> void;
                auto _setupExecScene() -> void;
                auto _setupDeleteScene() -> void;
                auto _addSpriteToScene(Registry &r, components::sprite_t sprite, components::position_t pos, components::direction_t dir, components::velocity_t vel, components::drawable_t draw, components::scene_t scene, components::zaxis_t zaxis) -> Entity;
                auto _addButtonToScene(Registry &r, components::sprite_t sprite, components::position_t pos, components::direction_t dir, components::velocity_t vel, components::drawable_t draw, components::scene_t scene, components::zaxis_t zaxis, components::clickable_t clickable, components::mouseState_t mouse, components::mySize_t size) -> Entity;

            // * Loading Menu functions
            private:
                auto _setupLoadingMenuScene() -> void;
                auto _setupExecLoadingMenuScene() -> void;
                auto _setupDeleteLoadingMenuScene() -> void;
                auto rtype::UpdateGraph::_createMusicLoadingMenu(Registry& r) -> Entity;

            // * Main Menu functions
            private:
                auto _setupMainMenuScene() -> void;
                auto _setupExecMainMenuScene() -> void;
                auto _setupDeleteMainMenuScene() -> void;

            // * Waiting Room functions
            private:
                auto _setupWaitingRoomScene() -> void;
                auto _setupExecWaitingRoomScene() -> void;
                auto _setupDeleteWaitingRoomScene() -> void;


            // * Select Room functions
            private:
                auto _setupSelectRoomScene() -> void;
                auto _setupExecSelectRoomScene() -> void;
                auto _setupDeleteSelectRoomScene() -> void;

            private:
                rtype::IGraphicalLib *_graphicalLib;
                std::map<rtype::constants::SCENE, std::function<void(Registry &, SparseArray<components::currentScene_s> &)>> _setupScene;
                std::map<rtype::constants::SCENE, std::function<void(Registry &, SparseArray<components::currentScene_s> &currentScenes)>> _execScene;
                std::map<rtype::constants::SCENE, std::function<void(Registry &)>> _deleteScene;
                std::map<rtype::constants::SCENE, std::any> _scenePlaceholders;
        };
    }

#endif /* !UPDATEGRAPH_HPP_ */
