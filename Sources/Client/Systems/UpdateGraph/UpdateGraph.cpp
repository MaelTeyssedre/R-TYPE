
#include "UpdateGraph.hpp"

UpdateGraph::UpdateGraph()
{ 
    _graphicalLib = new rtype::GraphicalLib();
    _isSetupNeeded = {};
    _setupScene = {};
    _displayScene = {};

    _graphicalLib->setCurrentScene(rtype::constants::LOADING_MENU);
    setupIsSetupNeeded();
    setupSetupScene();
    setupDisplayScene();
}

void UpdateGraph::operator()(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates)
{
    (void)r;
    updateEvent(mouseStates, keyStates);
    setupGraph(r);
    //displayGraph(r);
}

void UpdateGraph::setupGraph(Registry &r)
{
    (void)r;
}

void UpdateGraph::displayGraph(Registry &r)
{
    (void)r;
}

void UpdateGraph::updateEvent(SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates)
{
    (void)mouseStates;
    (void)keyStates;
    //rtype::mouse_t mouse = _graphicalLib->getMouseState();
    //std::optional<components::mouseState_s> mouseState = mouseStates[0];
    /*for (auto &&[mouseState, keyState] : Zipper(mouseStates, keyStates)) {
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
    }*/
}

void UpdateGraph::setupIsSetupNeeded()
{
    _isSetupNeeded[rtype::constants::MAIN_MENU] = true;
    _isSetupNeeded[rtype::constants::PARAMS] = true;
    _isSetupNeeded[rtype::constants::GAME] = true;
    _isSetupNeeded[rtype::constants::LOADING_MENU] = true;
    _isSetupNeeded[rtype::constants::LOADING_GAME] = true;
}

void UpdateGraph::setupSetupScene()
{
    setupSetupLoadingMenuScene();
    /*setupSetupLoadingGameScene();
    setupSetupGameScene();
    setupSetupParamsScene();
    setupSetupMainMenuScene();*/
}

void UpdateGraph::setupDisplayScene()
{
    setupDisplayLoadingMenuScene();
    /*setupDisplayLoadingGameScene();
    setupDisplayGameScene();
    setupDisplayParamsScene();
    setupDisplayMainMenuScene();*/
}

void UpdateGraph::setupSetupLoadingMenuScene()
{
    _setupScene[rtype::constants::LOADING_MENU] = [this](Registry &r, UpdateGraph &graph) {
        (void)r;
        (void)graph;
        _isSetupNeeded[rtype::constants::LOADING_MENU] = false;

        _graphicalLib->addSprite(rtype::constants::LOADING_MENU, _graphicalLib->createSprite(0.f, 0.f, (float)WINDOW_SIZE_X / 384, (float)WINDOW_SIZE_Y / 256, 0, 0, 384, 256, "ressources/LoadingMenu.jpg"));

/*
        rtype::component::position_s* pos_back = new rtype::component::position_s {0, 0};
        rtype::component::size_s* size_back = new rtype::component::size_s {800, 600};
        rtype::component::window_s* win_back = new rtype::component::window_s {&window};
        rtype::component::drawable_s* sprite_back = new rtype::component::drawable_s;
        sprite_back->texture.loadFromFile("ressources/LoadingMenu.jpg");
        sprite_back->sprite.setTexture(sprite_back->texture, true);
        sprite_back->window = &window;
        sprite_back->sprite.setPosition(sf::Vector2f((float)pos_back->x, (float)pos_back->y));
        sprite_back->sprite.setScale((float)window.getSize().x / sprite_back->texture.getSize().x, (float)window.getSize().y / sprite_back->texture.getSize().y);
        rtype::component::controllable_s* ctrl_back = new rtype::component::controllable_s {false};
        rtype::component::current_scene_s* current_scene_back = new rtype::component::current_scene_s {rtype::constants::LOADING_MENU};
        rtype::component::entity_scene_s* entity_scene_back = new rtype::component::entity_scene_s {rtype::constants::LOADING_MENU};
        rtype::component::callback_s* callback_back = new rtype::component::callback_s {[](Registry &r) -> void {
            SparseArray<rtype::component::current_scene_s> &current_scenes = r.getComponents<rtype::component::current_scene_s>();
            for (size_t i = 0; i < current_scenes.size(); i++) {
                std::optional<rtype::component::current_scene_s> &current_scene = current_scenes[i];
                if (current_scene)
                    current_scene.value().scene = rtype::constants::MAIN_MENU;
            }
        }};

        r.addComponent<rtype::component::position_s>(r.entityFromIndex(id_back), std::move(*pos_back));
        r.addComponent<rtype::component::controllable_s>(r.entityFromIndex(id_back), std::move(*ctrl_back));
        r.addComponent<rtype::component::drawable_s>(r.entityFromIndex(id_back), std::move(*sprite_back));
        r.addComponent<rtype::component::callback_s>(r.entityFromIndex(id_back), std::move(*callback_back));
        r.addComponent<rtype::component::size_s>(r.entityFromIndex(id_back), std::move(*size_back));
        r.addComponent<rtype::component::window_s>(r.entityFromIndex(id_back), std::move(*win_back));
        r.addComponent<rtype::component::current_scene_s>(r.entityFromIndex(id_back), std::move(*current_scene_back));
        r.addComponent<rtype::component::entity_scene_s>(r.entityFromIndex(id_back), std::move(*entity_scene_back));
*/
    };
}

void UpdateGraph::setupDisplayLoadingMenuScene()
{
    _displayScene[rtype::constants::LOADING_MENU] = std::function([this](Registry &r, UpdateGraph &graph) {
        (void)r;
        (void)graph;
        _graphicalLib->draw();
    });
}
