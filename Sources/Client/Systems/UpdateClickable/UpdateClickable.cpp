#include "UpdateClickable.hpp"
#include "Components.hpp"
#include "Zipper.hpp"
#include "Constants.hpp"

void rtype::UpdateClickable::operator()(Registry &r, SparseArray<components::clickable_s> &clickables, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::position_s> &positions, SparseArray<components::mySize_s> &sizes, SparseArray<components::index_s> &indexes, SparseArray<components::scene_s> &scenes)
{
   for (auto &&[clickable, mouseState, position, size, index, scene] : Zipper(clickables, mouseStates, positions, sizes, indexes, scenes)) {
      clickable.prevState = clickable.isPressed;
         std::cout << "is pressed: " << mouseState.mouseLeftClick << std::endl;

      //if (scenes[constants::GRAPH_UPDATE].value().scene == scene.scene) {
         if (mouseState.mouseLeftClick && mouseState.mousePosX < position.x + size.width && mouseState.mousePosX > position.x && mouseState.mousePosY > position.y && mouseState.mousePosY < position.y + size.heigth) {
            std::cout << "Click" << std::endl;
         }
            clickable.isPressed = true;
         if (!(mouseState.mouseLeftClick && mouseState.mousePosX < position.x + size.width && mouseState.mousePosX > position.x && mouseState.mousePosY > position.y && mouseState.mousePosY < position.y + size.heigth))
            clickable.isPressed = false;
         if (clickable.isPressed == true && clickable.prevState == false) {
            clickable.callbackClick(r, index.idx);
            std::cout << std::endl << "callBackClick" << std::endl << std::endl;
         }
         if (clickable.isPressed == false && clickable.prevState == true) {
            clickable.callbackReleased(r, index.idx);
            std::cout << std::endl << "callBackReleased" << std::endl << std::endl;
         }
      //}
   }
}
