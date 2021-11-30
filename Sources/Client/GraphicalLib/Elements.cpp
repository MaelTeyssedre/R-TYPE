
#include "Elements.hpp"
#include <iostream>
#include <new>
#include <stdexcept>
#include <exception>

rtype::Sprite::Sprite(float posX, float posY, float rotation, float scaleX, float scaleY, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path)
    : _posX(posX), _posY(posY), _rotation(rotation), _scaleX(scaleX), _scaleY(scaleY), _rectX(rectX), _rectY(rectY), _rectWidth(rectWidth), _rectHeigth(rectHeigth), _path(path), _texture(), _sprite()
{
    _sprite.setPosition(sf::Vector2f(_posX, _posY));
    _sprite.setRotation(_rotation);
    _sprite.setScale(sf::Vector2f(_scaleX, _scaleY));
    if (!_texture.loadFromFile(_path))
        throw std::runtime_error("Fail to load texture");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(_rectX, _rectY, _rectWidth, _rectHeigth));
}

float rtype::Sprite::getPosX()
{
    return _posX;
}

float rtype::Sprite::getPosY()
{
    return _posY;
}

float rtype::Sprite::getRotation()
{
    return _rotation;
}

float rtype::Sprite::getScale()
{
    return _scaleX;
}

int rtype::Sprite::getRectX()
{
    return _rectX;
}

int rtype::Sprite::getRectY()
{
    return _rectY;
}

int rtype::Sprite::getRectWidth()
{
    return _rectWidth;
}

int rtype::Sprite::getRectHeigth()
{
    return _rectHeigth;
}

int rtype::Sprite::getColorAlpha()
{
    return _colorAlpha;
}

void rtype::Sprite::setPosX(float posX)
{
    _posX = posX;
    _sprite.setPosition(sf::Vector2f(_posX, _posY));
}

void rtype::Sprite::setPosY(float posY)
{
    _posY = posY;
    _sprite.setPosition(sf::Vector2f(_posX, _posY));
}

void rtype::Sprite::setRotation(float rotation)
{
    _rotation = rotation;
    _sprite.setRotation(_rotation);
}

void rtype::Sprite::setScaleX(float scaleX)
{
    _scaleX = scaleX;
    _sprite.setScale(sf::Vector2f(_scaleX, _scaleY));
}

void rtype::Sprite::setScaleY(float scaleY)
{
    _scaleY = scaleY;
    _sprite.setScale(sf::Vector2f(_scaleX, _scaleY));
}

void rtype::Sprite::setRectX(int rectX)
{
    _rectX = rectX;
    _sprite.setTextureRect(sf::IntRect(_rectX, _rectY, _rectWidth, _rectHeigth));
}

void rtype::Sprite::setRectY(int rectY)
{
    _rectY = rectY;
    _sprite.setTextureRect(sf::IntRect(_rectX, _rectY, _rectWidth, _rectHeigth));
}

void rtype::Sprite::setRectWidth(int rectWith)
{
    _rectWidth = rectWith;
    _sprite.setTextureRect(sf::IntRect(_rectX, _rectY, _rectWidth, _rectHeigth));
}

void rtype::Sprite::setRectHeigth(int rectHeigth)
{
    _rectHeigth = rectHeigth;
    _sprite.setTextureRect(sf::IntRect(_rectX, _rectY, _rectWidth, _rectHeigth));
}

void rtype::Sprite::setColorAlpha(int colorAlpha)
{
    _colorAlpha = colorAlpha;
    _sprite.setColor(sf::Color(255, 255, 255, colorAlpha));
}

sf::Sprite &rtype::Sprite::getSprite()
{
    return _sprite;
}

void rtype::Sprite::drawSprite(sf::RenderWindow *win)
{
    win->draw(_sprite);
}


rtype::Text::Text(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath)
    : _posX(posX), _posY(posY), _fontSize(fontSize), _colorRed(colorRed), _colorGreen(colorGreen), _colorBlue(colorBlue), _colorAlpha(colorAlpha), _content(content), _fontPath(fontPath)
{
    _text.setPosition(sf::Vector2f(_posX, _posY));
    _text.setFillColor(sf::Color(_colorRed, _colorGreen, _colorBlue, _colorAlpha));
    _text.setCharacterSize(_fontSize);
    _text.setString(_content);
    if (!_font.loadFromFile(_fontPath))
        throw std::runtime_error("Fail to load font");
    _text.setFont(_font);
}

float rtype::Text::getPosX()
{
    return _posX;
}

float rtype::Text::getPosY()
{
    return _posY;
}

int rtype::Text::getFontSize()
{
    return _fontSize;
}

int rtype::Text::getColorRed()
{
    return _colorRed;
}

int rtype::Text::getColorGreen()
{
    return _colorGreen;
}

int rtype::Text::getColorBlue()
{
    return _colorBlue;
}

int rtype::Text::getColorAlpha()
{
    return _colorAlpha;
}

std::string rtype::Text::getContent()
{
    return _content;
}

void rtype::Text::setPosX(float posX)
{
    _posX = posX;
    _text.setPosition(sf::Vector2f(_posX, _posY));
}

void rtype::Text::setPosY(float posY)
{
    _posY = posY;
    _text.setPosition(sf::Vector2f(_posX, _posY));
}

void rtype::Text::setFontSize(int fontSize)
{
    _fontSize = fontSize;
    _text.setCharacterSize(_fontSize);
}

void rtype::Text::setColorRed(int colorRed)
{
    _colorRed = colorRed;
    _text.setFillColor(sf::Color(_colorRed, _colorGreen, _colorBlue, _colorAlpha));
}

void rtype::Text::setColorGreen(int colorGreen)
{
    _colorGreen = colorGreen;
    _text.setFillColor(sf::Color(_colorRed, _colorGreen, _colorBlue, _colorAlpha));
}

void rtype::Text::setColorBlue(int colorBlue)
{
    _colorBlue = colorBlue;
    _text.setFillColor(sf::Color(_colorRed, _colorGreen, _colorBlue, _colorAlpha));
}

void rtype::Text::setColorAlpha(int colorAlpha)
{
    _colorAlpha = colorAlpha;
    _text.setFillColor(sf::Color(_colorRed, _colorGreen, _colorBlue, _colorAlpha));
}

void rtype::Text::setContent(std::string &content)
{
    _content = content;
    _text.setString(_content);
}

sf::Text &rtype::Text::getText()
{
    return _text;
}

rtype::Sound::Sound(std::string path)
    : _path(path)
{
    if (!_buffer.loadFromFile(_path))
        throw std::runtime_error("Fail to load sound");
    _sound.setBuffer(_buffer);
}

sf::Sound &rtype::Sound::getSound()
{
    return _sound;
}

rtype::Music::Music(std::string path)
    : _path(path)
{
    if (!_music.openFromFile(_path))
        throw std::runtime_error("Fail to load music");
}

sf::Music &rtype::Music::getMusic()
{
    return _music;
}
