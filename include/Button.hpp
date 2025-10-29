#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Mouse.hpp"
#include "Key.hpp"

void alignText(sf::Text &text, float horizontal, float vertical);

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;

public:
    sf::Vector2f size         = {200.f, 100.f};
    sf::Vector2f position     = {0.f,  0.f};
    std::string  string       = "Hello";
    float        text_scale   = 0.5f;
    float        text_align_v = 0.6f;

    bool isOver          = false;
    bool isPressed       = false;
    bool isPressedInside = false;
    bool onPress         = false;
    bool onRelease       = false;

    sf::Color default_shape = sf::Color(0, 170, 255);
    sf::Color default_text  = sf::Color::White;
    sf::Color over_shape    = default_text;
    sf::Color over_text     = default_shape;
    sf::Color pressed_shape = sf::Color(64, 64, 127);
    sf::Color pressed_text  = sf::Color::White;

    Button(const sf::Font &font);

    void update(Mouse &mouse, Key key);
    void draw(sf::RenderWindow& window);
};
