
#ifndef SPRITECOMPONENT_HPP_
    #define SPRITECOMPONENT_HPP_

    #include <string>

    namespace rtype
    {
        namespace components {
            struct sprite_s {
                float scaleX;
                float scaleY;
                int rectX;
                int rectY;
                int rectWidth;
                int rectHeight;
                std::string path;
            };
        }   
    }
    
#endif /* !SPRITECOMPONENT_HPP_ */
