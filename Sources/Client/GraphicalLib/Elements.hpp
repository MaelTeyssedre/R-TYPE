/**
 * \file Elements.hpp
 *
 * \brief file where the graphical lib interface is defined
 */

#ifndef ELEMENT_HPP_
    #define ELEMENT_HPP_

    #include <iostream>
    #include <new>
    #include <stdexcept>
    #include <exception>
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
                explicit Sprite() = default;
                explicit Sprite(float posX, float posY, float rotation, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path);
                virtual ~Sprite() = default;

                float getPosX();
                float getPosY();
                float getRotation();
                float getScale();
                int getRectX();
                int getRectY();
                int getRectWidth();
                int getRectHeigth();
                sf::Sprite &getSprite();
                void setPosX(float posX);
                void setPosY(float posY);
                void setRotation(float rotation);
                void setScale(float scale);
                void setRectX(int rectX);
                void setRectY(int rectY);
                void setRectWidth(int rectWith);
                void setRectHeigth(int rectHeigth);
            // protected:
            //     friend class GraphicalLib;

                

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
                explicit Text() = default;
                explicit Text(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath);
                virtual ~Text() = default;

                float getPosX();
                float getPosY();
                int getFontSize();
                int getColorRed();
                int getColorGreen();
                int getColorBlue();
                int getColorAlpha();
                std::string getContent();
                sf::Text &getText();
                void setPosX(float posX);
                void setPosY(float posY);
                void setFontSize(int fontSize);
                void setColorRed(int colorRed);
                void setColorGreen(int colorGreen);
                void setColorBlue(int colorBlue);
                void setColorAlpha(int colorAlpha);
                void setContent(std::string &content);

            // protected:
            //     friend class GraphicalLib;

                

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
                explicit Sound() = default;
                virtual ~Sound() = default;

            // protected:
            //     friend class GraphicalLib;

                explicit Sound(std::string path);
                
                sf::Sound &getSound();

            private:
                std::string _path;

                sf::Sound _sound;
                sf::SoundBuffer _buffer;
        };

        class Music {
            public:
                explicit Music() = default;
                virtual ~Music() = default;

            // protected:
            //     friend class GraphicalLib;

                explicit Music(std::string path);

                sf::Music &getMusic();
            private:
                std::string _path;

                sf::Music _music;
        };
    }

#endif /* !ELEMENT_HPP_ */
