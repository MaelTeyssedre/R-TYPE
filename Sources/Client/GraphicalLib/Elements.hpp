/**
 * \file Elements.hpp
 *
 * \brief file where the graphical lib interface is defined
 */

#ifndef ELEMENT_HPP_
    #define ELEMENT_HPP_

    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>

    /**
     * \namespace rtype
     * 
     * \brief namespace forthe R-Type
     * 
     */
    namespace rtype
    {
        /**
         * \class GraphicalLib
         * 
         * \brief declaration of class graphicalLib to avoid circular includes...
         */
        class GraphicalLib;

        /**
         * \class Sprite Elements.hpp
         *
         * \brief Class that define sprite
         */
        class Sprite
        {
            public:
                /**
                 * \fn virtual ~Sprite() = default
                 * 
                 * \brief Sprite dtor
                 */
                virtual ~Sprite() = default;

                /**
                 * \fn auto getPosX() -> float
                 * 
                 * \brief get the X position of a sprite
                 *
                 * \return the X position of a sprite
                 */
                auto getPosX() -> float;

                /**
                 * \fn auto getPosY() -> float;
                 * 
                 * \brief get the Y position of a sprite
                 *
                 * \return the Y position of a sprite
                 */
                auto getPosY() -> float;

                /**
                 * \fn auto getRotation() -> float
                 * 
                 * \brief get the rotation of a sprite
                 *
                 * \return the rotation of a sprite
                 */
                auto getRotation() -> float;

                /**
                 * \fn auto getScale() -> float
                 * 
                 * \brief get the scale of a sprite
                 *
                 * \return the scale of a sprite
                 */
                auto getScale() -> float;

                /**
                 * \fn auto getRectX() -> int
                 * 
                 * \brief get the X position of a sprite rectangle
                 *
                 * \return the X position of a sprite rectangle
                 */
                auto getRectX() -> int;

                /**
                 * \fn auto getRectY() -> int;
                 * 
                 * \brief get the Y position of a sprite rectangle
                 *
                 * \return the Y position of a sprite rectangle
                 */
                auto getRectY() -> int;
                
                /**
                 * \fn auto getRectWidth() -> int
                 * 
                 * \brief get the width of a sprite rectangle
                 *
                 * \return the width of a sprite rectangle
                 */
                auto getRectWidth() -> int;

                /**
                 * \fn auto getRectHeigth() -> int
                 * 
                 * \brief get the heigth of a sprite rectangle
                 *
                 * \return the heigth of a sprite rectangle
                 */
                auto getRectHeigth() -> int;

                /**
                 * \fn auto getColorAlpha() -> int
                 * 
                 * \brief get the transparency of a sprite
                 *
                 * \return the transparency of a sprite
                 */
                auto getColorAlpha() -> int;

                /**
                 * \fn auto setPosX(float posX) -> void
                 * 
                 * \brief set the X position of a sprite
                 *
                 * \param posX the posX we want to set
                 */
                auto setPosX(float posX) -> void;

                /**
                 * \fn auto setPosY(float posY) -> void
                 * 
                 * \brief set the Y position of a sprite
                 *
                 * \param posY the posY we want to set
                 */
                auto setPosY(float posY) -> void;
                
                /**
                 * \fn auto setRotation(float rotation) -> void
                 * 
                 * \brief set the rotation position of a sprite
                 *
                 * \param rotation the rotation we want to set
                 */
                auto setRotation(float rotation) -> void;

                /**
                 * \fn auto setScaleX(float scaleX) -> void
                 * 
                 * \brief set the X Scale of a sprite
                 *
                 * \param ScaleX the ScaleX we want to set
                 */
                auto setScaleX(float scaleX) -> void;

                /**
                 * \fn auto setScaleY(float scaleY) -> void
                 * 
                 * \brief set the X Scale of a sprite
                 *
                 * \param ScaleY the ScaleY we want to set
                 */
                auto setScaleY(float scaleY) -> void;

                /**
                 * \fn auto setRectX(int rectX) -> void
                 * 
                 * \brief set the X position of a sprite rectangle
                 *
                 * \param rectX the X position we want to set
                 */
                auto setRectX(int rectX) -> void;

                /**
                 * \fn auto setRectY(int rectY) -> void
                 * 
                 * \brief set the Y position of a sprite rectangle
                 *
                 * \param rectY the Y position we want to set
                 */
                auto setRectY(int rectY) -> void;

                /**
                 * \fn auto setRectWidth(int rectWith) -> void
                 * 
                 * \brief set the width of a sprite rectangle
                 *
                 * \param rectWidth the width we want to set
                 */
                auto setRectWidth(int rectWith) -> void;

                /**
                 * \fn auto setRectHeigth(int rectHeigth) -> void
                 * 
                 * \brief set the heigth of a sprite rectangle
                 *
                 * \param rectHeigth the heigth we want to set
                 */
                auto setRectHeigth(int rectHeigth) -> void;

                /**
                 * \fn auto setColorAlpha(int colorAlpha) -> void
                 * 
                 * \brief set the transprency of a sprite
                 *
                 * \param colorAlpha the transparency we want to set
                 */
                auto setColorAlpha(int colorAlpha) -> void ;
                
                /**
                 * \fn auto drawSprite(sf::RenderWindow *win) -> void
                 * 
                 * \brief draw a sprite
                 *
                 * \param colorAlpha the windows where the sprite is going to be drawn
                 */
               auto drawSprite(sf::RenderWindow *win) -> void;

        protected:
            friend class GraphicalLib;

            /**
             * \fn explicit Sprite() = default
             * 
             * \brief Sprite default ctor
             */
             explicit Sprite() = default;

            /**
             * \fn explicit Sprite(float posX, float posY, float rotation, float scaleX, float scaleY, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path)
             * 
             * \brief Sprite precise ctor
             *
             * \param posX the x position of the sprite we want to set
             * 
             * \param posY the y position of the sprite we want to set
             * 
             * \param rotation the rotation of the sprite we want to set
             * 
             * \param scaleX the scale of the width of the sprite we want to set
             * 
             * \param scaleY the scale of the heigth of the sprite we want to set
             * 
             * \param rectX the x position of the sprite rectangle we want to set
             * 
             * \param rectY the y position of the sprite rectangle we want to set
             * 
             * \param rectWidth the width of the sprite rectangle we want to set
             * 
             * \param rectHeigth the heigth of the sprite rectangle we want to set
             * 
             * \param path Path of the sprite source
             */
             explicit Sprite(float posX, float posY, float rotation, float scaleX, float scaleY, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path);
                
            /**
             * \fn auto getSprite() -> sf::Sprite &
             * 
             * \brief get the sprite
             *
             * \return A reference to the sprite
             */
             auto getSprite() -> sf::Sprite &;


        private:
            float _posX; /*! x position of a sprite */
            float _posY; /*! y position of a sprite */
            float _rotation; /*! rotation of the sprite */
            float _scaleX; /*! x scaling of the sprite */
            float _scaleY; /*! y scaling of the sprite */

            int _rectX; /*! x position of a sprite rectangle*/
            int _rectY; /*! y position of a sprite rectangle*/
            int _rectWidth; /*! width of a sprite rectangle*/
            int _rectHeigth; /*! heigth of a sprite rectangle*/

            int _colorAlpha; /*! transparency of a sprite rectangle*/

            std::string _path; /*! path of a sprite*/

            sf::Texture _texture; /*! texture of a sprite */
            sf::Sprite _sprite; /*! the sprite */
        };

        /**
         * \class Text Elements.hpp
         *
         * \brief Class that define sprite
         */
        class Text
        {
            public:
               /**
                * \fn virtual ~Text() = default
                * 
                * \brief Text dtor
                */
                virtual ~Text() = default;

                /**
                 * \fn auto getPosX() -> float
                 * 
                 * \brief get the X position of a sprite
                 *
                 * \return the X position of a sprite
                 */
                auto getPosX() -> float;

                /**
                 * \fn auto getPosY() -> float
                 * 
                 * \brief get the Y position of a sprite
                 *
                 * \return the Y position of a sprite
                 */
                auto getPosY() -> float;

                /**
                 * \fn auto getFontSize() -> int
                 * 
                 * \brief get the font of a text
                 *
                 * \return the font of a text
                 */
                auto getFontSize() -> int;

                /**
                 * \fn auto getColorRed() -> int
                 * 
                 * \brief get the red color of a text
                 *
                 * \return the red color of a text
                 */
                auto getColorRed() -> int;

                /**
                 * \fn auto getColorGreen() -> int
                 * 
                 * \brief get the Green color of a text
                 *
                 * \return the Green color of a text
                 */
                auto getColorGreen() -> int;

                /**
                 * \fn auto getColorBlue() -> int
                 * 
                 * \brief get the Blue color of a text
                 *
                 * \return the Blue color of a text
                 */
                auto getColorBlue() -> int;

                /**
                 * \fn auto getColorAlpha() -> int
                 * 
                 * \brief get the transparency of a text
                 *
                 * \return the transparency of a text
                 */
                auto getColorAlpha() -> int;

                /**
                 * \fn auto getContent() -> std::string
                 * 
                 * \brief get the content of a text
                 *
                 * \return the content of a text
                 */
                auto getContent() -> std::string;
                
                /**
                 * \fn auto setPosX(float posX) -> void
                 * 
                 * \brief set the X position of a sprite
                 *
                 * \param posX the posX we want to set
                 */
                auto setPosX(float posX) -> void;

                /**
                 * \fn auto setPosY(float posY) -> void
                 * 
                 * \brief set the Y position of a sprite
                 *
                 * \param posY the posY we want to set
                 */
                auto setPosY(float posY) -> void;

                /**
                 * \fn auto setFontSize(int fontSize) -> void
                 * 
                 * \brief set the font size
                 *
                 * \param fontSize the font size we want to set
                 */
                auto setFontSize(int fontSize) -> void ;

                /**
                 * \fn auto setColorRed(int colorRed) -> void
                 * 
                 * \brief set the red color proportion of the text
                 *
                 * \param colorRed the red color proportion of the text
                 */
                auto setColorRed(int colorRed) -> void;

                /**
                 * \fn auto setColorGreen(int colorGreen) -> void
                 * 
                 * \brief set the Green color proportion of the text
                 *
                 * \param colorGreen the Green color proportion of the text
                 */
                auto setColorGreen(int colorGreen) -> void;

                /**
                 * \fn auto setColorBlue(int colorBlue) -> void;
                 * 
                 * \brief set the Blue color proportion of the text
                 *
                 * \param colorBlue the Blue color proportion of the text
                 */
                auto setColorBlue(int colorBlue) -> void;

                /**
                 * \fn auto setColorAlpha(int colorAlpha) -> void
                 * 
                 * \brief set the transparency proportion of the text
                 *
                 * \param colorAlpha the transparency proportion of the text
                 */
                auto setColorAlpha(int colorAlpha) -> void;

                /**
                 * \fn auto setContent(std::string &content) -> void
                 * 
                 * \brief set the content of the text
                 *
                 * \param content A reference to the content of the text
                 */
                auto setContent(std::string &content) -> void;

            protected:
               friend class GraphicalLib;

                /**
                 * \fn explicit Text() = default
                 * 
                 * \brief Text default ctor
                 */
                explicit Text() = default;

                /**
                 * \fn explicit Text(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath)
                 * 
                 * \brief Text precise ctor
                 *
                 * \param posX the x position of the text we want to set
                 * 
                 * \param posY the y position of the text we want to set
                 * 
                 * \param fontSize the font size of the text we want to set
                 * 
                 * \param colorRed the red proportion of the text we want to set
                 * 
                 * \param colorGreen the Green proportion of the text we want to set
                 * 
                 * \param colorBlue the Blue proportion of the text we want to set
                 * 
                 * \param colorAlpha the transparency of the text we want to set
                 * 
                 * \param content the content of the text rectangle we want to set
                 * 
                 * \param fontPath Path of the font source
                 */
                explicit Text(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath);
               
                /**
                 * \fn auto getText() -> sf::Text *
                 * 
                 * \brief get the text
                 *
                 * \return A pointer to the text
                 */
                auto getText() -> sf::Text *;

            private:
                float _posX; /*! x position of a sprite */
                float _posY; /*! y position of a sprite */
                int _fontSize; /*! font size of the text */

                int _colorRed; /*! red color proportion */
                int _colorGreen; /*! green color proportion */
                int _colorBlue; /*! blue color proportion */
                int _colorAlpha; /*! transparency proportion */

                std::string _content; /*! content of the text */
                std::string _fontPath; /*! path of the font source */

                sf::Font _font; /*! the font object */
                sf::Text _text; /*! the text object */
        };

        /**
         * \class Sound Elements.hpp
         *
         * \brief Class that define he sound
         */
        class Sound
        {
            public:
                /**
                 * \fn explicit Sound() = default
                 * 
                 * \brief Sound default ctor
                 */
                explicit Sound() = default;

                /**
                 * \fn virtual ~Sound() = default
                 * 
                 * \brief Sound dtor
                 */
                virtual ~Sound() = default;

            protected:
               friend class GraphicalLib;

                /**
                 * \fn explicit Sound(std::string path)
                 * 
                 * \brief ctor of Sound which take a path
                 *
                 * \param path the path of the sound source
                 */
                explicit Sound(std::string path);
                
                /**
                 * \fn auto getSound() -> sf::Sound &
                 * 
                 * \brief get the Sound
                 *
                 * \return A reference to the Sound
                 */
                auto getSound() -> sf::Sound &;

            private:
                std::string _path; /*! path of the sound file */

                sf::Sound _sound; /*! the sound object */
                sf::SoundBuffer _buffer; /*! buffer which contains the sound */
        };
        
        /**
         * \class Music Elements.hpp
         *
         * \brief Class that define he Music
         */
        class Music {
            public:
                /**
                 * \fn explicit Music() = default
                 * 
                 * \brief Music default ctor
                 */
                explicit Music() = default;

                /**
                 * \fn virtual ~Music() = default
                 * 
                 * \brief Music dtor
                 */
                virtual ~Music() = default;

            protected:
                friend class GraphicalLib;

                /**
                 * \fn explicit Music(std::string path)
                 * 
                 * \brief ctor of Music which take a path
                 *
                 * \param path the path of the music source
                 */
                explicit Music(std::string path);

                /**
                 * \fn auto getMusic() -> sf::Music &
                 * 
                 * \brief get the Music
                 *
                 * \return A reference to the Music
                 */
                auto getMusic() -> sf::Music &;
            
            private:
                std::string _path; /*! path of the music file */

                sf::Music _music;  /*! the music object */
        };
    }

#endif /* !ELEMENT_HPP_ */
