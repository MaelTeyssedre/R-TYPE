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

                const float getPosX();
                const float getPosY();
                const float getRotation();
                const float getScale();
                const int getRectX();
                const int getRectY();
                const int getRectWidth();
                const int getRectHeigth();

                void setPosX(float posX);
                void setPosY(float posY);
                void setRotation(float rotation);
                void setScale(float scale);
                void setRectX(int rectX);
                void setRectY(int rectY);
                void setRectWidth(int rectWith);
                void setRectHeigth(int rectHeigth);
            protected:
                friend class GraphicalLib;

                explicit Sprite(float posX, float posY, float rotation, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path);

                sf::Sprite &getSprite();

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

                const float getPosX();
                const float getPosY();
                const int getFontSize();
                const int getColorRed();
                const int getColorGreen();
                const int getColorBlue();
                const int getColorAlpha();
                const std::string getContent();

                void setPosX(float posX);
                void setPosY(float posY);
                void setFontSize(int fontSize);
                void setColorRed(int colorRed);
                void setColorGreen(int colorGreen);
                void setColorBlue(int colorBlue);
                void setColorAlpha(int colorAlpha);
                void setContent(std::string &content);

            protected:
                friend class GraphicalLib;

                explicit Text(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath);
                    
                sf::Text &getText();

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

                explicit Sound(std::string path);
                
                sf::Sound &getSound();

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

                explicit Music(std::string path);

                sf::Music &getMusic();
            private:
                std::string _path;

                sf::Music _music;
        };
    }

#endif /* !ELEMENT_HPP_ */
