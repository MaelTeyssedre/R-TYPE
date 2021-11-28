
#include "UpdateGraph.hpp"

rtype::UpdateGraph::UpdateGraph()
{
    _graphicalLib = new rtype::GraphicalLib();
    _setupScene = {};
    _execScene = {};

    _setupSetupScene();
    _setupExecScene();
}

void rtype::UpdateGraph::operator()(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes)
{
    _updateEvent(mouseStates, keyStates);
    std::optional<components::currentScene_s> &scene = currentScenes[constants::RESERVED_ID::GRAPH_UPDATE];
}

void rtype::UpdateGraph::_setupGraph(Registry &r)
{
}

void rtype::UpdateGraph::_execGraph(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes)
{
    if (currentScenes[rtype::constants::RESERVED_ID::GRAPH_UPDATE].value().isLoaded)
        _execScene[currentScenes[rtype::constants::RESERVED_ID::GRAPH_UPDATE].value().scene](r, *this, mouseStates, keyStates, currentScenes);
    else
        _setupScene[currentScenes[rtype::constants::RESERVED_ID::GRAPH_UPDATE].value().scene](r, *this, currentScenes);
}

void rtype::UpdateGraph::_updateEvent(SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates)
{
    (void)mouseStates;
    (void)keyStates;
    rtype::mouse_t mouse = _graphicalLib->getMouseState();
    for (size_t i = 0; i < mouseStates.size() && i < keyStates.size(); i++)
    {
        std::optional<components::mouseState_s> &mouseState = mouseStates[i];
        std::optional<components::keyState_s> &keyState = keyStates[i];
        if (mouseState && keyState)
        {
            mouseState.value().mousePosX = mouse.posX;
            mouseState.value().mousePosY = mouse.posY;
            mouseState.value().mouseLeftClick = mouse.leftPressed;
            mouseState.value().mouseRightClick = mouse.rightPressed;
            keyState.value().keyDown = _graphicalLib->getKeyState(rtype::constants::KEY_DOWN);
            keyState.value().keyUp = _graphicalLib->getKeyState(rtype::constants::KEY_UP);
            keyState.value().keyRight = _graphicalLib->getKeyState(rtype::constants::KEY_RIGHT);
            keyState.value().keyLeft = _graphicalLib->getKeyState(rtype::constants::KEY_LEFT);
            keyState.value().keyEnter = _graphicalLib->getKeyState(rtype::constants::KEY_ENTER);
            keyState.value().keySpace = _graphicalLib->getKeyState(rtype::constants::KEY_SPACE);
        }
    }
}

void rtype::UpdateGraph::_setupSetupScene()
{
    _setupSetupLoadingMenuScene();
}

void rtype::UpdateGraph::_setupExecScene()
{
    _setupExecLoadingMenuScene();
}

void rtype::UpdateGraph::_setupSetupLoadingMenuScene()
{
    _setupScene[rtype::constants::LOADING_MENU] = std::function([this](Registry &r, UpdateGraph &graph, SparseArray<components::currentScene_s> &currentScenes)
                                                                {
                                                                    (void)r;
                                                                    (void)graph;
                                                                    currentScenes[rtype::constants::RESERVED_ID::GRAPH_UPDATE].value().isLoaded = true;

                                                                    _graphicalLib->addSprite(rtype::constants::LOADING_MENU, _graphicalLib->createSprite(0.f, 0.f, (float)WINDOW_SIZE_X / 384, (float)WINDOW_SIZE_Y / 256, 0, 0, 384, 256, "ressources/LoadingMenu.jpg"));
                                                                });
}

void rtype::UpdateGraph::_setupExecLoadingMenuScene()
{
    _execScene[rtype::constants::LOADING_MENU] = std::function([this](Registry &r, UpdateGraph &graph, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes)
                                                               {
                                                                   (void)r;
                                                                   (void)graph;
                                                                   _graphicalLib->draw(currentScenes[rtype::constants::RESERVED_ID::GRAPH_UPDATE].value().scene);
                                                                   std::this_thread::sleep_for(std::chrono::seconds(5));
                                                               });
}
