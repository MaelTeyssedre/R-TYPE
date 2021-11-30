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

    /**
     * \namespace rtype
     * 
     * \brief namespace for the R-Type
     * 
     */
    namespace rtype {

        /**
         * \struct mouse_s
         * 
         * \brief mouse component
         *
         */
        typedef struct mouse_s
        {
            int posX; /*! the x position of the mouse */
            int posY; /*! the y position of the mouse */
            bool leftPressed; /*! check if there is a left click on the mouse */
            bool rightPressed; /*! check if there is a rigth click on the mouse */
        } mouse_t;

        /**
         * \class IGraphicalLib IGraphicalLib.hpp
         *
         * \brief Interface of the class that encapsulate the sfml lib
         */
        class IGraphicalLib {
            public:
                /**
                 * \fn virtual ~IGraphicalLib() = default
                 * 
                 * \brief IGraphicalLib dtor
                 */
                virtual ~IGraphicalLib() = default;

                
            public:
                /**
                 * \fn virtual void draw(size_t id) = 0
                 * 
                 * \brief draw the sprite
                 *
                 * \param id id of the sprite to draw
                 */
                virtual void draw(size_t id) = 0;

                /**
                 * \fn virtual void print(size_t id) = 0
                 * 
                 * \brief print the text
                 *
                 * \param id id of the text to print
                 */
                virtual void print(size_t id) = 0;

                /**
                 * \fn virtual void start(size_t id) = 0
                 * 
                 * \brief start a sound
                 *
                 * \param id id of the sound to start
                 */
                virtual void start(size_t id) = 0;

                /**
                 * \fn virtual void play(size_t id) = 0
                 * 
                 * \brief play a music
                 *
                 * \param id id of the music to play
                 */
                virtual void play(size_t id) = 0;

                /**
                 * \fn virtual void stop(size_t id) = 0
                 * 
                 * \brief stop a music
                 *
                 * \param id id of the music to stop
                 */
                virtual void stop(size_t id) = 0;

                /**
                 * \fn virtual void pause(size_t id) = 0
                 * 
                 * \brief pause a music
                 *
                 * \param id id of the music to pause
                 */
                virtual void pause(size_t id) = 0;

                /**
                 * \fn virtual void refresh() = 0
                 * 
                 * \brief refresh 
                 */
                virtual void refresh() = 0;

                /**
                 * \fn virtual void createSound(size_t id, const std::string &path) = 0
                 * 
                 * \brief create a sound
                 *
                 * \param id id of the sound to create
                 * 
                 * \param path reference to the sound source path
                 */
                virtual void createSound(size_t id, const std::string &path) = 0;

                /**
                 * \fn virtual void createMusic(size_t id, const std::string &path) = 0
                 * 
                 * \brief create a music
                 *
                 * \param id id of the music to create
                 * 
                 * \param path reference to the music source path
                 */
                virtual void createMusic(size_t id, const std::string &path) = 0;

                /**
                 * \fn virtual void createText(size_t id, float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) = 0
                 * 
                 * \brief create a text with given arguments
                 *
                 * \param id the id of the text we want to create
                 * 
                 * \param posX the x position of the text we want to create
                 * 
                 * \param posY the y position of the text we want to create
                 * 
                 * \param fontSize the font size of the text we want to create
                 * 
                 * \param colorRed the red proportion of the text we want to create
                 * 
                 * \param colorGreen the Green proportion of the text we want to create
                 * 
                 * \param colorBlue the Blue proportion of the text we want to create
                 * 
                 * \param colorAlpha the transparency of the text we want to create
                 * 
                 * \param content the content of the text rectangle we want to create
                 * 
                 * \param fontPath Path of the font source
                 */
                virtual void createText(size_t id, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) = 0;
                
                /**
                 * \fn virtual createSprite(size_t id, float posX, float posY, float rotation, float scaleX, float scaleY, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) = 0
                 * 
                 * \brief create a sprite with the given arguments
                 * 
                 * \param id the id of the sprite we want to create
                 *
                 * \param posX the x position of the sprite we want to create
                 * 
                 * \param posY the y position of the sprite we want to create
                 * 
                 * \param rotation the rotation of the sprite we want to create
                 * 
                 * \param scaleX the scale of the width of the sprite we want to create
                 * 
                 * \param scaleY the scale of the heigth of the sprite we want to create
                 * 
                 * \param rectX the x position of the sprite rectangle we want to create
                 * 
                 * \param rectY the y position of the sprite rectangle we want to create
                 * 
                 * \param rectWidth the width of the sprite rectangle we want to create
                 * 
                 * \param rectHeigth the heigth of the sprite rectangle we want to create
                 * 
                 * \param path Path of the sprite source
                 */
                virtual void createSprite(size_t id, float scalex, float scaley, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) = 0;
                
                /**
                 * \fn virtual void deleteSound(size_t id) = 0
                 * 
                 * \brief delete a sound
                 *
                 * \param id id of the sound to delete
                 */
                virtual void deleteSound(size_t id) = 0;

                /**
                 * \fn virtual void deleteMusic(size_t id) = 0
                 * 
                 * \brief delete a music
                 *
                 * \param id id of the music to delete
                 */
                virtual void deleteMusic(size_t id) = 0;

                /**
                 * \fn virtual void deleteText(size_t id) = 0
                 * 
                 * \brief delete a Text
                 *
                 * \param id id of the Text to delete
                 */
                virtual void deleteText(size_t id) = 0;

                /**
                 * \fn virtual void deleteSprite(size_t id) = 0
                 * 
                 * \brief delete a sprite
                 *
                 * \param id id of the sprite to delete
                 */
                virtual void deleteSprite(size_t id) = 0;

                /**
                 * \fn virtual bool getKeyState(rtype::constants::EVENT event) = 0
                 * 
                 * \brief get the key state
                 *
                 * \param event key event that is getted
                 * 
                 * \return the key state
                 */
                virtual bool getKeyState(rtype::constants::EVENT event) = 0;

                /**
                 * \fn virtual mouse_t getMouseState() = 0
                 * 
                 * \brief get the mouse state
                 *
                 * \return a mouse state component
                 */
                virtual mouse_t getMouseState() = 0;

                /**
                 * \fn virtual void setViewXPos(float viewXPos) = 0
                 * 
                 * \brief set the X position of the view
                 *
                 * \param viewXPos X position of the view we want to set
                 */
                virtual void setViewXPos(float viewXPos) = 0;

            public:
                /**
                 * \fn virtual float getSpritePosX(size_t id) = 0
                 * 
                 * \brief get the position x of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the x position of the sprite asked
                 */
                virtual float getSpritePosX(size_t id) = 0;

                /**
                 * \fn virtual float getSpritePosY(size_t id) = 0
                 * 
                 * \brief get the position y of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the y position of the sprite asked
                 */
                virtual float getSpritePosY(size_t id) = 0;

                /**
                 * \fn virtual float getSpriteRotation(size_t id) = 0
                 * 
                 * \brief get the rotation of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the rotation of the asked sprite
                 */
                virtual float getSpriteRotation(size_t id) = 0;

                /**
                 * \fn virtual float getSpriteScale(size_t id) = 0
                 * 
                 * \brief get the Scale of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the Scale of the asked sprite
                 */
                virtual float getSpriteScale(size_t id) = 0;

                /**
                 * \fn virtual int getSpriteRectX(size_t id) = 0
                 * 
                 * \brief get the x position of a sprite rectangle
                 *
                 * \param id id of the sprite
                 * 
                 * \return the x position of the asked sprite rectangle
                 */
                virtual int getSpriteRectX(size_t id) = 0;

                /**
                 * \fn virtual int getSpriteRectY(size_t id) = 0
                 * 
                 * \brief get the y position of a sprite rectangle
                 *
                 * \param id id of the sprite
                 * 
                 * \return the y position of the asked sprite rectangle
                 */
                virtual int getSpriteRectY(size_t id) = 0;

                /**
                 * \fn virtual int getSpriteRectWidth(size_t id) = 0
                 * 
                 * \brief get the width of a sprite rectangle
                 *
                 * \param id id of the sprite
                 * 
                 * \return the width of the asked sprite rectangle
                 */
                virtual int getSpriteRectWidth(size_t id) = 0;

                /**
                 * \fn virtual int getSpriteRectHeigth(size_t id) = 0
                 * 
                 * \brief get the heigth of a sprite rectangle
                 *
                 * \param id id of the sprite
                 * 
                 * \return the heigth of the asked sprite rectangle
                 */
                virtual int getSpriteRectHeigth(size_t id) = 0;

                /**
                 * \fn virtual int getSpriteColorAlpha(size_t id) = 0;
                 * 
                 * \brief get the transparency of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the transparency of the asked sprite
                 */
                virtual int getSpriteColorAlpha(size_t id) = 0;

               /**
                 * \fn virtual void setSpritePosX(size_t id, float posX) = 0
                 * 
                 * \brief set the x position of a sprite
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param posX x position to set
                 */
                virtual void setSpritePosX(size_t id, float posX) = 0;

                /**
                 * \fn virtual void setSpritePosY(size_t id, float posY) = 0
                 * 
                 * \brief set the y position of a sprite
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param posY y position to set
                 */
                virtual void setSpritePosY(size_t id, float posY) = 0;

                /**
                 * \fn virtual void setSpriteRotation(size_t id, float rotation) = 0
                 * 
                 * \brief set the rotation of a sprite
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rotation rotation to set
                 */
                virtual void setSpriteRotation(size_t id, float rotation) = 0;

                /**
                 * \fn virtual void setSpriteScale(size_t id, float scaleX, float scaleY) = 0
                 * 
                 * \brief set the scale of a sprite
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param scale scale to set
                 */
                virtual void setSpriteScale(size_t id, float scaleX, float scaleY) = 0;

                /**
                 * \fn virtual void setSpriteRectX(size_t id, int rectX) = 0
                 * 
                 * \brief set the x position of a sprite rectangle
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rectX x position of the sprite rectangle to set
                 */
                virtual void setSpriteRectX(size_t id, int rectX) = 0;

                /**
                 * \fn virtual void setSpriteRectY(size_t id, int rectY) = 0
                 * 
                 * \brief set the y position of a sprite rectangle
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rectY y position of the sprite rectangle to set
                 */
                virtual void setSpriteRectY(size_t id, int rectY) = 0;

                /**
                 * \fn virtual void setSpriteRectWidth(size_t id, int rectWith) = 0
                 * 
                 * \brief set the width of a sprite rectangle
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rectWidth width of the sprite rectangle to set
                 */
                virtual void setSpriteRectWidth(size_t id, int rectWith) = 0;

                /**
                 * \fn virtual void setSpriteRectHeigth(size_t id, int rectHeigth) = 0
                 * 
                 * \brief set the Heigth of a sprite rectangle
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rectHeigth Heigth of the sprite rectangle to set
                 */
                virtual void setSpriteRectHeigth(size_t id, int rectHeigth) = 0;

                /**
                 * \fn virtual void setSpriteColorAlpha(size_t id, int colorAlpha) = 0
                 * 
                 * \brief set the transparency of a sprite 
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param colorAlpha transparency of the to set
                 */
                virtual void setSpriteColorAlpha(size_t id, int colorAlpha) = 0;

            public:
                /**
                 * \fn virtual float getTextPosX(size_t id) = 0
                 * 
                 * \brief get the position x of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the x position of the text asked
                 */
                virtual float getTextPosX(size_t id) = 0;

                /**
                 * \fn virtual float getTextPosY(size_t id) = 0
                 * 
                 * \brief get the position y of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the y position of the text asked
                 */
                virtual float getTextPosY(size_t id) = 0;

                /**
                 * \fn virtual int getTextFontSize(size_t id) = 0
                 * 
                 * \brief get the font size of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the font size of the text asked
                 */
                virtual int getTextFontSize(size_t id) = 0;

                /**
                 * \fn virtual int getTextColorRed(size_t id) = 0
                 * 
                 * \brief get the red proportion of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the red proportion of the text asked
                 */
                virtual int getTextColorRed(size_t id) = 0;

                /**
                 * \fn virtual int getTextColorGreen(size_t id) = 0
                 * 
                 * \brief get the green proportion of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the green proportion of the text asked
                 */
                virtual int getTextColorGreen(size_t id) = 0;

                /**
                 * \fn virtual int getTextColorBlue(size_t id) = 0
                 * 
                 * \brief get the blue proportion of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the blue proportion of the text asked
                 */
                virtual int getTextColorBlue(size_t id) = 0;

                /**
                 * \fn virtual int getTextColorAlpha(size_t id) = 0
                 * 
                 * \brief get the transparency of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the transparency of the text asked
                 */
                virtual int getTextColorAlpha(size_t id) = 0;

                /**
                 * \fn virtual std::string getTextContent(size_t id) = 0
                 * 
                 * \brief get the content of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the content of the text asked
                 */
                virtual std::string getTextContent(size_t id) = 0;

                /**
                 * \fn virtual void setTextPosX(size_t id, float posX) = 0
                 * 
                 * \brief set the x position of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param posX x position to set
                 */
                virtual void setTextPosX(size_t id, float posX) = 0;

                /**
                 * \fn virtual void setTextPosY(size_t id, float posY) = 0
                 * 
                 * \brief set the y position of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param posY y position to set
                 */
                virtual void setTextPosY(size_t id, float posY) = 0;

                /**
                 * \fn virtual void setTextFontSize(size_t id, int fontSize) = 0
                 * 
                 * \brief set the font size of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param fontSize font size to set
                 */
                virtual void setTextFontSize(size_t id, int fontSize) = 0;

                /**
                 * \fn virtual void setTextColorRed(size_t id, int colorRed) = 0
                 * 
                 * \brief set red proportion of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param colorRed red proportion to set
                 */
                virtual void setTextColorRed(size_t id, int colorRed) = 0;

                /**
                 * \fn virtual void setTextColorGreen(size_t id, int colorGreen) = 0
                 * 
                 * \brief set Green proportion of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param colorGreen Green proportion to set
                 */
                virtual void setTextColorGreen(size_t id, int colorGreen) = 0;

                /**
                 * \fn virtual void setTextColorBlue(size_t id, int colorBlue) = 0
                 * 
                 * \brief set Blue proportion of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param colorBlue Blue proportion to set
                 */
                virtual void setTextColorBlue(size_t id, int colorBlue) = 0;

                /**
                 * \fn virtual void setTextColorAlpha(size_t id, int colorAlpha) = 0
                 * 
                 * \brief set the transparency of the Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param colorAlpha the transparency to set
                 */
                virtual void setTextColorAlpha(size_t id, int colorAlpha) = 0;

                /**
                 * \fn virtual void setTextContent(size_t id, std::string &content) = 0
                 * 
                 * \brief set the content of the text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param content reference to the content of the text
                 */
                virtual void setTextContent(size_t id, std::string &content) = 0;
        };
    }

#endif /* !IGRAPHICALLIB_HPP_ */
