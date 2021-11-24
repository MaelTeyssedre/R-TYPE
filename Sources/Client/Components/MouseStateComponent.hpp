
#ifndef MOUSESTATECOMPONENT_HPP_
    #define MOUSESTATECOMPONENT_HPP_

    #include <iostream>

    namespace components {
        typedef struct mouseState_s {
            int mousePosX;
            int mousePosY;
            bool mouseRightClick;
            bool mouseLeftClick;
        } mouseState_t;
    }

#endif /* !MOUSESTATECOMPONENT_HPP_ */
