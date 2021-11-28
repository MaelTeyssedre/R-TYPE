
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
    static constants::SCENE previous_scene = constants::LOADING_MENU;
    for (size_t i = 0; i < currentScenes.size(); i++)
    {
        auto &scene = currentScenes[i];
        if (!scene)
        {
            continue;
        }
        if (!(scene.value().isLoaded))
        {
            _deleteScene[previous_scene](r, *this, dynamic_cast<GraphicalLib *>(_graphicalLib));
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
    for (size_t i = 0; i < mouseStates.size() && i < keyStates.size(); i++)
    {
        std::optional<components::mouseState_s> &mouseState = mouseStates[i];
        std::optional<components::keyState_s> &keyState = keyStates[i];
        if (mouseState && keyState)
        {
            mouseState.value().mousePosX = mouse.posX;
            mouseState.value().mousePosY = mouse.posY;
            mouseState.value().mouseLeftClick = mouse.leftPressed;
            mouseState.value().mouseRightClick = mouse.rightPressed;
            keyState.value().keyDown = _graphicalLib->getKeyState(rtype::constants::KEY_DOWN);
            keyState.value().keyUp = _graphicalLib->getKeyState(rtype::constants::KEY_UP);
            keyState.value().keyRight = _graphicalLib->getKeyState(rtype::constants::KEY_RIGHT);
            keyState.value().keyLeft = _graphicalLib->getKeyState(rtype::constants::KEY_LEFT);
            keyState.value().keyEnter = _graphicalLib->getKeyState(rtype::constants::KEY_ENTER);
            keyState.value().keySpace = _graphicalLib->getKeyState(rtype::constants::KEY_SPACE);
        }
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
                                                                    struct components::sprite_s sprite = {(float)WINDOW_SIZE_X / 660, (float)WINDOW_SIZE_Y / 248, 0, 0, 384, 256, "ressources/LoadingMenu.jpg"};
                                                                    struct components::sprite_s switcher = {(float)WINDOW_SIZE_X / 250, (float)WINDOW_SIZE_Y / 250, 0, 0, 1920, 1080, "ressources/noir.jpg"};
                                                                    struct components::position_s posSprite = {0, 0};
                                                                    struct components::direction_s dirSprite = {0, 0};
                                                                    struct components::velocity_s velSprite = {0, 0};
                                                                    struct components::drawable_s drawableSprite = {true};
                                                                    struct components::scene_s my_sceneSprite = {constants::SCENE::LOADING_MENU};
                                                                    struct components::position_s posSwitcher = {0, 0};
                                                                    struct components::direction_s dirSwitcher = {0, 0};
                                                                    struct components::velocity_s velSwitcher = {0, 0};
                                                                    struct components::drawable_s drawableSwitcher = {true};
                                                                    struct components::scene_s my_sceneSwitcher = {constants::SCENE::LOADING_MENU};
                                                                    _graphicalLib->createSprite(_background_id, sprite.scaleX, sprite.scaleY, sprite.rectX, sprite.rectY, sprite.rectWidth, sprite.rectHeight, sprite.path);
                                                                    _graphicalLib->createSprite(_switchId, switcher.scaleX, switcher.scaleY, switcher.rectX, switcher.rectY, switcher.rectWidth, switcher.rectHeight, switcher.path);
                                                                    r.addComponent<components::sprite_s>(r.entityFromIndex(_background_id), std::move(sprite));
                                                                    r.addComponent<components::position_s>(r.entityFromIndex(_background_id), std::move(posSprite));
                                                                    r.addComponent<components::velocity_s>(r.entityFromIndex(_background_id), std::move(velSprite));
                                                                    r.addComponent<components::direction_s>(r.entityFromIndex(_background_id), std::move(dirSprite));
                                                                    r.addComponent<components::scene_s>(r.entityFromIndex(_background_id), std::move(my_sceneSprite));
                                                                    r.addComponent<components::drawable_s>(r.entityFromIndex(_background_id), std::move(drawableSprite));
                                                                    r.addComponent<components::sprite_s>(r.entityFromIndex(_switchId), std::move(switcher));
                                                                    r.addComponent<components::position_s>(r.entityFromIndex(_switchId), std::move(posSwitcher));
                                                                    r.addComponent<components::velocity_s>(r.entityFromIndex(_switchId), std::move(velSwitcher));
                                                                    r.addComponent<components::direction_s>(r.entityFromIndex(_switchId), std::move(dirSwitcher));
                                                                    r.addComponent<components::scene_s>(r.entityFromIndex(_switchId), std::move(my_sceneSwitcher));
                                                                    r.addComponent<components::drawable_s>(r.entityFromIndex(_switchId), std::move(drawableSwitcher));
                                                                    _graphicalLib->setSpriteColorAlpha(_switchId, 255);
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
                                                                   dtime += time.value().deltaTime;
                                                                   dtimeAnim += time.value().deltaTime;
                                                                   lib->clearScreen();
                                                                   for (size_t i = 0; i < positions.size(); i++)
                                                                   {
                                                                       auto &pos = positions[i];
                                                                       auto &sprite = sprites[i];
                                                                       auto &scene = scenes[i];
                                                                       auto &drawable = drawables[i];
                                                                       if (!scene || !drawable || !(drawable.value().drawable))
                                                                           continue;
                                                                       if (pos)
                                                                       {
                                                                           lib->setSpritePosX(i, pos.value().x);
                                                                           lib->setSpritePosY(i, pos.value().y);
                                                                       }
                                                                       if (sprite)
                                                                       {
                                                                           lib->draw(i);
                                                                       }
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
                                                                   if (dtime.count() > 10000000000)
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
                                                                     lib->clearScreen();
                                                                     for (size_t i = 0; i < scenes.size(); i++)
                                                                     {
                                                                         auto &scene = scenes[i];
                                                                         if (scene && scene.value().scene == constants::SCENE::LOADING_MENU)
                                                                             r.killEntity(r.entityFromIndex(i));
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
                                                                 struct components::sprite_s sprite = {(float)WINDOW_SIZE_X / 660, (float)WINDOW_SIZE_Y / 248, 0, 0, 384, 256, "ressources/LoadingMenu.jpg"};
                                                                 struct components::sprite_s switcher = {(float)WINDOW_SIZE_X / 250, (float)WINDOW_SIZE_Y / 250, 0, 0, 1920, 1080, "ressources/noir.jpg"};
                                                                 struct components::position_s posSprite = {0, 0};
                                                                 struct components::direction_s dirSprite = {0, 0};
                                                                 struct components::velocity_s velSprite = {0, 0};
                                                                 struct components::drawable_s drawableSprite = {true};
                                                                 struct components::scene_s my_sceneSprite = {constants::SCENE::MAIN_MENU};
                                                                 struct components::position_s posSwitcher = {0, 0};
                                                                 struct components::direction_s dirSwitcher = {0, 0};
                                                                 struct components::velocity_s velSwitcher = {0, 0};
                                                                 struct components::drawable_s drawableSwitcher = {true};
                                                                 struct components::scene_s my_sceneSwitcher = {constants::SCENE::MAIN_MENU};
                                                                 _graphicalLib->createSprite(_background_id, sprite.scaleX, sprite.scaleY, sprite.rectX, sprite.rectY, sprite.rectWidth, sprite.rectHeight, sprite.path);
                                                                 _graphicalLib->createSprite(_switchId, switcher.scaleX, switcher.scaleY, switcher.rectX, switcher.rectY, switcher.rectWidth, switcher.rectHeight, switcher.path);
                                                                 std::cout << "PAS LE SWITCH ID " << (size_t)(_background_id) << std::endl;
                                                                 std::cout << "SWITCH ID " << (size_t)(_switchId) << std::endl;
                                                                 r.addComponent<components::sprite_s>(r.entityFromIndex(_background_id), std::move(sprite));
                                                                 r.addComponent<components::position_s>(r.entityFromIndex(_background_id), std::move(posSprite));
                                                                 r.addComponent<components::velocity_s>(r.entityFromIndex(_background_id), std::move(velSprite));
                                                                 r.addComponent<components::direction_s>(r.entityFromIndex(_background_id), std::move(dirSprite));
                                                                 r.addComponent<components::scene_s>(r.entityFromIndex(_background_id), std::move(my_sceneSprite));
                                                                 r.addComponent<components::drawable_s>(r.entityFromIndex(_background_id), std::move(drawableSprite));
                                                                 r.addComponent<components::sprite_s>(r.entityFromIndex(_switchId), std::move(switcher));
                                                                 r.addComponent<components::position_s>(r.entityFromIndex(_switchId), std::move(posSwitcher));
                                                                 r.addComponent<components::velocity_s>(r.entityFromIndex(_switchId), std::move(velSwitcher));
                                                                 r.addComponent<components::direction_s>(r.entityFromIndex(_switchId), std::move(dirSwitcher));
                                                                 r.addComponent<components::scene_s>(r.entityFromIndex(_switchId), std::move(my_sceneSwitcher));
                                                                 r.addComponent<components::drawable_s>(r.entityFromIndex(_switchId), std::move(drawableSwitcher));
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
                                                                auto &scenes = r.getComponents<components::scene_s>();
                                                                auto &times = r.getComponents<components::myTime_s>();
                                                                auto &time = times[constants::RESERVED_ID::TIME_UPDATE];
                                                                auto &drawables = r.getComponents<components::drawable_s>();
                                                                dtimeAnim += time.value().deltaTime;
                                                                dtime += time.value().deltaTime;
                                                                lib->clearScreen();
                                                                for (size_t i = 0; i < positions.size(); i++)
                                                                {
                                                                    auto &pos = positions[i];
                                                                    auto &sprite = sprites[i];
                                                                    auto &scene = scenes[i];
                                                                    auto &drawable = drawables[i];
                                                                    if (!scene || !drawable || !(drawable.value().drawable))
                                                                    {
                                                                        continue;
                                                                    }
                                                                    if (pos)
                                                                    {
                                                                        lib->setSpritePosX(i, pos.value().x);
                                                                        lib->setSpritePosY(i, pos.value().y);
                                                                    }
                                                                    if (sprite)
                                                                    {
                                                                        lib->draw(i);
                                                                    }
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
                                                                if (dtime.count() > 10000000000)
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

                                                                  lib->clearScreen();
                                                                  for (size_t i = 0; i < scenes.size(); i++)
                                                                  {
                                                                      auto &scene = scenes[i];
                                                                      if (!scene)
                                                                          continue;
                                                                      if (scene && scene.value().scene == constants::SCENE::MAIN_MENU)
                                                                          r.killEntity(r.entityFromIndex(i));
                                                                  }
                                                                  lib->clearScreen();
                                                              });
}
