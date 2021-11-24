
#ifndef KEYSTATECOMPONENT_HPP_
    #define KEYSTATECOMPONENT_HPP_

    #include <iostream>

    namespace components {
        typedef struct keyState_s {
            bool keyUp;
            bool keyDown;
            bool keyRight;
            bool keyLeft;
            bool keyEnter;
            bool keySpace;
        } keyState_t;
    }

#endif /* !KEYSTATECOMPONENT_HPP_ */
