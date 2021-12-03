#include "UpdateGraph.hpp"

auto rtype::UpdateGraph::_createBackgroundWaitingRoom(Registry &r) -> Entity
{
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)0.9, (float)0.9, 0, 0, 1920, 1080, "ressources/MainMenu.jpg"};
    struct components::position_s pos = {0, 0};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {true};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::WAITING_ROOM};
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

auto rtype::UpdateGraph::_createYouWaitingRoom(Registry &r) -> Entity
{
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)1, (float)1, 0, 0, 835, 227, "ressources/you.png"};
    struct components::position_s pos = {0, 0};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {false};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::WAITING_ROOM};
    struct components::zaxis_s zaxis = {9};
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

auto rtype::UpdateGraph::_createPlayer1WaitingRoom(Registry &r) -> Entity
{
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)1, (float)1, 0, 0, 835, 227, "ressources/player-1-connected.png"};
    struct components::position_s pos = {0, 0};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {false};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::WAITING_ROOM};
    struct components::zaxis_s zaxis = {8};
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

auto rtype::UpdateGraph::_createPlayer2WaitingRoom(Registry &r) -> Entity
{
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)1, (float)1, 0, 0, 835, 227, "ressources/player-2-connected.png"};
    struct components::position_s pos = {0, 0};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {false};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::WAITING_ROOM};
    struct components::zaxis_s zaxis = {7};
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

auto rtype::UpdateGraph::_createPlayer3WaitingRoom(Registry &r) -> Entity
{
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)1, (float)1, 0, 0, 835, 227, "ressources/player-3-connected.png"};
    struct components::position_s pos = {0, 0};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {false};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::WAITING_ROOM};
    struct components::zaxis_s zaxis = {6};
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

auto rtype::UpdateGraph::_createPlayer4WaitingRoom(Registry &r) -> Entity
{
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)1, (float)1, 0, 0, 835, 227, "ressources/player-4-connected.png"};
    struct components::position_s pos = {0, 0};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {false};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::WAITING_ROOM};
    struct components::zaxis_s zaxis = {5};
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

auto rtype::UpdateGraph::_setupWaitingRoomScene() -> void
{
    _setupScene[rtype::constants::SCENE::WAITING_ROOM] = std::function(
        [this](Registry &r, SparseArray<components::currentScene_s> &currentScenes) -> void
        {
            Entity backgroundId = _createBackgroundWaitingRoom(r);
            Entity youId = _createYouWaitingRoom(r);
            Entity player1 = _createPlayer1WaitingRoom(r);
            Entity player2 = _createPlayer2WaitingRoom(r);
            Entity player3 = _createPlayer3WaitingRoom(r);
            Entity player4 = _createPlayer4WaitingRoom(r);
            _graphicalLib->createSprite(backgroundId, r.getComponents<components::sprite_s>()[backgroundId].value().scaleX, r.getComponents<components::sprite_s>()[backgroundId].value().scaleY, r.getComponents<components::sprite_s>()[backgroundId].value().rectX, r.getComponents<components::sprite_s>()[backgroundId].value().rectY, r.getComponents<components::sprite_s>()[backgroundId].value().rectWidth, r.getComponents<components::sprite_s>()[backgroundId].value().rectHeight, r.getComponents<components::sprite_s>()[backgroundId].value().path);
            _graphicalLib->createSprite(youId, r.getComponents<components::sprite_s>()[youId].value().scaleX, r.getComponents<components::sprite_s>()[youId].value().scaleY, r.getComponents<components::sprite_s>()[youId].value().rectX, r.getComponents<components::sprite_s>()[youId].value().rectY, r.getComponents<components::sprite_s>()[youId].value().rectWidth, r.getComponents<components::sprite_s>()[youId].value().rectHeight, r.getComponents<components::sprite_s>()[youId].value().path);
            _graphicalLib->createSprite(player1, r.getComponents<components::sprite_s>()[player1].value().scaleX, r.getComponents<components::sprite_s>()[player1].value().scaleY, r.getComponents<components::sprite_s>()[player1].value().rectX, r.getComponents<components::sprite_s>()[player1].value().rectY, r.getComponents<components::sprite_s>()[player1].value().rectWidth, r.getComponents<components::sprite_s>()[player1].value().rectHeight, r.getComponents<components::sprite_s>()[player1].value().path);
            _graphicalLib->createSprite(player2, r.getComponents<components::sprite_s>()[player2].value().scaleX, r.getComponents<components::sprite_s>()[player2].value().scaleY, r.getComponents<components::sprite_s>()[player2].value().rectX, r.getComponents<components::sprite_s>()[player2].value().rectY, r.getComponents<components::sprite_s>()[player2].value().rectWidth, r.getComponents<components::sprite_s>()[player2].value().rectHeight, r.getComponents<components::sprite_s>()[player2].value().path);
            _graphicalLib->createSprite(player3, r.getComponents<components::sprite_s>()[player3].value().scaleX, r.getComponents<components::sprite_s>()[player3].value().scaleY, r.getComponents<components::sprite_s>()[player3].value().rectX, r.getComponents<components::sprite_s>()[player3].value().rectY, r.getComponents<components::sprite_s>()[player3].value().rectWidth, r.getComponents<components::sprite_s>()[player3].value().rectHeight, r.getComponents<components::sprite_s>()[player3].value().path);
            _graphicalLib->createSprite(player4, r.getComponents<components::sprite_s>()[player4].value().scaleX, r.getComponents<components::sprite_s>()[player4].value().scaleY, r.getComponents<components::sprite_s>()[player4].value().rectX, r.getComponents<components::sprite_s>()[player4].value().rectY, r.getComponents<components::sprite_s>()[player4].value().rectWidth, r.getComponents<components::sprite_s>()[player4].value().rectHeight, r.getComponents<components::sprite_s>()[player4].value().path);
            auto &scene = currentScenes[constants::RESERVED_ID::GRAPH_UPDATE];
            if (scene)
                scene.value().isLoaded = true;
        });
}

auto rtype::UpdateGraph::_setupExecWaitingRoomScene() -> void
{
    _execScene[rtype::constants::SCENE::WAITING_ROOM] = std::function(
        [this](Registry &r, SparseArray<components::currentScene_s> &currentScenes) -> void
        {
            std::vector<int> myZAxises;
            std::map<int, std::pair<size_t, constants::TYPE>> zAxisMap;
            for (auto &&[pos, sprite, scene, drawable, index, zaxis] : Zipper(r.getComponents<components::position_s>(), r.getComponents<components::sprite_s>(), r.getComponents<components::scene_s>(), r.getComponents<components::drawable_s>(), r.getComponents<components::index_s>(), r.getComponents<components::zaxis_s>()))
            {
                if (!(drawable.drawable) || scene.scene != constants::SCENE::WAITING_ROOM)
                    continue;
                myZAxises.push_back((int)zaxis.zAxis);
                zAxisMap[(int)zaxis.zAxis] = std::pair(index.idx, constants::TYPE::SPRITE);
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
        });
}

auto rtype::UpdateGraph::_setupDeleteWaitingRoomScene() -> void
{
    _deleteScene[rtype::constants::WAITING_ROOM] = std::function(
        [this](Registry &r)
        {
            _graphicalLib->clearScreen();
            for (auto &&[scene, index, music] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>(), r.getComponents<components::music_s>()))
                if (scene.scene == constants::SCENE::WAITING_ROOM)
                {
                    _graphicalLib->stop(index.idx);
                    _graphicalLib->deleteMusic(index.idx);
                }
            for (auto &&[scene, index, sprite] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>(), r.getComponents<components::sprite_s>()))
                if (scene.scene == constants::SCENE::WAITING_ROOM)
                    _graphicalLib->deleteSprite(index.idx);
            for (auto &&[scene, index] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>()))
                if (scene.scene == constants::SCENE::WAITING_ROOM)
                {
                    r.getComponents<components::scene_s>().erase(index.idx);
                    r.getComponents<components::index_s>().erase(index.idx);
                    r.killEntity(r.entityFromIndex(index.idx));
                }
            _graphicalLib->clearScreen();
        });
}