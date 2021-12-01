
#ifndef TEXTCOMPONENT_HPP_
    #define TEXTCOMPONENT_HPP_

    #include <string>

    namespace rtype
    {
        namespace components {
            struct text_s {
                int fontSize;
                std::string fontPath;
                std::string text;
            };
        }   
    }

#endif /* !TEXTCOMPONENT_HPP_ */
