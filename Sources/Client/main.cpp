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

void callback_back()
{
    std::cout << "Click on Background" << std::endl;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");
    // * Registry
    Registry registry(0);
    // * Components creation
    component::position_s pos {50, 50};
    component::velocity_s vel {1, 1};
    component::drawable_s sprite;
    sprite.texture.loadFromFile("mike.png");
    sprite.sprite.setTexture(sprite.texture, true);
    sprite.window = &window;
    sprite.sprite.setPosition(sf::Vector2f((float)pos.x, (float)pos.y));
    sprite.sprite.setScale((float)0.3, (float)0.3);
    component::controllable_s ctrl {true};
    component::size_s size {800, 600};
    component::window_s win {&window};
    
    component::position_s pos_back {0, 0};
    component::drawable_s sprite_back;
    sprite_back.texture.loadFromFile("mike.png");
    sprite_back.sprite.setTexture(sprite_back.texture, true);
    sprite_back.window = &window;
    sprite_back.sprite.setPosition(sf::Vector2f((float)pos_back.x, (float)pos_back.y));
    sprite_back.sprite.setScale((float)window.getSize().x / sprite_back.texture.getSize().x, (float)window.getSize().y / sprite_back.texture.getSize().y);
    component::controllable_s ctrl_back {false};
    //component::callback_s callback_back;
    //callback_back.Callback = &callback_back;


    size_t id_back = registry.spawnEntity();
    size_t id = registry.spawnEntity();

    // * RegisterComponent
    registry.registerComponent<component::position_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<component::velocity_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<component::drawable_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<component::controllable_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    registry.registerComponent<component::size_s>([](Registry &, Entity const &) -> void {}, [](Registry &, Entity const &) -> void {});
    // * AddComponent
    registry.addComponent<component::position_s>(registry.entityFromIndex(id), std::move(pos));
    registry.addComponent<component::velocity_s>(registry.entityFromIndex(id), std::move(vel));
    registry.addComponent<component::controllable_s>(registry.entityFromIndex(id), std::move(ctrl));
    registry.addComponent<component::drawable_s>(registry.entityFromIndex(id), std::move(sprite));
    registry.addComponent<component::size_s>(registry.entityFromIndex(id), std::move(size));
    //registry.addComponent<component::window_s>(registry.entityFromIndex(id), std::move(win));

    registry.addComponent<component::position_s>(registry.entityFromIndex(id_back), std::move(pos_back));
    registry.addComponent<component::controllable_s>(registry.entityFromIndex(id_back), std::move(ctrl_back));
    registry.addComponent<component::drawable_s>(registry.entityFromIndex(id_back), std::move(sprite_back));
    // * addSystem
    registry.addSystem(loggingSystem, registry.getComponents<component::position_s>(), registry.getComponents<component::velocity_s>());
    registry.addSystem(positionSystem, registry.getComponents<component::position_s>(), registry.getComponents<component::drawable_s>());
    registry.addSystem(controlSystem, registry.getComponents<component::position_s>(), registry.getComponents<component::velocity_s>(), registry.getComponents<component::controllable_s>());
    registry.addSystem(drawSystem, registry.getComponents<component::drawable_s>());
    registry.addSystem(clickSystem, registry.getComponents<component::position_s>(), registry.getComponents<component::size_s>()/*, registry.getComponents<component::window_s>()*/);
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