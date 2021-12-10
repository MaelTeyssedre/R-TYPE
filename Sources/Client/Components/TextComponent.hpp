/**
 * \file TextComponent.hpp
 * 
 * \brief file for the Text component 
 */

#ifndef TEXTCOMPONENT_HPP_
    #define TEXTCOMPONENT_HPP_

    #include <string>

    /**
     * \namespace rtype
     * 
     * \brief namespace for rtype project
     * 
     */
    namespace rtype
    {
        /**
         * \namespace components
         * 
         * \brief namespace for ECS components
         * 
         */
        namespace components {
            /**
             * \struct text_s
             * 
             * \brief the text component
             *
             */
            typedef struct text_s {
                int fontSize; /*!< size of the font */
                std::string fontPath; /*!< path of the font */
                std::string text; /*!< content of the text */
            } text_t;
        }   
    }

#endif /* !TEXTCOMPONENT_HPP_ */
