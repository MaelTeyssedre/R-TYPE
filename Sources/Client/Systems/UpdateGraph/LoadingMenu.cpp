#include "UpdateGraph.hpp"



auto rtype::UpdateGraph::_createMusicLoadingMenu(Registry& r) -> Entity
{
	Entity id{ r.spawnEntity() };
	r.addComponent<components::scene_s>(r.entityFromIndex(id), std::move(components::scene_t{ constants::WAITING_ROOM }));
	r.addComponent<components::music_s>(r.entityFromIndex(id), std::move(components::music_t{ "ressources/MenuMusic.ogg" }));
	r.addComponent<components::index_s>(r.entityFromIndex(id), std::move(components::index_t{ id }));
	return id;
}

void rtype::UpdateGraph::_setupLoadingMenuScene()
{
	_setupScene[constants::LOADING_MENU] = std::function(
		[this](Registry& r, SparseArray<components::currentScene_s>& currentScenes)
		{
			Entity backgroundId{ _addSpriteToScene(r, components::sprite_t{0.96f, 0.81f, 0, 0, 1800, 1200, "ressources/LoadingMenu.jpg"}, components::position_t{0, 0}, components::direction_t{0, 0}, components::velocity_t{0, 0}, components::drawable_t{true}, components::scene_t{constants::LOADING_MENU}, components::zaxis_t{10}) };
			Entity transitionId{ _addSpriteToScene(r, components::sprite_t{ static_cast<float>(WINDOW_SIZE_X / 250), static_cast<float>(WINDOW_SIZE_Y / 250), 0, 0, 1920, 1080, "ressources/noir.jpg" }, components::position_t{0, 0}, components::direction_t{ 0, 0 }, components::velocity_t{ 0, 0 }, components::drawable_t{ true }, components::scene_t{ constants::LOADING_MENU }, components::zaxis_t{  }) };
			Entity musicId = _createMusicLoadingMenu(r);
			_graphicalLib->createSprite(backgroundId, r.getComponents<components::sprite_t>()[backgroundId].value().scaleX, r.getComponents<components::sprite_t>()[backgroundId].value().scaleY, r.getComponents<components::sprite_t>()[backgroundId].value().rectX, r.getComponents<components::sprite_t>()[backgroundId].value().rectY, r.getComponents<components::sprite_t>()[backgroundId].value().rectWidth, r.getComponents<components::sprite_t>()[backgroundId].value().rectHeight, r.getComponents<components::sprite_t>()[backgroundId].value().path);
			_graphicalLib->createSprite(transitionId, r.getComponents<components::sprite_t>()[transitionId].value().scaleX, r.getComponents<components::sprite_t>()[transitionId].value().scaleY, r.getComponents<components::sprite_t>()[transitionId].value().rectX, r.getComponents<components::sprite_t>()[transitionId].value().rectY, r.getComponents<components::sprite_t>()[transitionId].value().rectWidth, r.getComponents<components::sprite_t>()[transitionId].value().rectHeight, r.getComponents<components::sprite_t>()[transitionId].value().path);
			_graphicalLib->createMusic(musicId, r.getComponents<components::music_s>()[musicId].value().path);
			_graphicalLib->setSpriteColorAlpha(transitionId, 255);
			_graphicalLib->play(musicId);
			if (currentScenes[constants::GRAPH_UPDATE])
				currentScenes[constants::GRAPH_UPDATE].value().isLoaded = true;
		});
}

void rtype::UpdateGraph::_setupExecLoadingMenuScene()
{
	_execScene[rtype::constants::LOADING_MENU] = std::function(
		[this](Registry& r, SparseArray<components::currentScene_t>& currentScenes)
		{
			static std::chrono::duration dtime = std::chrono::nanoseconds(0);
			static std::chrono::duration dtimeAnim = std::chrono::nanoseconds(0);
			std::vector<int> myZAxises;
			std::map<int, size_t> zAxisMap;
			auto& times = r.getComponents<components::myTime_t>();
			auto& time = times[constants::TIME_UPDATE];
			dtime += time.value().deltaTime;
			dtimeAnim += time.value().deltaTime;
			_graphicalLib->clearScreen();
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
				if (!zaxis.zAxis)
				{
					if (dtime.count() < 8000000000 && dtimeAnim.count() > 5000000 && _graphicalLib->getSpriteColorAlpha(index.idx))
					{
						dtimeAnim = std::chrono::nanoseconds(0);
						_graphicalLib->setSpriteColorAlpha(index.idx, _graphicalLib->getSpriteColorAlpha(index.idx) - 1);
					}
					if (dtime.count() > 8000000000 && dtimeAnim.count() > 5000000 && _graphicalLib->getSpriteColorAlpha(index.idx) < 255)
					{
						dtimeAnim = std::chrono::nanoseconds(0);
						_graphicalLib->setSpriteColorAlpha(index.idx, _graphicalLib->getSpriteColorAlpha(index.idx) + 1);
					}
				}
			}
			if (r.getComponents<components::keyState_t>()[constants::GRAPH_UPDATE].value().keySpace) {
				currentScenes[constants::GRAPH_UPDATE].value().isLoaded = false;
				currentScenes[constants::GRAPH_UPDATE].value().scene = constants::SCENE::MAIN_MENU;
				_graphicalLib->clearScreen();
				dtime = std::chrono::nanoseconds(0);
				dtimeAnim = std::chrono::nanoseconds(0);
				return;
			}
			std::sort(myZAxises.begin(), myZAxises.end(), myCmp);
			std::reverse(myZAxises.begin(), myZAxises.end());
			for (auto i : myZAxises)
				_graphicalLib->draw(zAxisMap[i]);
			_graphicalLib->HandleClose();
			_graphicalLib->refresh();
			if (dtime.count() > 14000000000)
			{
				currentScenes[constants::GRAPH_UPDATE].value().isLoaded = false;
				currentScenes[constants::GRAPH_UPDATE].value().scene = constants::MAIN_MENU;
				_graphicalLib->clearScreen();
				dtime = std::chrono::nanoseconds(0);
				dtimeAnim = std::chrono::nanoseconds(0);
			}
		});
}

void rtype::UpdateGraph::_setupDeleteLoadingMenuScene()
{
	_deleteScene[constants::LOADING_MENU] = std::function(
		[this](Registry& r)
		{
			_graphicalLib->clearScreen();
			for (auto&& [scene, index, music] : Zipper(r.getComponents<components::scene_t>(), r.getComponents<components::index_t>(), r.getComponents<components::music_t>()))
				if (scene.scene == constants::LOADING_MENU)
				{
					_graphicalLib->stop(index.idx);
					_graphicalLib->deleteMusic(index.idx);
				}
			for (auto&& [scene, index, sprite] : Zipper(r.getComponents<components::scene_t>(), r.getComponents<components::index_t>(), r.getComponents<components::sprite_t>()))
				if (scene.scene == constants::LOADING_MENU)
					_graphicalLib->deleteSprite(index.idx);
			for (auto&& [scene, index] : Zipper(r.getComponents<components::scene_t>(), r.getComponents<components::index_t>()))
				if (scene.scene == constants::LOADING_MENU)
				{
					r.getComponents<components::scene_t>().erase(index.idx);
					r.getComponents<components::index_t>().erase(index.idx);
					r.killEntity(r.entityFromIndex(index.idx));
				}
		});
}