#include "Button.hpp"

void alignText(sf::Text &text, float horizontal, float vertical){
    sf::FloatRect bounds = text.getLocalBounds();

    float x = bounds.position.x + bounds.size.x * horizontal;
    float y = text.getCharacterSize() * vertical;

    text.setOrigin({x, y});
}

Button::Button(const sf::Font &font) : text(font) {}

//update states
void Button::update(Mouse &mouse, Key key){
    onPress   = 0;
    onRelease = 0;

    //mouse
    if (shape.getGlobalBounds().contains(mouse.position)){
        if (mouse.onPress){
            onPress = 1;
            isPressedInside = 1;
        }
        if (mouse.onRelease && isPressedInside){
            onRelease = 1;
        }
        if (mouse.isPressed && isPressedInside){
            isPressed = 1;
        }
        isOver = 1;
    }
    else{
        isOver    = 0;
        isPressed = 0;
    }
    
    if (!mouse.isPressed){
        isPressed       = 0;
        isPressedInside = 0;
    }

    //key
    if (key.isPressed){
        isPressed = 1;
    }

    if (key.onRelease){
        onRelease = 1;
    }
}

//draw
void Button::draw(sf::RenderWindow& window){

    //shape
    shape.setSize(size);
    shape.setOrigin(shape.getGeometricCenter());
    shape.setPosition(position);
    window.draw(shape);

    //text
    text.setString(string);
    text.setCharacterSize(size.y * text_scale);
    text.setPosition(position);
    alignText(text, 0.5f, text_align_v);

    //color
    if (isPressed){
        shape.setFillColor(pressed_shape);
        text.setFillColor(pressed_text);
    }
    else if (isOver){
        shape.setFillColor(over_shape);
        text.setFillColor(over_text);
    }
    else{
        shape.setFillColor(default_shape);
        text.setFillColor(default_text);
    }

    window.draw(text);
}
