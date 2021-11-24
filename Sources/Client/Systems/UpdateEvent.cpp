
#include "UpdateEvent.hpp"

void UpdateEvent::operator()(Registry &r, SparseArray<components::mouseState_t> &mouseStates, SparseArray<components::keyState_t> &keyStates)
{
    (void)r;
    std::optional<components::mouseState_t> &mouseState = mouseStates[rtype::constants::EVENT_UPDATE];
    std::optional<components::keyState_t> &keyState = keyStates[rtype::constants::EVENT_UPDATE];
    rtype::mouse_t mouse = rtype::GraphicalLib::getMouseState();
    if (mouseState && keyState) {
        mouseState.value().mousePosX = mouse.posX;
        mouseState.value().mousePosY = mouse.posY;
        mouseState.value().mouseLeftClick = mouse.leftPressed;
        mouseState.value().mouseRightClick = mouse.rightPressed;
        keyState.value().keyDown = rtype::GraphicalLib::getKeyState(rtype::constants::KEY_DOWN);
        keyState.value().keyUp = rtype::GraphicalLib::getKeyState(rtype::constants::KEY_UP);
        keyState.value().keyRight = rtype::GraphicalLib::getKeyState(rtype::constants::KEY_RIGHT);
        keyState.value().keyLeft = rtype::GraphicalLib::getKeyState(rtype::constants::KEY_LEFT);
        keyState.value().keyEnter = rtype::GraphicalLib::getKeyState(rtype::constants::KEY_ENTER);
        keyState.value().keySpace = rtype::GraphicalLib::getKeyState(rtype::constants::KEY_SPACE);
    }
}