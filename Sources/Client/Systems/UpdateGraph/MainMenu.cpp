#include "UpdateGraph.hpp"

auto rtype::UpdateGraph::_setupMainMenuScene() -> void
{
    _setupScene[rtype::constants::MAIN_MENU] = std::function(
        [this](Registry& r, SparseArray<components::currentScene_t>& currentScenes) -> void
        {
            Entity backgroundId{ _addSpriteToScene(r, components::sprite_t{static_cast<float>(0.9), static_cast<float>(0.9), 0, 0, 1920, 1080, "ressources/MainMenu.jpg"}, components::position_t{0, 0}, components::direction_t{0, 0}, components::velocity_t{0, 0}, components::drawable_t{true}, components::scene_t{constants::SCENE::MAIN_MENU}, components::zaxis_t{10}) };
            Entity logoId{ _addSpriteToScene(r, components::sprite_t{ static_cast<float>(0.9), static_cast<float>(0.9), 0, 0, 663, 369, "ressources/logo.png" }, components::position_t{ (WINDOW_SIZE_X / 2) - ((663) / 2), 150 }, components::direction_t{ 0, 0 }, components::velocity_t{ 0, 0 }, components::drawable_t{ true }, components::scene_t{ constants::SCENE::MAIN_MENU }, components::zaxis_t{ 7 }) };
            Entity transitionId{ _addSpriteToScene(r, components::sprite_t{ static_cast<float>(WINDOW_SIZE_X / 250), static_cast<float>(WINDOW_SIZE_Y / 250), 0, 0, 1920, 1080, "ressources/noir.jpg" }, components::position_t{ 0, 0 }, components::direction_t{ 0, 0 }, components::velocity_t{ 0, 0 }, components::drawable_t{ true }, components::scene_t{ constants::SCENE::MAIN_MENU }, components::zaxis_t{ 0 }) };
          
            Entity playButtonId{ _addButtonToScene(r, components::sprite_t{ static_cast<float>(0.7), static_cast<float>(0.7), 0, 0, 584, 183, "ressources/playButton.png"}, components::position_t{ 100 , (WINDOW_SIZE_Y / 2) + 200 }, components::direction_t{ 0, 0 }, components::velocity_t{ 0, 0 }, components::drawable_t{ true }, components::scene_t{ constants::SCENE::MAIN_MENU }, components::zaxis_t{ 8 }, components::clickable_t{ false, false, [this](Registry& r, size_t id) -> void { r.getComponents<components::sprite_t>()[id].value().rectX = 584; }, [this](Registry& r, size_t id) -> void {r.getComponents<components::sprite_t>()[id].value().rectX = 0; r.getComponents<components::network_s>()[constants::RESERVED_ID::NETWORK_UPDATE].value().sendRequest.push_back(std::vector<uint8_t>{23}); } }, components::mouseState_t { 0, 0, false, false }, components::mySize_t {600, 200}) };
          
            Entity NewGameButtonId{ _addButtonToScene(r, components::sprite_t{ static_cast<float>(0.7), static_cast<float>(0.7), 0, 0, 584, 183, "ressources/newGame.png" }, components::position_t{ 1220, (WINDOW_SIZE_Y / 2) + 200 }, components::direction_t{ 0, 0 }, components::velocity_t{ 0, 0 }, components::drawable_t{ true }, components::scene_t{ constants::SCENE::MAIN_MENU }, components::zaxis_t{ 9 }, components::clickable_t{ false, false, [this](Registry& r, size_t id) -> void { r.getComponents<components::sprite_t>()[id].value().rectX = 584; }, [this](Registry& r, size_t id) -> void {r.getComponents<components::sprite_t>()[id].value().rectX = 0; r.getComponents<components::network_s>()[constants::RESERVED_ID::NETWORK_UPDATE].value().sendRequest.push_back(std::vector<uint8_t>{18}); } }, components::mouseState_t { 0, 0, false, false }, components::mySize_t {600, 200}) };

            _graphicalLib->createSprite(backgroundId, r.getComponents<components::sprite_t>()[backgroundId].value().scaleX, r.getComponents<components::sprite_t>()[backgroundId].value().scaleY, r.getComponents<components::sprite_t>()[backgroundId].value().rectX, r.getComponents<components::sprite_t>()[backgroundId].value().rectY, r.getComponents<components::sprite_t>()[backgroundId].value().rectWidth, r.getComponents<components::sprite_t>()[backgroundId].value().rectHeight, r.getComponents<components::sprite_t>()[backgroundId].value().path);
            _graphicalLib->createSprite(logoId, r.getComponents<components::sprite_t>()[logoId].value().scaleX, r.getComponents<components::sprite_t>()[logoId].value().scaleY, r.getComponents<components::sprite_t>()[logoId].value().rectX, r.getComponents<components::sprite_t>()[logoId].value().rectY, r.getComponents<components::sprite_t>()[logoId].value().rectWidth, r.getComponents<components::sprite_t>()[logoId].value().rectHeight, r.getComponents<components::sprite_t>()[logoId].value().path);
            _graphicalLib->createSprite(transitionId, r.getComponents<components::sprite_t>()[transitionId].value().scaleX, r.getComponents<components::sprite_t>()[transitionId].value().scaleY, r.getComponents<components::sprite_t>()[transitionId].value().rectX, r.getComponents<components::sprite_t>()[transitionId].value().rectY, r.getComponents<components::sprite_t>()[transitionId].value().rectWidth, r.getComponents<components::sprite_t>()[transitionId].value().rectHeight, r.getComponents<components::sprite_t>()[transitionId].value().path);
            _graphicalLib->createSprite(playButtonId, r.getComponents<components::sprite_t>()[playButtonId].value().scaleX, r.getComponents<components::sprite_t>()[playButtonId].value().scaleY, r.getComponents<components::sprite_t>()[playButtonId].value().rectX, r.getComponents<components::sprite_t>()[playButtonId].value().rectY, r.getComponents<components::sprite_t>()[playButtonId].value().rectWidth, r.getComponents<components::sprite_t>()[playButtonId].value().rectHeight, r.getComponents<components::sprite_t>()[playButtonId].value().path);
            _graphicalLib->createSprite(NewGameButtonId, r.getComponents<components::sprite_t>()[NewGameButtonId].value().scaleX, r.getComponents<components::sprite_t>()[NewGameButtonId].value().scaleY, r.getComponents<components::sprite_t>()[NewGameButtonId].value().rectX, r.getComponents<components::sprite_t>()[NewGameButtonId].value().rectY, r.getComponents<components::sprite_t>()[NewGameButtonId].value().rectWidth, r.getComponents<components::sprite_t>()[NewGameButtonId].value().rectHeight, r.getComponents<components::sprite_t>()[NewGameButtonId].value().path);
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
            for (auto &&[pos, sprite, scene, drawable, index, zaxis] : Zipper(r.getComponents<components::position_s>(), r.getComponents<components::sprite_t>(), r.getComponents<components::scene_s>(), r.getComponents<components::drawable_s>(), r.getComponents<components::index_s>(), r.getComponents<components::zaxis_t>()))
            {
                if (!(drawable.drawable))
                    continue;
                myZAxises.push_back(static_cast<int>(zaxis.zAxis));
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
            if (!(net.value().request12.empty()) && !(net.value().request12.front().empty()))
            {
                std::cout << "received request 12" << std::endl;
                struct components::currentRoom_s currRoom { net.value().request12[0][1] };
                struct components::playerList_s playerList = {1, 1};
                net.value().request12.erase(net.value().request12.begin());
                r.addComponent<components::playerList_s>(r.entityFromIndex(constants::RESERVED_ID::GRAPH_UPDATE), std::move(playerList));
                r.addComponent<components::currentRoom_s>(r.entityFromIndex(constants::RESERVED_ID::GRAPH_UPDATE), std::move(currRoom));
                // get id de la room apr�s 12
                r.getComponents<components::currentScene_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().isLoaded = false;
                r.getComponents<components::currentScene_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().scene = constants::SCENE::WAITING_ROOM;
            }
            if (!(net.value().request17.empty()) && !(net.value().request17.back().empty()))
            {
                std::cout << "received request 17" << std::endl;
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
                //net.value().request17.erase(net.value().request17.begin());
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
            for (auto &&[scene, index, sprite] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>(), r.getComponents<components::sprite_t>()))
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
