/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** IGraphicalLib
*/

/**
 * \file IGraphicalLib.hpp
 *
 * \brief file where the graphical lib abstraction is defined
 */

#ifndef IGRAPHICALLIB_HPP_
    #define IGRAPHICALLIB_HPP_

    #include <iostream>
    #include <SFML/Window.hpp>
    #include "Constants.hpp"

    namespace rtype {

        /**
         * \struct Sprite IGraphicalLib.hpp
         *
         * \brief struct that define sprite
         */
        struct sprite_s {
            int posX;
            int posY;
            int rotation;
            int scale;

            int rectX;
            int rectY;
            int rectWidth;
            int rectHeigth;
            
            sf::Texture texture;
            sf::sprite sprite;
            std::string path;
        };
        using sprite_t = struct sprite_s;

        /**
         * \struct Text IGraphicalLib.hpp
         *
         * \brief struct that define sprite
         */
        struct text_s {
            int posX;
            int posY;
            int fontSize;

            int colorRed;
            int colorGreen;
            int colorBlue;
            int colorAlpha;

            std::string text;
            std::string fontPath;

            sf::Font font;
            sf::Text text;
            sf::Color color;
        };
        using text_t = struct text_s;

        /**
         * \struct sound_s IGraphicalLib.hpp
         * 
         * \brief sound informations
         *
         * \param path string of the path of the ressource
         */
        struct sound_s
        {
            std::string path;

            sf::Sound sound;
            sf::SoundBuffer buffer;
        };
        using sound_t = struct sound_s;

        /**
         * \struct music_s IGraphicalLib.hpp
         * 
         * \brief music informations
         *
         * \param path string of the path of the ressource
         */
        struct music_s
        {
            std::string path;

            sf::Music music;
        };
        using music_t = struct music_s;

        /**
         * \class IGraphicalLib IGraphicalLib.hpp
         *
         * \brief Class that define graphical library abstraction
         */
        class IGraphicalLib {
            public:
                virtual ~IGraphicalLib() = default;

                virtual void draw(sprite_t &obj) = 0;
                virtual void draw(text_t &obj) = 0;
                virtual void play(sound_t &sound) = 0;
                virtual void play(music_t &sound) = 0;
                virtual void refresh() = 0;
                virtual void load(const rtype::constants::TYPE &type, const std::string &path) = 0;
        };
    }

#endif /* !IGRAPHICALLIB_HPP_ */
