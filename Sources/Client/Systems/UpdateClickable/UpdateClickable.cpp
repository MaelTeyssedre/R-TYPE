#include "UpdateClickable.hpp"
#include "Components.hpp"
#include "Zipper.hpp"
#include "Constants.hpp"

void rtype::UpdateClickable::operator()(Registry& r, SparseArray<components::clickable_s>& clickables, SparseArray<components::mouseState_s>& mouseStates, SparseArray<components::position_s>& positions, SparseArray<components::mySize_s>& sizes, SparseArray<components::index_s>& indexes, SparseArray<components::scene_s>& scenes, SparseArray<components::currentScene_s>& current_scenes, SparseArray<components::sprite_t>& sprites)
{
	for (auto&& [clickable, mouseState, position, size, index, scene, sprite] : Zipper(clickables, mouseStates, positions, sizes, indexes, scenes, sprites)) {
		clickable.prevState = clickable.isPressed;
		if (current_scenes[constants::GRAPH_UPDATE].value().scene == scene.scene) {
			if (mouseState.mouseLeftClick && mouseState.mousePosX < position.x + size.width && mouseState.mousePosX > position.x && mouseState.mousePosY > position.y && mouseState.mousePosY < position.y + size.heigth)
				clickable.isPressed = true;
			if (!(mouseState.mouseLeftClick && mouseState.mousePosX < position.x + size.width && mouseState.mousePosX > position.x && mouseState.mousePosY > position.y && mouseState.mousePosY < position.y + size.heigth))
				clickable.isPressed = false;
			if (clickable.isPressed == true && clickable.prevState == false)
				clickable.callbackClick(r, index.idx);
			if (clickable.isPressed == false && clickable.prevState == true)
				clickable.callbackReleased(r, index.idx);
		}
	}
}
