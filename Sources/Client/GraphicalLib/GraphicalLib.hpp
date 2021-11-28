/**
 * \file GraphicalLib.hpp
 *
 * \brief file where the graphical lib abstraction is defined
 */

#ifndef GRAPHICALLIB_HPP_
    #define GRAPHICALLIB_HPP_

    #include "IGraphicalLib.hpp"
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include <vector>
    #include <memory>

    namespace rtype {

        class GraphicalLib : public IGraphicalLib {
            public:
                explicit GraphicalLib();
                virtual ~GraphicalLib() = default;

            public:
                void draw(size_t id) override; // for sprite
                void print(size_t id) override; // for text
                void start(size_t id) override; // for sound
                void play(size_t id) override; // for music
                void stop(size_t id) override; //for music
                void pause(size_t id) override; //for music
                void refresh() override;
                void createSound(size_t id, const std::string &path) override;
                void createMusic(size_t id, const std::string &path) override;
                void createText(size_t id, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) override;
                void createSprite(size_t id, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) override;
                
                void deleteSound(size_t id) override;
                void deleteMusic(size_t id) override;
                void deleteText(size_t id) override;
                void deleteSprite(size_t id) override;
                bool getKeyState(rtype::constants::EVENT event) override;
                mouse_t getMouseState() override;
                void setViewXPos(float viewXPos) override;

            public:
                float getSpritePosX(size_t id);
                float getSpritePosY(size_t id);
                float getSpriteRotation(size_t id);
                float getSpriteScale(size_t id);
                int getSpriteRectX(size_t id);
                int getSpriteRectY(size_t id);
                int getSpriteRectWidth(size_t id);
                int getSpriteRectHeigth(size_t id);

                void setSpritePosX(size_t id, float posX);
                void setSpritePosY(size_t id, float posY);
                void setSpriteRotation(size_t id, float rotation);
                void setSpriteScale(size_t id, float scale);
                void setSpriteRectX(size_t id, int rectX);
                void setSpriteRectY(size_t id, int rectY);
                void setSpriteRectWidth(size_t id, int rectWith);
                void setSpriteRectHeigth(size_t id, int rectHeigth);

            public:
                float getTextPosX(size_t id);
                float getTextPosY(size_t id);
                int getTextFontSize(size_t id);
                int getTextColorRed(size_t id);
                int getTextColorGreen(size_t id);
                int getTextColorBlue(size_t id);
                int getTextColorAlpha(size_t id);
                std::string getTextContent(size_t id);

                void setTextPosX(size_t id, float posX);
                void setTextPosY(size_t id, float posY);
                void setTextFontSize(size_t id, int fontSize);
                void setTextColorRed(size_t id, int colorRed);
                void setTextColorGreen(size_t id, int colorGreen);
                void setTextColorBlue(size_t id, int colorBlue);
                void setTextColorAlpha(size_t id, int colorAlpha);
                void setTextContent(size_t id, std::string &content);


            private:
                sf::RenderWindow _renderWindow;
                sf::Mouse _mouse;
                sf::View _view;

                float _viewX;

                std::map<size_t, Sprite> _spriteMap; // There is an id Jules
                std::map<size_t, Text> _textMap; // There is an id Jules
                std::map<size_t, Sound> _soundMap; // There is an id Jules
                // std::map<size_t, Music> _musicMap; // There is an id Jules
                
        };
    }

#endif /* !GRAPHICALLIB_HPP_ */
