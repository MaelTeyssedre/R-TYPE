
#include "Elements.hpp"
#include <iostream>
#include <new>
#include <stdexcept>
#include <exception>

rtype::Sprite::Sprite(float posX, float posY, float rotation, float scaleX, float scaleY, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path)
    : _posX(posX), _posY(posY), _rotation(rotation), _scaleX(scaleX), _scaleY(scaleY), _rectX(rectX), _rectY(rectY), _rectWidth(rectWidth), _rectHeigth(rectHeigth), _colorAlpha(255), _path(path), _texture(), _sprite()
{
    _sprite.setPosition(sf::Vector2f(_posX, _posY));
    _sprite.setRotation(_rotation);
    _sprite.setScale(sf::Vector2f(_scaleX, _scaleY));
    if (!_texture.loadFromFile(_path))
        throw std::runtime_error("Fail to load texture");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(_rectX, _rectY, _rectWidth, _rectHeigth));
}

auto rtype::Sprite::getPosX() -> float
{
    return _posX;
}

auto rtype::Sprite::getPosY() -> float
{
    return _posY;
}

auto rtype::Sprite::getRotation() -> float
{
    return _rotation;
}

auto rtype::Sprite::getScale() -> float
{
    return _scaleX;
}

auto rtype::Sprite::getRectX() -> int
{
    return _rectX;
}

auto rtype::Sprite::getRectY() -> int
{
    return _rectY;
}

auto rtype::Sprite::getRectWidth() -> int
{
    return _rectWidth;
}

auto rtype::Sprite::getRectHeigth() -> int
{
    return _rectHeigth;
}

auto rtype::Sprite::getColorAlpha() -> int
{
    return _colorAlpha;
}

auto rtype::Sprite::setPosX(float posX) -> void
{
    _posX = posX;
    _sprite.setPosition(sf::Vector2f(_posX, _posY));
}

auto rtype::Sprite::setPosY(float posY) -> void
{
    _posY = posY;
    _sprite.setPosition(sf::Vector2f(_posX, _posY));
}

auto rtype::Sprite::setRotation(float rotation) -> void
{
    _rotation = rotation;
    _sprite.setRotation(_rotation);
}

auto rtype::Sprite::setScaleX(float scaleX) -> void
{
    _scaleX = scaleX;
    _sprite.setScale(sf::Vector2f(_scaleX, _scaleY));
}

auto rtype::Sprite::setScaleY(float scaleY) -> void
{
    _scaleY = scaleY;
    _sprite.setScale(sf::Vector2f(_scaleX, _scaleY));
}

auto rtype::Sprite::setRectX(int rectX) -> void
{
    _rectX = rectX;
    _sprite.setTextureRect(sf::IntRect(_rectX, _rectY, _rectWidth, _rectHeigth));
}

auto rtype::Sprite::setRectY(int rectY) -> void
{
    _rectY = rectY;
    _sprite.setTextureRect(sf::IntRect(_rectX, _rectY, _rectWidth, _rectHeigth));
}

auto rtype::Sprite::setRectWidth(int rectWith) -> void
{
    _rectWidth = rectWith;
    _sprite.setTextureRect(sf::IntRect(_rectX, _rectY, _rectWidth, _rectHeigth));
}

auto rtype::Sprite::setRectHeigth(int rectHeigth) -> void
{
    _rectHeigth = rectHeigth;
    _sprite.setTextureRect(sf::IntRect(_rectX, _rectY, _rectWidth, _rectHeigth));
}

auto rtype::Sprite::setColorAlpha(int colorAlpha) -> void
{
    _colorAlpha = colorAlpha;
    _sprite.setColor(sf::Color(255, 255, 255, (uint8_t)colorAlpha));
}

auto rtype::Sprite::getSprite() -> sf::Sprite &
{
    return _sprite;
}

auto rtype::Sprite::drawSprite(sf::RenderWindow *win) -> void
{
    win->draw(_sprite);
}


rtype::Text::Text(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath)
    : _posX(posX), _posY(posY), _fontSize(fontSize), _colorRed(colorRed), _colorGreen(colorGreen), _colorBlue(colorBlue), _colorAlpha(colorAlpha), _content(content), _fontPath(fontPath)
{
    if (!_font.loadFromFile(_fontPath))
        throw std::runtime_error("Fail to load font");
    _text.setFont(_font);
    _text.setString(_content);
    _text.setPosition(sf::Vector2f(_posX, _posY));
    _text.setFillColor(sf::Color((uint8_t)_colorRed, (uint8_t)_colorGreen, (uint8_t)_colorBlue, (uint8_t)_colorAlpha));
    _text.setCharacterSize(_fontSize);
}

auto rtype::Text::getPosX() -> float
{
    return _posX;
}

auto rtype::Text::getPosY() -> float
{
    return _posY;
}

auto rtype::Text::getFontSize() -> int
{
    return _fontSize;
}

auto rtype::Text::getColorRed() -> int
{
    return _colorRed;
}

auto rtype::Text::getColorGreen() -> int
{
    return _colorGreen;
}

auto rtype::Text::getColorBlue() -> int
{
    return _colorBlue;
}

auto rtype::Text::getColorAlpha() -> int
{
    return _colorAlpha;
}

auto rtype::Text::getContent() -> std::string
{
    return _content;
}

auto rtype::Text::setPosX(float posX) -> void
{
    _posX = posX;
    _text.setPosition(sf::Vector2f(_posX, _posY));
}

auto rtype::Text::setPosY(float posY) -> void
{
    _posY = posY;
    _text.setPosition(sf::Vector2f(_posX, _posY));
}

auto rtype::Text::setFontSize(int fontSize) -> void
{
    _fontSize = fontSize;
    _text.setCharacterSize(_fontSize);
}

auto rtype::Text::setColorRed(int colorRed) -> void
{
    _colorRed = colorRed;
    _text.setFillColor(sf::Color((uint8_t)_colorRed, (uint8_t)_colorGreen, (uint8_t)_colorBlue, (uint8_t)_colorAlpha));
}

auto rtype::Text::setColorGreen(int colorGreen) -> void
{
    _colorGreen = colorGreen;
    _text.setFillColor(sf::Color((uint8_t)_colorRed, (uint8_t)_colorGreen, (uint8_t)_colorBlue, (uint8_t)_colorAlpha));
}

auto rtype::Text::setColorBlue(int colorBlue) -> void
{
    _colorBlue = colorBlue;
    _text.setFillColor(sf::Color((uint8_t)_colorRed, (uint8_t)_colorGreen, (uint8_t)_colorBlue, (uint8_t)_colorAlpha));
}

auto rtype::Text::setColorAlpha(int colorAlpha) -> void
{
    _colorAlpha = colorAlpha;
    _text.setFillColor(sf::Color((uint8_t)_colorRed, (uint8_t)_colorGreen, (uint8_t)_colorBlue, (uint8_t)_colorAlpha));
}

auto rtype::Text::setContent(std::string &content) -> void
{
    _content = content;
    _text.setString(_content);
}

auto rtype::Text::getText() -> sf::Text *
{
    return &_text;
}

rtype::Sound::Sound(std::string path)
    : _path(path)
{
    if (!_buffer.loadFromFile(_path))
        throw std::runtime_error("Fail to load sound");
    _sound.setBuffer(_buffer);
}

auto rtype::Sound::getSound() -> sf::Sound &
{
    return _sound;
}

rtype::Music::Music(std::string path)
    : _path(path)
{
    if (!_music.openFromFile(_path))
        throw std::runtime_error("Fail to load music");
    _music.setVolume(0.f);
}

auto rtype::Music::getMusic() -> sf::Music &
{
    return _music;
}
