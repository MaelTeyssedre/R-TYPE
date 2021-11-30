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

    /**
     * \namespace rtype
     * 
     * \brief namespace for the R-Type
     * 
     */
    namespace rtype {

        /**
         * \class GraphicalLib GraphicalLib.hpp
         *
         * \brief Class that encapsulate the sfml lib, inherit from IGraphicalLib
         */
        class GraphicalLib : public IGraphicalLib {
            public:

                /**
                 * \fn explicit GraphicalLib()
                 * 
                 * \brief GraphicalLib ctor
                 */
                explicit GraphicalLib();

                /**
                 * \fn virtual ~GraphicalLib() = default
                 * 
                 * \brief GraphicalLib dtor
                 */
                virtual ~GraphicalLib() = default;

            public:

                /**
                 * \fn void draw(size_t id) override
                 * 
                 * \brief draw the sprite
                 *
                 * \param id id of the sprite to draw
                 */
                void draw(size_t id) override;

                /**
                 * \fn void print(size_t id) override
                 * 
                 * \brief print the text
                 *
                 * \param id id of the text to print
                 */
                void print(size_t id) override;

                /**
                 * \fn void start(size_t id) override
                 * 
                 * \brief start a sound
                 *
                 * \param id id of the sound to start
                 */
                void start(size_t id) override;

                /**
                 * \fn void play(size_t id) override
                 * 
                 * \brief play a music
                 *
                 * \param id id of the music to play
                 */
                void play(size_t id) override;

                /**
                 * \fn void stop(size_t id) override
                 * 
                 * \brief stop a music
                 *
                 * \param id id of the music to stop
                 */
                void stop(size_t id) override;

                /**
                 * \fn void pause(size_t id) override
                 * 
                 * \brief pause a music
                 *
                 * \param id id of the music to pause
                 */
                void pause(size_t id) override;

                /**
                 * \fn void refresh() override
                 * 
                 * \brief refresh 
                 */
                void refresh() override;

                /**
                 * \fn void createSound(size_t id, const std::string &path) override
                 * 
                 * \brief create a sound
                 *
                 * \param id id of the sound to create
                 * 
                 * \param path reference to the sound source path
                 */
                void createSound(size_t id, const std::string &path) override;

                /**
                 * \fn void createMusic(size_t id, const std::string &path) override
                 * 
                 * \brief create a music
                 *
                 * \param id id of the music to create
                 * 
                 * \param path reference to the music source path
                 */
                void createMusic(size_t id, const std::string &path) override;

                /**
                 * \fn void createText(size_t id, float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) override
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
                void createText(size_t id, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) override;
                
                /**
                 * \fn createSprite(size_t id, float posX, float posY, float rotation, float scaleX, float scaleY, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) override
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
                void createSprite(size_t id, float scaleX, float scaleY, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) override;
                
                /**
                 * \fn void clearScreen()
                 * 
                 * \brief clear the screen
                 */
                void clearScreen();

                /**
                 * \fn void deleteSound(size_t id) override
                 * 
                 * \brief delete a sound
                 *
                 * \param id id of the sound to delete
                 */
                void deleteSound(size_t id) override;

                /**
                 * \fn void deleteMusic(size_t id) override
                 * 
                 * \brief delete a music
                 *
                 * \param id id of the music to delete
                 */
                void deleteMusic(size_t id) override;

                /**
                 * \fn void deleteText(size_t id) override
                 * 
                 * \brief delete a Text
                 *
                 * \param id id of the Text to delete
                 */
                void deleteText(size_t id) override;

                /**
                 * \fn void deleteSprite(size_t id) override
                 * 
                 * \brief delete a sprite
                 *
                 * \param id id of the sprite to delete
                 */
                void deleteSprite(size_t id) override;

                /**
                 * \fn bool getKeyState(rtype::constants::EVENT event) override
                 * 
                 * \brief get the key state
                 *
                 * \param event key event that is getted
                 * 
                 * \return the key state
                 */
                bool getKeyState(rtype::constants::EVENT event) override;

                /**
                 * \fn mouse_t getMouseState() override
                 * 
                 * \brief get the mouse state
                 *
                 * \return a mouse state component
                 */
                mouse_t getMouseState() override;

                /**
                 * \fn void setViewXPos(float viewXPos) override
                 * 
                 * \brief set the X position of the view
                 *
                 * \param viewXPos X position of the view we want to set
                 */
                void setViewXPos(float viewXPos) override;

            public:
                /**
                 * \fn float getSpritePosX(size_t id) override
                 * 
                 * \brief get the position x of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the x position of the sprite asked
                 */
                float getSpritePosX(size_t id) override;

                /**
                 * \fn float getSpritePosY(size_t id) override
                 * 
                 * \brief get the position y of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the y position of the sprite asked
                 */
                float getSpritePosY(size_t id) override;

                /**
                 * \fn float getSpriteRotation(size_t id) override
                 * 
                 * \brief get the rotation of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the rotation of the asked sprite
                 */
                float getSpriteRotation(size_t id) override;

                /**
                 * \fn float getSpriteScale(size_t id) override
                 * 
                 * \brief get the Scale of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the Scale of the asked sprite
                 */
                float getSpriteScale(size_t id) override;

                /**
                 * \fn int getSpriteRectX(size_t id) override
                 * 
                 * \brief get the x position of a sprite rectangle
                 *
                 * \param id id of the sprite
                 * 
                 * \return the x position of the asked sprite rectangle
                 */
                int getSpriteRectX(size_t id) override;

                /**
                 * \fn int getSpriteRectY(size_t id) override
                 * 
                 * \brief get the y position of a sprite rectangle
                 *
                 * \param id id of the sprite
                 * 
                 * \return the y position of the asked sprite rectangle
                 */
                int getSpriteRectY(size_t id) override;

                /**
                 * \fn int getSpriteRectWidth(size_t id) override
                 * 
                 * \brief get the width of a sprite rectangle
                 *
                 * \param id id of the sprite
                 * 
                 * \return the width of the asked sprite rectangle
                 */
                int getSpriteRectWidth(size_t id) override;

                /**
                 * \fn int getSpriteRectHeigth(size_t id) override
                 * 
                 * \brief get the heigth of a sprite rectangle
                 *
                 * \param id id of the sprite
                 * 
                 * \return the heigth of the asked sprite rectangle
                 */
                int getSpriteRectHeigth(size_t id) override;

                /**
                 * \fn int getSpriteColorAlpha(size_t id) override;
                 * 
                 * \brief get the transparency of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the transparency of the asked sprite
                 */
                int getSpriteColorAlpha(size_t id) override;

                /**
                 * \fn void setSpritePosX(size_t id, float posX) override
                 * 
                 * \brief set the x position of a sprite
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param posX x position to set
                 */
                void setSpritePosX(size_t id, float posX) override;

                /**
                 * \fn void setSpritePosY(size_t id, float posY) override
                 * 
                 * \brief set the y position of a sprite
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param posY y position to set
                 */
                void setSpritePosY(size_t id, float posY) override;

                /**
                 * \fn void setSpriteRotation(size_t id, float rotation) override
                 * 
                 * \brief set the rotation of a sprite
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rotation rotation to set
                 */
                void setSpriteRotation(size_t id, float rotation) override;

                /**
                 * \fn void setSpriteScale(size_t id, float scale) override
                 * 
                 * \brief set the scale of a sprite
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param scale scale to set
                 */
                void setSpriteScale(size_t id, float scaleX, float scaleY) override;

                /**
                 * \fn void setSpriteRectX(size_t id, int rectX) override
                 * 
                 * \brief set the x position of a sprite rectangle
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rectX x position of the sprite rectangle to set
                 */
                void setSpriteRectX(size_t id, int rectX) override;

                /**
                 * \fn void setSpriteRectY(size_t id, int rectY) override
                 * 
                 * \brief set the y position of a sprite rectangle
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rectY y position of the sprite rectangle to set
                 */
                void setSpriteRectY(size_t id, int rectY) override;

                /**
                 * \fn void setSpriteWidth(size_t id, int rectWidth) override
                 * 
                 * \brief set the width of a sprite rectangle
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rectWidth width of the sprite rectangle to set
                 */
                void setSpriteRectWidth(size_t id, int rectWidth) override;

                /**
                 * \fn void setSpriteHeigth(size_t id, int rectHeigth) override
                 * 
                 * \brief set the Heigth of a sprite rectangle
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rectHeigth Heigth of the sprite rectangle to set
                 */
                void setSpriteRectHeigth(size_t id, int rectHeigth) override;

                /**
                 * \fn void setSpriteColorAlpha(size_t id, int colorAlpha) override
                 * 
                 * \brief set the transparency of a sprite 
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param colorAlpha transparency of the to set
                 */
                void setSpriteColorAlpha(size_t id, int colorAlpha) override;

            public:

                /**
                 * \fn float getTextPosX(size_t id) override
                 * 
                 * \brief get the position x of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the x position of the text asked
                 */
                float getTextPosX(size_t id) override;

                /**
                 * \fn float getTextPosY(size_t id) override
                 * 
                 * \brief get the position y of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the y position of the text asked
                 */
                float getTextPosY(size_t id) override;

                /**
                 * \fn int getTextFontSize(size_t id) override
                 * 
                 * \brief get the font size of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the font size of the text asked
                 */
                int getTextFontSize(size_t id) override;

                /**
                 * \fn int getTextColorRed(size_t id) override
                 * 
                 * \brief get the red proportion of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the red proportion of the text asked
                 */
                int getTextColorRed(size_t id) override;

                /**
                 * \fn int getTextColorGreen(size_t id) override
                 * 
                 * \brief get the green proportion of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the green proportion of the text asked
                 */
                int getTextColorGreen(size_t id) override;

                /**
                 * \fn int getTextColorBlue(size_t id) override
                 * 
                 * \brief get the blue proportion of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the blue proportion of the text asked
                 */
                int getTextColorBlue(size_t id) override;

                /**
                 * \fn int getTextColorAlpha(size_t id) override
                 * 
                 * \brief get the transparency of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the transparency of the text asked
                 */
                int getTextColorAlpha(size_t id) override;

                /**
                 * \fn std::string getTextContent(size_t id) override
                 * 
                 * \brief get the content of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the content of the text asked
                 */
                std::string getTextContent(size_t id) override;

                /**
                 * \fn void setTextPosX(size_t id, float posX) override
                 * 
                 * \brief set the x position of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param posX x position to set
                 */
                void setTextPosX(size_t id, float posX) override;

                /**
                 * \fn void setTextPosY(size_t id, float posY) override
                 * 
                 * \brief set the y position of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param posY y position to set
                 */
                void setTextPosY(size_t id, float posY) override;

                /**
                 * \fn void setTextFontSize(size_t id, float fontSize) override
                 * 
                 * \brief set the font size of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param fontSize font size to set
                 */
                void setTextFontSize(size_t id, int fontSize) override;

                /**
                 * \fn void setTextColorRed(size_t id, int colorRed) override
                 * 
                 * \brief set red proportion of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param colorRed red proportion to set
                 */
                void setTextColorRed(size_t id, int colorRed) override;

                /**
                 * \fn void setTextColorGreen(size_t id, int colorGreen) override
                 * 
                 * \brief set Green proportion of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param colorGreen Green proportion to set
                 */
                void setTextColorGreen(size_t id, int colorGreen) override;

                /**
                 * \fn void setTextColorBlue(size_t id, int colorBlue) override
                 * 
                 * \brief set Blue proportion of a Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param colorBlue Blue proportion to set
                 */
                void setTextColorBlue(size_t id, int colorBlue) override;

                /**
                 * \fn void setTextColorAlpha(size_t id, int colorAlpha) override
                 * 
                 * \brief set the transparency of the Text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param colorAlpha the transparency to set
                 */
                void setTextColorAlpha(size_t id, int colorAlpha) override;

                /**
                 * \fn void setTextContent(size_t id, std::string &content) override
                 * 
                 * \brief set the content of the text
                 *
                 * \param id id of the asked Text
                 * 
                 * \param content reference to the content of the text
                 */
                void setTextContent(size_t id, std::string &content) override;

                /**
                 * \fn void HandleClose()
                 * 
                 * \brief handle the game close event
                 */
                void HandleClose();


            private:
                sf::RenderWindow *_renderWindow; /*! the windows renderer */
                sf::Mouse _mouse; /*! A mouse sfml object */
                sf::View _view; /*! A view sfml object */

                float _viewX; /*! the x position of the view*/

                std::map<size_t, std::shared_ptr<Sprite>> _spriteMap; /*! A list of indexed sprite objects */
                std::map<size_t, std::shared_ptr<Text>> _textMap; /*! A list of indexed text objects */
                std::map<size_t, std::shared_ptr<Sound>> _soundMap; /*! A list of indexed sound objects */
                std::map<size_t, std::shared_ptr<Music>> _musicMap; /*! A list of indexed music objects */
                
        };
    }

#endif /* !GRAPHICALLIB_HPP_ */
