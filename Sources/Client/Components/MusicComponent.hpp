/**
 * \file MusicComponent.hpp
 * 
 * \brief file for the Music component 
 */

#ifndef MUSICCOMPONENT_HPP_
    #define MUSICCOMPONENT_HPP_

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
             * \struct music_s
             * 
             * \brief the music component
             *
             */
            typedef struct music_s {
                std::string path; /*!< path of the music */
            } music_t;
        }   
    }

#endif /* !MUSICCOMPONENT_HPP_ */
