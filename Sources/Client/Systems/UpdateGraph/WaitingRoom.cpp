#include "UpdateGraph.hpp"

auto rtype::UpdateGraph::_setupWaitingRoomScene() -> void
{
	_setupScene[constants::WAITING_ROOM] = std::function(
		[this](Registry& r, SparseArray<components::currentScene_t>& currentScenes) -> void
		{
			_scenePlaceholders.try_emplace(constants::SELECT_ROOM, std::vector<Entity> {});
			auto playerList = r.getComponents<components::playerList_t>()[constants::GRAPH_UPDATE].value();
			if (playerList.self == 1)
			{
				auto player1{ _addSpriteToScene(r, components::sprite_t{0.5f, 0.5f, 0, 0, 835, 227, "ressources/you.png"}, components::position_t{200, 250}, components::direction_t{0, 0}, components::velocity_t{0, 0}, components::drawable_t{true}, components::scene_t{constants::WAITING_ROOM}, components::zaxis_t{9}) };
				_graphicalLib->createSprite(player1, r.getComponents<components::sprite_t>()[player1].value().scaleX, r.getComponents<components::sprite_t>()[player1].value().scaleY, r.getComponents<components::sprite_t>()[player1].value().rectX, r.getComponents<components::sprite_t>()[player1].value().rectY, r.getComponents<components::sprite_t>()[player1].value().rectWidth, r.getComponents<components::sprite_t>()[player1].value().rectHeight, r.getComponents<components::sprite_t>()[player1].value().path);
				std::any_cast<std::vector<Entity>>(_scenePlaceholders[constants::SELECT_ROOM]).push_back(player1);
			}
			else
			{
				auto player1{ _addSpriteToScene(r, components::sprite_t{0.5f, 0.5f, 0, 0, 835, 227, "ressources/player-1-connected.png"}, components::position_t{200, 250}, components::direction_t{0, 0}, components::velocity_t{0, 0}, components::drawable_t{true}, components::scene_t{constants::WAITING_ROOM}, components::zaxis_t{8}) };
				_graphicalLib->createSprite(player1, r.getComponents<components::sprite_t>()[player1].value().scaleX, r.getComponents<components::sprite_t>()[player1].value().scaleY, r.getComponents<components::sprite_t>()[player1].value().rectX, r.getComponents<components::sprite_t>()[player1].value().rectY, r.getComponents<components::sprite_t>()[player1].value().rectWidth, r.getComponents<components::sprite_t>()[player1].value().rectHeight, r.getComponents<components::sprite_t>()[player1].value().path);
				std::any_cast<std::vector<Entity>>(_scenePlaceholders[constants::SELECT_ROOM]).push_back(player1);
			}
			if (playerList.self == 2)
			{
				auto player2{ _addSpriteToScene(r, components::sprite_t{0.5f, 0.5f, 0, 0, 835, 227, "ressources/you.png"}, components::position_t{1520, 250}, components::direction_t{0, 0}, components::velocity_t{0, 0}, components::drawable_t{true}, components::scene_t{constants::WAITING_ROOM}, components::zaxis_t{9}) };
				_graphicalLib->createSprite(player2, r.getComponents<components::sprite_t>()[player2].value().scaleX, r.getComponents<components::sprite_t>()[player2].value().scaleY, r.getComponents<components::sprite_t>()[player2].value().rectX, r.getComponents<components::sprite_t>()[player2].value().rectY, r.getComponents<components::sprite_t>()[player2].value().rectWidth, r.getComponents<components::sprite_t>()[player2].value().rectHeight, r.getComponents<components::sprite_t>()[player2].value().path);
				std::any_cast<std::vector<Entity>>(_scenePlaceholders[constants::SELECT_ROOM]).push_back(player2);
			}
			else
			{
				auto player2{ _addSpriteToScene(r, components::sprite_t{0.5f, 0.5f, 0, 0, 835, 227, "ressources/player-2-connected.png"}, components::position_t{1520, 250}, components::direction_t{0, 0}, components::velocity_t{0, 0}, components::drawable_t{true}, components::scene_t{constants::WAITING_ROOM}, components::zaxis_t{7}) };
				_graphicalLib->createSprite(player2, r.getComponents<components::sprite_t>()[player2].value().scaleX, r.getComponents<components::sprite_t>()[player2].value().scaleY, r.getComponents<components::sprite_t>()[player2].value().rectX, r.getComponents<components::sprite_t>()[player2].value().rectY, r.getComponents<components::sprite_t>()[player2].value().rectWidth, r.getComponents<components::sprite_t>()[player2].value().rectHeight, r.getComponents<components::sprite_t>()[player2].value().path);
				std::any_cast<std::vector<Entity>>(_scenePlaceholders[constants::SELECT_ROOM]).push_back(player2);
			}
			if (playerList.self == 3)
			{
				auto player3{ _addSpriteToScene(r, components::sprite_t{0.5f, 0.5f, 0, 0, 835, 227, "ressources/you.png"}, components::position_t{200, 600}, components::direction_t{0, 0}, components::velocity_t{0, 0}, components::drawable_t{true}, components::scene_t{constants::WAITING_ROOM}, components::zaxis_t{9}) };
				_graphicalLib->createSprite(player3, r.getComponents<components::sprite_t>()[player3].value().scaleX, r.getComponents<components::sprite_t>()[player3].value().scaleY, r.getComponents<components::sprite_t>()[player3].value().rectX, r.getComponents<components::sprite_t>()[player3].value().rectY, r.getComponents<components::sprite_t>()[player3].value().rectWidth, r.getComponents<components::sprite_t>()[player3].value().rectHeight, r.getComponents<components::sprite_t>()[player3].value().path);
				std::any_cast<std::vector<Entity>>(_scenePlaceholders[constants::SELECT_ROOM]).push_back(player3);
			}
			else
			{
				auto player3{ _addSpriteToScene(r, components::sprite_t{0.5f, 0.5f, 0, 0, 835, 227, "ressources/player-3-connected.png"}, components::position_t{200, 600}, components::direction_t{0, 0}, components::velocity_t{0, 0}, components::drawable_t{true}, components::scene_t{constants::WAITING_ROOM}, components::zaxis_t{6}) };
				_graphicalLib->createSprite(player3, r.getComponents<components::sprite_t>()[player3].value().scaleX, r.getComponents<components::sprite_t>()[player3].value().scaleY, r.getComponents<components::sprite_t>()[player3].value().rectX, r.getComponents<components::sprite_t>()[player3].value().rectY, r.getComponents<components::sprite_t>()[player3].value().rectWidth, r.getComponents<components::sprite_t>()[player3].value().rectHeight, r.getComponents<components::sprite_t>()[player3].value().path);
				std::any_cast<std::vector<Entity>>(_scenePlaceholders[constants::SELECT_ROOM]).push_back(player3);
			}
			if (playerList.self == 4)
			{
				auto player4{ _addSpriteToScene(r, components::sprite_t{0.5f, 0.5f, 0, 0, 835, 227, "ressources/you.png"}, components::position_t{1520, 600}, components::direction_t{0, 0}, components::velocity_t{0, 0}, components::drawable_t{true}, components::scene_t{constants::WAITING_ROOM}, components::zaxis_t{9}) };
				_graphicalLib->createSprite(player4, r.getComponents<components::sprite_t>()[player4].value().scaleX, r.getComponents<components::sprite_t>()[player4].value().scaleY, r.getComponents<components::sprite_t>()[player4].value().rectX, r.getComponents<components::sprite_t>()[player4].value().rectY, r.getComponents<components::sprite_t>()[player4].value().rectWidth, r.getComponents<components::sprite_t>()[player4].value().rectHeight, r.getComponents<components::sprite_t>()[player4].value().path);
				std::any_cast<std::vector<Entity>>(_scenePlaceholders[constants::SELECT_ROOM]).push_back(player4);
			}
			else
			{
				auto player4{ _addSpriteToScene(r, components::sprite_t{0.5f, 0.5f, 0, 0, 835, 227, "ressources/player-4-connected.png"}, components::position_t{1520, 600}, components::direction_t{0, 0}, components::velocity_t{0, 0}, components::drawable_t{true}, components::scene_t{constants::WAITING_ROOM}, components::zaxis_t{5}) };
				_graphicalLib->createSprite(player4, r.getComponents<components::sprite_t>()[player4].value().scaleX, r.getComponents<components::sprite_t>()[player4].value().scaleY, r.getComponents<components::sprite_t>()[player4].value().rectX, r.getComponents<components::sprite_t>()[player4].value().rectY, r.getComponents<components::sprite_t>()[player4].value().rectWidth, r.getComponents<components::sprite_t>()[player4].value().rectHeight, r.getComponents<components::sprite_t>()[player4].value().path);
				std::any_cast<std::vector<Entity>>(_scenePlaceholders[constants::SELECT_ROOM]).push_back(player4);
			}
			auto backgroundId{ _addSpriteToScene(r, components::sprite_t{0.9f, 0.9f, 0, 0, 1920, 1080, "ressources/MainMenu.jpg"}, components::position_t{0, 0}, components::direction_t{0, 0}, components::velocity_t{0, 0}, components::drawable_t{true}, components::scene_t{constants::WAITING_ROOM}, components::zaxis_t{10}) };
			_graphicalLib->createSprite(backgroundId, r.getComponents<components::sprite_t>()[backgroundId].value().scaleX, r.getComponents<components::sprite_t>()[backgroundId].value().scaleY, r.getComponents<components::sprite_t>()[backgroundId].value().rectX, r.getComponents<components::sprite_t>()[backgroundId].value().rectY, r.getComponents<components::sprite_t>()[backgroundId].value().rectWidth, r.getComponents<components::sprite_t>()[backgroundId].value().rectHeight, r.getComponents<components::sprite_t>()[backgroundId].value().path);
			if (currentScenes[constants::GRAPH_UPDATE])
				currentScenes[constants::GRAPH_UPDATE].value().isLoaded = true;
		});
}

auto rtype::UpdateGraph::_setupExecWaitingRoomScene() -> void
{
	_execScene[constants::WAITING_ROOM] = std::function(
		[this](Registry& r, SparseArray<components::currentScene_t>& currentScenes) -> void
		{
			(void)currentScenes;
			auto localEntities = std::any_cast<std::vector<Entity>>(_scenePlaceholders[constants::WAITING_ROOM]);
			static auto dtime = std::chrono::nanoseconds(0);
			auto& time = r.getComponents<components::myTime_t>()[constants::TIME_UPDATE];
			std::vector<size_t> savedIdx {};
			auto& playerList = r.getComponents<components::playerList_t>()[constants::GRAPH_UPDATE];
			std::vector<int> myZAxises {};
			std::map<int, std::pair<size_t, constants::TYPE>> zAxisMap;
			auto& net = r.getComponents<components::network_t>()[constants::NETWORK_UPDATE];
			dtime += time.value().deltaTime;
			for (auto&& [pos, sprite, scene, drawable, index, zaxis, playerData] : Zipper(r.getComponents<components::position_t>(), r.getComponents<components::sprite_t>(), r.getComponents<components::scene_t>(), r.getComponents<components::drawable_t>(), r.getComponents<components::index_t>(), r.getComponents<components::zaxis_t>(), r.getComponents<components::playerData_t>()))
				if (scene.scene != constants::WAITING_ROOM)
					continue;
				else if (playerList.value().players > playerData.id)
					drawable.drawable = true;
			for (auto&& [pos, sprite, scene, drawable, index, zaxis] : Zipper(r.getComponents<components::position_t>(), r.getComponents<components::sprite_t>(), r.getComponents<components::scene_t>(), r.getComponents<components::drawable_t>(), r.getComponents<components::index_t>(), r.getComponents<components::zaxis_t>()))
			{
				if (!(drawable.drawable) || scene.scene != constants::WAITING_ROOM)
					continue;
				myZAxises.push_back(static_cast<int>(zaxis.zAxis));
				zAxisMap[static_cast<int>(zaxis.zAxis)] = std::pair(index.idx, constants::SPRITE);
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
				if (zAxisMap[i].second == constants::TYPE::SPRITE)
					_graphicalLib->draw(zAxisMap[i].first);
			_graphicalLib->HandleClose();
			_graphicalLib->refresh();
			if (!net.value().request16.empty() && (net.value().request16.front().size() == 2))
				playerList.value().players = net.value().request16.front()[1];
			if (dtime.count() > 1500000000)
			{
				net.value().sendRequest.push_back(std::vector<uint8_t>{22, (uint8_t)(r.getComponents<components::currentRoom_t>()[constants::GRAPH_UPDATE].value().id)});
				dtime = std::chrono::nanoseconds(0);
			}
			if (!net.value().request17.empty() && !net.value().request16.front().empty())
			{
				r.getComponents<components::drawable_t>()[localEntities[0]].value().drawable = (net.value().request17.front()[1] == 1) ? true : false;
				r.getComponents<components::drawable_t>()[localEntities[1]].value().drawable = (net.value().request17.front()[2] == 2) ? true : false;
				r.getComponents<components::drawable_t>()[localEntities[2]].value().drawable = (net.value().request17.front()[3] == 3) ? true : false;
				r.getComponents<components::drawable_t>()[localEntities[3]].value().drawable = (net.value().request17.front()[4] == 4) ? true : false;
				r.getComponents<components::drawable_t>()[localEntities[4]].value().drawable = (net.value().request17.front()[5] == 5) ? true : false;
				net.value().request17.erase(net.value().request17.begin());
			}
			//if (playerList.value().players == 4)
			//{
			//	r.getComponents<components::currentScene_t>()[constants::GRAPH_UPDATE].value().isLoaded = false;
			//	r.getComponents<components::currentScene_t>()[constants::GRAPH_UPDATE].value().scene = constants::LOADING_MENU;
			//}
		});
}

auto rtype::UpdateGraph::_setupDeleteWaitingRoomScene() -> void
{
	_deleteScene[constants::WAITING_ROOM] = std::function(
		[this](Registry& r)
		{
			_graphicalLib->clearScreen();
			for (auto&& [scene, index, music] : Zipper(r.getComponents<components::scene_t>(), r.getComponents<components::index_t>(), r.getComponents<components::music_t>()))
				if (scene.scene == constants::WAITING_ROOM)
				{
					_graphicalLib->stop(index.idx);
					_graphicalLib->deleteMusic(index.idx);
				}
			for (auto&& [scene, index, sprite] : Zipper(r.getComponents<components::scene_t>(), r.getComponents<components::index_t>(), r.getComponents<components::sprite_t>()))
				if (scene.scene == constants::WAITING_ROOM)
					_graphicalLib->deleteSprite(index.idx);
			for (auto&& [scene, index] : Zipper(r.getComponents<components::scene_t>(), r.getComponents<components::index_t>()))
				if (scene.scene == constants::WAITING_ROOM)
				{
					r.getComponents<components::scene_t>().erase(index.idx);
					r.getComponents<components::index_t>().erase(index.idx);
					r.killEntity(r.entityFromIndex(index.idx));
				}
			_graphicalLib->clearScreen();
		});
}