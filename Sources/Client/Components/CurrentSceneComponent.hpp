
#ifndef CURRENTSCENECOMPONENT_HPP_
    #define CURRENTSCENECOMPONENT_HPP_

    #include "Constants.hpp"

    namespace rtype {
        namespace components {
            struct currentScene_s {
                constants::SCENE scene;
                bool isLoaded;
            };
        }
    }

#endif /* !CURRENTSCENECOMPONENT_HPP_ */
