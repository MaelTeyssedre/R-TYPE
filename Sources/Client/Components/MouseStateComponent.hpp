/**
 * \file MouseStateComponent.hpp
 * 
 * \brief file for the mouse state component 
 */
#ifndef MOUSESTATECOMPONENT_HPP_
    #define MOUSESTATECOMPONENT_HPP_

    #include <iostream>

    namespace rtype {
        namespace components {
            struct mouseState_s {
                int mousePosX;
                int mousePosY;
                bool mouseRightClick;
                bool mouseLeftClick;
            };
        }
    }

#endif /* !MOUSESTATECOMPONENT_HPP_ */
