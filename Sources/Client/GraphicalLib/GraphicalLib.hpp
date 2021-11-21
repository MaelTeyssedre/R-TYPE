
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
                size_t createSound(constants::SCENE scene, const std::string &path) override;
                size_t createMusic(constants::SCENE scene, const std::string &path) override;
                size_t createText(constants::SCENE scene, float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) override;
                size_t createSprite(constants::SCENE scene, float posX, float posY, float rotation, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) override;
                void deleteSound(size_t id) override;
                void deleteMusic(size_t id) override;
                void deleteText(size_t id) override;
                void deleteSprite(size_t id) override;

            private:

                std::vector<std::pair<constants::SCENE, std::shared_ptr<Sprite>>> _sprites;
                std::vector<std::pair<constants::SCENE, std::shared_ptr<Text>>> _texts;
                std::vector<std::pair<constants::SCENE, std::shared_ptr<Sound>>> _sounds;
                std::vector<std::pair<constants::SCENE, std::shared_ptr<Music>>> _musics;

                constants::SCENE _currentScene;
                sf::RenderWindow _renderWindow;
        };
    }

#endif /* !GRAPHICALLIB_HPP_ */
