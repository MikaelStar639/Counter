#pragma once
#include <SFML/Graphics.hpp>

class Mouse{
    public:
    //position
    sf::Vector2f position;

    //state
    bool isPressed  = 0;
    bool onPress    = 0;
    bool onRelease = 0;

    
    //function - update State
    void update(sf::RenderWindow& window);
};
