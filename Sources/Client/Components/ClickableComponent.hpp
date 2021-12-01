#ifndef CLICKABLECOMPONENT_HPP_
    #define CLICKABLECOMPONENT_HPP_

    namespace rtype
    {
        namespace components {
            struct clickable_s {
                bool isPressed;
                bool prevState;
                std::function<void(Registry &r, size_t index)> callbackClick;
                std::function<void(Registry &r, size_t index)> callbackReleased;
            };
        }   
    }
    
#endif /* !CLICKABLECOMPONENT_HPP_ */
