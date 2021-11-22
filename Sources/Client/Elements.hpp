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
         * \class Sprite
         *
         * \brief Class that define sprite
         */
        class Sprite {
            public:

                /**
                 * \fn virtual ~Sprite() = default
                 * 
                 * \brief default dtor
                 * 
                 */
                virtual ~Sprite() = default;

                /**
                 * \fn float getPosX()
                 * 
                 * \brief get the x position of the sprite
                 * 
                 * \return float x position of the sprite 
                 */
                float getPosX();

                /**
                 * \fn float getPosY()
                 * 
                 * \brief get the y position of the sprite
                 * 
                 * \return float y position of the sprite 
                 */
                float getPosY();

                /**
                 * \fn float getRotation()
                 * 
                 * \brief get the rotation of the sprite
                 * 
                 * \return float rotation of the sprite 
                 */
                float getRotation();

                /**
                 * \fn float getScale()
                 * 
                 * \brief get the scale of the sprite
                 * 
                 * \return float scale of the sprite 
                 */
                float getScale();

                /**
                 * \fn int getRectX()
                 * 
                 * \brief get the x position of a rectangle
                 * 
                 * \return int the x position of a rectangle
                 */
                int getRectX();

                /**
                 * \fn int getRectY()
                 * 
                 * \brief get the y position of a rectangle
                 * 
                 * \return int the y position of a rectangle
                 */
                int getRectY();

                /**
                 * \fn int getRectWidth()
                 * 
                 * \brief get the width of a rectangle
                 * 
                 * \return int the width of a rectangle
                 */
                int getRectWidth();

                /**
                 * \fn int getRectHeigth()
                 * 
                 * \brief get the eigth of a rectangle
                 * 
                 * \return int the heigth of a rectangle
                 */
                int getRectHeigth();


                /**
                 * \fn void setPosX(float PosX)
                 * 
                 * \param PosX position x of the sprite
                 * 
                 * \brief set the position x of the sprite
                 */
                void setPosX(float posX);

                /**
                 * \fn void setPosY(float PosY)
                 * 
                 * \param PosY position y of the sprite
                 * 
                 * \brief set the position y of the sprite
                 */
                void setPosY(float posY);

                /**
                 * \fn void setRotation(float rotation)
                 * 
                 * \param rotation rotation of the sprite
                 * 
                 * \brief set the rotation of the sprite
                 */
                void setRotation(float rotation);

                /**
                 * \fn void setScale(float scale)
                 * 
                 * \param scale scale of the sprite
                 * 
                 * \brief set the scale of the sprite
                 */
                void setScale(float scale);

                /**
                 * \fn void setRectX(int rectX)
                 * 
                 * \param rectX position x of the rectangle
                 * 
                 * \brief set the position x of the rectangle
                 */
                void setRectX(int rectX);

                /**
                 * \fn void setRectY(int rectY)
                 * 
                 * \param rectY position y of the rectangle
                 * 
                 * \brief set the position y of the rectangle
                 */
                void setRectY(int rectY);

                /**
                 * \fn void setRectWidth(int rectWidth)
                 * 
                 * \param rectWidth widthof the rectangle
                 * 
                 * \brief set the width of the rectangle
                 */
                void setRectWidth(int rectWith);

                /**
                 * \fn void setRectHeigth(int rectHeigth)
                 * 
                 * \param rectHeigth Heigth of the rectangle
                 * 
                 * \brief set the Heigth of the rectangle
                 */
                void setRectHeigth(int rectHeigth);
            protected:
                /**
                 * \brief class passed in friend to only be able to be created by it
                 */
                friend class GraphicalLib;

                /**
                 * \fn explicit Sprite(float posX, float posY, float rotation, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path)
                 * 
                 * \param posX pos X to display the sprite
                 * 
                 * \param posY pos Y to display the sprite
                 * 
                 * \param rotation rotation to display the sprite
                 * 
                 * \param scale scale to display the sprite
                 * 
                 * \param rectX position x where your texture rect start
                 * 
                 * \param rectY position y where your texture rect start
                 * 
                 * \param rectWidth width of your texture rect
                 * 
                 * \param rectHeigth heigth of your texture rect
                 * 
                 * \param path path of the texture
                 * 
                 * \brief create a sprite class
                 */
                explicit Sprite(float posX, float posY, float rotation, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path);

                /**
                 * \fn sf::Sprite &getSprite()
                 * 
                 * \brief get the sprite
                 * 
                 * \return sf::Sprite & return a reference to the sprite
                 */
                sf::Sprite &getSprite();

            private:
                float _posX; /*! position x of the sprite */
                float _posY; /*! position y of the sprite */
                float _rotation; /*! rotation of the sprite */
                float _scale; /*! scale of the sprite */

                int _rectX; /*! position x of the rect */
                int _rectY; /*! position y of the rect */
                int _rectWidth; /*! width of the rect */
                int _rectHeigth; /*! heigth of the rect */
                
                std::string _path; /*! path of a sprite */

                sf::Texture _texture; /*! texture the sprite */
                sf::Sprite _sprite; /*! sprite */
        };

        /**
         * \class Text
         *
         * \brief Class that define Text
         */
        class Text {
            public:
                /**
                 * \fn virtual ~Text() = default
                 * 
                 * \brief default dtor
                 * 
                 */
                virtual ~Text() = default;

                /**
                 * \fn float getPosX()
                 * 
                 * \brief get the x position of the text
                 * 
                 * \return float x position of the text 
                 */
                float getPosX();

                /**
                 * \fn float getPosY()
                 * 
                 * \brief get the y position of the text
                 * 
                 * \return float y position of the text 
                 */
                float getPosY();

                /**
                 * \fn int getFontSize()
                 * 
                 * \brief get the font size of the text
                 * 
                 * \return float font size of the text 
                 */
                int getFontSize();

                /**
                 * \fn int getColorRed()
                 * 
                 * \brief get the proportion of red in the text
                 * 
                 * \return float the proportion of red in the text
                 */
                int getColorRed();

                /**
                 * \fn int getColorGreen()
                 * 
                 * \brief get the proportion of green in the text
                 * 
                 * \return int the proportion of green in the text
                 */
                int getColorGreen();
                
                /**
                 * \fn int getColorBlue()
                 * 
                 * \brief get the proportion of blue in the text
                 * 
                 * \return int the proportion of blue in the text
                 */
                int getColorBlue();

                /**
                 * \fn int getColorAlpha()
                 * 
                 * \brief get the proportion of alpha in the text
                 * 
                 * \return int the proportion of alpha in the text
                 */
                int getColorAlpha();

                /**
                 * \fn std::string getContent()
                 * 
                 * \brief get the content of the text
                 * 
                 * \return std::string the content the text
                 */
                std::string getContent();

                /**
                 * \fn void setPosX(int posX)
                 * 
                 * \param rectX position x of the text
                 * 
                 * \brief set the position x of the text
                 */
                void setPosX(float posX);

                /**
                 * \fn void setPosY(int posY)
                 * 
                 * \param rectY position y of the text
                 * 
                 * \brief set the position y of the text
                 */
                void setPosY(float posY);

                /**
                 * \fn void setFontSize(int fontSize)
                 * 
                 * \param fontSize font size of the text
                 * 
                 * \brief set the font size of the text
                 */
                void setFontSize(int fontSize);

                /**
                 * \fn void setColorRed(int colorRed)
                 * 
                 * \param colorRed proportion of red
                 * 
                 * \brief set the proportion of red of the text
                 */
                void setColorRed(int colorRed);

                /**
                 * \fn void setColorGreen(int colorGreen)
                 * 
                 * \param colorGreen proportion of green
                 * 
                 * \brief set the proportion of green of the text
                 */
                void setColorGreen(int colorGreen);

                /**
                 * \fn void setColorBlue(int colorBlue)
                 * 
                 * \param colorBlue proportion of blue
                 * 
                 * \brief set the proportion of blue of the text
                 */
                void setColorBlue(int colorBlue);

                /**
                 * \fn void setColorAlpha(int colorAlpha)
                 * 
                 * \param colorAlpha transparence of the text
                 * 
                 * \brief set the transparence of the text
                 */
                void setColorAlpha(int colorAlpha);

                /**
                 * \fn std::string setContent(std:string &content)
                 * 
                 * \param content content of the text
                 * 
                 * \brief set the content of the text
                 */
                void setContent(std::string &content);

            protected:
                /**
                 * \brief class passed in friend to only be able to be created by it
                 */
                friend class GraphicalLib;

                /**
                 * \fn Text(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) override
                 * 
                 * \param posX pos X to display the text
                 * 
                 * \param posY pos Y to display the text
                 * 
                 * \param fontSize Size to display the text
                 * 
                 * \param colorRed proportion of red of the color you display the text
                 * 
                 * \param colorGreen proportion of green of the color you display the text
                 * 
                 * \param colorBlue proportion of blue of the color you display the text
                 * 
                 * \param colorAlpha proportion of transparency of the color you display the text
                 * 
                 * \param content text you display
                 * 
                 * \param fontPath path of the font file
                 * 
                 * \brief create a Text class
                 */
                explicit Text(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath);
                
                /**
                 * \fn sf::Text &getText()
                 * 
                 * \brief get the text
                 * 
                 * \return  Text & return a reference to the text
                 */
                sf::Text &getText();

            private:
                float _posX; /*! position x of the text */
                float _posY; /*! position y of the text */
                int _fontSize; /*! font size of the text */

                int _colorRed; /*! proportion of red of the text */
                int _colorGreen; /*! proportion of green of the text */
                int _colorBlue; /*! proportion of blue of the text */
                int _colorAlpha; /*! proportion of alpha of the text */

                std::string _content; /*! content of the text */
                std::string _fontPath; /*! path of the font of the text */

                sf::Font _font; /*! font of the text */
                sf::Text _text; /*! text */
        };

        /**
         * \class Sound
         *
         * \brief Class that define Sound
         */
        class Sound {
            public:

                /**
                 * \fn virtual ~Sound() = default
                 * 
                 * \brief default dtor
                 * 
                 */
                virtual ~Sound() = default;

            protected:
                /**
                 * \brief class passed in friend to only be able to be created by it
                 */
                friend class GraphicalLib;

                /**
                 * \fn explicit Sound()
                 * 
                 * \param path path of the sound file
                 * 
                 * \brief ctor
                 * 
                 */
                explicit Sound(std::string path);
                
                /**
                 * \fn sf::Sound &getSound()
                 * 
                 * \brief get the sound
                 * 
                 * \return  Sound & return a reference to the sound
                 */
                sf::Sound &getSound();

            private:
                std::string _path; /*! path of the sound */

                sf::Sound _sound; /*! the sound */
                sf::SoundBuffer _buffer; /*! soundbuffer which load the sound */
        };

        /**
         * \class Music
         *
         * \brief Class that define Music
         */
        class Music {
            public:
                /**
                 * \fn virtual ~Music() = default
                 * 
                 * \brief default dtor
                 * 
                 */
                virtual ~Music() = default;

            protected:
                /**
                 * \brief class passed in friend to only be able to be created by it
                 */
                friend class GraphicalLib;

                /**
                 * \fn explicit Music()
                 * 
                 * \param path path of the sound file
                 * 
                 * \brief ctor
                 * 
                 */
                explicit Music(std::string path);

                /**
                 * \fn sf::Music &getMusic()
                 * 
                 * \brief get the music
                 * 
                 * \return  Music & return a reference to the music
                 */
                sf::Music &getMusic();
            private:


                std::string _path; /*! path of the sound */

                sf::Music _music; /*! music */
        };
    }

#endif /* !ELEMENT_HPP_ */