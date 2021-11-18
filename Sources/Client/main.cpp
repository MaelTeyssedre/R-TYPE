/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** main
*/

#include <cstdlib>
#include <cstring>
#include <iostream>
#include "asio.hpp"
#include <SFML/Window.hpp>
#include "Registry.hpp"
#include "components.hpp"
#include "systems.hpp"

using asio::ip::tcp;

enum { max_length = 1024 };
/*
int main(int argc, char* argv[])
{
 /* try
  {
    if (argc != 3)
    {
      std::cerr << "Usage: blocking_tcp_echo_client <host> <port>\n";
      return 1;
    }

    asio::io_context io_context;

    tcp::socket s(io_context);
    tcp::resolver resolver(io_context);
    asio::connect(s, resolver.resolve(argv[1], argv[2]));
  
    /*std::cout << "Enter message: ";
    char request[max_length];
    std::cin.getline(request, max_length);
    size_t request_length = std::strlen(request);
    asio::write(s, asio::buffer(request, request_length));*/

   /* char reply[max_length];
    size_t reply_length = asio::read(s,
        asio::buffer(reply, 3));
    std::cout << "Reply is: ";
    std::cout.write(reply, reply_length);
    std::cout << "\n";
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }*/
/*
  return 0;
}*/

void init_mike(Registry &registry, sf::RenderWindow &window, size_t id)
{
    rtype::component::position_s* pos = new rtype::component::position_s {50, 50};
    rtype::component::velocity_s* vel = new rtype::component::velocity_s {1, 1};
    rtype::component::window_s* win = new rtype::component::window_s {&window};
    rtype::component::drawable_s* sprite = new rtype::component::drawable_s;
    sprite->texture.loadFromFile("ressources/mike.png");
    sprite->sprite.setTexture(sprite->texture, true);
    sprite->window = &window;
    sprite->sprite.setPosition(sf::Vector2f((float)pos->x, (float)pos->y));
    sprite->sprite.setScale((float)0.3, (float)0.3);
    rtype::component::controllable_s* ctrl = new rtype::component::controllable_s {true};
    rtype::component::size_s* size = new rtype::component::size_s {80, 90};
    rtype::component::current_scene_s* current_scene = new rtype::component::current_scene_s {rtype::constants::LOADING_MENU};
    rtype::component::entity_scene_s* entity_scene = new rtype::component::entity_scene_s {rtype::constants::MAIN_MENU};


    registry.addComponent<rtype::component::position_s>(registry.entityFromIndex(id), std::move(*pos));
    registry.addComponent<rtype::component::velocity_s>(registry.entityFromIndex(id), std::move(*vel));
    registry.addComponent<rtype::component::controllable_s>(registry.entityFromIndex(id), std::move(*ctrl));
    registry.addComponent<rtype::component::drawable_s>(registry.entityFromIndex(id), std::move(*sprite));
    registry.addComponent<rtype::component::size_s>(registry.entityFromIndex(id), std::move(*size));
    registry.addComponent<rtype::component::window_s>(registry.entityFromIndex(id), std::move(*win));
    registry.addComponent<rtype::component::current_scene_s>(registry.entityFromIndex(id), std::move(*current_scene));
    registry.addComponent<rtype::component::entity_scene_s>(registry.entityFromIndex(id), std::move(*entity_scene));
}

void init_load_screen(Registry &registry, sf::RenderWindow &window, size_t id_back)
{
    rtype::component::position_s* pos_back = new rtype::component::position_s {0, 0};
    rtype::component::size_s* size_back = new rtype::component::size_s {800, 600};
    rtype::component::window_s* win_back = new rtype::component::window_s {&window};
    rtype::component::drawable_s* sprite_back = new rtype::component::drawable_s;
    sprite_back->texture.loadFromFile("ressources/LoadingMenu.jpg");
    sprite_back->sprite.setTexture(sprite_back->texture, true);
    sprite_back->window = &window;
    sprite_back->sprite.setPosition(sf::Vector2f((float)pos_back->x, (float)pos_back->y));
    sprite_back->sprite.setScale((float)window.getSize().x / sprite_back->texture.getSize().x, (float)window.getSize().y / sprite_back->texture.getSize().y);
    rtype::component::controllable_s* ctrl_back = new rtype::component::controllable_s {false};
    rtype::component::current_scene_s* current_scene_back = new rtype::component::current_scene_s {rtype::constants::LOADING_MENU};
    rtype::component::entity_scene_s* entity_scene_back = new rtype::component::entity_scene_s {rtype::constants::LOADING_MENU};
    rtype::component::callback_s* callback_back = new rtype::component::callback_s {[](Registry &registry) -> void {
        SparseArray<rtype::component::current_scene_s> &current_scenes = registry.getComponents<rtype::component::current_scene_s>();
        for (size_t i = 0; i < current_scenes.size(); i++) {
            std::optional<rtype::component::current_scene_s> &current_scene = current_scenes[i];
            if (current_scene)
                current_scene.value().scene = rtype::constants::MAIN_MENU;
        }
    }};

    registry.addComponent<rtype::component::position_s>(registry.entityFromIndex(id_back), std::move(*pos_back));
    registry.addComponent<rtype::component::controllable_s>(registry.entityFromIndex(id_back), std::move(*ctrl_back));
    registry.addComponent<rtype::component::drawable_s>(registry.entityFromIndex(id_back), std::move(*sprite_back));
    registry.addComponent<rtype::component::callback_s>(registry.entityFromIndex(id_back), std::move(*callback_back));
    registry.addComponent<rtype::component::size_s>(registry.entityFromIndex(id_back), std::move(*size_back));
    registry.addComponent<rtype::component::window_s>(registry.entityFromIndex(id_back), std::move(*win_back));
    registry.addComponent<rtype::component::current_scene_s>(registry.entityFromIndex(id_back), std::move(*current_scene_back));
    registry.addComponent<rtype::component::entity_scene_s>(registry.entityFromIndex(id_back), std::move(*entity_scene_back));
}

void registerAllComponent(Registry &registry)
{
    registry.registerComponent<rtype::component::position_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<rtype::component::velocity_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<rtype::component::drawable_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<rtype::component::controllable_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<rtype::component::size_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<rtype::component::callback_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<rtype::component::window_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<rtype::component::entity_scene_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<rtype::component::current_scene_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
}


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");
    // * Registry
    Registry registry(0);
    
    size_t id_back = registry.spawnEntity();
    size_t id = registry.spawnEntity();
    

    // * RegisterComponent

    registerAllComponent(registry);

    /*
    registry.registerComponent<rtype::component::position_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<rtype::component::velocity_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<rtype::component::drawable_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<rtype::component::controllable_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<rtype::component::size_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<rtype::component::callback_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<rtype::component::window_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<rtype::component::entity_scene_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<rtype::component::current_scene_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    */
    // * Create and Add Component

    init_mike(registry, window, id);
    init_load_screen(registry, window, id_back);

    // * addSystem
    registry.addSystem(loggingSystem, registry.getComponents<rtype::component::position_s>(), registry.getComponents<rtype::component::velocity_s>());
    registry.addSystem(positionSystem, registry.getComponents<rtype::component::position_s>(), registry.getComponents<rtype::component::drawable_s>(), registry.getComponents<rtype::component::current_scene_s>(),  registry.getComponents<rtype::component::entity_scene_s>());
    registry.addSystem(controlSystem, registry.getComponents<rtype::component::position_s>(), registry.getComponents<rtype::component::velocity_s>(), registry.getComponents<rtype::component::controllable_s>(), registry.getComponents<rtype::component::current_scene_s>(),  registry.getComponents<rtype::component::entity_scene_s>());
    registry.addSystem(drawSystem, registry.getComponents<rtype::component::drawable_s>(), registry.getComponents<rtype::component::current_scene_s>(),  registry.getComponents<rtype::component::entity_scene_s>());
    registry.addSystem(clickSystem, registry.getComponents<rtype::component::position_s>(), registry.getComponents<rtype::component::size_s>(), registry.getComponents<rtype::component::callback_s>(), registry.getComponents<rtype::component::window_s>(), registry.getComponents<rtype::component::current_scene_s>(),  registry.getComponents<rtype::component::entity_scene_s>());
    // * mainLoop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        window.clear(sf::Color::Black);
        registry.run_system();
        window.display();
    }
    return 0;
}