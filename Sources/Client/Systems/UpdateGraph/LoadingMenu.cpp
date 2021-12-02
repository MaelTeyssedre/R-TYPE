#include "UpdateGraph.hpp"

Entity rtype::UpdateGraph::_createBackgroundLoadingMenu(Registry &r)
{
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)0.96, (float)0.81, 0, 0, 1800, 1200, "ressources/LoadingMenu.jpg"};
    struct components::position_s pos = {0, 0};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {true};
    struct components::scene_s my_scene = {constants::SCENE::LOADING_MENU};
    struct components::index_s index = {id};
    struct components::zaxis_s zaxis = {10};

    r.addComponent<components::sprite_s>(r.entityFromIndex(id), std::move(sprite));
    r.addComponent<components::index_s>(r.entityFromIndex(id), std::move(index));
    r.addComponent<components::position_s>(r.entityFromIndex(id), std::move(pos));
    r.addComponent<components::velocity_s>(r.entityFromIndex(id), std::move(vel));
    r.addComponent<components::direction_s>(r.entityFromIndex(id), std::move(dir));
    r.addComponent<components::scene_s>(r.entityFromIndex(id), std::move(my_scene));
    r.addComponent<components::drawable_s>(r.entityFromIndex(id), std::move(drawable));
    r.addComponent<components::zaxis_s>(r.entityFromIndex(id), std::move(zaxis));

    return id;
}

Entity rtype::UpdateGraph::_createTransitionLoadingMenu(Registry &r)
{
    Entity id = r.spawnEntity();
    struct components::sprite_s sprite = {(float)WINDOW_SIZE_X / 250, (float)WINDOW_SIZE_Y / 250, 0, 0, 1920, 1080, "ressources/noir.jpg"};
    struct components::position_s pos = {0, 0};
    struct components::direction_s dir = {0, 0};
    struct components::velocity_s vel = {0, 0};
    struct components::drawable_s drawable = {true};
    struct components::scene_s my_scene = {constants::SCENE::LOADING_MENU};
    struct components::index_s index = {id};
    struct components::zaxis_s zaxis = {0};

    r.addComponent<components::sprite_s>(r.entityFromIndex(id), std::move(sprite));
    r.addComponent<components::index_s>(r.entityFromIndex(id), std::move(index));
    r.addComponent<components::position_s>(r.entityFromIndex(id), std::move(pos));
    r.addComponent<components::velocity_s>(r.entityFromIndex(id), std::move(vel));
    r.addComponent<components::direction_s>(r.entityFromIndex(id), std::move(dir));
    r.addComponent<components::scene_s>(r.entityFromIndex(id), std::move(my_scene));
    r.addComponent<components::drawable_s>(r.entityFromIndex(id), std::move(drawable));
    r.addComponent<components::scene_s>(r.entityFromIndex(id), std::move(my_scene));
    r.addComponent<components::zaxis_s>(r.entityFromIndex(id), std::move(zaxis));

    return id;
}

Entity rtype::UpdateGraph::_createMusicLoadingMenu(Registry &r)
{
    Entity id = r.spawnEntity();
    struct components::music_s path = {"ressources/MenuMusic.ogg"};
    struct components::scene_s scene = {constants::SCENE::MAIN_MENU};
    struct components::index_s index = {id};

    r.addComponent<components::scene_s>(r.entityFromIndex(id), std::move(scene));
    r.addComponent<components::music_s>(r.entityFromIndex(id), std::move(path));
    r.addComponent<components::index_s>(r.entityFromIndex(id), std::move(index));

    return id;
}

void rtype::UpdateGraph::_setupLoadingMenuScene()
{
    _setupScene[rtype::constants::LOADING_MENU] = std::function(
        [this](Registry &r, SparseArray<components::currentScene_s> &currentScenes)
        {
            auto &scene = currentScenes[constants::RESERVED_ID::GRAPH_UPDATE];
            size_t backgroundId = _createBackgroundLoadingMenu(r);
            size_t transitionId = _createTransitionLoadingMenu(r);
            size_t musicId = _createMusicLoadingMenu(r);
            _graphicalLib->createSprite(backgroundId, r.getComponents<components::sprite_s>()[backgroundId].value().scaleX, r.getComponents<components::sprite_s>()[backgroundId].value().scaleY, r.getComponents<components::sprite_s>()[backgroundId].value().rectX, r.getComponents<components::sprite_s>()[backgroundId].value().rectY, r.getComponents<components::sprite_s>()[backgroundId].value().rectWidth, r.getComponents<components::sprite_s>()[backgroundId].value().rectHeight, r.getComponents<components::sprite_s>()[backgroundId].value().path);
            _graphicalLib->createSprite(transitionId, r.getComponents<components::sprite_s>()[transitionId].value().scaleX, r.getComponents<components::sprite_s>()[transitionId].value().scaleY, r.getComponents<components::sprite_s>()[transitionId].value().rectX, r.getComponents<components::sprite_s>()[transitionId].value().rectY, r.getComponents<components::sprite_s>()[transitionId].value().rectWidth, r.getComponents<components::sprite_s>()[transitionId].value().rectHeight, r.getComponents<components::sprite_s>()[transitionId].value().path);
            _graphicalLib->createMusic(musicId, r.getComponents<components::music_s>()[musicId].value().path);
            _graphicalLib->setSpriteColorAlpha(transitionId, 255);
            _graphicalLib->play(musicId);
            if (scene)
                scene.value().isLoaded = true;
        });
}

void rtype::UpdateGraph::_setupExecLoadingMenuScene()
{
    _execScene[rtype::constants::LOADING_MENU] = std::function(
        [this](Registry &r, SparseArray<components::currentScene_s> &currentScenes)
        {
            static std::chrono::duration dtime = std::chrono::nanoseconds(0);
            static std::chrono::duration dtimeAnim = std::chrono::nanoseconds(0);
            std::vector<int> myZAxises;
            std::map<int, size_t> zAxisMap;
            auto &times = r.getComponents<components::myTime_s>();
            auto &time = times[constants::RESERVED_ID::TIME_UPDATE];
            dtime += time.value().deltaTime;
            dtimeAnim += time.value().deltaTime;
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

                if (zaxis.zAxis == 0)
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
            if (r.getComponents<components::keyState_s>()[constants::RESERVED_ID::GRAPH_UPDATE].value().keySpace) {
                currentScenes[constants::RESERVED_ID::GRAPH_UPDATE].value().isLoaded = false;
                currentScenes[constants::RESERVED_ID::GRAPH_UPDATE].value().scene = constants::SCENE::MAIN_MENU;
                _graphicalLib->clearScreen();
                dtime = std::chrono::nanoseconds(0);
                dtimeAnim = std::chrono::nanoseconds(0);
                return;
            }
            std::sort(myZAxises.begin(), myZAxises.end(), myCmp);
            std::reverse(myZAxises.begin(), myZAxises.end());
            for (auto i : myZAxises)
            {
                _graphicalLib->draw(zAxisMap[i]);
            }
            _graphicalLib->HandleClose();
            _graphicalLib->refresh();

            if (dtime.count() > 14000000000)
            {
                auto &current = currentScenes[constants::RESERVED_ID::GRAPH_UPDATE];
                current.value().isLoaded = false;
                current.value().scene = constants::SCENE::MAIN_MENU;
                _graphicalLib->clearScreen();
                dtime = std::chrono::nanoseconds(0);
                dtimeAnim = std::chrono::nanoseconds(0);
            }
        });
}

void rtype::UpdateGraph::_setupDeleteLoadingMenuScene()
{
    _deleteScene[rtype::constants::LOADING_MENU] = std::function(
        [this](Registry &r)
        {
            _graphicalLib->clearScreen();

            for (auto &&[scene, index, music] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>(), r.getComponents<components::music_s>()))
            {
                if (scene.scene == constants::SCENE::LOADING_MENU)
                {
                    _graphicalLib->stop(index.idx);
                    _graphicalLib->deleteMusic(index.idx);
                }
            }
            for (auto &&[scene, index, sprite] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>(), r.getComponents<components::sprite_s>()))
            {
                if (scene.scene == constants::SCENE::LOADING_MENU) {
                    std::cout << "Destroy: " << index.idx << std::endl;
                    _graphicalLib->deleteSprite(index.idx);
                }
            }
            for (auto &&[scene, index] : Zipper(r.getComponents<components::scene_s>(), r.getComponents<components::index_s>()))
                if (scene.scene == constants::SCENE::LOADING_MENU) {
                    std::cout << "kill Entity: " << index.idx << std::endl;
                    r.getComponents<components::scene_s>().erase(index.idx);
                    r.getComponents<components::index_s>().erase(index.idx);
                    r.killEntity(r.entityFromIndex(index.idx));
                }
        });
}