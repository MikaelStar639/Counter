#pragma once
#include <SFML/Graphics.hpp>

class Key {
public:
    enum class ModifierState {
        Ignore,    
        Required,  
        Forbidden  
    };

    //key
    sf::Keyboard::Scancode key;
    
    //require
    ModifierState shift     = ModifierState::Ignore;
    ModifierState control   = ModifierState::Ignore;
    ModifierState alt       = ModifierState::Ignore;

    //State
    bool isPressed = false;
    bool onPress = false;
    bool onRelease = false;

    //Constructors
    Key() = default;
    Key(sf::Keyboard::Scancode k) : key(k) {}
    Key(sf::Keyboard::Scancode k, 
        ModifierState reqShift, 
        ModifierState reqControl = ModifierState::Ignore, 
        ModifierState reqAlt = ModifierState::Ignore)
        : key(k), shift(reqShift), control(reqControl), alt(reqAlt) {}


    void update();
};
