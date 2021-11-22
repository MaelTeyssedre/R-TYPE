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
     * \brief global namespace for rtype project 
     * 
     */
    namespace rtype {

        /**
         * \class GraphicalLib
         * 
         * \brief graphical lib abstraction class
         * 
         */
        class GraphicalLib : public IGraphicalLib {
            public:

                /**
                 * \fn explicit GraphicalLib()
                 * 
                 * \brief Ctor
                 */
                explicit GraphicalLib();
                
                /**
                 * \fn virtual ~GraphicalLib() = default
                 * 
                 * \brief default dtor
                 */
                virtual ~GraphicalLib() = default;

                /**
                 * \fn void draw() override
                 * 
                 * \brief draw all sprites/texts in the current scene
                 */
                void draw() override;
                
                /**
                 * \fn void play(Sound &sound) override
                 * 
                 * \param sound sound to play
                 * 
                 * \brief play a sound
                 */
                void play(Sound &sound) override;
                
                /**
                 * \fn void play(Music &music) override
                 * 
                 * \param music music to play
                 * 
                 * \brief play a music
                 */
                void play(Music &music) override;
                
                /**
                 * \fn void refresh() override
                 * 
                 * \brief display and clean the screen
                 */
                void refresh() override;

                /**
                 * \fn std::shared_ptr<Sound> createSound(const std::string &path) override
                 * 
                 * \param path path of the sound file
                 * 
                 * \brief create a sound class, load the sound inside
                 * 
                 * \return shared_ptr on a sound class
                 */
                std::shared_ptr<Sound> createSound(const std::string &path) override;
                
                /**
                 * \fn std::shared_ptr<Music> createMusic(const std::string &path) override
                 * 
                 * \param path path of the sound file
                 * 
                 * \brief create a music class, load the music inside
                 * 
                 * \return shared_ptr on a music class
                 */
                std::shared_ptr<Music> createMusic(const std::string &path) override;
                
                /**
                 * \fn std::shared_ptr<Text> createText(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) override
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
                std::shared_ptr<Text> createText(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) override;
                
                /**
                 * \fn std::shared_ptr<Sprite> createSprite(float posX, float posY, float rotation, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) override
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
                std::shared_ptr<Sprite> createSprite(float posX, float posY, float rotation, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) override;
                
                /**
                 * \fn void addSound(constants::SCENE scene, std::shared_ptr<Sound> sound) override
                 * 
                 * \param scene scene where the sound is played
                 * 
                 * \param sound sound that you're adding
                 * 
                 * \brief add a sound
                 */
                void addSound(constants::SCENE scene, std::shared_ptr<Sound> sound) override;

                /**
                 * \fn void addMusic(constants::SCENE scene, std::shared_ptr<Music> music) override
                 * 
                 * \param scene scene where the music is played
                 * 
                 * \param music music that you're adding
                 * 
                 * \brief add a music
                 */
                void addMusic(constants::SCENE scene, std::shared_ptr<Music> music) override;
                
                /**
                 * \fn void addText(constants::SCENE scene, std::shared_ptr<Text> text) override
                 * 
                 * \param scene scene where the text is put
                 * 
                 * \param text text that you're adding
                 * 
                 * \brief add a text
                 */
                void addText(constants::SCENE scene, std::shared_ptr<Text> text) override;
                
                /**
                 * \fn void addSprite(constants::SCENE scene, std::shared_ptr<Sprite> sprite) override
                 * 
                 * \param scene scene where the sprite will be added
                 * 
                 * \param sound sound that you're adding
                 * 
                 * \brief add a sound
                 */
                void addSprite(constants::SCENE scene, std::shared_ptr<Sprite> sprite) override;
                
                /**
                 * \fn void deleteSound(std::shared_ptr<Sound> sound) override
                 * 
                 * \param sound sound that you're deleting
                 * 
                 * \brief delete a sound
                 */
                void deleteSound(std::shared_ptr<Sound> sound) override;
                
                /**
                 * \fn void deleteMusic(std::shared_ptr<Music> music) override
                 * 
                 * \param music music that you're deleting
                 * 
                 * \brief delete a music
                 */
                void deleteMusic(std::shared_ptr<Music> music) override;
                
                /**
                 * \fn void deleteText(std::shared_ptr<Text> text) override
                 * 
                 * \param text text that you're deleting
                 * 
                 * \brief delete a text
                 */
                void deleteText(std::shared_ptr<Text> text) override;
                
                /**
                 * \fn void deleteSprite(std::shared_ptr<Sprite> sprite) override
                 * 
                 * \param sprite sprite that you're deleting
                 * 
                 * \brief delete a sprite
                 */
                void deleteSprite(std::shared_ptr<Sprite> sprite) override;
                
                /**
                 * \fn std::map<rtype::constants::KEY, bool> getKeyState() override
                 * 
                 * \brief get the keys states
                 * 
                 * \return map of key state 
                 */
                std::map<rtype::constants::KEY, bool> getKeyState() override;
                
                /**
                 * \fn mouse_t getMouseState() override
                 * 
                 * \brief get the mouse states
                 * 
                 * \return struct with all mouse informations 
                 */
                mouse_t getMouseState() override;

                /**
                 * \fn void setViewXPos(float viewXPos) override
                 * 
                 * \param viewXPos position x of the view
                 * 
                 * \brief set the position x of the view
                 */
                void setViewXPos(float viewXPos) override;

            private:

                std::vector<std::pair<constants::SCENE, std::shared_ptr<Sprite>>> _sprites; /*! list of sprites with their corresponding scene */
                std::vector<std::pair<constants::SCENE, std::shared_ptr<Text>>> _texts; /*! list of texts with their corresponding scene */
                std::vector<std::pair<constants::SCENE, std::shared_ptr<Sound>>> _sounds; /*! list of sounds with their corresponding scene */
                std::vector<std::pair<constants::SCENE, std::shared_ptr<Music>>> _musics; /*! list of music with their corresponding scene */

                constants::SCENE _currentScene; /*! current scene display */

                sf::RenderWindow _renderWindow; /*! window of the game */
                sf::Mouse _mouse; /*! mouse class */
                sf::View _view; /*! view class */

                std::map<rtype::constants::KEY, bool> _keyState; /*! map of the key state */
                mouse_t _mouseState; /*! mouse state struct */

                float _viewX; /*! position X of the view */
        };
    }

#endif /* !GRAPHICALLIB_HPP_ */
