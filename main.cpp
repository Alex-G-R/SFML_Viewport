#include <iostream>

#include <Graphics.hpp>
#include <System.hpp>
#include <Window.hpp>
#include <Audio.hpp>
#include <Network.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Works!", sf::Style::Default);
    window.setFramerateLimit(120);

    sf::View mainView;
    mainView.setSize(1920, 1080);
    float viewZoom = 1.f;


    sf::RectangleShape player;
    player.setSize(sf::Vector2f(50.f, 50.f));
    player.setPosition(500.f, 500.f);

    sf::RectangleShape object;
    object.setSize(sf::Vector2f(50.f, 50.f));
    object.setPosition(500.f, 500.f);
    object.setFillColor(sf::Color::Red);

    sf::RectangleShape UIElement;
    UIElement.setSize(sf::Vector2f(200.f, 50.f));
    UIElement.setFillColor(sf::Color::Red);


    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            // Zoom in and out
            if (event.type == sf::Event::MouseWheelMoved)
            {
                mainView.zoom(viewZoom - event.mouseWheel.delta*0.05);
            }
        }

        // Update
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            player.move(-5.f, 0.f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            player.move(5.f, 0.f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            player.move(0.f, -5.f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            player.move(0.f, 5.f);

        // Camera movment
        mainView.setCenter(player.getPosition()); // Follow the player

        // Rotate the camera
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            mainView.setRotation(mainView.getRotation()+1.f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            mainView.setRotation(mainView.getRotation()-1.f);




        // Draw
        window.clear();

        // Draw stuff
        window.setView(mainView);
        window.draw(player);
        window.draw(object);


        // Draw UI -> Go back to defualt view
        window.setView(window.getDefaultView());
        window.draw(UIElement);


        window.display();

    }

    return 0;
}

