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

    namespace rtype {

        typedef struct mouse_s
        {
            int posX;
            int posY;
            bool leftPressed;
            bool rightPressed;
        } mouse_t;

        class IGraphicalLib {
            public:
                virtual ~IGraphicalLib() = default;

                virtual void draw() = 0;
                virtual void play(Sound &sound) = 0;
                virtual void play(Music &music) = 0;
                virtual void refresh() = 0;
                virtual std::shared_ptr<Sound> createSound(const std::string &path) = 0;
                virtual std::shared_ptr<Music> createMusic(const std::string &path) = 0;
                virtual std::shared_ptr<Text> createText(float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) = 0;
                virtual std::shared_ptr<Sprite> createSprite(float posX, float posY, float rotation, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) = 0;
                virtual void addSound(constants::SCENE scene, std::shared_ptr<Sound> sound) = 0;
                virtual void addMusic(constants::SCENE scene, std::shared_ptr<Music> music) = 0;
                virtual void addText(constants::SCENE scene, std::shared_ptr<Text> text) = 0;
                virtual void addSprite(constants::SCENE scene, std::shared_ptr<Sprite> sprite) = 0;
                virtual void deleteSound(std::shared_ptr<Sound> sound) = 0;
                virtual void deleteMusic(std::shared_ptr<Music> music) = 0;
                virtual void deleteText(std::shared_ptr<Text> text) = 0;
                virtual void deleteSprite(std::shared_ptr<Sprite> sprite) = 0;
                virtual std::map<rtype::constants::KEY, bool> getKeyState() = 0;
                virtual mouse_t getMouseState() = 0;
                virtual void setViewXPos(float viewXPos) = 0;
        };
    }

#endif /* !IGRAPHICALLIB_HPP_ */
