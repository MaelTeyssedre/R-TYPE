/**
 * \file IGraphicalLib.hpp
 *
 * \brief file where the graphical lib interface is defined
 */

#ifndef IGRAPHICALLIB_HPP_
    #define IGRAPHICALLIB_HPP_

    #include "Elements.hpp"
    #include <iostream>
    #include <SFML/Window.hpp>
    #include "Constants.hpp"
    #include <memory>

    namespace rtype {

        typedef struct mouse_s
        {
            int posX;
            int posY;
            bool leftPressed;
            bool rightPressed;
        } mouse_t;

        class IGraphicalLib {
            public:
                virtual ~IGraphicalLib() = default;

                
            public:
                virtual void draw(size_t id) = 0; // for sprite
                virtual void print(size_t id) = 0; // for text
                virtual void start(size_t id) = 0; // for sound
                virtual void play(size_t id) = 0; // for music
                virtual void stop(size_t id) = 0; //for music
                virtual void pause(size_t id) = 0; //for music
                virtual void refresh() = 0;
                virtual void createSound(size_t id, const std::string &path) = 0;
                virtual void createMusic(size_t id, const std::string &path) = 0;
                virtual void createText(size_t id, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) = 0;
                virtual void createSprite(size_t id, float scalex, float scaley, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) = 0;
                
                virtual void deleteSound(size_t id) = 0;
                virtual void deleteMusic(size_t id) = 0;
                virtual void deleteText(size_t id) = 0;
                virtual void deleteSprite(size_t id) = 0;
                virtual bool getKeyState(rtype::constants::EVENT event) = 0;
                virtual mouse_t getMouseState() = 0;

            public:
                virtual float getSpritePosX(size_t id) = 0;
                virtual float getSpritePosY(size_t id) = 0;
                virtual float getSpriteRotation(size_t id) = 0;
                virtual float getSpriteScale(size_t id) = 0;
                virtual int getSpriteRectX(size_t id) = 0;
                virtual int getSpriteRectY(size_t id) = 0;
                virtual int getSpriteRectWidth(size_t id) = 0;
                virtual int getSpriteRectHeigth(size_t id) = 0;
                virtual int getSpriteColorAlpha(size_t id) = 0;

                virtual void setSpritePosX(size_t id, float posX) = 0;
                virtual void setSpritePosY(size_t id, float posY) = 0;
                virtual void setSpriteRotation(size_t id, float rotation) = 0;
                virtual void setSpriteScale(size_t id, float scaleX, float scaleY) = 0;
                virtual void setSpriteRectX(size_t id, int rectX) = 0;
                virtual void setSpriteRectY(size_t id, int rectY) = 0;
                virtual void setSpriteRectWidth(size_t id, int rectWith) = 0;
                virtual void setSpriteRectHeigth(size_t id, int rectHeigth) = 0;
                virtual void setSpriteColorAlpha(size_t id, int colorAlpha) = 0;


            public:
                virtual float getTextPosX(size_t id) = 0;
                virtual float getTextPosY(size_t id) = 0;
                virtual int getTextFontSize(size_t id) = 0;
                virtual int getTextColorRed(size_t id) = 0;
                virtual int getTextColorGreen(size_t id) = 0;
                virtual int getTextColorBlue(size_t id) = 0;
                virtual int getTextColorAlpha(size_t id) = 0;
                virtual std::string getTextContent(size_t id) = 0;

                virtual void setTextPosX(size_t id, float posX) = 0;
                virtual void setTextPosY(size_t id, float posY) = 0;
                virtual void setTextFontSize(size_t id, int fontSize) = 0;
                virtual void setTextColorRed(size_t id, int colorRed) = 0;
                virtual void setTextColorGreen(size_t id, int colorGreen) = 0;
                virtual void setTextColorBlue(size_t id, int colorBlue) = 0;
                virtual void setTextColorAlpha(size_t id, int colorAlpha) = 0;
                virtual void setTextContent(size_t id, std::string &content) = 0;
        };
    }

#endif /* !IGRAPHICALLIB_HPP_ */
