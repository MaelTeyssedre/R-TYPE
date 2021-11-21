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

                void draw() override;
                void play(Sound &sound) override;
                void play(Music &music) override;
                void refresh() override;
                std::shared_ptr<Sound> createSound(const std::string &path) override;
                std::shared_ptr<Music> createMusic(const std::string &path) override;
                std::shared_ptr<Text> createText(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) override;
                std::shared_ptr<Sprite> createSprite(float posX, float posY, float rotation, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) override;
                void addSound(constants::SCENE scene, std::shared_ptr<Sound> sound) override;
                void addMusic(constants::SCENE scene, std::shared_ptr<Music> music) override;
                void addText(constants::SCENE scene, std::shared_ptr<Text> text) override;
                void addSprite(constants::SCENE scene, std::shared_ptr<Sprite> sprite) override;
                void deleteSound(std::shared_ptr<Sound> sound) override;
                void deleteMusic(std::shared_ptr<Music> music) override;
                void deleteText(std::shared_ptr<Text> text) override;
                void deleteSprite(std::shared_ptr<Sprite> sprite) override;
                std::map<rtype::constants::KEY, bool> getKeyState() override;
                mouse_t getMouseState() override;
                void setViewXPos(float viewXPos) override;

            private:

                std::vector<std::pair<constants::SCENE, std::shared_ptr<Sprite>>> _sprites;
                std::vector<std::pair<constants::SCENE, std::shared_ptr<Text>>> _texts;
                std::vector<std::pair<constants::SCENE, std::shared_ptr<Sound>>> _sounds;
                std::vector<std::pair<constants::SCENE, std::shared_ptr<Music>>> _musics;

                constants::SCENE _currentScene;

                sf::RenderWindow _renderWindow;
                sf::Mouse _mouse;
                sf::View _view;

                std::map<rtype::constants::KEY, bool> _keyState;
                mouse_t _mouseState;

                float _viewX;
        };
    }

#endif /* !GRAPHICALLIB_HPP_ */
