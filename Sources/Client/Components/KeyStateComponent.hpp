
#ifndef KEYSTATECOMPONENT_HPP_
    #define KEYSTATECOMPONENT_HPP_

    #include <iostream>

    namespace rtype {
        namespace components {
            struct keyState_s {
                bool keyUp;
                bool keyDown;
                bool keyRight;
                bool keyLeft;
                bool keyEnter;
                bool keySpace;
            };
        }
    }

#endif /* !KEYSTATECOMPONENT_HPP_ */
