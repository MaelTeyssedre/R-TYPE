#include "UpdateGraph.hpp"


Entity rtype::UpdateGraph::_createBackgroundWaitingRoom(Registry &r)
{
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)0.9, (float)0.9, 0, 0, 1920, 1080, "ressources/MainMenu.jpg"};
    struct components::position_s pos = {0, 0};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {true};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::MAIN_MENU};
    struct components::zaxis_s zaxis = {10};

    r.addComponent<components::sprite_s>(r.entityFromIndex(id), std::move(sprite));
    r.addComponent<components::index_s>(r.entityFromIndex(id), std::move(idx));
    r.addComponent<components::position_s>(r.entityFromIndex(id), std::move(pos));
    r.addComponent<components::velocity_s>(r.entityFromIndex(id), std::move(vel));
    r.addComponent<components::direction_s>(r.entityFromIndex(id), std::move(dir));
    r.addComponent<components::scene_s>(r.entityFromIndex(id), std::move(my_scene));
    r.addComponent<components::drawable_s>(r.entityFromIndex(id), std::move(drawable));
    r.addComponent<components::zaxis_s>(r.entityFromIndex(id), std::move(zaxis));
    return id;
}

Entity rtype::UpdateGraph::_createTransitionWaitingRoom(Registry &r)
{
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)WINDOW_SIZE_X / 250, (float)WINDOW_SIZE_Y / 250, 0, 0, 1920, 1080, "ressources/noir.jpg"};
    struct components::position_s pos = {0, 0};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {true};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::MAIN_MENU};
    struct components::zaxis_s zaxis = {0};

    r.addComponent<components::sprite_s>(r.entityFromIndex(id), std::move(sprite));
    r.addComponent<components::index_s>(r.entityFromIndex(id), std::move(idx));
    r.addComponent<components::position_s>(r.entityFromIndex(id), std::move(pos));
    r.addComponent<components::velocity_s>(r.entityFromIndex(id), std::move(vel));
    r.addComponent<components::direction_s>(r.entityFromIndex(id), std::move(dir));
    r.addComponent<components::scene_s>(r.entityFromIndex(id), std::move(my_scene));
    r.addComponent<components::drawable_s>(r.entityFromIndex(id), std::move(drawable));
    r.addComponent<components::zaxis_s>(r.entityFromIndex(id), std::move(zaxis));

    return id;
}

void rtype::UpdateGraph::_setupWaitingRoomScene()
{
    _setupScene[rtype::constants::WAITING_ROOM] = std::function(
        [this](Registry &r, SparseArray<components::currentScene_s> &currentScene)
        {
            Entity backgroundId = _createBackgroundWaitingRoom(r);
            Entity transitionId = _createTransitionWaitingRoom(r);
            _graphicalLib->createSprite(backgroundId, r.getComponents<components::sprite_s>()[backgroundId].value().scaleX, r.getComponents<components::sprite_s>()[backgroundId].value().scaleY, r.getComponents<components::sprite_s>()[backgroundId].value().rectX, r.getComponents<components::sprite_s>()[backgroundId].value().rectY, r.getComponents<components::sprite_s>()[backgroundId].value().rectWidth, r.getComponents<components::sprite_s>()[backgroundId].value().rectHeight, r.getComponents<components::sprite_s>()[backgroundId].value().path);
            _graphicalLib->createSprite(transitionId, r.getComponents<components::sprite_s>()[transitionId].value().scaleX, r.getComponents<components::sprite_s>()[transitionId].value().scaleY, r.getComponents<components::sprite_s>()[transitionId].value().rectX, r.getComponents<components::sprite_s>()[transitionId].value().rectY, r.getComponents<components::sprite_s>()[transitionId].value().rectWidth, r.getComponents<components::sprite_s>()[transitionId].value().rectHeight, r.getComponents<components::sprite_s>()[transitionId].value().path);
        }
    );
}

void rtype::UpdateGraph::_setupExecWaitingRoomScene()
{

}

void rtype::UpdateGraph::_setupDeleteWaitingRoomScene()
{

}