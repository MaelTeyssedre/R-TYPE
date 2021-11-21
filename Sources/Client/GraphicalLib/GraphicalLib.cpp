/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** GraphicalLib
*/

#include "GraphicalLib.hpp"

rtype::GraphicalLib::GraphicalLib()
    : _sprites(), _texts(), _sounds(), _musics(), _currentScene(rtype::constants::LOADING_MENU), _renderWindow (sf::VideoMode(1720, 970), "RPR-TYPE")
{
}

void rtype::GraphicalLib::draw()
{
    for (const auto &it : _sprites) {
        if (it.first == _currentScene)
            _renderWindow.draw(it.second->getSprite());
    }
    for (const auto &it : _texts) {
        if (it.first == _currentScene)
            _renderWindow.draw(it.second->getText());
    }
}

void rtype::GraphicalLib::play(rtype::Sound &sound)
{
    sound.getSound().play();
}

void rtype::GraphicalLib::play(rtype::Music &music)
{
    music.getMusic().play();
}

void rtype::GraphicalLib::refresh()
{
    _renderWindow.display();
    _renderWindow.clear();
}

std::shared_ptr<rtype::Sound> rtype::GraphicalLib::createSound(const std::string &path)
{
    return (std::shared_ptr<Sound>(new Sound(path)));
}

std::shared_ptr<rtype::Music> rtype::GraphicalLib::createMusic(const std::string &path)
{
    return (std::shared_ptr<Music>(new Music(path)));
}

std::shared_ptr<rtype::Text> rtype::GraphicalLib::createText(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath)
{
    return (std::shared_ptr<Text>(new Text(posX, posY, fontSize, colorRed, colorGreen, colorBlue, colorAlpha, content, fontPath)));
}

std::shared_ptr<rtype::Sprite> rtype::GraphicalLib::createSprite(float posX, float posY, float rotation, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path)
{
    return (std::shared_ptr<Sprite>(new Sprite(posX, posY, rotation, scale, rectX, rectY, rectWidth, rectHeigth, path)));
}

void rtype::GraphicalLib::addSound(rtype::constants::SCENE scene, std::shared_ptr<rtype::Sound> sound)
{
    _sounds.push_back(std::make_pair(scene, sound));
}

void rtype::GraphicalLib::addMusic(rtype::constants::SCENE scene, std::shared_ptr<rtype::Music> music)
{
    _musics.push_back(std::make_pair(scene, music));
}

void rtype::GraphicalLib::addText(rtype::constants::SCENE scene, std::shared_ptr<rtype::Text> text)
{
    _texts.push_back(std::make_pair(scene, text));
}

void rtype::GraphicalLib::addSprite(rtype::constants::SCENE scene, std::shared_ptr<rtype::Sprite> sprite)
{
    _sprites.push_back(std::make_pair(scene, sprite));
}

void rtype::GraphicalLib::deleteSound(size_t id)
{
    if (id < _sounds.size())
        _sounds.erase(_sounds.begin() + id);
}

void rtype::GraphicalLib::deleteMusic(size_t id)
{
    if (id < _musics.size())
        _musics.erase(_musics.begin() + id);
}

void rtype::GraphicalLib::deleteText(size_t id)
{
    if (id < _texts.size())
        _texts.erase(_texts.begin() + id);
}

void rtype::GraphicalLib::deleteSprite(size_t id)
{
    if (id < _sprites.size())
        _sprites.erase(_sprites.begin() + id);
}

std::map<rtype::constants::KEY, bool> rtype::GraphicalLib::getKeyState()
{
    _keyState[constants::KEY_DOWN] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    _keyState[constants::KEY_UP] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    _keyState[constants::KEY_LEFT] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    _keyState[constants::KEY_RIGHT] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    _keyState[constants::KEY_ENTER] = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
    _keyState[constants::KEY_SPACE] = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
    return (_keyState);
}

rtype::mouse_t rtype::GraphicalLib::getMouseState()
{
    _mouseState.posX = _mouse.getPosition(_renderWindow).x;
    _mouseState.posY = _mouse.getPosition(_renderWindow).y;
    _mouseState.leftPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    _mouseState.leftPressed = sf::Mouse::isButtonPressed(sf::Mouse::Right);
    return (_mouseState);
}