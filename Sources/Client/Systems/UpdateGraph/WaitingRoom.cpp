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
    auto &playerList = r.getComponents<components::playerList_s>()[constants::RESERVED_ID::GRAPH_UPDATE];
    struct components::sprite_s sprite = {(float)0.5, (float)0.5, 0, 0, 835, 227, "ressources/you.png"};
    struct components::position_s pos = {200, 250};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {true};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::WAITING_ROOM};
    struct components::zaxis_s zaxis = {9};
    struct components::playerData_s playerData = {playerList.value().self, true};
    r.addComponent<components::playerData_s>(r.entityFromIndex(id), std::move(playerData));
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
    auto &playerList = r.getComponents<components::playerList_s>()[constants::RESERVED_ID::GRAPH_UPDATE];
    struct components::sprite_s sprite = {(float)0.5, (float)0.5, 0, 0, 835, 227, "ressources/player-1-connected.png"};
    struct components::position_s pos = {200, 250};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {false};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::WAITING_ROOM};
    struct components::zaxis_s zaxis = {8};
    struct components::playerData_s playerData = {1, (playerList.value().self == 1) ? true : false};
    r.addComponent<components::playerData_s>(r.entityFromIndex(id), std::move(playerData));
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
    auto &playerList = r.getComponents<components::playerList_s>()[constants::RESERVED_ID::GRAPH_UPDATE];
    struct components::sprite_s sprite = {(float)0.5, (float)0.5, 0, 0, 835, 227, "ressources/player-2-connected.png"};
    struct components::position_s pos = {1520, 250};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {false};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::WAITING_ROOM};
    struct components::zaxis_s zaxis = {7};
    struct components::playerData_s playerData = {2, (playerList.value().self == 2) ? true : false};
    r.addComponent<components::playerData_s>(r.entityFromIndex(id), std::move(playerData));
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
    auto &playerList = r.getComponents<components::playerList_s>()[constants::RESERVED_ID::GRAPH_UPDATE];
    struct components::sprite_s sprite = {(float)0.5, (float)0.5, 0, 0, 835, 227, "ressources/player-3-connected.png"};
    struct components::position_s pos = {200, 600};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {false};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::WAITING_ROOM};
    struct components::zaxis_s zaxis = {6};
    struct components::playerData_s playerData = {3, (playerList.value().self == 3) ? true : false};
    r.addComponent<components::playerData_s>(r.entityFromIndex(id), std::move(playerData));
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
    auto &playerList = r.getComponents<components::playerList_s>()[constants::RESERVED_ID::GRAPH_UPDATE];
    struct components::sprite_s sprite = {(float)0.5, (float)0.5, 0, 0, 835, 227, "ressources/player-4-connected.png"};
    struct components::position_s pos = {1520, 600};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {false};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::WAITING_ROOM};
    struct components::zaxis_s zaxis = {5};
    struct components::playerData_s playerData = {4, (playerList.value().self == 4) ? true : false};
    r.addComponent<components::playerData_s>(r.entityFromIndex(id), std::move(playerData));
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
            auto playerList = r.getComponents<components::playerList_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value();
            if (playerList.self == 1)
            {
                Entity player1 = _createYouWaitingRoom(r);
                _graphicalLib->createSprite(player1, r.getComponents<components::sprite_s>()[player1].value().scaleX, r.getComponents<components::sprite_s>()[player1].value().scaleY, r.getComponents<components::sprite_s>()[player1].value().rectX, r.getComponents<components::sprite_s>()[player1].value().rectY, r.getComponents<components::sprite_s>()[player1].value().rectWidth, r.getComponents<components::sprite_s>()[player1].value().rectHeight, r.getComponents<components::sprite_s>()[player1].value().path);
            }
            else
            {
                Entity player1 = _createPlayer1WaitingRoom(r);
                _graphicalLib->createSprite(player1, r.getComponents<components::sprite_s>()[player1].value().scaleX, r.getComponents<components::sprite_s>()[player1].value().scaleY, r.getComponents<components::sprite_s>()[player1].value().rectX, r.getComponents<components::sprite_s>()[player1].value().rectY, r.getComponents<components::sprite_s>()[player1].value().rectWidth, r.getComponents<components::sprite_s>()[player1].value().rectHeight, r.getComponents<components::sprite_s>()[player1].value().path);
            }
            if (playerList.self == 2)
            {
                Entity player2 = _createYouWaitingRoom(r);
                _graphicalLib->createSprite(player2, r.getComponents<components::sprite_s>()[player2].value().scaleX, r.getComponents<components::sprite_s>()[player2].value().scaleY, r.getComponents<components::sprite_s>()[player2].value().rectX, r.getComponents<components::sprite_s>()[player2].value().rectY, r.getComponents<components::sprite_s>()[player2].value().rectWidth, r.getComponents<components::sprite_s>()[player2].value().rectHeight, r.getComponents<components::sprite_s>()[player2].value().path);
            }
            else
            {
                Entity player2 = _createPlayer2WaitingRoom(r);
                _graphicalLib->createSprite(player2, r.getComponents<components::sprite_s>()[player2].value().scaleX, r.getComponents<components::sprite_s>()[player2].value().scaleY, r.getComponents<components::sprite_s>()[player2].value().rectX, r.getComponents<components::sprite_s>()[player2].value().rectY, r.getComponents<components::sprite_s>()[player2].value().rectWidth, r.getComponents<components::sprite_s>()[player2].value().rectHeight, r.getComponents<components::sprite_s>()[player2].value().path);
            }
            if (playerList.self == 3)
            {
                Entity player3 = _createYouWaitingRoom(r);
                _graphicalLib->createSprite(player3, r.getComponents<components::sprite_s>()[player3].value().scaleX, r.getComponents<components::sprite_s>()[player3].value().scaleY, r.getComponents<components::sprite_s>()[player3].value().rectX, r.getComponents<components::sprite_s>()[player3].value().rectY, r.getComponents<components::sprite_s>()[player3].value().rectWidth, r.getComponents<components::sprite_s>()[player3].value().rectHeight, r.getComponents<components::sprite_s>()[player3].value().path);
            }
            else
            {
                Entity player3 = _createPlayer3WaitingRoom(r);
                _graphicalLib->createSprite(player3, r.getComponents<components::sprite_s>()[player3].value().scaleX, r.getComponents<components::sprite_s>()[player3].value().scaleY, r.getComponents<components::sprite_s>()[player3].value().rectX, r.getComponents<components::sprite_s>()[player3].value().rectY, r.getComponents<components::sprite_s>()[player3].value().rectWidth, r.getComponents<components::sprite_s>()[player3].value().rectHeight, r.getComponents<components::sprite_s>()[player3].value().path);
            }
            if (playerList.self == 4)
            {
                Entity player4 = _createYouWaitingRoom(r);
                _graphicalLib->createSprite(player4, r.getComponents<components::sprite_s>()[player4].value().scaleX, r.getComponents<components::sprite_s>()[player4].value().scaleY, r.getComponents<components::sprite_s>()[player4].value().rectX, r.getComponents<components::sprite_s>()[player4].value().rectY, r.getComponents<components::sprite_s>()[player4].value().rectWidth, r.getComponents<components::sprite_s>()[player4].value().rectHeight, r.getComponents<components::sprite_s>()[player4].value().path);
            }
            else
            {
                Entity player4 = _createPlayer4WaitingRoom(r);
                _graphicalLib->createSprite(player4, r.getComponents<components::sprite_s>()[player4].value().scaleX, r.getComponents<components::sprite_s>()[player4].value().scaleY, r.getComponents<components::sprite_s>()[player4].value().rectX, r.getComponents<components::sprite_s>()[player4].value().rectY, r.getComponents<components::sprite_s>()[player4].value().rectWidth, r.getComponents<components::sprite_s>()[player4].value().rectHeight, r.getComponents<components::sprite_s>()[player4].value().path);
            }
            Entity backgroundId = _createBackgroundWaitingRoom(r);
            _graphicalLib->createSprite(backgroundId, r.getComponents<components::sprite_s>()[backgroundId].value().scaleX, r.getComponents<components::sprite_s>()[backgroundId].value().scaleY, r.getComponents<components::sprite_s>()[backgroundId].value().rectX, r.getComponents<components::sprite_s>()[backgroundId].value().rectY, r.getComponents<components::sprite_s>()[backgroundId].value().rectWidth, r.getComponents<components::sprite_s>()[backgroundId].value().rectHeight, r.getComponents<components::sprite_s>()[backgroundId].value().path);
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
            (void)currentScenes;
            static std::chrono::duration dtime = std::chrono::nanoseconds(0);
            auto& time = r.getComponents<components::myTime_s>()[constants::RESERVED_ID::TIME_UPDATE];
            dtime += time.value().deltaTime;
            std::vector<size_t> savedIdx {};
            auto &playerList = r.getComponents<components::playerList_s>()[constants::RESERVED_ID::GRAPH_UPDATE];
            std::vector<int> myZAxises;
            std::map<int, std::pair<size_t, constants::TYPE>> zAxisMap;
            auto& net = r.getComponents<components::network_s>()[constants::RESERVED_ID::NETWORK_UPDATE];
            for (auto&& [pos, sprite, scene, drawable, index, zaxis, playerData] : Zipper(r.getComponents<components::position_s>(), r.getComponents<components::sprite_s>(), r.getComponents<components::scene_s>(), r.getComponents<components::drawable_s>(), r.getComponents<components::index_s>(), r.getComponents<components::zaxis_s>(), r.getComponents<components::playerData_s>())) {
                if (scene.scene != constants::SCENE::WAITING_ROOM)
                    continue;
                if (playerList.value().players > playerData.id)
                    drawable.drawable = true;
            }
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
            if (!(net.value().request16.empty()) && !(net.value().request16.front().empty()))
            {
                playerList.value().players = net.value().request16.front()[1];
            }
            if (dtime.count() > 1500000000) {
                net.value().sendRequest.push_back(std::vector<uint8_t>{22, (uint8_t)(r.getComponents<components::currentRoom_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().id)});
                dtime = std::chrono::nanoseconds(0);
            }
            if (playerList.value().players == 4)
            {
                r.getComponents<components::currentScene_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().isLoaded = false;
                r.getComponents<components::currentScene_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().scene = constants::SCENE::LOADING_MENU;
            }
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