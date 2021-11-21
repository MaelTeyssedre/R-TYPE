
#include "Elements.hpp"

rtype::Sprite::Sprite(float posX, float posY, float rotation, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path)
    : _posX(posX), _posY(posY), _rotation(rotation), _scale(scale), _rectX(rectX), _rectY(rectY), _rectWidth(rectWidth), _rectHeigth(rectHeigth), _path(path)
{
    _sprite.setPosition(sf::Vector2f(_posX, _posY));
    _sprite.setRotation(_rotation);
    _sprite.setScale(sf::Vector2f(_scale, _scale));
    _texture.loadFromFile(_path);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(_rectX, _rectY, _rectWidth, _rectHeigth));
}

const float rtype::Sprite::getPosX()
{
    return _posX;
}

const float rtype::Sprite::getPosY()
{
    return _posY;
}

const float rtype::Sprite::getRotation()
{
    return _rotation;
}

const float rtype::Sprite::getScale()
{
    return _scale;
}

const int rtype::Sprite::getRectX()
{
    return _rectX;
}

const int rtype::Sprite::getRectY()
{
    return _rectY;
}

const int rtype::Sprite::getRectWidth()
{
    return _rectWidth;
}

const int rtype::Sprite::getRectHeigth()
{
    return _rectHeigth;
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

void rtype::Sprite::setScale(float scale)
{
    _scale = scale;
    _sprite.setRotation(scale);
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

sf::Sprite &rtype::Sprite::getSprite()
{
    return _sprite;
}

rtype::Text::Text(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath)
    : _posX(posX), _posY(posY), _fontSize(fontSize), _colorRed(colorRed), _colorGreen(colorGreen), _colorBlue(colorBlue), _colorAlpha(colorAlpha), _content(content), _fontPath(_fontPath)
{
    _text.setPosition(sf::Vector2f(_posX, _posY));
    _text.setFillColor(sf::Color(_colorRed, _colorGreen, _colorBlue, _colorAlpha));
    _text.setCharacterSize(_fontSize);
    _text.setString(_content);
    _font.loadFromFile(_fontPath);
    _text.setFont(_font);
}

const float rtype::Text::getPosX()
{
    return _posX;
}

const float rtype::Text::getPosY()
{
    return _posY;
}

const int rtype::Text::getFontSize()
{
    return _fontSize;
}

const int rtype::Text::getColorRed()
{
    return _colorRed;
}

const int rtype::Text::getColorGreen()
{
    return _colorGreen;
}

const int rtype::Text::getColorBlue()
{
    return _colorBlue;
}

const int rtype::Text::getColorAlpha()
{
    return _colorAlpha;
}

const std::string rtype::Text::getContent()
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
    _buffer.loadFromFile(_path);
    _sound.setBuffer(_buffer);
}

sf::Sound &rtype::Sound::getSound()
{
    return _sound;
}

rtype::Music::Music(std::string path)
    : _path(path)
{
    _music.openFromFile(_path);
}

sf::Music &rtype::Music::getMusic()
{
    return _music;
}
