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
                 * \fn auto draw(size_t id) -> void override
                 * 
                 * \brief draw the sprite
                 *
                 * \param id id of the sprite to draw
                 */
                auto draw(size_t id) -> void override;

                /**
                 * \fn auto print(size_t id) -> void override
                 * 
                 * \brief print the text
                 *
                 * \param id id of the text to print
                 */
                auto print(size_t id) -> void override;

                /**
                 * \fn void start(size_t id) override
                 * 
                 * \brief start a sound
                 *
                 * \param id id of the sound to start
                 */
                auto start(size_t id) -> void override;

                /**
                 * \fn auto play(size_t id) -> void override
                 * 
                 * \brief play a music
                 *
                 * \param id id of the music to play
                 */
                auto play(size_t id) -> void override;

                /**
                 * \fn auto stop(size_t id) -> void override
                 * 
                 * \brief stop a music
                 *
                 * \param id id of the music to stop
                 */
                auto stop(size_t id) -> void override;

                /**
                 * \fn auto pause(size_t id) -> void override
                 * 
                 * \brief pause a music
                 *
                 * \param id id of the music to pause
                 */
                auto pause(size_t id) -> void override;

                /**
                 * \fn auto refresh() -> void override
                 * 
                 * \brief refresh 
                 */
                auto refresh() -> void override;

                /**
                 * \fn auto clearScreen() -> void override
                 * 
                 * \brief clear the screen from all the previously drawed element 
                 */
                auto clearScreen() -> void override;

                /**
                 * \fn auto createSound(size_t id, const std::string &path) -> void override
                 * 
                 * \brief create a sound
                 *
                 * \param id id of the sound to create
                 * 
                 * \param path reference to the sound source path
                 */
                auto createSound(size_t id, const std::string &path) -> void override;

                /**
                 * \fn auto createMusic(size_t id, const std::string &path) -> void override
                 * 
                 * \brief create a music
                 *
                 * \param id id of the music to create
                 * 
                 * \param path reference to the music source path
                 */
                auto createMusic(size_t id, const std::string &path) -> void override;

                /**
                 * \fn auto createText(size_t id, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) -> void override;
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
                auto createText(size_t id, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) -> void override;
                
                /**
                 * \fn auto createSprite(size_t id, float scaleX, float scaleY, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) -> void override
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
                auto createSprite(size_t id, float scaleX, float scaleY, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) -> void override;
                
                

                /**
                 * \fn auto deleteSound(size_t id) -> void override
                 * 
                 * \brief delete a sound
                 *
                 * \param id id of the sound to delete
                 */
                auto deleteSound(size_t id) -> void override;

                /**
                 * \fn auto deleteMusic(size_t id) -> void override
                 * 
                 * \brief delete a music
                 *
                 * \param id id of the music to delete
                 */
                auto deleteMusic(size_t id) -> void override;

                /**
                 * \fn auto deleteText(size_t id) -> void override
                 * 
                 * \brief delete a Text
                 *
                 * \param id id of the Text to delete
                 */
                auto deleteText(size_t id) -> void override;

                /**
                 * \fn auto deleteSprite(size_t id) -> void override
                 * 
                 * \brief delete a sprite
                 *
                 * \param id id of the sprite to delete
                 */
                auto deleteSprite(size_t id) -> void override;

                /**
                 * \fn auto getKeyState(rtype::constants::EVENT event) -> bool override
                 * 
                 * \brief get the key state
                 *
                 * \param event key event that is getted
                 * 
                 * \return the key state
                 */
                auto getKeyState(rtype::constants::EVENT event) -> bool override;

                /**
                 * \fn auto getMouseState() -> mouse_t override
                 * 
                 * \brief get the mouse state
                 *
                 * \return a mouse state component
                 */
                auto getMouseState() -> mouse_t override;

                /**
                 * \fn auto HandleClose() -> void override
                 * 
                 * \brief Handle the lose event
                 * 
                 */
                auto HandleClose() -> void override;

            public:
                /**
                 * \fn auto getSpritePosX(size_t id) -> float
                 * 
                 * \brief get the position x of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the x position of the sprite asked
                 */
                auto getSpritePosX(size_t id) -> float override;

                /**
                 * \fn auto getSpritePosY(size_t id) -> float override
                 * 
                 * \brief get the position y of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the y position of the sprite asked
                 */
                auto getSpritePosY(size_t id) -> float override;

                /**
                 * \fn auto getSpriteRotation(size_t id) -> float override
                 * 
                 * \brief get the rotation of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the rotation of the asked sprite
                 */
                auto getSpriteRotation(size_t id) -> float override;

                /**
                 * \fn auto getSpriteScale(size_t id) -> float override
                 * 
                 * \brief get the Scale of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the Scale of the asked sprite
                 */
                auto getSpriteScale(size_t id) -> float override;

                /**
                 * \fn auto getSpriteRectX(size_t id) -> int override
                 * 
                 * \brief get the x position of a sprite rectangle
                 *
                 * \param id id of the sprite
                 * 
                 * \return the x position of the asked sprite rectangle
                 */
                auto getSpriteRectX(size_t id) -> int override;

                /**
                 * \fn auto getSpriteRectY(size_t id) -> int override
                 * 
                 * \brief get the y position of a sprite rectangle
                 *
                 * \param id id of the sprite
                 * 
                 * \return the y position of the asked sprite rectangle
                 */
                auto getSpriteRectY(size_t id) -> int override;

                /**
                 * \fn auto getSpriteRectWidth(size_t id) -> int override
                 * 
                 * \brief get the width of a sprite rectangle
                 *
                 * \param id id of the sprite
                 * 
                 * \return the width of the asked sprite rectangle
                 */
                auto getSpriteRectWidth(size_t id) -> int override;

                /**
                 * \fn auto getSpriteRectHeigth(size_t id) -> int override
                 * 
                 * \brief get the heigth of a sprite rectangle
                 *
                 * \param id id of the sprite
                 * 
                 * \return the heigth of the asked sprite rectangle
                 */
                auto getSpriteRectHeigth(size_t id) -> int override;

                /**
                 * \fn auto getSpriteColorAlpha(size_t id) -> int override
                 * 
                 * \brief get the transparency of a sprite
                 *
                 * \param id id of the sprite
                 * 
                 * \return the transparency of the asked sprite
                 */
                auto getSpriteColorAlpha(size_t id) -> int override;

                /**
                 * \fn auto setSpritePosX(size_t id, float posX) -> void override
                 * 
                 * \brief set the x position of a sprite
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param posX x position to set
                 */
                auto setSpritePosX(size_t id, float posX) -> void override;

                /**
                 * \fn auto setSpritePosY(size_t id, float posY) -> void override
                 * 
                 * \brief set the y position of a sprite
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param posY y position to set
                 */
                auto setSpritePosY(size_t id, float posY) -> void override;

                /**
                 * \fn auto setSpriteRotation(size_t id, float rotation) -> void override
                 * 
                 * \brief set the rotation of a sprite
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rotation rotation to set
                 */
                auto setSpriteRotation(size_t id, float rotation) -> void override;

                /**
                 * \fn auto setSpriteScale(size_t id, float scaleX, float scaleY)-> void override
                 * 
                 * \brief set the scale of a sprite
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param scale scale to set
                 */
                auto setSpriteScale(size_t id, float scaleX, float scaleY)-> void override;

                /**
                 * \fn auto setSpriteRectX(size_t id, int rectX) -> void override
                 * 
                 * \brief set the x position of a sprite rectangle
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rectX x position of the sprite rectangle to set
                 */
                auto setSpriteRectX(size_t id, int rectX) -> void override;

                /**
                 * \fn auto setSpriteRectY(size_t id, int rectY) -> void override
                 * 
                 * \brief set the y position of a sprite rectangle
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rectY y position of the sprite rectangle to set
                 */
                auto setSpriteRectY(size_t id, int rectY) -> void override;

                /**
                 * \fn auto setSpriteRectWidth(size_t id, int rectWidth) -> void override
                 * 
                 * \brief set the width of a sprite rectangle
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rectWidth width of the sprite rectangle to set
                 */
                auto setSpriteRectWidth(size_t id, int rectWidth) -> void override;

                /**
                 * \fn auto setSpriteRectHeigth(size_t id, int rectHeigth) -> void override
                 * 
                 * \brief set the Heigth of a sprite rectangle
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param rectHeigth Heigth of the sprite rectangle to set
                 */
                auto setSpriteRectHeigth(size_t id, int rectHeigth) -> void override;

                /**
                 * \fn auto setSpriteColorAlpha(size_t id, int colorAlpha) -> void override
                 * 
                 * \brief set the transparency of a sprite 
                 *
                 * \param id id of the asked sprite
                 * 
                 * \param colorAlpha transparency of the to set
                 */
                auto setSpriteColorAlpha(size_t id, int colorAlpha) -> void override;

            public:
                /**
                 * \fn auto getTextPosX(size_t id) -> float override
                 * 
                 * \brief get the position x of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the x position of the text asked
                 */
                auto getTextPosX(size_t id) -> float override;

                /**
                 * \fn auto getTextPosY(size_t id) -> float override
                 * 
                 * \brief get the position y of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the y position of the text asked
                 */
                auto getTextPosY(size_t id) -> float override;

                /**
                 * \fn auto getTextFontSize(size_t id) -> int override
                 * 
                 * \brief get the font size of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the font size of the text asked
                 */
                auto getTextFontSize(size_t id) -> int override;

                /**
                 * \fn auto getTextColorRed(size_t id) -> int override
                 * 
                 * \brief get the red proportion of a text
                 *
                 * \param id id of the text
                 * 
                 * \return the red proportion of the text asked
                 */
                auto getTextColorRed(size_t id) -> int override;

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


                void setTextPosX(size_t id, float posX) override;
                void setTextPosY(size_t id, float posY) override;
                void setTextFontSize(size_t id, int fontSize) override;
                void setTextColorRed(size_t id, int colorRed) override;
                void setTextColorGreen(size_t id, int colorGreen) override;
                void setTextColorBlue(size_t id, int colorBlue) override;
                void setTextColorAlpha(size_t id, int colorAlpha) override;
                void setTextContent(size_t id, std::string &content) override;


            private:
                sf::RenderWindow *_renderWindow;
                sf::Mouse _mouse;

                std::map<size_t, std::shared_ptr<Sprite>> _spriteMap;
                std::map<size_t, std::shared_ptr<Text>> _textMap;
                std::map<size_t, std::shared_ptr<Sound>> _soundMap;
                std::map<size_t, std::shared_ptr<Music>> _musicMap;
                
        };
    }

#endif /* !GRAPHICALLIB_HPP_ */
