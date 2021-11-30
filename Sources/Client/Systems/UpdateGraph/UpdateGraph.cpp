
#include "UpdateGraph.hpp"

rtype::UpdateGraph::UpdateGraph()
{
    _graphicalLib = new rtype::GraphicalLib();
    _setupScene = {};
    _execScene = {};
    _deleteScene = {};

    _setupScenes();
    _setupExecScene();
    _setupDeleteScene();
}

void rtype::UpdateGraph::operator()(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes)
{
    _updateEvent(mouseStates, keyStates);
    _updateGraph(r, mouseStates, keyStates, currentScenes);
}

void rtype::UpdateGraph::_updateGraph(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes)
{
    (void)mouseStates;
    (void)keyStates;
    static constants::SCENE previous_scene = constants::LOADING_MENU;
    for (auto &&[scene] : Zipper(currentScenes))
    {
        if (!(scene.isLoaded))
        {
            _deleteScene[previous_scene](r, *this, static_cast<GraphicalLib *>(_graphicalLib));
            auto &tmp = currentScenes[constants::RESERVED_ID::GRAPH_UPDATE];
            if (tmp)
                previous_scene = tmp.value().scene;
            _setupScene[currentScenes[rtype::constants::RESERVED_ID::GRAPH_UPDATE].value().scene](r, *this, currentScenes);
        }
    }
    // auto &scene = currentScenes[rtype::constants::RESERVED_ID::GRAPH_UPDATE];
    // if (!scene) {
    //     std::cout << "5.25: scene not found" << std::endl;
    // }
    // if (!(scene.value().isLoaded)) {
    //     std::cout << "5.5: scene not loaded" << std::endl;
    //     _setupScene[currentScenes[rtype::constants::RESERVED_ID::GRAPH_UPDATE].value().scene](r, *this, currentScenes);
    // }
    _execScene[currentScenes[rtype::constants::RESERVED_ID::GRAPH_UPDATE].value().scene](r, *this, currentScenes, dynamic_cast<GraphicalLib *>(_graphicalLib));
}

void rtype::UpdateGraph::_updateEvent(SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates)
{
    (void)mouseStates;
    (void)keyStates;
    rtype::mouse_t mouse = _graphicalLib->getMouseState();
    for (auto &&[mouseState, keyState] : Zipper(mouseStates, keyStates))
    {
        mouseState.mousePosX = mouse.posX;
        mouseState.mousePosY = mouse.posY;
        mouseState.mouseLeftClick = mouse.leftPressed;
        mouseState.mouseRightClick = mouse.rightPressed;
        keyState.keyDown = _graphicalLib->getKeyState(rtype::constants::KEY_DOWN);
        keyState.keyUp = _graphicalLib->getKeyState(rtype::constants::KEY_UP);
        keyState.keyRight = _graphicalLib->getKeyState(rtype::constants::KEY_RIGHT);
        keyState.keyLeft = _graphicalLib->getKeyState(rtype::constants::KEY_LEFT);
        keyState.keyEnter = _graphicalLib->getKeyState(rtype::constants::KEY_ENTER);
        keyState.keySpace = _graphicalLib->getKeyState(rtype::constants::KEY_SPACE);
    }
}

void rtype::UpdateGraph::_setupScenes()
{
    _setupLoadingMenuScene();
    _setupLoadingGameScene();
    _setupGameScene();
    _setupParamsScene();
    _setupMainMenuScene();
}

void rtype::UpdateGraph::_setupExecScene()
{
    _setupExecLoadingMenuScene();
    _setupExecLoadingGameScene();

    _setupExecGameScene();
    _setupExecParamsScene();
    _setupExecMainMenuScene();
}

void rtype::UpdateGraph::_setupDeleteScene()
{
    _setupDeleteLoadingMenuScene();
    _setupDeleteLoadingGameScene();
    _setupDeleteGameScene();
    _setupDeleteParamsScene();
    _setupDeleteMainMenuScene();
}

void rtype::UpdateGraph::_setupLoadingMenuScene()
{
    _setupScene[rtype::constants::LOADING_MENU] = std::function([this](Registry &r, UpdateGraph &graph, SparseArray<components::currentScene_s> &currentScenes)
                                                                {
                                                                    (void)graph;
                                                                    _background_id = (size_t)(r.spawnEntity());
                                                                    _switchId = (size_t)(r.spawnEntity());
                                                                    _musicId = (size_t)(r.spawnEntity());
                                                                    if (_switchId < _background_id)
                                                                    {
                                                                        size_t tmp = _switchId;
                                                                        _switchId = _background_id;
                                                                        _background_id = tmp;
                                                                    }
                                                                    struct components::sprite_s sprite = {(float)WINDOW_SIZE_X / 380, (float)WINDOW_SIZE_Y / 248, 0, 0, 384, 256, "ressources/LoadingMenu.jpg"};
                                                                    struct components::sprite_s switcher = {(float)WINDOW_SIZE_X / 250, (float)WINDOW_SIZE_Y / 250, 0, 0, 1920, 1080, "ressources/noir.jpg"};
                                                                    struct components::position_s posSprite = {0, 0};
                                                                    struct components::direction_s dirSprite = {0, 0};
                                                                    struct components::velocity_s velSprite = {0, 0};
                                                                    struct components::drawable_s drawableSprite = {true};
                                                                    struct components::scene_s my_sceneSprite = {constants::SCENE::LOADING_MENU};
                                                                    struct components::index_s indexSprite = {_background_id};
                                                                    struct components::position_s posSwitcher = {0, 0};
                                                                    struct components::direction_s dirSwitcher = {0, 0};
                                                                    struct components::velocity_s velSwitcher = {0, 0};
                                                                    struct components::drawable_s drawableSwitcher = {true};
                                                                    struct components::scene_s my_sceneSwitcher = {constants::SCENE::LOADING_MENU};
                                                                    struct components::index_s indexSwitch = {_switchId};
                                                                    struct components::music_s pathMusic = {"ressources/MenuMusic.ogg"};
                                                                    struct components::scene_s sceneMusic = {constants::SCENE::MAIN_MENU};
                                                                    struct components::index_s indexMusic = {_musicId};
                                                                    _graphicalLib->createSprite(_background_id, sprite.scaleX, sprite.scaleY, sprite.rectX, sprite.rectY, sprite.rectWidth, sprite.rectHeight, sprite.path);
                                                                    _graphicalLib->createSprite(_switchId, switcher.scaleX, switcher.scaleY, switcher.rectX, switcher.rectY, switcher.rectWidth, switcher.rectHeight, switcher.path);
                                                                    _graphicalLib->createMusic(_musicId, pathMusic.path);
                                                                    r.addComponent<components::sprite_s>(r.entityFromIndex(_background_id), std::move(sprite));
                                                                    r.addComponent<components::index_s>(r.entityFromIndex(_background_id), std::move(indexSprite));
                                                                    r.addComponent<components::position_s>(r.entityFromIndex(_background_id), std::move(posSprite));
                                                                    r.addComponent<components::velocity_s>(r.entityFromIndex(_background_id), std::move(velSprite));
                                                                    r.addComponent<components::direction_s>(r.entityFromIndex(_background_id), std::move(dirSprite));
                                                                    r.addComponent<components::scene_s>(r.entityFromIndex(_background_id), std::move(my_sceneSprite));
                                                                    r.addComponent<components::drawable_s>(r.entityFromIndex(_background_id), std::move(drawableSprite));
                                                                    r.addComponent<components::sprite_s>(r.entityFromIndex(_switchId), std::move(switcher));
                                                                    r.addComponent<components::index_s>(r.entityFromIndex(_switchId), std::move(indexSwitch));
                                                                    r.addComponent<components::position_s>(r.entityFromIndex(_switchId), std::move(posSwitcher));
                                                                    r.addComponent<components::velocity_s>(r.entityFromIndex(_switchId), std::move(velSwitcher));
                                                                    r.addComponent<components::direction_s>(r.entityFromIndex(_switchId), std::move(dirSwitcher));
                                                                    r.addComponent<components::scene_s>(r.entityFromIndex(_switchId), std::move(my_sceneSwitcher));
                                                                    r.addComponent<components::drawable_s>(r.entityFromIndex(_switchId), std::move(drawableSwitcher));
                                                                    r.addComponent<components::scene_s>(r.entityFromIndex(_switchId), std::move(my_sceneSwitcher));
                                                                    r.addComponent<components::drawable_s>(r.entityFromIndex(_switchId), std::move(drawableSwitcher));
                                                                    r.addComponent<components::scene_s>(r.entityFromIndex(_musicId), std::move(sceneMusic));
                                                                    r.addComponent<components::music_s>(r.entityFromIndex(_musicId), std::move(pathMusic));
                                                                    r.addComponent<components::index_s>(r.entityFromIndex(_musicId), std::move(indexMusic));

                                                                    auto &testSprite = r.getComponents<components::sprite_s>();
                                                                    auto &testIndex = r.getComponents<components::index_s>();
                                                                    auto &testPos = r.getComponents<components::position_s>();
                                                                    auto &testVel = r.getComponents<components::velocity_s>(); 
                                                                    auto &testDir = r.getComponents<components::direction_s>();
                                                                    auto &testDrawable = r.getComponents<components::drawable_s>();
                                                                    auto &testScenes = r.getComponents<components::scene_s>();
                                                                    std::cout << "sprite : " << ((testSprite[_background_id]) ? "true" : "false") << std::endl;
                                                                    std::cout << "Index : " << ((testIndex[_background_id]) ? "true" : "false") << std::endl;
                                                                    std::cout << "pos : " << ((testPos[_background_id]) ? "true" : "false") << std::endl;
                                                                    std::cout << "dir : " << ((testDir[_background_id]) ? "true" : "false") << std::endl;
                                                                    std::cout << "vel : " << ((testVel[_background_id]) ? "true" : "false") << std::endl;
                                                                    std::cout << "draw : " << ((testDrawable[_background_id]) ? "true" : "false") << std::endl;
                                                                    std::cout << "scenes : " << ((testScenes[_background_id]) ? "true" : "false") << std::endl;

                                                                    _graphicalLib->setSpriteColorAlpha(_switchId, 255);
                                                                    _graphicalLib->play(_musicId);
                                                                    auto &scene = currentScenes[constants::RESERVED_ID::GRAPH_UPDATE];
                                                                    if (scene)
                                                                        scene.value().isLoaded = true;
                                                                });
}

void rtype::UpdateGraph::_setupExecLoadingMenuScene()
{
    _execScene[rtype::constants::LOADING_MENU] = std::function([this](Registry &r, UpdateGraph &graph, SparseArray<components::currentScene_s> &currentScenes, GraphicalLib *lib)
                                                               {
                                                                   static std::chrono::duration dtime = std::chrono::nanoseconds(0);
                                                                   static std::chrono::duration dtimeAnim = std::chrono::nanoseconds(0);
                                                                   (void)graph;
                                                                   auto &positions = r.getComponents<components::position_s>();
                                                                   auto &sprites = r.getComponents<components::sprite_s>();
                                                                   auto &scenes = r.getComponents<components::scene_s>();
                                                                   auto &times = r.getComponents<components::myTime_s>();
                                                                   auto &drawables = r.getComponents<components::drawable_s>();
                                                                   auto &time = times[constants::RESERVED_ID::TIME_UPDATE];
                                                                   auto &indexes = r.getComponents<components::index_s>();
                                                                   dtime += time.value().deltaTime;
                                                                   dtimeAnim += time.value().deltaTime;
                                                                   lib->clearScreen();
                                                                   for (auto &&[pos, sprite, scene, drawable, index] : Zipper(positions, sprites, scenes, drawables, indexes))
                                                                   {
                                                                    //    std::cout << "print index : " << index.idx << std::endl;
                                                                       if (!(drawable.drawable))
                                                                           continue;
                                                                       lib->setSpritePosX(index.idx, pos.x);
                                                                       lib->setSpritePosY(index.idx, pos.y);
                                                                       lib->draw(index.idx);
                                                                   }
                                                                   lib->HandleClose();
                                                                   lib->refresh();
                                                                   if (dtime.count() < 8000000000 && dtimeAnim.count() > 5000000 && lib->getSpriteColorAlpha(_switchId))
                                                                   {
                                                                       dtimeAnim = std::chrono::nanoseconds(0);
                                                                       lib->setSpriteColorAlpha(_switchId, lib->getSpriteColorAlpha(_switchId) - 1);
                                                                   }
                                                                   if (dtime.count() > 8000000000 && dtimeAnim.count() > 5000000 && lib->getSpriteColorAlpha(_switchId) < 255)
                                                                   {
                                                                       dtimeAnim = std::chrono::nanoseconds(0);
                                                                       lib->setSpriteColorAlpha(_switchId, lib->getSpriteColorAlpha(_switchId) + 1);
                                                                   }
                                                                   if (dtime.count() > 14000000000)
                                                                   {
                                                                       auto &current = currentScenes[constants::RESERVED_ID::GRAPH_UPDATE];
                                                                       current.value().isLoaded = false;
                                                                       current.value().scene = constants::SCENE::MAIN_MENU;
                                                                       lib->clearScreen();
                                                                       dtime = std::chrono::nanoseconds(0);
                                                                       dtimeAnim = std::chrono::nanoseconds(0);
                                                                   }
                                                               });
}

void rtype::UpdateGraph::_setupDeleteLoadingMenuScene()
{
    _deleteScene[rtype::constants::LOADING_MENU] = std::function([this](Registry &r, UpdateGraph &graph, GraphicalLib *lib)
                                                                 {
                                                                     (void)graph;
                                                                     auto &scenes = r.getComponents<components::scene_s>();
                                                                     auto &indexes = r.getComponents<components::index_s>();
                                                                     lib->clearScreen();
                                                                     for (auto &&[scene, index] : Zipper(scenes, indexes))
                                                                     {
                                                                         if (scene.scene == constants::SCENE::LOADING_MENU)
                                                                             r.killEntity(r.entityFromIndex(index.idx));
                                                                     }
                                                                 });
}

void rtype::UpdateGraph::_setupMainMenuScene()
{
    _setupScene[rtype::constants::MAIN_MENU] = std::function([this](Registry &r, UpdateGraph &graph, SparseArray<components::currentScene_s> &currentScenes)
                                                             {
                                                                 (void)graph;
                                                                 _switchId = (size_t)(r.spawnEntity());
                                                                 _background_id = (size_t)(r.spawnEntity());
                                                                 _buttonStart = (size_t)(r.spawnEntity());
                                                                 if (_switchId < _background_id)
                                                                 {
                                                                     size_t tmp = _switchId;
                                                                     _switchId = _background_id;
                                                                     _background_id = tmp;
                                                                 }
                                                                 struct components::sprite_s sprite = { (float)WINDOW_SIZE_X / 380, (float)WINDOW_SIZE_Y / 248, 0, 0, 384, 256, "ressources/LoadingMenu.jpg" };
                                                                 struct components::sprite_s switcher = {(float)WINDOW_SIZE_X / 250, (float)WINDOW_SIZE_Y / 250, 0, 0, 1920, 1080, "ressources/noir.jpg"};
                                                                 struct components::sprite_s buttonStartSprite = {(float)1, (float)1, 0, 0, 1100, 965, "ressources/canard.png"};
                                                                 struct components::clickable_s buttonStart = {false};
                                                                 struct components::position_s posSprite = {0, 0};
                                                                 struct components::direction_s dirSprite = {0, 0};
                                                                 struct components::velocity_s velSprite = {0, 0};
                                                                 struct components::drawable_s drawableSprite = {true};
                                                                 struct components::index_s idxSprite = {_background_id};
                                                                 struct components::scene_s my_sceneSprite = {constants::SCENE::MAIN_MENU};
                                                                 struct components::position_s posSwitcher = {0, 0};
                                                                 struct components::direction_s dirSwitcher = {0, 0};
                                                                 struct components::velocity_s velSwitcher = {0, 0};
                                                                 struct components::drawable_s drawableSwitcher = {true};
                                                                 struct components::index_s idxSwitch = {_switchId};
                                                                 struct components::scene_s my_sceneSwitcher = {constants::SCENE::MAIN_MENU};
                                                                 _graphicalLib->createSprite(_background_id, sprite.scaleX, sprite.scaleY, sprite.rectX, sprite.rectY, sprite.rectWidth, sprite.rectHeight, sprite.path);
                                                                 _graphicalLib->createSprite(_switchId, switcher.scaleX, switcher.scaleY, switcher.rectX, switcher.rectY, switcher.rectWidth, switcher.rectHeight, switcher.path);
                                                                 struct components::position_s posButton = {100, 100};
                                                                 struct components::direction_s dirButton = {0, 0};
                                                                 struct components::velocity_s velButton = {0, 0};
                                                                 struct components::drawable_s drawableButton = {true};
                                                                 struct components::index_s idxButton = {_buttonStart};
                                                                 struct components::scene_s my_sceneButton = {constants::SCENE::MAIN_MENU};
                                                                 _graphicalLib->createSprite(_buttonStart, buttonStartSprite.scaleX, buttonStartSprite.scaleY, buttonStartSprite.rectX, buttonStartSprite.rectY, buttonStartSprite.rectWidth, buttonStartSprite.rectHeight, buttonStartSprite.path);
                                                                 r.addComponent<components::sprite_s>(r.entityFromIndex(_background_id), std::move(sprite));
                                                                 r.addComponent<components::clickable_s>(r.entityFromIndex(_buttonStart), std::move(buttonStart));
                                                                 r.addComponent<components::index_s>(r.entityFromIndex(_background_id), std::move(idxSprite));
                                                                 r.addComponent<components::position_s>(r.entityFromIndex(_background_id), std::move(posSprite));
                                                                 r.addComponent<components::velocity_s>(r.entityFromIndex(_background_id), std::move(velSprite));
                                                                 r.addComponent<components::direction_s>(r.entityFromIndex(_background_id), std::move(dirSprite));
                                                                 r.addComponent<components::scene_s>(r.entityFromIndex(_background_id), std::move(my_sceneSprite));
                                                                 r.addComponent<components::drawable_s>(r.entityFromIndex(_background_id), std::move(drawableSprite));
                                                                 r.addComponent<components::sprite_s>(r.entityFromIndex(_switchId), std::move(switcher));
                                                                 r.addComponent<components::index_s>(r.entityFromIndex(_switchId), std::move(idxSwitch));
                                                                 r.addComponent<components::position_s>(r.entityFromIndex(_switchId), std::move(posSwitcher));
                                                                 r.addComponent<components::velocity_s>(r.entityFromIndex(_switchId), std::move(velSwitcher));
                                                                 r.addComponent<components::direction_s>(r.entityFromIndex(_switchId), std::move(dirSwitcher));
                                                                 r.addComponent<components::scene_s>(r.entityFromIndex(_switchId), std::move(my_sceneSwitcher));
                                                                 r.addComponent<components::drawable_s>(r.entityFromIndex(_switchId), std::move(drawableSwitcher));
                                                                 r.addComponent<components::sprite_s>(r.entityFromIndex(_buttonStart), std::move(buttonStartSprite));
                                                                 r.addComponent<components::index_s>(r.entityFromIndex(_buttonStart), std::move(idxButton));
                                                                 r.addComponent<components::position_s>(r.entityFromIndex(_buttonStart), std::move(posButton));
                                                                 r.addComponent<components::velocity_s>(r.entityFromIndex(_buttonStart), std::move(velButton));
                                                                 r.addComponent<components::direction_s>(r.entityFromIndex(_buttonStart), std::move(dirButton));
                                                                 r.addComponent<components::scene_s>(r.entityFromIndex(_buttonStart), std::move(my_sceneButton));
                                                                 r.addComponent<components::drawable_s>(r.entityFromIndex(_buttonStart), std::move(drawableButton));
                                                                 _graphicalLib->setSpriteColorAlpha(_switchId, 255);
                                                                 auto &scene = currentScenes[constants::RESERVED_ID::GRAPH_UPDATE];
                                                                 if (scene)
                                                                     scene.value().isLoaded = true;
                                                             });
}

void rtype::UpdateGraph::_setupExecMainMenuScene()
{
    _execScene[rtype::constants::MAIN_MENU] = std::function([this](Registry &r, UpdateGraph &graph, SparseArray<components::currentScene_s> &currentScenes, GraphicalLib *lib)
                                                            {
                                                                static std::chrono::duration dtime = std::chrono::nanoseconds(0);
                                                                static std::chrono::duration dtimeAnim = std::chrono::nanoseconds(0);
                                                                (void)graph;
                                                                auto &positions = r.getComponents<components::position_s>();
                                                                auto &sprites = r.getComponents<components::sprite_s>();
                                                                auto &buttons = r.getComponents<components::clickable_s>();
                                                                auto &scenes = r.getComponents<components::scene_s>();
                                                                auto &times = r.getComponents<components::myTime_s>();
                                                                auto &indexes = r.getComponents<components::index_s>();
                                                                auto &time = times[constants::RESERVED_ID::TIME_UPDATE];
                                                                auto &drawables = r.getComponents<components::drawable_s>();
                                                                dtimeAnim += time.value().deltaTime;
                                                                dtime += time.value().deltaTime;
                                                                lib->clearScreen();
                                                                for (auto &&[pos, sprite, scene, drawable, index] : Zipper(positions, sprites, scenes, drawables, indexes))
                                                                {
                                                                    if (!(drawable.drawable))
                                                                    {
                                                                        continue;
                                                                    }
                                                                    lib->setSpritePosX(index.idx, pos.x);
                                                                    lib->setSpritePosY(index.idx, pos.y);
                                                                    lib->draw(index.idx);
                                                                }
                                                                lib->HandleClose();
                                                                lib->refresh();
                                                                if (dtime.count() < 8000000000 && dtimeAnim.count() > 5000000 && lib->getSpriteColorAlpha(_switchId))
                                                                {
                                                                    dtimeAnim = std::chrono::nanoseconds(0);
                                                                    lib->setSpriteColorAlpha(_switchId, lib->getSpriteColorAlpha(_switchId) - 1);
                                                                }
                                                                if (dtime.count() > 8000000000 && dtimeAnim.count() > 5000000 && lib->getSpriteColorAlpha(_switchId) < 255)
                                                                {
                                                                    dtimeAnim = std::chrono::nanoseconds(0);
                                                                    lib->setSpriteColorAlpha(_switchId, lib->getSpriteColorAlpha(_switchId) + 1);
                                                                }
                                                                if (dtime.count() > 14000000000)
                                                                {
                                                                    auto &current = currentScenes[constants::RESERVED_ID::GRAPH_UPDATE];
                                                                    current.value().isLoaded = false;
                                                                    current.value().scene = constants::SCENE::LOADING_MENU;
                                                                    lib->clearScreen();
                                                                    dtime = std::chrono::nanoseconds(0);
                                                                    dtimeAnim = std::chrono::nanoseconds(0);
                                                                }
                                                            });
}

void rtype::UpdateGraph::_setupDeleteMainMenuScene()
{
    _deleteScene[rtype::constants::MAIN_MENU] = std::function([this](Registry &r, UpdateGraph &graph, GraphicalLib *lib)
                                                              {
                                                                  (void)graph;
                                                                  auto &scenes = r.getComponents<components::scene_s>();
                                                                  auto &indexes = r.getComponents<components::index_s>();
                                                                  auto &musics = r.getComponents<components::music_s>();

                                                                  lib->clearScreen();
                                                                  for (auto &&[scene, index, music] : Zipper(scenes, indexes, musics))
                                                                  {
                                                                      if (scene.scene == constants::SCENE::MAIN_MENU)
                                                                          lib->stop(index.idx);
                                                                  }
                                                                  for (auto &&[scene, index] : Zipper(scenes, indexes))
                                                                  {
                                                                      if (scene.scene == constants::SCENE::MAIN_MENU)
                                                                          r.killEntity(r.entityFromIndex(index.idx));
                                                                  }
                                                                  lib->clearScreen();
                                                              });
}
