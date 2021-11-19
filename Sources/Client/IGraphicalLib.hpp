/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** IGraphicalLib
*/

#ifndef IGRAPHICALLIB_HPP_
    #define IGRAPHICALLIB_HPP_

    #include <iostream>

    namespace rtype {

        class Sprite {
            public:
                explicit Sprite() = default;
                virtual ~Sprite() = default;

                int posX;
                int posY;
                int rotation;
                int scale;
                //texture
                //sprite
		        std::string path;
        };

        class Text {
            public:
                explicit Text() = default;
                virtual ~Text() = default;

                int posX;
                int posY;
		        int fontSize;
                std::string text;
		        std::string fontPath;
        };

        struct Sound
        {
            std::string path;

            // Should this sound loop?
            bool loop;
        };

        class IGraphicalLib {
            public:
                virtual ~IGraphicalLib() = default;

                virtual void draw(rtype::Sprite &obj) = 0;
                virtual void draw(rtype::Text &obj) = 0;
                virtual void refresh() = 0;
                virtual void load(const std::string &type, const std::string &path) = 0;
                virtual void unload(const std::string &type, const std::string &path) = 0;
                virtual void unloadAll() = 0; // Usefull?
                virtual void playSound(rtype::Sound &sound) = 0;
        };
    }

#endif /* !IGRAPHICALLIB_HPP_ */
