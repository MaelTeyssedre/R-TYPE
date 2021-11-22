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
    #include <memory.h>

    namespace rtype {

        /**
         * \struct mouse_s
         * 
         * \brief mouse struct which contains the necessary information for handling mouse event
         * 
         */
        typedef struct mouse_s
        {
            int posX;
            int posY;
            bool leftPressed;
            bool rightPressed;
        } mouse_t;

        class IGraphicalLib {
            public:

                /**
                 * \fn virtual ~IGraphicalLib() = default
                 * 
                 * \brief default dtor
                 */
                virtual ~IGraphicalLib() = default;

                /**
                 * \fn virtual void draw() = 0
                 * 
                 * \brief draw all sprites/texts in the current scene
                 */
                virtual void draw() = 0;

                /**
                 * \fn virtual void play(Sound &sound) = 0
                 * 
                 * \param sound sound to play
                 * 
                 * \brief play a sound
                 */
                virtual void play(Sound &sound) = 0;

                /**
                 * \fn virtual void play(Music &music) = 0
                 * 
                 * \param music music to play
                 * 
                 * \brief play a music
                 */
                virtual void play(Music &music) = 0;

                /**
                 * \fn virtual void refresh() = 0
                 * 
                 * \brief display and clean the screen
                 */
                virtual void refresh() = 0;

                /**
                 * \fn virtual std::shared_ptr<Sound> createSound(const std::string &path) = 0
                 * 
                 * \param path path of the sound file
                 * 
                 * \brief create a sound class, load the sound inside
                 * 
                 * \return shared_ptr on a sound class
                 */
                virtual std::shared_ptr<Sound> createSound(const std::string &path) = 0;

                /**
                 * \fn virtual std::shared_ptr<Music> createMusic(const std::string &path) = 0
                 * 
                 * \param path path of the sound file
                 * 
                 * \brief create a music class, load the music inside
                 * 
                 * \return shared_ptr on a music class
                 */
                virtual std::shared_ptr<Music> createMusic(const std::string &path) = 0;

                /**
                 * \fn virtual std::shared_ptr<Text> createText(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) = 0
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
                 * \brief create a Text class, initialize the text inside
                 * 
                 * \return shared_ptr on a text class
                 */
                virtual std::shared_ptr<Text> createText(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) = 0;

                /**
                 * \fn virtual std::shared_ptr<Sprite> createSprite(float posX, float posY, float rotation, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) = 0
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
                 * \brief create a sprite class, initialize the sprite inside
                 * 
                 * \return shared_ptr on a sprite class
                 */
                virtual std::shared_ptr<Sprite> createSprite(float posX, float posY, float rotation, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) = 0;
                
                /**
                 * \fn virtual void addSound(constants::SCENE scene, std::shared_ptr<Sound> sound) = 0
                 * 
                 * \param scene scene where the sound is played
                 * 
                 * \param sound sound that you're adding
                 * 
                 * \brief add a sound
                 */
                virtual void addSound(constants::SCENE scene, std::shared_ptr<Sound> sound) = 0;

                /**
                 * \fn virtual void addMusic(constants::SCENE scene, std::shared_ptr<Music> music) = 0
                 * 
                 * \param scene scene where the music is played
                 * 
                 * \param music music that you're adding
                 * 
                 * \brief add a music
                 */
                virtual void addMusic(constants::SCENE scene, std::shared_ptr<Music> music) = 0;

                /**
                 * \fn virtual void addText(constants::SCENE scene, std::shared_ptr<Text> text) = 0
                 * 
                 * \param scene scene where the text is put
                 * 
                 * \param text text that you're adding
                 * 
                 * \brief add a text
                 */
                virtual void addText(constants::SCENE scene, std::shared_ptr<Text> text) = 0;

                /**
                 * \fn virtual void addSprite(constants::SCENE scene, std::shared_ptr<Sprite> sprite) = 0
                 * 
                 * \param scene scene where the sprite will be added
                 * 
                 * \param sound sound that you're adding
                 * 
                 * \brief add a sound
                 */
                virtual void addSprite(constants::SCENE scene, std::shared_ptr<Sprite> sprite) = 0;

                /**
                 * \fn virtual void deleteSound(std::shared_ptr<Sound> sound) = 0
                 * 
                 * \param sound sound that you're deleting
                 * 
                 * \brief delete a sound
                 */
                virtual void deleteSound(std::shared_ptr<Sound> sound) = 0;

                /**
                 * \fn virtual void deleteMusic(std::shared_ptr<Music> music) = 0
                 * 
                 * \param music music that you're deleting
                 * 
                 * \brief delete a music
                 */
                virtual void deleteMusic(std::shared_ptr<Music> music) = 0;

                /**
                 * \fn virtual void deleteText(std::shared_ptr<Text> text) = 0
                 * 
                 * \param text text that you're deleting
                 * 
                 * \brief delete a text
                 */
                virtual void deleteText(std::shared_ptr<Text> text) = 0;

                /**
                 * \fn virtual void deleteSprite(std::shared_ptr<Sprite> sprite) = 0
                 * 
                 * \param sprite sprite that you're deleting
                 * 
                 * \brief delete a sprite
                 */
                virtual void deleteSprite(std::shared_ptr<Sprite> sprite) = 0;

                /**
                 * \fn virtual std::map<rtype::constants::KEY, bool> getKeyState() = 0
                 * 
                 * \brief get the keys states
                 * 
                 * \return map of key state 
                 */
                virtual std::map<rtype::constants::KEY, bool> getKeyState() = 0;

                /**
                 * \fn virtual mouse_t getMouseState() = 0
                 * 
                 * \brief get the mouse states
                 * 
                 * \return struct with all mouse informations 
                 */
                virtual mouse_t getMouseState() = 0;

                /**
                 * \fn virtual void setViewXPos(float viewXPos) = 0
                 * 
                 * \param viewXPos position x of the view
                 * 
                 * \brief set the position x of the view
                 */
                virtual void setViewXPos(float viewXPos) = 0;
        };
    }

#endif /* !IGRAPHICALLIB_HPP_ */
