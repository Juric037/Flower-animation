#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include "Flower.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML is here!");
    window.setFramerateLimit(60);

    sf::Texture imageTexture;
    if (!imageTexture.loadFromFile("hqdefault.jpg")) {
        std::cerr << "Failed to load image.\n";
        return 1;
    }

    sf::Sprite imageSprite(imageTexture);
    imageSprite.setPosition(sf::Vector2f(200.f, 150.f));
    imageSprite.setScale(sf::Vector2f(0.5f, 0.5f));

    
    sf::Clock modeClock;
    float switchInterval = 3.0f;
    bool showingImage = false;


    Flower flower(&window);  

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {

            if (event->is<sf::Event::Closed>())
                window.close();
        }

      
        if (modeClock.getElapsedTime().asSeconds() > switchInterval) {
            showingImage = !showingImage;
            modeClock.restart();
        }

        window.clear();

        if (showingImage) {
            window.draw(imageSprite);
        }
        else {
            flower.update();
            flower.draw();
        }

        window.display();


        
    }

    return 0;
}