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

size_t rtype::GraphicalLib::createSound(constants::SCENE scene, const std::string &path)
{
    _sounds.push_back(std::make_pair(scene, std::shared_ptr<Sound>(new Sound(path))));
}

size_t rtype::GraphicalLib::createMusic(constants::SCENE scene, const std::string &path)
{
    _musics.push_back(std::make_pair(scene, std::shared_ptr<Music>(new Music(path))));
}

size_t rtype::GraphicalLib::createText(constants::SCENE scene, float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath)
{
    _texts.push_back(std::make_pair(scene, std::shared_ptr<Text>(new Text(posX, posY, fontSize, colorRed, colorGreen, colorBlue, colorAlpha, content, fontPath))));
}

size_t rtype::GraphicalLib::createSprite(constants::SCENE scene, float posX, float posY, float rotation, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path)
{
    _sprites.push_back(std::make_pair(scene, std::shared_ptr<Sprite>(new Sprite(posX, posY, rotation, scale, rectX, rectY, rectWidth, rectHeigth, path))));
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