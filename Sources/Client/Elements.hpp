/**
 * \file Elements.hpp
 *
 * \brief file where the graphical lib interface is defined
 */

#ifndef ELEMENT_HPP_
    #define ELEMENT_HPP_

    #include <iostream>
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>

    namespace rtype {

        class GraphicalLib;

        /**
         * \class Sprite IGraphicalLib.hpp
         *
         * \brief Class that define sprite
         */
        class Sprite {
            public:
                virtual ~Sprite() = default;

                const float getPosX() {return _posX;};
                const float getPosY() {return _posY;};
                const float getRotation() {return _rotation;};
                const float getScale() {return _scale;};
                const int getRectX() {return _rectX;};
                const int getRectY() {return _rectY;};
                const int getRectWidth() {return _rectWidth;};
                const int getRectHeigth() {return _rectHeigth;};

                void setPosX(float posX) {_posX = posX; _sprite.setPosition(sf::Vector2f(_posX, _posY));};
                void setPosY(float posY) {_posY = posY; _sprite.setPosition(sf::Vector2f(_posX, _posY));};
                void setRotation(float rotation) {_rotation = rotation; _sprite.setRotation(_rotation);};
                void setScale(float scale) {_scale = scale; _sprite.setRotation(scale);};
                void setRectX(int rectX) {_rectX = rectX; _sprite.setTextureRect(sf::IntRect(_rectX, _rectY, _rectWidth, _rectHeigth));};
                void setRectY(int rectY) {_rectY = rectY; _sprite.setTextureRect(sf::IntRect(_rectX, _rectY, _rectWidth, _rectHeigth));};
                void setRectWidth(int rectWith) {_rectWidth = rectWith; _sprite.setTextureRect(sf::IntRect(_rectX, _rectY, _rectWidth, _rectHeigth));};
                void setRectHeigth(int rectHeigth) {_rectHeigth = rectHeigth; _sprite.setTextureRect(sf::IntRect(_rectX, _rectY, _rectWidth, _rectHeigth));};
            protected:
                friend class GraphicalLib;

                explicit Sprite(float posX, float posY, float rotation, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path)
                    : _posX(posX), _posY(posY), _rotation(rotation), _scale(scale), _rectX(rectX), _rectY(rectY), _rectWidth(rectWidth), _rectHeigth(rectHeigth), _path(path) {
                        _sprite.setPosition(sf::Vector2f(_posX, _posY));
                        _sprite.setRotation(_rotation);
                        _sprite.setScale(sf::Vector2f(_scale, _scale));
                        _texture.loadFromFile(_path);
                        _sprite.setTexture(_texture);
                        _sprite.setTextureRect(sf::IntRect(_rectX, _rectY, _rectWidth, _rectHeigth));
                    };

                sf::Sprite &getSprite() {return _sprite;};

            private:
                float _posX;
                float _posY;
                float _rotation;
                float _scale;

                int _rectX;
                int _rectY;
                int _rectWidth;
                int _rectHeigth;
                
                std::string _path;

                sf::Texture _texture;
                sf::Sprite _sprite;
        };

        class Text {
            public:
                virtual ~Text() = default;

                const float getPosX() {return _posX;};
                const float getPosY() {return _posY;};
                const int getFontSize() {return _fontSize;};
                const int getColorRed() {return _colorRed;};
                const int getColorGreen() {return _colorGreen;};
                const int getColorBlue() {return _colorBlue;};
                const int getColorAlpha() {return _colorAlpha;};
                const std::string getContent() {return _content;};

                void setPosX(float posX) {_posX = posX; _text.setPosition(sf::Vector2f(_posX, _posY));};
                void setPosY(float posY) {_posY = posY; _text.setPosition(sf::Vector2f(_posX, _posY));};
                void setFontSize(int fontSize) {_fontSize = fontSize; _text.setCharacterSize(_fontSize);};
                void setColorRed(int colorRed) {_colorRed = colorRed; _text.setFillColor(sf::Color(_colorRed, _colorGreen, _colorBlue, _colorAlpha));};
                void setColorGreen(int colorGreen) {_colorGreen = colorGreen; _text.setFillColor(sf::Color(_colorRed, _colorGreen, _colorBlue, _colorAlpha));};
                void setColorBlue(int colorBlue) {_colorBlue = colorBlue; _text.setFillColor(sf::Color(_colorRed, _colorGreen, _colorBlue, _colorAlpha));};
                void setColorAlpha(int colorAlpha) {_colorAlpha = colorAlpha; _text.setFillColor(sf::Color(_colorRed, _colorGreen, _colorBlue, _colorAlpha));};
                void setContent(std::string &content) {;};

            protected:
                friend class GraphicalLib;

                explicit Text(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath)
                    : _posX(posX), _posY(posY), _fontSize(fontSize), _colorRed(colorRed), _colorGreen(colorGreen), _colorBlue(colorBlue), _colorAlpha(colorAlpha), _content(content), _fontPath(_fontPath) {
                        _text.setPosition(sf::Vector2f(_posX, _posY));
                        _text.setFillColor(sf::Color(_colorRed, _colorGreen, _colorBlue, _colorAlpha));
                        _text.setCharacterSize(_fontSize);
                        _text.setString(_content);
                        _font.loadFromFile(_fontPath);
                        _text.setFont(_font);
                    };

                sf::Text &getText() {return _text;};

            private:
                float _posX;
                float _posY;
                int _fontSize;

                int _colorRed;
                int _colorGreen;
                int _colorBlue;
                int _colorAlpha;

                std::string _content;
                std::string _fontPath;

                sf::Font _font;
                sf::Text _text;
        };

        class Sound {
            public:
                virtual ~Sound() = default;

            protected:
                friend class GraphicalLib;

                explicit Sound(std::string path)
                    : _path(path) {
                        _buffer.loadFromFile(_path);
                        _sound.setBuffer(_buffer);
                    };
                
                sf::Sound &getSound() {return _sound;};

            private:
                std::string _path;

                sf::Sound _sound;
                sf::SoundBuffer _buffer;
        };

        class Music {
            public:
                virtual ~Music() = default;

            protected:
                friend class GraphicalLib;

                explicit Music(std::string path)
                    : _path(path) {
                        _music.openFromFile(_path);
                    };

                sf::Music &getMusic() {return _music;};
            private:
                std::string _path;

                sf::Music _music;
        };
    }

#endif /* !ELEMENT_HPP_ */
