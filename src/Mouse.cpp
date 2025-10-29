#include "Mouse.hpp"

void Mouse::update(sf::RenderWindow& window) {
    //update position
    position = sf::Vector2f(sf::Mouse::getPosition(window));

    //update state
    onPress    = 0;
    onRelease = 0;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        if (!isPressed){
            onPress = 1;
        }
        isPressed = 1;
    }
    else{
        if (isPressed){
            onRelease = 1;
        }
        isPressed = 0;
    }
}