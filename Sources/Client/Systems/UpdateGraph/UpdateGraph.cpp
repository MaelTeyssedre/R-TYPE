#include "UpdateGraph.hpp"
#include <algorithm>
#include <vector>

rtype::UpdateGraph::UpdateGraph()
{
	_graphicalLib = new rtype::GraphicalLib();
	_setupScenes();
	_setupExecScene();
	_setupDeleteScene();
}

rtype::UpdateGraph::UpdateGraph(UpdateGraph&& other) noexcept
	: _graphicalLib{ other._graphicalLib }, _setupScene{ other._setupScene }, _execScene{ other._execScene }, _deleteScene{ other._deleteScene } {}

void rtype::UpdateGraph::operator()(Registry& r, SparseArray<components::mouseState_s>& mouseStates, SparseArray<components::keyState_s>& keyStates, SparseArray<components::currentScene_s>& currentScenes)
{
	_updateEvent(mouseStates, keyStates);
	_updateGraph(r, mouseStates, keyStates, currentScenes);
}

void rtype::UpdateGraph::_updateGraph(Registry& r, SparseArray<components::mouseState_s>& mouseStates, SparseArray<components::keyState_s>& keyStates, SparseArray<components::currentScene_s>& currentScenes)
{
	(void)keyStates;
	(void)mouseStates;
	static constants::SCENE previous_scene{ constants::LOADING_MENU };
	for (auto&& [scene] : Zipper(currentScenes))
		if (!scene.isLoaded)
		{
			_deleteScene[previous_scene](r);
			previous_scene = currentScenes[constants::GRAPH_UPDATE].value().scene;
			_setupScene[currentScenes[constants::GRAPH_UPDATE].value().scene](r, currentScenes);
		}
	_execScene[currentScenes[constants::GRAPH_UPDATE].value().scene](r, currentScenes);
}

void rtype::UpdateGraph::_updateEvent(SparseArray<components::mouseState_s>& mouseStates, SparseArray<components::keyState_s>& keyStates)
{
	rtype::mouse_t mouse{ _graphicalLib->getMouseState() };
	for (auto&& [mouseState] : Zipper(mouseStates))
	{
		mouseState.mousePosX = mouse.posX;
		mouseState.mousePosY = mouse.posY;
		mouseState.mouseLeftClick = mouse.leftPressed;
		mouseState.mouseRightClick = mouse.rightPressed;
	}
	for (auto&& [keyState] : Zipper(keyStates))
	{
		keyState.keyDown = _graphicalLib->getKeyState(constants::KEY_DOWN);
		keyState.keyUp = _graphicalLib->getKeyState(constants::KEY_UP);
		keyState.keyRight = _graphicalLib->getKeyState(constants::KEY_RIGHT);
		keyState.keyLeft = _graphicalLib->getKeyState(constants::KEY_LEFT);
		keyState.keyEnter = _graphicalLib->getKeyState(constants::KEY_ENTER);
		keyState.keySpace = _graphicalLib->getKeyState(constants::KEY_SPACE);
	}
}

auto rtype::UpdateGraph::_setupScenes() -> void
{
	_setupLoadingMenuScene();
	_setupMainMenuScene();
	_setupWaitingRoomScene();
	_setupSelectRoomScene();
}

auto rtype::UpdateGraph::_setupExecScene() -> void
{
	_setupExecLoadingMenuScene();
	_setupExecMainMenuScene();
	_setupExecWaitingRoomScene();
	_setupExecSelectRoomScene();
}

auto rtype::UpdateGraph::_setupDeleteScene() -> void
{
	_setupDeleteLoadingMenuScene();
	_setupDeleteMainMenuScene();
	_setupDeleteWaitingRoomScene();
	_setupDeleteSelectRoomScene();
}

auto rtype::UpdateGraph::_addSpriteToScene(Registry& r, components::sprite_t sprite, components::position_t pos, components::direction_t dir, components::velocity_t vel, components::drawable_t draw, components::scene_t scene, components::zaxis_t zaxis)->Entity
{
	Entity id{ r.spawnEntity() };
	r.addComponent<components::sprite_t>(r.entityFromIndex(id), std::move(sprite));
	r.addComponent<components::index_s>(r.entityFromIndex(id), std::move(components::index_t{ id }));
	r.addComponent<components::position_s>(r.entityFromIndex(id), std::move(pos));
	r.addComponent<components::velocity_t>(r.entityFromIndex(id), std::move(vel));
	r.addComponent<components::direction_s>(r.entityFromIndex(id), std::move(dir));
	r.addComponent<components::scene_s>(r.entityFromIndex(id), std::move(scene));
	r.addComponent<components::drawable_s>(r.entityFromIndex(id), std::move(draw));
	r.addComponent<components::zaxis_t>(r.entityFromIndex(id), std::move(zaxis));
	return id;
}

auto rtype::UpdateGraph::_addButtonToScene(Registry& r, components::sprite_t sprite, components::position_t pos, components::direction_t dir, components::velocity_t vel, components::drawable_t draw, components::scene_t scene, components::zaxis_t zaxis, components::clickable_t clickable, components::mouseState_t mouse, components::mySize_t size)->Entity
{
	Entity id{ r.spawnEntity() };
	r.addComponent<components::sprite_t>(r.entityFromIndex(id), std::move(sprite));
	r.addComponent<components::index_s>(r.entityFromIndex(id), std::move(components::index_t{ id }));
	r.addComponent<components::position_s>(r.entityFromIndex(id), std::move(pos));
	r.addComponent<components::velocity_t>(r.entityFromIndex(id), std::move(vel));
	r.addComponent<components::direction_s>(r.entityFromIndex(id), std::move(dir));
	r.addComponent<components::scene_s>(r.entityFromIndex(id), std::move(scene));
	r.addComponent<components::drawable_s>(r.entityFromIndex(id), std::move(draw));
	r.addComponent<components::clickable_s>(r.entityFromIndex(id), std::move(clickable));
	r.addComponent<components::mouseState_s>(r.entityFromIndex(id), std::move(mouse));
	r.addComponent<components::zaxis_t>(r.entityFromIndex(id), std::move(zaxis));
	r.addComponent<components::mySize_s>(r.entityFromIndex(id), std::move(size));
	return id;
}