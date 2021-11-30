
#include "GraphicalLib.hpp"
#include <vector>
#include <memory>

rtype::GraphicalLib::GraphicalLib()
    : _renderWindow(new sf::RenderWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), WINDOW_NAME, sf::Style::Titlebar | sf::Style::Close)), _mouse()
{
    _spriteMap = {};
    _textMap = {};
    _soundMap = {};
    _musicMap = {};

    sf::Image icon;
    icon.loadFromFile("ressources/canard.png");
    _renderWindow->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    _renderWindow->setFramerateLimit(FRAME_RATE);
}

void rtype::GraphicalLib::draw(size_t id)
{
    _renderWindow->draw(_spriteMap[id]->getSprite());
}

void rtype::GraphicalLib::print(size_t id)
{
    _renderWindow->draw(_textMap[id]->getText());
}

void rtype::GraphicalLib::start(size_t id)
{
    _soundMap[id]->getSound().play();
}

void rtype::GraphicalLib::play(size_t id)
{
    _musicMap[id]->getMusic().play();
}

void rtype::GraphicalLib::stop(size_t id)
{
    _musicMap[id]->getMusic().stop();
}

void rtype::GraphicalLib::pause(size_t id)
{
    _musicMap[id]->getMusic().pause();
}

void rtype::GraphicalLib::clearScreen()
{
    _renderWindow->clear(sf::Color(sf::Color::Magenta));
}

void rtype::GraphicalLib::refresh()
{
    _renderWindow->display();
}

void rtype::GraphicalLib::createSound(size_t id, const std::string &path)
{
    _soundMap[id].reset(new Sound(path));
}

void rtype::GraphicalLib::createMusic(size_t id, const std::string &path)
{
    _musicMap[id].reset(new Music(path));
}

void rtype::GraphicalLib::createText(size_t id, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath)
{
    _textMap[id].reset(new Text(0.f, 0.f, fontSize, colorRed, colorGreen, colorBlue, colorAlpha, content, fontPath));
}

void rtype::GraphicalLib::createSprite(size_t id, float scaleX, float scaleY, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path)
{
    _spriteMap[id].reset(new Sprite(0.f, 0.f, 0.f, scaleX, scaleY, rectX, rectY, rectWidth, rectHeigth, path));
}

void rtype::GraphicalLib::deleteSound(size_t id)
{
    (void)id;
}

void rtype::GraphicalLib::deleteMusic(size_t id)
{
    (void)id;
}

void rtype::GraphicalLib::deleteText(size_t id)
{
    (void)id;
}

void rtype::GraphicalLib::deleteSprite(size_t id)
{
    (void)id;
}

bool rtype::GraphicalLib::getKeyState(rtype::constants::EVENT event)
{
    switch (event)
    {
    case (constants::KEY_DOWN):
        return (sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
    case (constants::KEY_UP):
        return (sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
    case (constants::KEY_LEFT):
        return (sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
    case (constants::KEY_RIGHT):
        return (sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
    case (constants::KEY_ENTER):
        return (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));
    case (constants::KEY_SPACE):
        return (sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
    default:
        return (false);
    }
}

rtype::mouse_t rtype::GraphicalLib::getMouseState()
{
    rtype::mouse_t mouseState;
    mouseState.posX = _mouse.getPosition(*_renderWindow).x;
    mouseState.posY = _mouse.getPosition(*_renderWindow).y;
    mouseState.leftPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    mouseState.leftPressed = sf::Mouse::isButtonPressed(sf::Mouse::Right);
    return (mouseState);
}

float rtype::GraphicalLib::getSpritePosX(size_t id)
{
    return (_spriteMap[id]->getPosX());
}

float rtype::GraphicalLib::getSpritePosY(size_t id)
{
    return (_spriteMap[id]->getPosY());
}

float rtype::GraphicalLib::getSpriteRotation(size_t id)
{
    return (_spriteMap[id]->getRotation());
}

float rtype::GraphicalLib::getSpriteScale(size_t id)
{
    return (_spriteMap[id]->getScale());
}

int rtype::GraphicalLib::getSpriteRectX(size_t id)
{
    return (_spriteMap[id]->getRectX());
}

int rtype::GraphicalLib::getSpriteRectY(size_t id)
{
    return (_spriteMap[id]->getRectY());
}

int rtype::GraphicalLib::getSpriteRectHeigth(size_t id)
{
    return (_spriteMap[id]->getRectHeigth());
}

int rtype::GraphicalLib::getSpriteRectWidth(size_t id)
{
    return (_spriteMap[id]->getRectWidth());
}

int rtype::GraphicalLib::getSpriteColorAlpha(size_t id)
{
    return (_spriteMap[id]->getColorAlpha());
}

void rtype::GraphicalLib::setSpritePosX(size_t id, float posX)
{
    _spriteMap[id]->setPosX(posX);
}

void rtype::GraphicalLib::setSpritePosY(size_t id, float posY)
{
    _spriteMap[id]->setPosY(posY);
}

void rtype::GraphicalLib::setSpriteRotation(size_t id, float rotation)
{
    _spriteMap[id]->setRotation(rotation);
}

void rtype::GraphicalLib::setSpriteScale(size_t id, float scaleX, float scaleY)
{
    _spriteMap[id]->setScaleX(scaleX);
    _spriteMap[id]->setScaleY(scaleY);
}

void rtype::GraphicalLib::setSpriteRectX(size_t id, int rectX)
{
    _spriteMap[id]->setRectX(rectX);
}

void rtype::GraphicalLib::setSpriteRectY(size_t id, int rectY)
{
    _spriteMap[id]->setRectY(rectY);
}

void rtype::GraphicalLib::setSpriteRectWidth(size_t id, int rectWidth)
{
    _spriteMap[id]->setRectWidth(rectWidth);
}

void rtype::GraphicalLib::setSpriteRectHeigth(size_t id, int rectHeigth)
{
    _spriteMap[id]->setRectHeigth(rectHeigth);
}

void rtype::GraphicalLib::setSpriteColorAlpha(size_t id, int colorAlpha)
{
    _spriteMap[id]->setColorAlpha(colorAlpha);
}

float rtype::GraphicalLib::getTextPosX(size_t id)
{
    return (_textMap[id]->getPosX());
}

float rtype::GraphicalLib::getTextPosY(size_t id)
{
    return (_textMap[id]->getPosY());
}

int rtype::GraphicalLib::getTextFontSize(size_t id)
{
    return (_textMap[id]->getFontSize());
}

int rtype::GraphicalLib::getTextColorRed(size_t id)
{
    return (_textMap[id]->getColorRed());
}

int rtype::GraphicalLib::getTextColorGreen(size_t id)
{
    return (_textMap[id]->getColorGreen());
}

int rtype::GraphicalLib::getTextColorBlue(size_t id)
{
    return (_textMap[id]->getColorBlue());
}

int rtype::GraphicalLib::getTextColorAlpha(size_t id)
{
    return (_textMap[id]->getColorAlpha());
}

std::string rtype::GraphicalLib::getTextContent(size_t id)
{
    return (_textMap[id]->getContent());
}

void rtype::GraphicalLib::setTextPosX(size_t id, float posX)
{
    _textMap[id]->setPosX(posX);
}

void rtype::GraphicalLib::setTextPosY(size_t id, float posY)
{
    _textMap[id]->setPosY(posY);
}

void rtype::GraphicalLib::setTextFontSize(size_t id, int fontSize)
{
    _textMap[id]->setFontSize(fontSize);
}

void rtype::GraphicalLib::setTextColorRed(size_t id, int colorRed)
{
    _textMap[id]->setColorRed(colorRed);
}

void rtype::GraphicalLib::setTextColorGreen(size_t id, int colorGreen)
{
    _textMap[id]->setColorGreen(colorGreen);
}

void rtype::GraphicalLib::setTextColorBlue(size_t id, int colorBlue)
{
    _textMap[id]->setColorBlue(colorBlue);
}

void rtype::GraphicalLib::setTextColorAlpha(size_t id, int colorAlpha)
{
    _textMap[id]->setColorAlpha(colorAlpha);
}

void rtype::GraphicalLib::setTextContent(size_t id, std::string &content)
{
    _textMap[id]->setContent(content);
}

void rtype::GraphicalLib::HandleClose()
{
    sf::Event _event;
    _renderWindow->pollEvent(_event);
    if (_event.type == sf::Event::Closed)
    {
        _renderWindow->close();
    }
}
