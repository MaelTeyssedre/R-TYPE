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

Entity rtype::UpdateGraph::_createTransitionWaitingRoom(Registry &r)
{
    Entity id = r.spawnEntity();

    struct components::sprite_s sprite = {(float)WINDOW_SIZE_X / 250, (float)WINDOW_SIZE_Y / 250, 0, 0, 1920, 1080, "ressources/noir.jpg"};
    struct components::position_s pos = {0, 0};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {true};
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

    if (!(drawable.drawable))
        std::cout << "bad Drawable" << std::endl;
    else
        std::cout << "good Drawable" << std::endl;
    return id;
}

Entity rtype::UpdateGraph::_createTextWaitingRoom(Registry &r)
{
    Entity id = r.spawnEntity();

    struct components::text_s text = {50, "ressources/font.ttf", "0 player in room"};
    struct components::color_s color = {0, 0, 0, 255};
    struct components::position_s pos = {200, 200};
    struct components::drawable_s drawable = {true};
    struct components::index_s idx = {id};
    struct components::scene_s my_scene = {constants::SCENE::WAITING_ROOM};
    struct components::zaxis_s zaxis = {1};

    r.addComponent<components::text_s>(r.entityFromIndex(id), std::move(text));
    r.addComponent<components::color_s>(r.entityFromIndex(id), std::move(color));
    r.addComponent<components::position_s>(r.entityFromIndex(id), std::move(pos));
    r.addComponent<components::scene_s>(r.entityFromIndex(id), std::move(my_scene));
    r.addComponent<components::drawable_s>(r.entityFromIndex(id), std::move(drawable));
    r.addComponent<components::zaxis_s>(r.entityFromIndex(id), std::move(zaxis));
    r.addComponent<components::index_s>(r.entityFromIndex(id), std::move(idx));

    return id;
}

void rtype::UpdateGraph::_setupWaitingRoomScene()
{
    _setupScene[rtype::constants::SCENE::WAITING_ROOM] = std::function(
        [this](Registry &r, SparseArray<components::currentScene_s> &currentScenes) -> void
        {
            Entity backgroundId = _createBackgroundWaitingRoom(r);
            Entity transitionId = _createTransitionWaitingRoom(r);
            // Entity textId = _createTextWaitingRoom(r);
            _graphicalLib->createSprite(backgroundId, r.getComponents<components::sprite_s>()[backgroundId].value().scaleX, r.getComponents<components::sprite_s>()[backgroundId].value().scaleY, r.getComponents<components::sprite_s>()[backgroundId].value().rectX, r.getComponents<components::sprite_s>()[backgroundId].value().rectY, r.getComponents<components::sprite_s>()[backgroundId].value().rectWidth, r.getComponents<components::sprite_s>()[backgroundId].value().rectHeight, r.getComponents<components::sprite_s>()[backgroundId].value().path);
            _graphicalLib->createSprite(transitionId, r.getComponents<components::sprite_s>()[transitionId].value().scaleX, r.getComponents<components::sprite_s>()[transitionId].value().scaleY, r.getComponents<components::sprite_s>()[transitionId].value().rectX, r.getComponents<components::sprite_s>()[transitionId].value().rectY, r.getComponents<components::sprite_s>()[transitionId].value().rectWidth, r.getComponents<components::sprite_s>()[transitionId].value().rectHeight, r.getComponents<components::sprite_s>()[transitionId].value().path);
            // _graphicalLib->createText(textId, r.getComponents<components::text_s>()[textId].value().fontSize, r.getComponents<components::color_s>()[textId].value().colorRed, r.getComponents<components::color_s>()[textId].value().colorGreen, r.getComponents<components::color_s>()[textId].value().colorBlue, r.getComponents<components::color_s>()[textId].value().colorAlpha, r.getComponents<components::text_s>()[textId].value().text, r.getComponents<components::text_s>()[textId].value().fontPath);

            auto &scene = currentScenes[constants::RESERVED_ID::GRAPH_UPDATE];
            if (scene)
                scene.value().isLoaded = true;
        });
}

void rtype::UpdateGraph::_setupExecWaitingRoomScene()
{
    _execScene[rtype::constants::SCENE::WAITING_ROOM] = std::function(
        [this](Registry &r, SparseArray<components::currentScene_s> &currentScenes) -> void
        {
            static std::chrono::duration dtimeAnim = std::chrono::nanoseconds(0);
            std::vector<int> myZAxises;
            std::map<int, std::pair<size_t, constants::TYPE>> zAxisMap;
            auto &texts = r.getComponents<components::text_s>();
            auto &colors = r.getComponents<components::color_s>();
            for (auto &&[pos, sprite, scene, drawable, index, zaxis] : Zipper(r.getComponents<components::position_s>(), r.getComponents<components::sprite_s>(), r.getComponents<components::scene_s>(), r.getComponents<components::drawable_s>(), r.getComponents<components::index_s>(), r.getComponents<components::zaxis_s>()))
            {
                if (!(drawable.drawable))
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
                if (zaxis.zAxis == 9) {
                    if (dtimeAnim.count() > 5000000 && _graphicalLib->getSpriteColorAlpha(index.idx))
                    {
                        dtimeAnim = std::chrono::nanoseconds(0);
                        _graphicalLib->setSpriteColorAlpha(index.idx, _graphicalLib->getSpriteColorAlpha(index.idx) - 1);
                    }
                }
            }
            dtimeAnim += r.getComponents<components::myTime_s>()[constants::RESERVED_ID::TIME_UPDATE].value().deltaTime;
            // for (auto &&[text, drawable, color, pos, scene, zaxis, index] : Zipper(texts, drawables, colors, positions, scenes, zaxises, indexs))
            // {
            //     if (!(drawable.drawable))
            //         continue;
            //     myZAxises.push_back((int)zaxis.zAxis);
            //     zAxisMap[(int)zaxis.zAxis] = std::pair(index.idx, constants::TYPE::TEXT);
            //     _graphicalLib->setTextPosX(index.idx, pos.x);
            //     _graphicalLib->setTextPosY(index.idx, pos.y);
            //     _graphicalLib->setTextColorRed(index.idx, color.colorRed);
            //     _graphicalLib->setTextColorGreen(index.idx, color.colorGreen);
            //     _graphicalLib->setTextColorBlue(index.idx, color.colorBlue);
            //     _graphicalLib->setTextColorAlpha(index.idx, color.colorAlpha);
            //     _graphicalLib->setTextContent(index.idx, text.text);
            // }
            std::sort(myZAxises.begin(), myZAxises.end(), myCmp);
            std::reverse(myZAxises.begin(), myZAxises.end());
            for (auto i : myZAxises)
            {
                if (zAxisMap[i].second == constants::TYPE::SPRITE)
                    _graphicalLib->draw(zAxisMap[i].first);
                if (zAxisMap[i].second == constants::TYPE::TEXT)
                    _graphicalLib->print(zAxisMap[i].first);
            }
            _graphicalLib->HandleClose();
            _graphicalLib->refresh();
        });
}

void rtype::UpdateGraph::_setupDeleteWaitingRoomScene()
{
    _deleteScene[rtype::constants::WAITING_ROOM] = std::function(
        [this](Registry &r)
        {
            _graphicalLib->clearScreen();
            auto &scenes = r.getComponents<components::scene_s>();
            auto &indexes = r.getComponents<components::index_s>();
            auto &musics = r.getComponents<components::music_s>();
            auto &sprites = r.getComponents<components::sprite_s>();

            for (auto &&[scene, index, music] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>(), r.getComponents<components::music_s>()))
            {
                if (scene.scene == constants::SCENE::WAITING_ROOM)
                {
                    _graphicalLib->stop(index.idx);
                    _graphicalLib->deleteMusic(index.idx);
                }
            }
            for (auto &&[scene, index, sprite] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>(), r.getComponents<components::sprite_s>()))
            {
                if (scene.scene == constants::SCENE::WAITING_ROOM)
                {
                    _graphicalLib->deleteSprite(index.idx);
                    std::cout << "destroy: " << index.idx << std::endl;
                }
            }
            for (auto &&[scene, index] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>()))
            {
                if (scene.scene == constants::SCENE::WAITING_ROOM) {
                    std::cout << "kill Entity: " << index.idx << std::endl;
                    r.getComponents<components::scene_s>().erase(index.idx);
                    r.getComponents<components::index_s>().erase(index.idx);    
                    r.killEntity(r.entityFromIndex(index.idx));
                }
            }
            _graphicalLib->clearScreen();
        });
}