
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
                void operator()(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes);
                
            private:
                void _updateEvent(SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates);
                void _updateGraph(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes);
                struct intCmp {
                    bool operator() (int i, int j) {return i<j;}
                } myCmp;

            private:
                void _setupScenes();
                void _setupExecScene();
                void _setupDeleteScene();

            // * Loading Menu functions
            private:
                void _setupLoadingMenuScene();
                void _setupExecLoadingMenuScene();
                void _setupDeleteLoadingMenuScene();
                Entity _createBackgroundLoadingMenu(Registry &r);
                Entity _createTransitionLoadingMenu(Registry &r);
                Entity _createMusicLoadingMenu(Registry &r);

            // * Main Menu functions
            private:
                auto _setupMainMenuScene() -> void;
                auto _setupExecMainMenuScene() -> void;
                auto _setupDeleteMainMenuScene() -> void;
                auto _createBackgroundMainMenu(Registry &r) -> Entity;
                auto _createLogoMainMenu(Registry &r) -> Entity;
                auto _createTransitionMainMenu(Registry &r) -> Entity;
                auto _createPlayButtonMainMenu(Registry &r) -> Entity;
                auto _createNewGameButtonMainMenu(Registry &r) -> Entity;

            // * Waiting Room functions
            private:
                auto _setupWaitingRoomScene() -> void;
                auto _setupExecWaitingRoomScene() -> void;
                auto _setupDeleteWaitingRoomScene() -> void;
                auto _createBackgroundWaitingRoom(Registry &r) -> Entity;
                auto _createYouWaitingRoom(Registry &r) -> Entity;
                auto _createPlayer1WaitingRoom(Registry &r) -> Entity;
                auto _createPlayer2WaitingRoom(Registry &r) -> Entity;
                auto _createPlayer3WaitingRoom(Registry &r) -> Entity;
                auto _createPlayer4WaitingRoom(Registry &r) -> Entity;

            // * Select Room functions
            private:
                auto _setupSelectRoomScene() -> void;
                auto _setupExecSelectRoomScene() -> void;
                auto _setupDeleteSelectRoomScene() -> void;
                auto _createBackgroundSelectRoom(Registry &r) -> Entity;
                auto _createLogoSelectRoom(Registry &r) -> Entity;
                auto _createSelectRoom1ButtonSelectRoom(Registry &r) -> Entity;
                auto _createSelectRoom2ButtonSelectRoom(Registry &r) -> Entity;
                auto _createSelectRoom3ButtonSelectRoom(Registry &r) -> Entity;
                auto _createSelectRoom4ButtonSelectRoom(Registry &r) -> Entity;
                auto _createSelectRoom5ButtonSelectRoom(Registry &r) -> Entity;
                auto _createSelectRoom5NoRoom(Registry& r)->Entity;
                auto _createSelectBackButtonSelectRoom(Registry& r)->Entity;
                
            private:
                rtype::IGraphicalLib *_graphicalLib;

                std::map<rtype::constants::SCENE, std::function<void(Registry &, SparseArray<components::currentScene_s> &)>> _setupScene;
                std::map<rtype::constants::SCENE, std::function<void(Registry &, SparseArray<components::currentScene_s> &currentScenes)>> _execScene;
                std::map<rtype::constants::SCENE, std::function<void(Registry &)>> _deleteScene;
        };
    }

#endif /* !UPDATEGRAPH_HPP_ */
