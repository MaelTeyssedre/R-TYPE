
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

    namespace rtype {
        
        /**
         * \class IGraphicalLib IGraphicalLib.hpp
         *
         * \brief Class that define graphical library abstraction
         */
        class IGraphicalLib {
            public:
                virtual ~IGraphicalLib() = default;

                virtual void draw() = 0;
                virtual void play(Sound &sound) = 0;
                virtual void play(Music &music) = 0;
                virtual void refresh() = 0;
                virtual size_t createSound(constants::SCENE scene, const std::string &path) = 0;
                virtual size_t createMusic(constants::SCENE scene, const std::string &path) = 0;
                virtual size_t createText(constants::SCENE scene, float posX, float posY, int fontSize, int colorRed, int colorGreen, int colorBlue, int colorAlpha, std::string content, std::string fontPath) = 0;
                virtual size_t createSprite(constants::SCENE scene, float posX, float posY, float rotation, float scale, int rectX, int rectY, int rectWidth, int rectHeigth, std::string path) = 0;
                virtual void deleteSound(size_t id) = 0;
                virtual void deleteMusic(size_t id) = 0;
                virtual void deleteText(size_t id) = 0;
                virtual void deleteSprite(size_t id) = 0;
        };
    }

#endif /* !IGRAPHICALLIB_HPP_ */
