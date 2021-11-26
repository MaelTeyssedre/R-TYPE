
#ifndef MOUSESTATECOMPONENT_HPP_
    #define MOUSESTATECOMPONENT_HPP_

    #include <iostream>

    namespace components {
        struct mouseState_s {
            int mousePosX;
            int mousePosY;
            bool mouseRightClick;
            bool mouseLeftClick;
        };
    }

#endif /* !MOUSESTATECOMPONENT_HPP_ */
