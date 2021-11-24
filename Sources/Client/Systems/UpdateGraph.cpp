
#include "UpdateGraph.hpp"

UpdateGraph::UpdateGraph()
    : _graphicalLib() {}

void UpdateGraph::operator()(Registry &r, SparseArray<components::mouseState_t> &mouseStates, SparseArray<components::keyState_t> &keyStates)
{
    (void)r;
    updateEvent(mouseStates, keyStates);
}

void UpdateGraph::updateEvent(SparseArray<components::mouseState_t> &mouseStates, SparseArray<components::keyState_t> &keyStates)
{
    std::optional<components::mouseState_t> &mouseState = mouseStates[rtype::constants::EVENT_UPDATE];
    std::optional<components::keyState_t> &keyState = keyStates[rtype::constants::EVENT_UPDATE];
    rtype::mouse_t mouse = _graphicalLib.getMouseState();

    if (mouseState && keyState) {
        mouseState.value().mousePosX = mouse.posX;
        mouseState.value().mousePosY = mouse.posY;
        mouseState.value().mouseLeftClick = mouse.leftPressed;
        mouseState.value().mouseRightClick = mouse.rightPressed;
        keyState.value().keyDown = _graphicalLib.getKeyState(rtype::constants::KEY_DOWN);
        keyState.value().keyUp = _graphicalLib.getKeyState(rtype::constants::KEY_UP);
        keyState.value().keyRight = _graphicalLib.getKeyState(rtype::constants::KEY_RIGHT);
        keyState.value().keyLeft = _graphicalLib.getKeyState(rtype::constants::KEY_LEFT);
        keyState.value().keyEnter = _graphicalLib.getKeyState(rtype::constants::KEY_ENTER);
        keyState.value().keySpace = _graphicalLib.getKeyState(rtype::constants::KEY_SPACE);
    }
}
