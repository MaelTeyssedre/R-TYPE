#include "UpdateGraph.hpp"

auto rtype::UpdateGraph::_createLogoMainMenu(Registry &r) -> Entity
{
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)0.9, (float)0.9, 0, 0, 663, 369, "ressources/logo.png"};
    struct components::position_s pos = {(WINDOW_SIZE_X / 2) - ((663) / 2), 150};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {true};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::MAIN_MENU};
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

auto rtype::UpdateGraph::_createBackgroundMainMenu(Registry &r) -> Entity
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

auto rtype::UpdateGraph::_createTransitionMainMenu(Registry &r) -> Entity
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

auto rtype::UpdateGraph::_createPlayButtonMainMenu(Registry &r) -> Entity
{
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)0.7, (float)0.7, 0, 0, 584, 183, "ressources/playButton.png"};
    struct components::clickable_s clickable = {false, false, [this](Registry &r, size_t id) -> void
                                                { r.getComponents<components::sprite_s>()[id].value().rectX = 584; },
                                                [this](Registry &r, size_t id) -> void
                                                {
                                                    r.getComponents<components::sprite_s>()[id].value().rectX = 0;
                                                    r.getComponents<components::network_s>()[constants::RESERVED_ID::NETWORK_UPDATE].value().sendRequest.push_back(std::vector<uint8_t>{23}); //request get rooms
                                                }};
    struct components::position_s pos = {100 , (WINDOW_SIZE_Y / 2) + 200};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {true};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::MAIN_MENU};
    struct components::mouseState_s mouse = {0, 0, false, false};
    struct components::zaxis_s zaxis = {8};
    struct components::mySize_s size = {600, 200};

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

    return id;
}

auto rtype::UpdateGraph::_createNewGameButtonMainMenu(Registry &r) -> Entity
{
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)0.7, (float)0.7, 0, 0, 584, 183, "ressources/newGame.png"};
    struct components::clickable_s clickable = {
        false,
        false, [this](Registry &r, size_t id) -> void
        { r.getComponents<components::sprite_s>()[id].value().rectX = 584; },
        [this](Registry &r, size_t id) -> void
        {
            r.getComponents<components::sprite_s>()[id].value().rectX = 0;
            r.getComponents<components::network_s>()[constants::RESERVED_ID::NETWORK_UPDATE].value().sendRequest.push_back(std::vector<uint8_t>{18}); //request create room
        }};
    struct components::position_s pos = {1220, (WINDOW_SIZE_Y / 2) + 200};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {true};
    struct components::mouseState_s mouse = {0, 0, false, false};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::MAIN_MENU};
    struct components::zaxis_s zaxis = {9};
    struct components::mySize_s size = {600, 200};
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
    return id;
}

auto rtype::UpdateGraph::_setupMainMenuScene() -> void
{
    _setupScene[rtype::constants::MAIN_MENU] = std::function(
        [this](Registry &r, SparseArray<components::currentScene_s> &currentScenes) -> void
        {
            Entity backgroundId = _createBackgroundMainMenu(r);
            Entity logoId = _createLogoMainMenu(r);
            Entity transitionId = _createTransitionMainMenu(r);
            Entity playButtonId = _createPlayButtonMainMenu(r);
            Entity NewGameButtonId = _createNewGameButtonMainMenu(r);

            _graphicalLib->createSprite(backgroundId, r.getComponents<components::sprite_s>()[backgroundId].value().scaleX, r.getComponents<components::sprite_s>()[backgroundId].value().scaleY, r.getComponents<components::sprite_s>()[backgroundId].value().rectX, r.getComponents<components::sprite_s>()[backgroundId].value().rectY, r.getComponents<components::sprite_s>()[backgroundId].value().rectWidth, r.getComponents<components::sprite_s>()[backgroundId].value().rectHeight, r.getComponents<components::sprite_s>()[backgroundId].value().path);
            _graphicalLib->createSprite(logoId, r.getComponents<components::sprite_s>()[logoId].value().scaleX, r.getComponents<components::sprite_s>()[logoId].value().scaleY, r.getComponents<components::sprite_s>()[logoId].value().rectX, r.getComponents<components::sprite_s>()[logoId].value().rectY, r.getComponents<components::sprite_s>()[logoId].value().rectWidth, r.getComponents<components::sprite_s>()[logoId].value().rectHeight, r.getComponents<components::sprite_s>()[logoId].value().path);
            _graphicalLib->createSprite(transitionId, r.getComponents<components::sprite_s>()[transitionId].value().scaleX, r.getComponents<components::sprite_s>()[transitionId].value().scaleY, r.getComponents<components::sprite_s>()[transitionId].value().rectX, r.getComponents<components::sprite_s>()[transitionId].value().rectY, r.getComponents<components::sprite_s>()[transitionId].value().rectWidth, r.getComponents<components::sprite_s>()[transitionId].value().rectHeight, r.getComponents<components::sprite_s>()[transitionId].value().path);
            _graphicalLib->createSprite(playButtonId, r.getComponents<components::sprite_s>()[playButtonId].value().scaleX, r.getComponents<components::sprite_s>()[playButtonId].value().scaleY, r.getComponents<components::sprite_s>()[playButtonId].value().rectX, r.getComponents<components::sprite_s>()[playButtonId].value().rectY, r.getComponents<components::sprite_s>()[playButtonId].value().rectWidth, r.getComponents<components::sprite_s>()[playButtonId].value().rectHeight, r.getComponents<components::sprite_s>()[playButtonId].value().path);
            _graphicalLib->createSprite(NewGameButtonId, r.getComponents<components::sprite_s>()[NewGameButtonId].value().scaleX, r.getComponents<components::sprite_s>()[NewGameButtonId].value().scaleY, r.getComponents<components::sprite_s>()[NewGameButtonId].value().rectX, r.getComponents<components::sprite_s>()[NewGameButtonId].value().rectY, r.getComponents<components::sprite_s>()[NewGameButtonId].value().rectWidth, r.getComponents<components::sprite_s>()[NewGameButtonId].value().rectHeight, r.getComponents<components::sprite_s>()[NewGameButtonId].value().path);
            _graphicalLib->setSpriteColorAlpha(transitionId, 255);
            auto &scene = currentScenes[constants::RESERVED_ID::GRAPH_UPDATE];
            if (scene)
                scene.value().isLoaded = true;
        });
}

auto rtype::UpdateGraph::_setupExecMainMenuScene() -> void
{
    _execScene[rtype::constants::MAIN_MENU] = std::function(
        [this](Registry &r, SparseArray<components::currentScene_s> &currentScenes) -> void
        {
            static std::chrono::duration dtime = std::chrono::nanoseconds(0);
            static std::chrono::duration dtimeAnim = std::chrono::nanoseconds(0);
            std::vector<int> myZAxises;
            std::map<int, size_t> zAxisMap;
            auto &net = r.getComponents<components::network_s>()[constants::RESERVED_ID::NETWORK_UPDATE];
            auto &times = r.getComponents<components::myTime_s>();
            auto &time = times[constants::RESERVED_ID::TIME_UPDATE];
            dtimeAnim += time.value().deltaTime;
            dtime += time.value().deltaTime;
            _graphicalLib->clearScreen();
            for (auto &&[pos, sprite, scene, drawable, index, zaxis] : Zipper(r.getComponents<components::position_s>(), r.getComponents<components::sprite_s>(), r.getComponents<components::scene_s>(), r.getComponents<components::drawable_s>(), r.getComponents<components::index_s>(), r.getComponents<components::zaxis_s>()))
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
                if (!(zaxis.zAxis))
                    if (dtime.count() < 8000000000 && dtimeAnim.count() > 5000000 && _graphicalLib->getSpriteColorAlpha(index.idx))
                    {
                        dtimeAnim = std::chrono::nanoseconds(0);
                        _graphicalLib->setSpriteColorAlpha(index.idx, _graphicalLib->getSpriteColorAlpha(index.idx) - 1);
                    }
            }
            std::sort(myZAxises.begin(), myZAxises.end(), myCmp);
            std::reverse(myZAxises.begin(), myZAxises.end());
            for (auto i : myZAxises)
                _graphicalLib->draw(zAxisMap[i]);
            _graphicalLib->HandleClose();
            _graphicalLib->refresh();
            if (!(net.value().request12.empty()) && !(net.value().request12.front().empty())) {
                net.value().request12.erase(net.value().request12.begin());
                struct components::playerList_s playerList = {1, 1};
                r.addComponent<components::playerList_s>(r.entityFromIndex(constants::RESERVED_ID::GRAPH_UPDATE), std::move(playerList));
                // get id de la room après 12
                r.getComponents<components::currentScene_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().isLoaded = false;
                r.getComponents<components::currentScene_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().scene = constants::SCENE::WAITING_ROOM;
            }
            if (!(net.value().request17.empty()) && !(net.value().request17.front().empty()))
            {
                std::vector<size_t> tmp;
                struct components::roomList_s roomList = {false, false, false, false, false};
                if (net.value().request17.front().at(1) == 1)
                    roomList.room1 = true;
                if (net.value().request17.front().at(2) == 2)
                    roomList.room2 = true;
                if (net.value().request17.front().at(3) == 3)
                    roomList.room3 = true;
                if (net.value().request17.front().at(4) == 4)
                    roomList.room4 = true;
                if (net.value().request17.front().at(5) == 5)
                    roomList.room5 = true;
                r.addComponent<components::roomList_s>(r.entityFromIndex(constants::RESERVED_ID::GRAPH_UPDATE), std::move(roomList));
                r.getComponents<components::currentScene_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().isLoaded = false;
                r.getComponents<components::currentScene_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().scene = constants::SCENE::SELECT_ROOM;
                net.value().request17.erase(net.value().request17.begin());
            }
            (void)currentScenes;
        });
}

auto rtype::UpdateGraph::_setupDeleteMainMenuScene() -> void
{
    _deleteScene[rtype::constants::MAIN_MENU] = std::function(
        [this](Registry &r)
        {
            _graphicalLib->clearScreen();

            for (auto &&[scene, index, music] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>(), r.getComponents<components::music_s>()))
            {
                if (scene.scene == constants::SCENE::MAIN_MENU)
                {
                    _graphicalLib->stop(index.idx);
                    _graphicalLib->deleteMusic(index.idx);
                }
            }
            for (auto &&[scene, index, sprite] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>(), r.getComponents<components::sprite_s>()))
            {
                if (scene.scene == constants::SCENE::MAIN_MENU)
                {
                    _graphicalLib->deleteSprite(index.idx);
                }
            }
            for (auto &&[scene, index, text] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>(), r.getComponents<components::text_s>()))
            {
                if (scene.scene == constants::SCENE::MAIN_MENU)
                {
                    _graphicalLib->deleteText(index.idx);
                }
            }
            for (auto&& [scene, index, clickable] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>(), r.getComponents<components::clickable_s>()))
            {
                if (scene.scene == constants::SCENE::MAIN_MENU)
                {
                    clickable = { false, false, [this](Registry& r, size_t id) -> void
                    { 
                        (void)r;
                        (void)id;
                    },
                    [this](Registry& r, size_t id) -> void
                    {
                        (void)r;
                        (void)id;
                    } };
                }
            }
            for (auto &&[scene, index] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>()))
            {
                if (scene.scene == constants::SCENE::MAIN_MENU)
                {
                    r.getComponents<components::scene_s>().erase(index.idx);
                    r.getComponents<components::index_s>().erase(index.idx);
                    r.killEntity(r.entityFromIndex(index.idx));
                }
            }
            _graphicalLib->clearScreen();
        });
}
