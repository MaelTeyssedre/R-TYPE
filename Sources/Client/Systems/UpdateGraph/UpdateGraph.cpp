
#include "UpdateGraph.hpp"
#include <algorithm>
#include <vector>

rtype::UpdateGraph::UpdateGraph()
{
    _graphicalLib = new rtype::GraphicalLib();
    _setupScene = {};
    _execScene = {};
    _deleteScene = {};
    _setupScenes();
    _setupExecScene();
    _setupDeleteScene();
}

rtype::UpdateGraph::UpdateGraph(UpdateGraph &&other) noexcept
    : _graphicalLib{other._graphicalLib}, _setupScene{other._setupScene}, _execScene{other._execScene}, _deleteScene{other._deleteScene} {}

void rtype::UpdateGraph::operator()(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes)
{
    _updateEvent(mouseStates, keyStates);
    _updateGraph(r, mouseStates, keyStates, currentScenes);
}

void rtype::UpdateGraph::_updateGraph(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes)
{
    static constants::SCENE previous_scene = constants::SCENE::LOADING_MENU;
    for (auto&& [scene] : Zipper(currentScenes)) {
        if (!(scene.isLoaded))
        {
            _deleteScene[previous_scene](r);
            previous_scene = currentScenes[constants::RESERVED_ID::GRAPH_UPDATE].value().scene;
            _setupScene[currentScenes[rtype::constants::RESERVED_ID::GRAPH_UPDATE].value().scene](r, currentScenes);
        }
    }
    _execScene[currentScenes[rtype::constants::RESERVED_ID::GRAPH_UPDATE].value().scene](r, currentScenes);
}

void rtype::UpdateGraph::_updateEvent(SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates)
{
    rtype::mouse_t mouse = _graphicalLib->getMouseState();
    for (auto &&[mouseState] : Zipper(mouseStates))
    {
        mouseState.mousePosX = mouse.posX;
        mouseState.mousePosY = mouse.posY;
        mouseState.mouseLeftClick = mouse.leftPressed;
        mouseState.mouseRightClick = mouse.rightPressed;
    }
    for (auto &&[keyState] : Zipper(keyStates))
    {
        keyState.keyDown = _graphicalLib->getKeyState(rtype::constants::KEY_DOWN);
        keyState.keyUp = _graphicalLib->getKeyState(rtype::constants::KEY_UP);
        keyState.keyRight = _graphicalLib->getKeyState(rtype::constants::KEY_RIGHT);
        keyState.keyLeft = _graphicalLib->getKeyState(rtype::constants::KEY_LEFT);
        keyState.keyEnter = _graphicalLib->getKeyState(rtype::constants::KEY_ENTER);
        keyState.keySpace = _graphicalLib->getKeyState(rtype::constants::KEY_SPACE);
    }
}

void rtype::UpdateGraph::_setupScenes()
{
    _setupLoadingMenuScene();
    _setupMainMenuScene();
    _setupWaitingRoomScene();
}

void rtype::UpdateGraph::_setupExecScene()
{
    _setupExecLoadingMenuScene();
    _setupExecMainMenuScene();
    _setupExecWaitingRoomScene();
}

void rtype::UpdateGraph::_setupDeleteScene()
{
    _setupDeleteLoadingMenuScene();
    _setupDeleteMainMenuScene();
    _setupDeleteWaitingRoomScene();
}
