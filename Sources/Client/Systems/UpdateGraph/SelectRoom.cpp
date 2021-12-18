#include "UpdateGraph.hpp"

auto rtype::UpdateGraph::_setupSelectRoomScene() -> void
{
	_setupScene[constants::SELECT_ROOM] = std::function(
		[this](Registry& r, SparseArray<components::currentScene_t>& currentScenes) -> void
		{
			auto roomList{ r.getComponents<components::roomList_t>()[constants::GRAPH_UPDATE].value() };
			Entity room1Id{ _addButtonToScene(r, components::sprite_t{0.5f, 0.5f, 0, 0, 800, 215, BUTTON_1_SELECT_ROOM}, components::position_t{ WINDOW_SIZE_X * 0.1, WINDOW_SIZE_Y * 0.5 }, components::direction_t{ 0, 0 }, components::velocity_t{ 0, 0 }, components::drawable_t{ true }, components::scene_t{ constants::SELECT_ROOM }, components::zaxis_t{ 9 }, components::clickable_t{ false, false,
				[this](Registry& r, size_t id) -> void {
					if (!r.getComponents<components::drawable_t>()[id].value().drawable)
						return;
					r.getComponents<components::sprite_t>()[id].value().rectY = 215;
				},
				[this](Registry& r, size_t id) -> void {
					if (!r.getComponents<components::drawable_t>()[id].value().drawable)
						return;
					r.getComponents<components::sprite_t>()[id].value().rectY = 0;
					r.getComponents<components::network_s>()[constants::NETWORK_UPDATE].value().sendRequest.push_back(std::vector<uint8_t>{19, 1});
				}}, components::mouseState_s {0, 0, false, false}, components::mySize_t {400, 215}) };
			_graphicalLib->createSprite(room1Id, r.getComponents<components::sprite_t>()[room1Id].value().scaleX, r.getComponents<components::sprite_t>()[room1Id].value().scaleY, r.getComponents<components::sprite_t>()[room1Id].value().rectX, r.getComponents<components::sprite_t>()[room1Id].value().rectY, r.getComponents<components::sprite_t>()[room1Id].value().rectWidth, r.getComponents<components::sprite_t>()[room1Id].value().rectHeight, r.getComponents<components::sprite_t>()[room1Id].value().path);
			Entity room2Id{ _addButtonToScene(r, components::sprite_t{ 0.5f, 0.5f, 0, 0, 800, 215, BUTTON_2_SELECT_ROOM }, components::position_t{ WINDOW_SIZE_X * 0.1, WINDOW_SIZE_Y * 0.8 }, components::direction_t{ 0, 0 }, components::velocity_t{ 0, 0 }, components::drawable_t{ true }, components::scene_t{ constants::SELECT_ROOM }, components::zaxis_t{ 8 }, components::clickable_t{ false, false,
				[this](Registry& r, size_t id) -> void {
					if (!r.getComponents<components::drawable_t>()[id].value().drawable)
						return;
					r.getComponents<components::sprite_t>()[id].value().rectY = 215;
				},
				[this](Registry& r, size_t id) -> void {
					if (!r.getComponents<components::drawable_t>()[id].value().drawable)
						return;
					r.getComponents<components::sprite_t>()[id].value().rectY = 0;
					r.getComponents<components::network_t>()[constants::NETWORK_UPDATE].value().sendRequest.push_back(std::vector<uint8_t>{19, 2});
				}}, components::mouseState_s {0, 0, false, false}, components::mySize_t {400, 215}) };
			_graphicalLib->createSprite(room2Id, r.getComponents<components::sprite_t>()[room2Id].value().scaleX, r.getComponents<components::sprite_t>()[room2Id].value().scaleY, r.getComponents<components::sprite_t>()[room2Id].value().rectX, r.getComponents<components::sprite_t>()[room2Id].value().rectY, r.getComponents<components::sprite_t>()[room2Id].value().rectWidth, r.getComponents<components::sprite_t>()[room2Id].value().rectHeight, r.getComponents<components::sprite_t>()[room2Id].value().path);
			Entity room3Id{ _addButtonToScene(r, components::sprite_t{0.5f, 0.5f, 0, 0, 800, 215, BUTTON_3_SELECT_ROOM }, components::position_t{ static_cast<float>((WINDOW_SIZE_X * 0.4)), WINDOW_SIZE_Y * 0.65 }, components::direction_t{ 0, 0 }, components::velocity_t{ 0, 0 }, components::drawable_t{ true }, components::scene_t{ constants::SELECT_ROOM }, components::zaxis_t{ 3 }, components::clickable_t{ false, false,
				[this](Registry& r, size_t id) -> void {
					if (!r.getComponents<components::drawable_t>()[id].value().drawable)
						return;
					r.getComponents<components::sprite_t>()[id].value().rectY = 215;
				},
				[this](Registry& r, size_t id) -> void {
					if (!r.getComponents<components::drawable_t>()[id].value().drawable)
						return;
					r.getComponents<components::sprite_t>()[id].value().rectY = 0;
					r.getComponents<components::network_s>()[constants::NETWORK_UPDATE].value().sendRequest.push_back(std::vector<uint8_t>{19, 3});
				}}, components::mouseState_t {0, 0, false, false},components::mySize_t {400, 215}) };
			_graphicalLib->createSprite(room3Id, r.getComponents<components::sprite_t>()[room3Id].value().scaleX, r.getComponents<components::sprite_t>()[room3Id].value().scaleY, r.getComponents<components::sprite_t>()[room3Id].value().rectX, r.getComponents<components::sprite_t>()[room3Id].value().rectY, r.getComponents<components::sprite_t>()[room3Id].value().rectWidth, r.getComponents<components::sprite_t>()[room3Id].value().rectHeight, r.getComponents<components::sprite_t>()[room3Id].value().path);
			Entity room4Id{ _addButtonToScene(r, components::sprite_t{0.5f, 0.5f, 0, 0, 800, 215, BUTTON_4_SELECT_ROOM }, components::position_t{ WINDOW_SIZE_X * 0.7, WINDOW_SIZE_Y * 0.5 }, components::direction_t{ 0, 0 }, components::velocity_t{ 0, 0 }, components::drawable_t{ true }, components::scene_t{ constants::SELECT_ROOM }, components::zaxis_t{ 6 }, components::clickable_t{  false, false,
				[this](Registry& r, size_t id) -> void {
					if (!r.getComponents<components::drawable_t>()[id].value().drawable)
						return;
					r.getComponents<components::sprite_t>()[id].value().rectY = 215;
				},
				[this](Registry& r, size_t id) -> void {
					if (!r.getComponents<components::drawable_t>()[id].value().drawable)
						return;
					r.getComponents<components::sprite_t>()[id].value().rectY = 0;
					r.getComponents<components::network_t>()[constants::NETWORK_UPDATE].value().sendRequest.push_back(std::vector<uint8_t>{19, 4});
				}}, components::mouseState_t { 0, 0, false, false }, components::mySize_t {400, 215}) };
			_graphicalLib->createSprite(room4Id, r.getComponents<components::sprite_t>()[room4Id].value().scaleX, r.getComponents<components::sprite_t>()[room4Id].value().scaleY, r.getComponents<components::sprite_t>()[room4Id].value().rectX, r.getComponents<components::sprite_t>()[room4Id].value().rectY, r.getComponents<components::sprite_t>()[room4Id].value().rectWidth, r.getComponents<components::sprite_t>()[room4Id].value().rectHeight, r.getComponents<components::sprite_t>()[room4Id].value().path);
			Entity room5Id{ _addButtonToScene(r, components::sprite_t{ 0.5f, 0.5f, 0, 0, 800, 215, BUTTON_5_SELECT_ROOM  }, components::position_t{  WINDOW_SIZE_X * 0.7, WINDOW_SIZE_Y * 0.8 }, components::direction_t{ 0, 0 }, components::velocity_t{ 0, 0 }, components::drawable_t{ true }, components::scene_t{ constants::SELECT_ROOM }, components::zaxis_t{ 5 }, components::clickable_t{ false, false,
				[this](Registry& r, size_t id) -> void {
					if (!r.getComponents<components::drawable_t>()[id].value().drawable)
						return;
					r.getComponents<components::sprite_t>()[id].value().rectY = 215;
				},
				[this](Registry& r, size_t id) -> void {
					if (!r.getComponents<components::drawable_t>()[id].value().drawable)
						return;
					r.getComponents<components::sprite_t>()[id].value().rectY = 0;
					r.getComponents<components::network_t>()[constants::NETWORK_UPDATE].value().sendRequest.push_back(std::vector<uint8_t>{19, 5});
					r.getComponents<components::currentRoom_t>()[constants::GRAPH_UPDATE].value().id = 5;
				}}, components::mouseState_s {0, 0, false, false}, components::mySize_t {400, 215}) };
			_graphicalLib->createSprite(room5Id, r.getComponents<components::sprite_t>()[room5Id].value().scaleX, r.getComponents<components::sprite_t>()[room5Id].value().scaleY, r.getComponents<components::sprite_t>()[room5Id].value().rectX, r.getComponents<components::sprite_t>()[room5Id].value().rectY, r.getComponents<components::sprite_t>()[room5Id].value().rectWidth, r.getComponents<components::sprite_t>()[room5Id].value().rectHeight, r.getComponents<components::sprite_t>()[room5Id].value().path);
			if (!roomList.room1 && !roomList.room2 && !roomList.room3 && !roomList.room4 && !roomList.room5)
			{
				Entity logoId{ _addSpriteToScene(r, components::sprite_t{ 0.9f, 0.9f, 0, 0, 663, 369, "ressources/NoRoom.png" }, components::position_t{ (WINDOW_SIZE_X / 2) - ((663) / 2), 150 }, components::direction_t{ 0, 0 }, components::velocity_t{ 0, 0 }, components::drawable_t{ true }, components::scene_t{ constants::SELECT_ROOM }, components::zaxis_t{ 7 }) };
				_graphicalLib->createSprite(logoId, r.getComponents<components::sprite_t>()[logoId].value().scaleX, r.getComponents<components::sprite_t>()[logoId].value().scaleY, r.getComponents<components::sprite_t>()[logoId].value().rectX, r.getComponents<components::sprite_t>()[logoId].value().rectY, r.getComponents<components::sprite_t>()[logoId].value().rectWidth, r.getComponents<components::sprite_t>()[logoId].value().rectHeight, r.getComponents<components::sprite_t>()[logoId].value().path);
			}
			else
			{
				Entity logoId{ _addSpriteToScene(r, components::sprite_t{ 0.9f, 0.9f, 0, 0, 663, 369, "ressources/logo.png" }, components::position_t{ (WINDOW_SIZE_X / 2) - ((663) / 2), 150 }, components::direction_t{ 0, 0 }, components::velocity_t{ 0, 0 }, components::drawable_t{ true }, components::scene_t{ constants::SELECT_ROOM }, components::zaxis_t{ 7 }) };
				_graphicalLib->createSprite(logoId, r.getComponents<components::sprite_t>()[logoId].value().scaleX, r.getComponents<components::sprite_t>()[logoId].value().scaleY, r.getComponents<components::sprite_t>()[logoId].value().rectX, r.getComponents<components::sprite_t>()[logoId].value().rectY, r.getComponents<components::sprite_t>()[logoId].value().rectWidth, r.getComponents<components::sprite_t>()[logoId].value().rectHeight, r.getComponents<components::sprite_t>()[logoId].value().path);
			}
			Entity backgroundId{ _addSpriteToScene(r, components::sprite_t{ 0.9f, 0.9f, 0, 0, 1920, 1080, "ressources/MainMenu.jpg" }, components::position_t{ 0, 0 }, components::direction_t{ 0, 0 }, components::velocity_t{ 0, 0 }, components::drawable_t{ true }, components::scene_t{ constants::SELECT_ROOM }, components::zaxis_t{ 10 }) };
			_graphicalLib->createSprite(backgroundId, r.getComponents<components::sprite_t>()[backgroundId].value().scaleX, r.getComponents<components::sprite_t>()[backgroundId].value().scaleY, r.getComponents<components::sprite_t>()[backgroundId].value().rectX, r.getComponents<components::sprite_t>()[backgroundId].value().rectY, r.getComponents<components::sprite_t>()[backgroundId].value().rectWidth, r.getComponents<components::sprite_t>()[backgroundId].value().rectHeight, r.getComponents<components::sprite_t>()[backgroundId].value().path);
			if (currentScenes[constants::GRAPH_UPDATE])
				currentScenes[constants::GRAPH_UPDATE].value().isLoaded = true;
			_scenePlaceholders.try_emplace(constants::SELECT_ROOM, std::vector<Entity> {room1Id, room2Id, room3Id, room4Id, room5Id});
		});
}

auto rtype::UpdateGraph::_setupExecSelectRoomScene() -> void
{
	_execScene[constants::SELECT_ROOM] = std::function(
		[this](Registry& r, SparseArray<components::currentScene_t>& currentScenes) -> void
		{
			std::vector<Entity> localEntities = std::any_cast<std::vector<Entity>>(_scenePlaceholders[constants::SELECT_ROOM]);
			static std::chrono::duration dtime = std::chrono::nanoseconds(0);
			auto& time = r.getComponents<components::myTime_t>()[constants::TIME_UPDATE];
			std::vector<int> myZAxises;
			std::map<int, size_t> zAxisMap;
			auto& netArray = r.getComponents<components::network_t>();
			auto& net = netArray[constants::NETWORK_UPDATE];
			_graphicalLib->clearScreen();
			dtime += time.value().deltaTime;
			for (auto&& [pos, sprite, scene, drawable, index, zaxis] : Zipper(r.getComponents<components::position_t>(), r.getComponents<components::sprite_t>(), r.getComponents<components::scene_t>(), r.getComponents<components::drawable_t>(), r.getComponents<components::index_t>(), r.getComponents<components::zaxis_t>()))
			{
				if (!drawable.drawable)
					continue;
				myZAxises.push_back(static_cast<int>(zaxis.zAxis));
				zAxisMap[static_cast<int>(zaxis.zAxis)] = index.idx;
				_graphicalLib->setSpritePosX(index.idx, pos.x);
				_graphicalLib->setSpritePosY(index.idx, pos.y);
				_graphicalLib->setSpriteScale(index.idx, sprite.scaleX, sprite.scaleY);
				_graphicalLib->setSpriteRectX(index.idx, sprite.rectX);
				_graphicalLib->setSpriteRectY(index.idx, sprite.rectY);
				_graphicalLib->setSpriteRectWidth(index.idx, sprite.rectWidth);
				_graphicalLib->setSpriteRectHeigth(index.idx, sprite.rectHeight);
			}
			std::sort(myZAxises.begin(), myZAxises.end(), myCmp);
			std::reverse(myZAxises.begin(), myZAxises.end());
			for (auto i : myZAxises)
				_graphicalLib->draw(zAxisMap[i]);
			_graphicalLib->HandleClose();
			_graphicalLib->refresh();
			if (dtime.count() > 1500000000)
			{
				net.value().sendRequest.push_back(std::vector<uint8_t>{23});
				dtime = std::chrono::nanoseconds(0);
			}
			if (!net.value().request17.empty() && !net.value().request17.front().empty())
			{
				r.getComponents<components::drawable_t>()[localEntities[0]].value().drawable = (net.value().request17.front()[1] == 1) ? true : false;
				r.getComponents<components::drawable_t>()[localEntities[1]].value().drawable = (net.value().request17.front()[2] == 2) ? true : false;
				r.getComponents<components::drawable_t>()[localEntities[2]].value().drawable = (net.value().request17.front()[3] == 3) ? true : false;
				r.getComponents<components::drawable_t>()[localEntities[3]].value().drawable = (net.value().request17.front()[4] == 4) ? true : false;
				r.getComponents<components::drawable_t>()[localEntities[4]].value().drawable = (net.value().request17.front()[5] == 5) ? true : false;
				net.value().request17.erase(net.value().request17.begin());
			}
		}
	);
}

auto rtype::UpdateGraph::_setupDeleteSelectRoomScene() -> void
{
	_deleteScene[constants::SELECT_ROOM] = std::function(
		[this](Registry& r)
		{
			_graphicalLib->clearScreen();
			for (auto&& [scene, index, music] : Zipper(r.getComponents<components::scene_t>(), r.getComponents<components::index_t>(), r.getComponents<components::music_t>()))
				if (scene.scene == constants::SELECT_ROOM)
				{
					_graphicalLib->stop(index.idx);
					_graphicalLib->deleteMusic(index.idx);
				}
			for (auto&& [scene, index, sprite] : Zipper(r.getComponents<components::scene_t>(), r.getComponents<components::index_t>(), r.getComponents<components::sprite_t>()))
				if (scene.scene == constants::SELECT_ROOM)
					_graphicalLib->deleteSprite(index.idx);
			for (auto&& [scene, index, text] : Zipper(r.getComponents<components::scene_t>(), r.getComponents<components::index_t>(), r.getComponents<components::text_t>()))
				if (scene.scene == constants::SELECT_ROOM)
					_graphicalLib->deleteText(index.idx);
			for (auto&& [scene, index] : Zipper(r.getComponents<components::scene_t>(), r.getComponents<components::index_t>()))
				if (scene.scene == constants::SELECT_ROOM)
				{
					r.getComponents<components::scene_t>().erase(index.idx);
					r.getComponents<components::index_t>().erase(index.idx);
					r.killEntity(r.entityFromIndex(index.idx));
				}
			_graphicalLib->clearScreen();
		});
}
