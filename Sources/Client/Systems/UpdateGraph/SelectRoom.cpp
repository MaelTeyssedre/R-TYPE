#include "UpdateGraph.hpp"

Entity rtype::UpdateGraph::_createBackgroundSelectRoom(Registry &r)
{
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)0.9, (float)0.9, 0, 0, 1920, 1080, "ressources/MainMenu.jpg"};
    struct components::position_s pos = {0, 0};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {true};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::SELECT_ROOM};
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

auto rtype::UpdateGraph::_createLogoSelectRoom(Registry &r) -> Entity
{
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)0.9, (float)0.9, 0, 0, 663, 369, "ressources/logo.png"};
    struct components::position_s pos = {(WINDOW_SIZE_X * 0.5) - ((663) / 2), WINDOW_SIZE_Y * 0.25};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {true};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::SELECT_ROOM};
    struct components::zaxis_s zaxis = {4};
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

auto rtype::UpdateGraph::_createSelectRoom1ButtonSelectRoom(Registry &r) -> Entity
{
    auto &roomList = r.getComponents<components::roomList_s>()[constants::RESERVED_ID::GRAPH_UPDATE];
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)0.5, (float)0.5, 0, 0, 800, 215, "ressources/room1.png"};
    struct components::clickable_s clickable = {
        false,
        false, [this](Registry &r, size_t id) -> void
        { r.getComponents<components::sprite_s>()[id].value().rectY = 215; },
        [this](Registry &r, size_t id) -> void
        {
            r.getComponents<components::sprite_s>()[id].value().rectY = 0;
            r.getComponents<components::network_s>()[constants::RESERVED_ID::NETWORK_UPDATE].value().sendRequest.push_back(std::vector<uint8_t>{19, 1});
            r.getComponents<components::currentRoom_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().id = 1;
        }};
    struct components::position_s pos = {WINDOW_SIZE_X * 0.1, WINDOW_SIZE_Y * 0.5 };
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {true};
    struct components::mouseState_s mouse = {0, 0, false, false};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::SELECT_ROOM};
    struct components::zaxis_s zaxis = {9};
    struct components::mySize_s size = {400, 215};
    struct components::roomData_s roomData = {roomList.value().room1};
    r.addComponent<components::sprite_s>(r.entityFromIndex(id), std::move(sprite));
    r.addComponent<components::index_s>(r.entityFromIndex(id), std::move(idx));
    r.addComponent<components::position_s>(r.entityFromIndex(id), std::move(pos));
    r.addComponent<components::velocity_s>(r.entityFromIndex(id), std::move(vel));
    r.addComponent<components::direction_s>(r.entityFromIndex(id), std::move(dir));
    r.addComponent<components::scene_s>(r.entityFromIndex(id), std::move(my_scene));
    r.addComponent<components::drawable_s>(r.entityFromIndex(id), std::move(drawable));
    r.addComponent<components::clickable_s>(r.entityFromIndex(id), std::move(clickable));
    r.addComponent<components::mouseState_s>(r.entityFromIndex(id), std::move(mouse));
    r.addComponent<components::zaxis_s>(r.entityFromIndex(id), std::move(zaxis));
    r.addComponent<components::mySize_s>(r.entityFromIndex(id), std::move(size));
    r.addComponent<components::roomData_s>(r.entityFromIndex(id), std::move(roomData));

    return id;
}

auto rtype::UpdateGraph::_createSelectRoom2ButtonSelectRoom(Registry &r) -> Entity
{
    auto &roomList = r.getComponents<components::roomList_s>()[constants::RESERVED_ID::GRAPH_UPDATE];

    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)0.5, (float)0.5, 0, 0, 800, 215, "ressources/room2.png"};
    struct components::clickable_s clickable = {
        false,
        false, [this](Registry &r, size_t id) -> void
        { r.getComponents<components::sprite_s>()[id].value().rectY = 215; },
        [this](Registry &r, size_t id) -> void
        {
            r.getComponents<components::sprite_s>()[id].value().rectY = 0;
            r.getComponents<components::network_s>()[constants::RESERVED_ID::NETWORK_UPDATE].value().sendRequest.push_back(std::vector<uint8_t>{19, 2});
            r.getComponents<components::currentRoom_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().id = 2;
        }};
    struct components::position_s pos = { WINDOW_SIZE_X * 0.1, WINDOW_SIZE_Y * 0.8 };
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {true};
    struct components::mouseState_s mouse = {0, 0, false, false};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::SELECT_ROOM};
    struct components::zaxis_s zaxis = {8};
    struct components::mySize_s size = {400, 215};
    struct components::roomData_s roomData = {roomList.value().room2};
    r.addComponent<components::sprite_s>(r.entityFromIndex(id), std::move(sprite));
    r.addComponent<components::index_s>(r.entityFromIndex(id), std::move(idx));
    r.addComponent<components::position_s>(r.entityFromIndex(id), std::move(pos));
    r.addComponent<components::velocity_s>(r.entityFromIndex(id), std::move(vel));
    r.addComponent<components::direction_s>(r.entityFromIndex(id), std::move(dir));
    r.addComponent<components::scene_s>(r.entityFromIndex(id), std::move(my_scene));
    r.addComponent<components::drawable_s>(r.entityFromIndex(id), std::move(drawable));
    r.addComponent<components::clickable_s>(r.entityFromIndex(id), std::move(clickable));
    r.addComponent<components::mouseState_s>(r.entityFromIndex(id), std::move(mouse));
    r.addComponent<components::zaxis_s>(r.entityFromIndex(id), std::move(zaxis));
    r.addComponent<components::mySize_s>(r.entityFromIndex(id), std::move(size));
    r.addComponent<components::roomData_s>(r.entityFromIndex(id), std::move(roomData));
    return id;
}

auto rtype::UpdateGraph::_createSelectRoom3ButtonSelectRoom(Registry &r) -> Entity
{
    auto &roomList = r.getComponents<components::roomList_s>()[constants::RESERVED_ID::GRAPH_UPDATE];

    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)0.5, (float)0.5, 0, 0, 800, 215, "ressources/room3.png"};
    struct components::clickable_s clickable = {
        false,
        false, [this](Registry &r, size_t id) -> void
        { r.getComponents<components::sprite_s>()[id].value().rectY = 215; },
        [this](Registry &r, size_t id) -> void
        {
            r.getComponents<components::sprite_s>()[id].value().rectY = 0;
            r.getComponents<components::network_s>()[constants::RESERVED_ID::NETWORK_UPDATE].value().sendRequest.push_back(std::vector<uint8_t>{19, 3});
            r.getComponents<components::currentRoom_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().id = 3;
        }};
    struct components::position_s pos = { (float)((WINDOW_SIZE_X * 0.4) - (sprite.rectX * sprite.scaleX)) , WINDOW_SIZE_Y * 0.65 };
    struct components::direction_s dir = { 0, 0 };
    struct components::velocity_s vel = { 0, 0 };
    struct components::drawable_s drawable = { true };
    struct components::mouseState_s mouse = { 0, 0, false, false };
    struct components::index_s idx = { id };
    struct components::scene_s my_scene = { constants::SCENE::SELECT_ROOM };
    struct components::zaxis_s zaxis = { 3 };
    struct components::mySize_s size = { 400, 215 };
    struct components::roomData_s roomData = { roomList.value().room3 };
    r.addComponent<components::sprite_s>(r.entityFromIndex(id), std::move(sprite));
    r.addComponent<components::index_s>(r.entityFromIndex(id), std::move(idx));
    r.addComponent<components::position_s>(r.entityFromIndex(id), std::move(pos));
    r.addComponent<components::velocity_s>(r.entityFromIndex(id), std::move(vel));
    r.addComponent<components::direction_s>(r.entityFromIndex(id), std::move(dir));
    r.addComponent<components::scene_s>(r.entityFromIndex(id), std::move(my_scene));
    r.addComponent<components::drawable_s>(r.entityFromIndex(id), std::move(drawable));
    r.addComponent<components::clickable_s>(r.entityFromIndex(id), std::move(clickable));
    r.addComponent<components::mouseState_s>(r.entityFromIndex(id), std::move(mouse));
    r.addComponent<components::zaxis_s>(r.entityFromIndex(id), std::move(zaxis));
    r.addComponent<components::mySize_s>(r.entityFromIndex(id), std::move(size));
    r.addComponent<components::roomData_s>(r.entityFromIndex(id), std::move(roomData));

    return id;
}

auto rtype::UpdateGraph::_createSelectBackButtonSelectRoom(Registry& r) -> Entity
{
    auto& roomList = r.getComponents<components::roomList_s>()[constants::RESERVED_ID::GRAPH_UPDATE];

    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = { (float)0.5, (float)0.5, 0, 0, 583, 183, "ressources/backbtn.png" };
    struct components::clickable_s clickable = {
        false,
        false, [this](Registry& r, size_t id) -> void
        { r.getComponents<components::sprite_s>()[id].value().rectX = 583; },
        [this](Registry& r, size_t id) -> void
        {
            r.getComponents<components::sprite_s>()[id].value().rectX = 0;
            r.getComponents<components::currentScene_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().scene = constants::SCENE::MAIN_MENU;
            r.getComponents<components::currentScene_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().isLoaded = false;
        } };
    struct components::position_s pos = { 0.f, 0.f};
    struct components::direction_s dir = { 0, 0 };
    struct components::velocity_s vel = { 0, 0 };
    struct components::drawable_s drawable = { true };
    struct components::mouseState_s mouse = { 0, 0, false, false };
    struct components::index_s idx = { id };
    struct components::scene_s my_scene = { constants::SCENE::SELECT_ROOM };
    struct components::zaxis_s zaxis = { 3 };
    struct components::mySize_s size = { 400, 215 };
    struct components::roomData_s roomData = { roomList.value().room3 };
    r.addComponent<components::sprite_s>(r.entityFromIndex(id), std::move(sprite));
    r.addComponent<components::index_s>(r.entityFromIndex(id), std::move(idx));
    r.addComponent<components::position_s>(r.entityFromIndex(id), std::move(pos));
    r.addComponent<components::velocity_s>(r.entityFromIndex(id), std::move(vel));
    r.addComponent<components::direction_s>(r.entityFromIndex(id), std::move(dir));
    r.addComponent<components::scene_s>(r.entityFromIndex(id), std::move(my_scene));
    r.addComponent<components::drawable_s>(r.entityFromIndex(id), std::move(drawable));
    r.addComponent<components::clickable_s>(r.entityFromIndex(id), std::move(clickable));
    r.addComponent<components::mouseState_s>(r.entityFromIndex(id), std::move(mouse));
    r.addComponent<components::zaxis_s>(r.entityFromIndex(id), std::move(zaxis));
    r.addComponent<components::mySize_s>(r.entityFromIndex(id), std::move(size));
    r.addComponent<components::roomData_s>(r.entityFromIndex(id), std::move(roomData));

    return id;
}

auto rtype::UpdateGraph::_createSelectRoom4ButtonSelectRoom(Registry &r) -> Entity
{
    auto &roomList = r.getComponents<components::roomList_s>()[constants::RESERVED_ID::GRAPH_UPDATE];

    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)0.5, (float)0.5, 0, 0, 800, 215, "ressources/room4.png"};
    struct components::clickable_s clickable = {
        false,
        false, [this](Registry &r, size_t id) -> void
        { r.getComponents<components::sprite_s>()[id].value().rectY = 215; },
        [this](Registry &r, size_t id) -> void
        {
            r.getComponents<components::sprite_s>()[id].value().rectY = 0;
            r.getComponents<components::network_s>()[constants::RESERVED_ID::NETWORK_UPDATE].value().sendRequest.push_back(std::vector<uint8_t>{19, 4});
            r.getComponents<components::currentRoom_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().id = 4;
        }};
    struct components::position_s pos = { WINDOW_SIZE_X * 0.7, WINDOW_SIZE_Y * 0.5 };
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {true};
    struct components::mouseState_s mouse = {0, 0, false, false};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::SELECT_ROOM};
    struct components::zaxis_s zaxis = {6};
    struct components::mySize_s size = {400, 215};
    struct components::roomData_s roomData = {roomList.value().room4};

    r.addComponent<components::sprite_s>(r.entityFromIndex(id), std::move(sprite));
    r.addComponent<components::index_s>(r.entityFromIndex(id), std::move(idx));
    r.addComponent<components::position_s>(r.entityFromIndex(id), std::move(pos));
    r.addComponent<components::velocity_s>(r.entityFromIndex(id), std::move(vel));
    r.addComponent<components::direction_s>(r.entityFromIndex(id), std::move(dir));
    r.addComponent<components::scene_s>(r.entityFromIndex(id), std::move(my_scene));
    r.addComponent<components::drawable_s>(r.entityFromIndex(id), std::move(drawable));
    r.addComponent<components::clickable_s>(r.entityFromIndex(id), std::move(clickable));
    r.addComponent<components::mouseState_s>(r.entityFromIndex(id), std::move(mouse));
    r.addComponent<components::zaxis_s>(r.entityFromIndex(id), std::move(zaxis));
    r.addComponent<components::mySize_s>(r.entityFromIndex(id), std::move(size));
    r.addComponent<components::roomData_s>(r.entityFromIndex(id), std::move(roomData));

    return id;
}

auto rtype::UpdateGraph::_createSelectRoom5ButtonSelectRoom(Registry &r) -> Entity
{
    auto &roomList = r.getComponents<components::roomList_s>()[constants::RESERVED_ID::GRAPH_UPDATE];

    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)0.5, (float)0.5, 0, 0, 800, 215, "ressources/room5.png"};
    struct components::clickable_s clickable = {
        false,
        false, [this](Registry &r, size_t id) -> void
        { r.getComponents<components::sprite_s>()[id].value().rectY = 215; },
        [this](Registry &r, size_t id) -> void
        {
            r.getComponents<components::sprite_s>()[id].value().rectY = 0;
            r.getComponents<components::network_s>()[constants::RESERVED_ID::NETWORK_UPDATE].value().sendRequest.push_back(std::vector<uint8_t>{19, 5});
            r.getComponents<components::currentRoom_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().id = 5;
        }};
    struct components::position_s pos = { WINDOW_SIZE_X * 0.7, WINDOW_SIZE_Y * 0.8 };
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {true};
    struct components::mouseState_s mouse = {0, 0, false, false};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::SELECT_ROOM};
    struct components::zaxis_s zaxis = {5};
    struct components::mySize_s size = {400, 215};
    struct components::roomData_s roomData = {roomList.value().room5};

    r.addComponent<components::sprite_s>(r.entityFromIndex(id), std::move(sprite));
    r.addComponent<components::index_s>(r.entityFromIndex(id), std::move(idx));
    r.addComponent<components::position_s>(r.entityFromIndex(id), std::move(pos));
    r.addComponent<components::velocity_s>(r.entityFromIndex(id), std::move(vel));
    r.addComponent<components::direction_s>(r.entityFromIndex(id), std::move(dir));
    r.addComponent<components::scene_s>(r.entityFromIndex(id), std::move(my_scene));
    r.addComponent<components::drawable_s>(r.entityFromIndex(id), std::move(drawable));
    r.addComponent<components::clickable_s>(r.entityFromIndex(id), std::move(clickable));
    r.addComponent<components::mouseState_s>(r.entityFromIndex(id), std::move(mouse));
    r.addComponent<components::zaxis_s>(r.entityFromIndex(id), std::move(zaxis));
    r.addComponent<components::mySize_s>(r.entityFromIndex(id), std::move(size));
    r.addComponent<components::roomData_s>(r.entityFromIndex(id), std::move(roomData));
    return id;
}

auto rtype::UpdateGraph::_createSelectRoom5NoRoom(Registry& r) -> Entity
{
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = { (float)0.9, (float)0.9, 0, 0, 663, 369, "ressources/noRoom.png" };
    struct components::position_s pos = { (WINDOW_SIZE_X * 0.5) - ((663) / 2), WINDOW_SIZE_Y * 0.25 };
    struct components::direction_s dir = { 0, 0 };
    struct components::velocity_s vel = { 0, 0 };
    struct components::drawable_s drawable = { true };
    struct components::index_s idx = { id };
    struct components::scene_s my_scene = { constants::SCENE::SELECT_ROOM };
    struct components::zaxis_s zaxis = { 4 };
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

auto rtype::UpdateGraph::_setupSelectRoomScene() -> void
{
    _setupScene[rtype::constants::SELECT_ROOM] = std::function(
        [this](Registry& r, SparseArray<components::currentScene_s>& currentScenes) -> void
        {
            auto roomList{ r.getComponents<components::roomList_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value() };
            if (roomList.room1)
            {
                Entity room1Id{ _createSelectRoom1ButtonSelectRoom(r) };
                _graphicalLib->createSprite(room1Id, r.getComponents<components::sprite_s>()[room1Id].value().scaleX, r.getComponents<components::sprite_s>()[room1Id].value().scaleY, r.getComponents<components::sprite_s>()[room1Id].value().rectX, r.getComponents<components::sprite_s>()[room1Id].value().rectY, r.getComponents<components::sprite_s>()[room1Id].value().rectWidth, r.getComponents<components::sprite_s>()[room1Id].value().rectHeight, r.getComponents<components::sprite_s>()[room1Id].value().path);
            }
            if (roomList.room2)
            {
                Entity room2Id{ _createSelectRoom2ButtonSelectRoom(r) };
                _graphicalLib->createSprite(room2Id, r.getComponents<components::sprite_s>()[room2Id].value().scaleX, r.getComponents<components::sprite_s>()[room2Id].value().scaleY, r.getComponents<components::sprite_s>()[room2Id].value().rectX, r.getComponents<components::sprite_s>()[room2Id].value().rectY, r.getComponents<components::sprite_s>()[room2Id].value().rectWidth, r.getComponents<components::sprite_s>()[room2Id].value().rectHeight, r.getComponents<components::sprite_s>()[room2Id].value().path);
            }
            if (roomList.room3)
            {
                Entity room3Id{ _createSelectRoom3ButtonSelectRoom(r) };
                _graphicalLib->createSprite(room3Id, r.getComponents<components::sprite_s>()[room3Id].value().scaleX, r.getComponents<components::sprite_s>()[room3Id].value().scaleY, r.getComponents<components::sprite_s>()[room3Id].value().rectX, r.getComponents<components::sprite_s>()[room3Id].value().rectY, r.getComponents<components::sprite_s>()[room3Id].value().rectWidth, r.getComponents<components::sprite_s>()[room3Id].value().rectHeight, r.getComponents<components::sprite_s>()[room3Id].value().path);
            }
            if (roomList.room4)
            {
                Entity room4Id{ _createSelectRoom4ButtonSelectRoom(r) };
                _graphicalLib->createSprite(room4Id, r.getComponents<components::sprite_s>()[room4Id].value().scaleX, r.getComponents<components::sprite_s>()[room4Id].value().scaleY, r.getComponents<components::sprite_s>()[room4Id].value().rectX, r.getComponents<components::sprite_s>()[room4Id].value().rectY, r.getComponents<components::sprite_s>()[room4Id].value().rectWidth, r.getComponents<components::sprite_s>()[room4Id].value().rectHeight, r.getComponents<components::sprite_s>()[room4Id].value().path);
            }
            if (roomList.room5)
            {
                Entity room5Id{ _createSelectRoom5ButtonSelectRoom(r) };
                _graphicalLib->createSprite(room5Id, r.getComponents<components::sprite_s>()[room5Id].value().scaleX, r.getComponents<components::sprite_s>()[room5Id].value().scaleY, r.getComponents<components::sprite_s>()[room5Id].value().rectX, r.getComponents<components::sprite_s>()[room5Id].value().rectY, r.getComponents<components::sprite_s>()[room5Id].value().rectWidth, r.getComponents<components::sprite_s>()[room5Id].value().rectHeight, r.getComponents<components::sprite_s>()[room5Id].value().path);
            }
            if (!roomList.room1 && !roomList.room2 && !roomList.room3 && !roomList.room4 && !roomList.room5)
            {
                Entity logoId{ _createSelectRoom5NoRoom(r) };
                _graphicalLib->createSprite(logoId, r.getComponents<components::sprite_s>()[logoId].value().scaleX, r.getComponents<components::sprite_s>()[logoId].value().scaleY, r.getComponents<components::sprite_s>()[logoId].value().rectX, r.getComponents<components::sprite_s>()[logoId].value().rectY, r.getComponents<components::sprite_s>()[logoId].value().rectWidth, r.getComponents<components::sprite_s>()[logoId].value().rectHeight, r.getComponents<components::sprite_s>()[logoId].value().path);
            }
            else
            {
                Entity logoId{ _createLogoMainMenu(r) };
                _graphicalLib->createSprite(logoId, r.getComponents<components::sprite_s>()[logoId].value().scaleX, r.getComponents<components::sprite_s>()[logoId].value().scaleY, r.getComponents<components::sprite_s>()[logoId].value().rectX, r.getComponents<components::sprite_s>()[logoId].value().rectY, r.getComponents<components::sprite_s>()[logoId].value().rectWidth, r.getComponents<components::sprite_s>()[logoId].value().rectHeight, r.getComponents<components::sprite_s>()[logoId].value().path);
            }
            Entity backButton { _createSelectBackButtonSelectRoom(r) };
            _graphicalLib->createSprite(backButton, r.getComponents<components::sprite_s>()[backButton].value().scaleX, r.getComponents<components::sprite_s>()[backButton].value().scaleY, r.getComponents<components::sprite_s>()[backButton].value().rectX, r.getComponents<components::sprite_s>()[backButton].value().rectY, r.getComponents<components::sprite_s>()[backButton].value().rectWidth, r.getComponents<components::sprite_s>()[backButton].value().rectHeight, r.getComponents<components::sprite_s>()[backButton].value().path);
            Entity backgroundId { _createBackgroundMainMenu(r) };
            _graphicalLib->createSprite(backgroundId, r.getComponents<components::sprite_s>()[backgroundId].value().scaleX, r.getComponents<components::sprite_s>()[backgroundId].value().scaleY, r.getComponents<components::sprite_s>()[backgroundId].value().rectX, r.getComponents<components::sprite_s>()[backgroundId].value().rectY, r.getComponents<components::sprite_s>()[backgroundId].value().rectWidth, r.getComponents<components::sprite_s>()[backgroundId].value().rectHeight, r.getComponents<components::sprite_s>()[backgroundId].value().path);
            auto &scene = currentScenes[constants::RESERVED_ID::GRAPH_UPDATE];
            if (scene)
                scene.value().isLoaded = true;
        });
}

auto rtype::UpdateGraph::_setupExecSelectRoomScene() -> void
{
    _execScene[rtype::constants::SELECT_ROOM] = std::function(
        [this](Registry& r, SparseArray<components::currentScene_s>& currentScenes) -> void
        {
            static std::chrono::duration dtime = std::chrono::nanoseconds(0);
            static std::chrono::duration dtimeAnim = std::chrono::nanoseconds(0);
            std::vector<int> myZAxises;
            std::map<int, size_t> zAxisMap;
            auto& net = r.getComponents<components::network_s>()[constants::RESERVED_ID::NETWORK_UPDATE];
            auto& times = r.getComponents<components::myTime_s>();
            auto& time = times[constants::RESERVED_ID::TIME_UPDATE];
            dtimeAnim += time.value().deltaTime;
            dtime += time.value().deltaTime;
            _graphicalLib->clearScreen();
            for (auto&& [pos, sprite, scene, drawable, index, zaxis, roomData] : Zipper(r.getComponents<components::position_s>(), r.getComponents<components::sprite_s>(), r.getComponents<components::scene_s>(), r.getComponents<components::drawable_s>(), r.getComponents<components::index_s>(), r.getComponents<components::zaxis_s>(), r.getComponents<components::roomData_s>()))
            {
                if (!(drawable.drawable) || scene.scene != currentScenes[constants::RESERVED_ID::GRAPH_UPDATE].value().scene)
                    continue;
                myZAxises.push_back((int)zaxis.zAxis);
                zAxisMap[(int)zaxis.zAxis] = index.idx;
                _graphicalLib->setSpritePosX(index.idx, pos.x);
                _graphicalLib->setSpritePosY(index.idx, pos.y);
                _graphicalLib->setSpriteScale(index.idx, sprite.scaleX, sprite.scaleY);
                _graphicalLib->setSpriteRectX(index.idx, sprite.rectX);
                _graphicalLib->setSpriteRectY(index.idx, sprite.rectY);
                _graphicalLib->setSpriteRectWidth(index.idx, sprite.rectWidth);
                _graphicalLib->setSpriteRectHeigth(index.idx, sprite.rectHeight);
            }
            for (auto&& [pos, sprite, scene, drawable, index, zaxis] : Zipper(r.getComponents<components::position_s>(), r.getComponents<components::sprite_s>(), r.getComponents<components::scene_s>(), r.getComponents<components::drawable_s>(), r.getComponents<components::index_s>(), r.getComponents<components::zaxis_s>()))
            {
                if (!(drawable.drawable))
                    continue;
                myZAxises.push_back((int)zaxis.zAxis);
                zAxisMap[(int)zaxis.zAxis] = index.idx;
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
            if (net.value().request10.size())
            {
                net.value().request10.erase(net.value().request10.begin());
                struct components::playerList_s playerList = r.getComponents<components::playerList_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value();
                r.addComponent<components::playerList_s>(r.entityFromIndex(constants::RESERVED_ID::GRAPH_UPDATE), std::move(playerList));
                r.getComponents<components::currentScene_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().isLoaded = false;
                r.getComponents<components::currentScene_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().scene = constants::SCENE::WAITING_ROOM;
            }
        }
    );
}

auto rtype::UpdateGraph::_setupDeleteSelectRoomScene() -> void
{
    _deleteScene[rtype::constants::SELECT_ROOM] = std::function(
        [this](Registry &r)
        {
            _graphicalLib->clearScreen();

            for (auto &&[scene, index, music] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>(), r.getComponents<components::music_s>()))
            {
                if (scene.scene == constants::SCENE::SELECT_ROOM)
                {
                    _graphicalLib->stop(index.idx);
                    _graphicalLib->deleteMusic(index.idx);
                }
            }
            for (auto &&[scene, index, sprite] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>(), r.getComponents<components::sprite_s>()))
            {
                if (scene.scene == constants::SCENE::SELECT_ROOM)
                {
                    _graphicalLib->deleteSprite(index.idx);
                }
            }
            for (auto &&[scene, index, text] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>(), r.getComponents<components::text_s>()))
            {
                if (scene.scene == constants::SCENE::SELECT_ROOM)
                {
                    _graphicalLib->deleteText(index.idx);
                }
            }
            for (auto &&[scene, index] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>()))
            {
                if (scene.scene == constants::SCENE::SELECT_ROOM)
                {
                    r.getComponents<components::scene_s>().erase(index.idx);
                    r.getComponents<components::index_s>().erase(index.idx);
                    r.killEntity(r.entityFromIndex(index.idx));
                }
            }
            _graphicalLib->clearScreen();
        });
}
