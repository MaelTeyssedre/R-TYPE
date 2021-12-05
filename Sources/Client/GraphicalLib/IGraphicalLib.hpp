/**
 * \file IGraphicalLib.hpp
 *
 * \brief file where the graphical lib interface is defined
 */
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
                 * \fn virtual auto draw(size_t id) -> void = 0
                 * 
                 * \brief draw the sprite
                 *
                 * \param id id of the sprite to draw
                 */
                virtual auto draw(size_t id) -> void = 0;

                /**
                 * \fn virtual auto print(size_t id) -> void = 0
                 * 
                 * \brief print the text
                 *
                 * \param id id of the text to print
                 */
                virtual auto print(size_t id) -> void = 0;

                /**
                 * \fn virtual auto start(size_t id) -> void = 0
                 * 
                 * \brief start a sound
                 *
                 * \param id id of the sound to start
                 */
                virtual auto start(size_t id) -> void = 0;

                /**
                 * \fn virtual auto play(size_t id) -> void = 0
                 * 
                 * \brief play a music
                 *
                 * \param id id of the music to play
                 */
                virtual auto play(size_t id) -> void = 0;

                /**
                 * \fn virtual auto stop(size_t id) -> void = 0
                 * 
                 * \brief stop a music
                 *
                 * \param id id of the music to stop
                 */
                virtual auto stop(size_t id) -> void = 0;

                /**
                 * \fn virtual auto pause(size_t id) -> void = 0
                 * 
                 * \brief pause a music
                 *
                 * \param id id of the music to pause
                 */
                virtual auto pause(size_t id) -> void = 0;

                /**
                 * \fn virtual auto refresh() -> void = 0
                 * 
                 * \brief refresh 
                 */
                virtual auto refresh() -> void = 0;

                /**
                 * \fn virtual auto clearScreen() -> void = 0
                 * 
                 * \brief clear the screen from all the previously drawed element 
                 */
                virtual auto clearScreen() -> void = 0;

                /**
                 * \fn virtual auto createSound(size_t id, const std::string &path) -> void = 0
                 * 
                 * \brief create a sound
                 *
                 * \param id id of the sound to create
                 * 
                 * \param path reference to the sound source path
                 */
                virtual auto createSound(size_t id, const std::string &path) -> void = 0;

                /**
                 * \fn virtual auto createMusic(size_t id, const std::string &path) -> void = 0
                 * 
                 * \brief create a music
                 *
                 * \param id id of the music to create
                 * 
                 * \param path reference to the music source path
                 */
                virtual auto createMusic(size_t id, const std::string &path) -> void = 0;

                /**
                 * \fn virtual auto createText(size_t id, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) -> void = 0;
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
                virtual auto createText(size_t id, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) -> void = 0;
                
                /**
                 * \fn virtual auto createSprite(size_t id, float scalex, float scaley, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) -> void = 0;
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
                virtual auto createSprite(size_t id, float scalex, float scaley, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) -> void = 0;
                
                /**
                 * \fn virtual auto deleteSound(size_t id) -> void = 0
                 * 
                 * \brief delete a sound
                 *
                 * \param id id of the sound to delete
                 */
                virtual auto deleteSound(size_t id) -> void = 0;

                /**
                 * \fn virtual auto deleteMusic(size_t id) -> void =  0
                 * 
                 * \brief delete a music
                 *
                 * \param id id of the music to delete
                 */
                virtual auto deleteMusic(size_t id) -> void = 0;

                /**
                 * \fn virtual auto deleteText(size_t id) -> void = 0
                 * 
                 * \brief delete a Text
                 *
                 * \param id id of the Text to delete
                 */
                virtual auto deleteText(size_t id) -> void = 0;

                /**
                 * \fn virtual auto deleteSprite(size_t id) -> void = 0
                 * 
                 * \brief delete a sprite
                 *
                 * \param id id of the sprite to delete
                 */
                virtual auto deleteSprite(size_t id) -> void = 0;

                /**
                 * \fn virtual auto getKeyState(rtype::constants::EVENT event) -> bool = 0
                 * 
                 * \brief get the key state
                 *
                 * \param event key event that is getted
                 * 
                 * \return the key state
                 */
                virtual auto getKeyState(rtype::constants::EVENT event) -> bool = 0;

                /**
                 * \fn virtual auto getMouseState() -> mouse_t = 0
                 * 
                 * \brief get the mouse state
                 *
                 * \return a mouse state component
                 */
                virtual auto getMouseState() -> mouse_t = 0;

                /**
                 * \fn virtual auto HandleClose() -> void = 0
                 * 
                 * \brief Handle the lose event
                 * 
                 */
                virtual auto HandleClose() -> void = 0;

            public:
                /**
                 * \fn virtual auto getSpritePosX(size_t id) -> float = 0
                 * 
                 * \brief get the position x of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the x position of the sprite asked
                 */
                virtual auto getSpritePosX(size_t id) -> float = 0;

                /**
                 * \fn virtual auto getSpritePosY(size_t id) -> float = 0
                 * 
                 * \brief get the position y of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the y position of the sprite asked
                 */
                virtual auto getSpritePosY(size_t id) -> float = 0;

                /**
                 * \fn virtual auto getSpriteRotation(size_t id) -> float = 0
                 * 
                 * \brief get the rotation of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the rotation of the asked sprite
                 */
                virtual auto getSpriteRotation(size_t id) -> float = 0;

                /**
                 * \fn virtual auto getSpriteScale(size_t id) -> float  = 0
                 * 
                 * \brief get the Scale of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the Scale of the asked sprite
                 */
                virtual auto getSpriteScale(size_t id) -> float  = 0;

                /**
                 * \fn virtual auto getSpriteRectX(size_t id) -> int = 0
                 * 
                 * \brief get the x position of a sprite rectangle
                 *
                 * \param id id of the sprite
                 * 
                 * \return the x position of the asked sprite rectangle
                 */
                virtual auto getSpriteRectX(size_t id) -> int = 0;

                /**
                 * \fn virtual auto getSpriteRectY(size_t id) -> int = 0
                 * 
                 * \brief get the y position of a sprite rectangle
                 *
                 * \param id id of the sprite
                 * 
                 * \return the y position of the asked sprite rectangle
                 */
                virtual auto getSpriteRectY(size_t id) -> int = 0;

                /**
                 * \fn virtual auto getSpriteRectWidth(size_t id) -> int = 0;
                 * 
                 * \brief get the width of a sprite rectangle
                 *
                 * \param id id of the sprite
                 * 
                 * \return the width of the asked sprite rectangle
                 */
                virtual auto getSpriteRectWidth(size_t id) -> int = 0;

                /**
                 * \fn virtual auto getSpriteRectHeigth(size_t id) -> int = 0
                 * 
                 * \brief get the heigth of a sprite rectangle
                 *
                 * \param id id of the sprite
                 * 
                 * \return the heigth of the asked sprite rectangle
                 */
                virtual auto getSpriteRectHeigth(size_t id) -> int = 0;

                /**
                 * \fn virtual auto getSpriteColorAlpha(size_t id) -> int = 0
                 * 
                 * \brief get the transparency of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the transparency of the asked sprite
                 */
                virtual auto getSpriteColorAlpha(size_t id) -> int = 0;


                /**
                 * \fn virtual auto setSpritePosX(size_t id, float posX) -> void = 0
                 * 
                 * \brief set the x position of a sprite
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param posX x position to set
                 */
                virtual auto setSpritePosX(size_t id, float posX) -> void = 0;

                /**
                 * \fn virtual auto setSpritePosY(size_t id, float posY) -> void = 0
                 * 
                 * \brief set the y position of a sprite
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param posY y position to set
                 */
                virtual auto setSpritePosY(size_t id, float posY) -> void = 0;

                /**
                 * \fn virtual auto setSpriteRotation(size_t id, float rotation) -> void = 0
                 * 
                 * \brief set the rotation of a sprite
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rotation rotation to set
                 */
                virtual auto setSpriteRotation(size_t id, float rotation) -> void = 0;

                /**
                 * \fn virtual auto setSpriteScale(size_t id, float scaleX, float scaleY) -> void = 0
                 * 
                 * \brief set the scale of a sprite
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param scale scale to set
                 */
                virtual auto setSpriteScale(size_t id, float scaleX, float scaleY) -> void = 0;

                /**
                 * \fn virtual auto setSpriteRectX(size_t id, int rectX) -> void = 0
                 * 
                 * \brief set the x position of a sprite rectangle
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rectX x position of the sprite rectangle to set
                 */
                virtual auto setSpriteRectX(size_t id, int rectX) -> void = 0;

                /**
                 * \fn virtual auto setSpriteRectY(size_t id, int rectY) -> void = 0
                 * 
                 * \brief set the y position of a sprite rectangle
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rectY y position of the sprite rectangle to set
                 */
                virtual auto setSpriteRectY(size_t id, int rectY) -> void = 0;

                /**
                 * \fn virtual auto setSpriteRectWidth(size_t id, int rectWith) -> void  = 0
                 * 
                 * \brief set the width of a sprite rectangle
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rectWidth width of the sprite rectangle to set
                 */
                virtual auto setSpriteRectWidth(size_t id, int rectWith) -> void  = 0;

                /**
                 * \fn virtual auto setSpriteRectHeigth(size_t id, int rectHeigth) -> void = 0
                 * 
                 * \brief set the Heigth of a sprite rectangle
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rectHeigth Heigth of the sprite rectangle to set
                 */
                virtual auto setSpriteRectHeigth(size_t id, int rectHeigth) -> void = 0;

                /**
                 * \fn virtual auto setSpriteColorAlpha(size_t id, int colorAlpha) -> void = 0
                 * 
                 * \brief set the transparency of a sprite 
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param colorAlpha transparency of the to set
                 */
                virtual auto setSpriteColorAlpha(size_t id, int colorAlpha) -> void = 0;


            public:
                /**
                 * \fn virtual auto getTextPosX(size_t id) -> float = 0
                 * 
                 * \brief get the position x of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the x position of the text asked
                 */
                virtual auto getTextPosX(size_t id) -> float = 0;

                /**
                 * \fn virtual auto getTextPosY(size_t id) -> float = 0
                 * 
                 * \brief get the position y of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the y position of the text asked
                 */
                virtual auto getTextPosY(size_t id) -> float = 0;

                /**
                 * \fn virtual auto getTextFontSize(size_t id) -> int = 0
                 * 
                 * \brief get the font size of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the font size of the text asked
                 */
                virtual auto getTextFontSize(size_t id) -> int = 0;

                /**
                 * \fn virtual auto getTextColorRed(size_t id) -> int = 0
                 * 
                 * \brief get the red proportion of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the red proportion of the text asked
                 */
                virtual auto getTextColorRed(size_t id) -> int = 0;

                /**
                 * \fn virtual auto getTextColorGreen(size_t id) -> int = 0
                 * 
                 * \brief get the green proportion of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the green proportion of the text asked
                 */
                virtual auto getTextColorGreen(size_t id) -> int = 0;

                /**
                 * \fn virtual auto getTextColorBlue(size_t id) -> int = 0
                 * 
                 * \brief get the blue proportion of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the blue proportion of the text asked
                 */
                virtual auto getTextColorBlue(size_t id) -> int = 0;

                /**
                 * \fn virtual auto getTextColorAlpha(size_t id) -> int = 0
                 * 
                 * \brief get the transparency of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the transparency of the text asked
                 */
                virtual auto getTextColorAlpha(size_t id) -> int = 0;

                /**
                 * \fn virtual auto getTextContent(size_t id) -> std::string = 0
                 * 
                 * \brief get the content of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the content of the text asked
                 */
                virtual auto getTextContent(size_t id) -> std::string = 0;

                /**
                 * \fn irtual auto setTextPosX(size_t id, float posX) -> void = 0
                 * 
                 * \brief set the x position of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param posX x position to set
                 */
                virtual auto setTextPosX(size_t id, float posX) -> void = 0;

                /**
                 * \fn virtual auto setTextPosY(size_t id, float posY) -> void = 0
                 * 
                 * \brief set the y position of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param posY y position to set
                 */
                virtual auto setTextPosY(size_t id, float posY) -> void = 0;

                /**
                 * \fn virtual auto setTextFontSize(size_t id, int fontSize) -> void = 0
                 * 
                 * \brief set the font size of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param fontSize font size to set
                 */
                virtual auto setTextFontSize(size_t id, int fontSize) -> void = 0;

                /**
                 * \fn virtual auto setTextColorRed(size_t id, int colorRed) -> void = 0
                 * 
                 * \brief set red proportion of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param colorRed red proportion to set
                 */
                virtual auto setTextColorRed(size_t id, int colorRed) -> void = 0;

                /**
                 * \fn virtual auto setTextColorGreen(size_t id, int colorGreen) -> void = 0
                 * 
                 * \brief set Green proportion of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param colorGreen Green proportion to set
                 */
                virtual auto setTextColorGreen(size_t id, int colorGreen) -> void = 0;

                /**
                 * \fn virtual auto setTextColorBlue(size_t id, int colorBlue) -> void = 0
                 * 
                 * \brief set Blue proportion of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param colorBlue Blue proportion to set
                 */
                virtual auto setTextColorBlue(size_t id, int colorBlue) -> void = 0;

                /**
                 * \fn virtual auto setTextColorAlpha(size_t id, int colorAlpha) -> void = 0
                 * 
                 * \brief set the transparency of the Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param colorAlpha the transparency to set
                 */
                virtual auto setTextColorAlpha(size_t id, int colorAlpha) -> void = 0;

                /**
                 * \fn virtual auto setTextContent(size_t id, std::string &content) -> void = 0;
                 * 
                 * \brief set the content of the text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param content reference to the content of the text
                 */
                virtual auto setTextContent(size_t id, std::string &content) -> void = 0;
            
        };
    }

#endif /* !IGRAPHICALLIB_HPP_ */
