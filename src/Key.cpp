#include "Key.hpp"

void Key::update() {
    onPress = false;
    onRelease = false;

    bool shiftDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) ||
                        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift);
    
    bool ctrlDown  = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) ||
                        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl);
                        
    bool altDown   = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LAlt) ||
                        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RAlt);

    bool mainKeyDown = sf::Keyboard::isKeyPressed(key);


    bool shiftOk = (shift == ModifierState::Ignore) ||
                    (shift == ModifierState::Required && shiftDown) ||
                    (shift == ModifierState::Forbidden && !shiftDown);

    bool ctrlOk  = (control == ModifierState::Ignore) ||
                    (control == ModifierState::Required && ctrlDown) ||
                    (control == ModifierState::Forbidden && !ctrlDown);
                    
    bool altOk   = (alt == ModifierState::Ignore) ||
                    (alt == ModifierState::Required && altDown) ||
                    (alt == ModifierState::Forbidden && !altDown);


    bool allConditionsMet = mainKeyDown && shiftOk && ctrlOk && altOk;

    if (allConditionsMet) {
        if (!isPressed) {
            onPress = true;
        }
        isPressed = true;
    } else {
        if (isPressed) {
            onRelease = true;
        }
        isPressed = false;
    }
}