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
                void draw(size_t id) override;
                void print(size_t id) override;
                void start(size_t id) override;
                void play(size_t id) override;
                void stop(size_t id) override;
                void pause(size_t id) override;
                void refresh() override;
                void createSound(size_t id, const std::string &path) override;
                void createMusic(size_t id, const std::string &path) override;
                void createText(size_t id, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) override;
                void createSprite(size_t id, float scaleX, float scaleY, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) override;
                
                void clearScreen();

                void deleteSound(size_t id) override;
                void deleteMusic(size_t id) override;
                void deleteText(size_t id) override;
                void deleteSprite(size_t id) override;
                bool getKeyState(rtype::constants::EVENT event) override;
                mouse_t getMouseState() override;
                void setViewXPos(float viewXPos) override;

            public:
                float getSpritePosX(size_t id) override;
                float getSpritePosY(size_t id) override;
                float getSpriteRotation(size_t id) override;
                float getSpriteScale(size_t id) override;
                int getSpriteRectX(size_t id) override;
                int getSpriteRectY(size_t id) override;
                int getSpriteRectWidth(size_t id) override;
                int getSpriteRectHeigth(size_t id) override;
                int getSpriteColorAlpha(size_t id) override;

                void setSpritePosX(size_t id, float posX) override;
                void setSpritePosY(size_t id, float posY) override;
                void setSpriteRotation(size_t id, float rotation) override;
                void setSpriteScale(size_t id, float scaleX, float scaleY) override;
                void setSpriteRectX(size_t id, int rectX) override;
                void setSpriteRectY(size_t id, int rectY) override;
                void setSpriteRectWidth(size_t id, int rectWith) override;
                void setSpriteRectHeigth(size_t id, int rectHeigth) override;
                void setSpriteColorAlpha(size_t id, int colorAlpha) override;

            public:
                float getTextPosX(size_t id) override;
                float getTextPosY(size_t id) override;
                int getTextFontSize(size_t id) override;
                int getTextColorRed(size_t id) override;
                int getTextColorGreen(size_t id) override;
                int getTextColorBlue(size_t id) override;
                int getTextColorAlpha(size_t id) override;
                std::string getTextContent(size_t id) override;

                void setTextPosX(size_t id, float posX) override;
                void setTextPosY(size_t id, float posY) override;
                void setTextFontSize(size_t id, int fontSize) override;
                void setTextColorRed(size_t id, int colorRed) override;
                void setTextColorGreen(size_t id, int colorGreen) override;
                void setTextColorBlue(size_t id, int colorBlue) override;
                void setTextColorAlpha(size_t id, int colorAlpha) override;
                void setTextContent(size_t id, std::string &content) override;
                void HandleClose();


            private:
                sf::RenderWindow *_renderWindow;
                sf::Mouse _mouse;
                sf::View _view;

                float _viewX;

                std::map<size_t, std::shared_ptr<Sprite>> _spriteMap;
                std::map<size_t, std::shared_ptr<Text>> _textMap;
                std::map<size_t, std::shared_ptr<Sound>> _soundMap;
                std::map<size_t, std::shared_ptr<Music>> _musicMap;
                
        };
    }

#endif /* !GRAPHICALLIB_HPP_ */
