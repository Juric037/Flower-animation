#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Angle.hpp>

class Flower {
private:
    sf::RenderWindow* window;

    sf::Vector2f position = sf::Vector2f(350.f, 250.f); // main flower position

    sf::CircleShape center;
    sf::RectangleShape stem;
    sf::CircleShape leaf;

    float scaleFactor = 1.0f;
    bool growing = true;

public:
    Flower(sf::RenderWindow* win) : window(win) {
        // Center 
        center.setRadius(50.f);
        center.setFillColor(sf::Color::Yellow);
        center.setOutlineThickness(50.f);
        center.setOutlineColor(sf::Color::Blue);
        center.setOrigin(sf::Vector2f(50.f, 50.f)); 
        center.setPosition(position);

        // Stem
        stem.setSize(sf::Vector2f(20.f, 150.f));
        stem.setFillColor(sf::Color(34, 139, 34));
        stem.setOrigin(sf::Vector2f(10.f, 0.f)); 
        stem.setPosition(position + sf::Vector2f(0.f, 100.f));

        // Leaf
        leaf.setRadius(30.f);
        leaf.setPointCount(60);
        leaf.setFillColor(sf::Color(0, 128, 0));
        leaf.setOrigin(sf::Vector2f(30.f, 30.f)); 
        leaf.setScale(sf::Vector2f(1.5f, 0.5f));
        leaf.setRotation(sf::degrees(-45.f));
        leaf.setPosition(position + sf::Vector2f(-40.f, 130.f));
    }

    void update() {
        if (growing) {
            scaleFactor += 0.005f;
            if (scaleFactor >= 1.05f)
                growing = false;
        }
        else {
            scaleFactor -= 0.005f;
            if (scaleFactor <= 0.95f)
                growing = true;
        }

        
        center.setScale(sf::Vector2f(scaleFactor, scaleFactor));
        stem.setScale(sf::Vector2f(scaleFactor, scaleFactor));
        leaf.setScale(sf::Vector2f(1.5f * scaleFactor, 0.5f * scaleFactor)); 
    }

    void draw() {
        if (!window) return;

        window->draw(stem);
        window->draw(leaf);
        window->draw(center);
    }
};
