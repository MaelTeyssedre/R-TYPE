#include <SFML/Window.hpp>
#include "Registry.hpp"
#include "components.hpp"

int main() {
    sf::Window window(sf::VideoMode(800, 600), "My Window");

    Registry registry(10);

    component::position_s pos = {50, 50};
    std::function<void(Registry &, Entity const &)> PosCreator = [](Registry &reg, Entity const &e){
        SparseArray<component::position_s> array = reg.getComponents<component::position_s>();
        array.insertAt(array.size(), std::nullopt);
    };
    std::function<void(Registry &, Entity const &)> PosDestructor = [](Registry &reg, Entity const &e){
        SparseArray<component::position_s> array = reg.getComponents<component::position_s>();
        array.insertAt(e, std::nullopt);
    };

    component::velocity_s vel = {10, 10};
    std::function<void(Registry &, Entity const &)> VelCreator = [](Registry &reg, Entity const &e){
        SparseArray<component::velocity_s> array = reg.getComponents<component::velocity_s>();
        array.insertAt(array.size(), std::nullopt);
    };
    std::function<void(Registry &, Entity const &)> VelDestructor = [](Registry &reg, Entity const &e){
        SparseArray<component::velocity_s> array = reg.getComponents<component::velocity_s>();
        array.insertAt(e, std::nullopt);
    };

    component::drawable_s sprite;
    sprite.texture.loadFromFile("canard.png");
    sprite.sprite.setTexture(sprite.texture, true);
    std::function<void(Registry &, Entity const &)> SpriteCreator = [](Registry &reg, Entity const &e){
        SparseArray<component::drawable_s> array = reg.getComponents<component::drawable_s>();
        array.insertAt(array.size(), std::nullopt);
    };
    std::function<void(Registry &, Entity const &)> SpriteDestructor = [](Registry &reg, Entity const &e){
        SparseArray<component::drawable_s> array = reg.getComponents<component::drawable_s>();
        array.insertAt(e, std::nullopt);
    };
    SparseArray<component::position_s> pos_component = registry.registerComponent<component::position_s>(PosCreator, PosDestructor);
    SparseArray<component::velocity_s> vel_component = registry.registerComponent<component::velocity_s>(VelCreator, VelDestructor);
    SparseArray<component::drawable_s> draw_component = registry.registerComponent<component::drawable_s>(SpriteCreator, SpriteDestructor);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
    }
    return 0;
}
