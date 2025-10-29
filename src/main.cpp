#include <SFML/Graphics.hpp>
#include "Mouse.hpp"
#include "Key.hpp"
#include "Button.hpp"
#include <string>

int main(){

    sf::ContextSettings setting;
    setting.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({400, 600}), "Counter", sf::State::Windowed, setting);
    
    //font load
    sf::Font font("assets/fonts/Monocraft.ttc");
    
    //counter
    int count = 0;
    sf::Text text(font);

    Mouse mouse;

    //Increase
    Button button1(font);
    button1.string = "+";
    Key key1(sf::Keyboard::Scan::Equal, Key::ModifierState::Required);
    
    //Decrease
    Button button2(font);
    button2.string = "-";
    Key key2(sf::Keyboard::Scan::Hyphen);
    
    //Reset
    Button button3(font);
    button3.string = "reset";
    Key key3(sf::Keyboard::Scancode::R);


    while (window.isOpen()){
        // handle event
        while (auto event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window.close();
                break;
            }
            if (event->is<sf::Event::Resized>()){
                sf::View view(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                window.setView(view);
            }
        }

        // background color
        window.clear(sf::Color(64, 64, 64));

        // window size
        float window_w = window.getSize().x;        
        float window_h = window.getSize().y;        

        //update mouse:
        mouse.update(window);
        key1.update();
        key2.update();
        key3.update();

        //update button:
        button1.update(mouse, key1);
        button2.update(mouse, key2);
        button3.update(mouse, key3);

        //on button release
        if (button1.onRelease && count < 999) ++count;
        if (button2.onRelease && count > 0) --count;
        if (button3.onRelease) count = 0;

        //text
        text.setString(std::to_string(count));
        text.setCharacterSize(window_h/4);
        alignText(text, 0.5f, 0.6f);
        text.setPosition({window_w/2, window_h/6});

        //draw
        float space = 10.f;

        button1.size = {window_w/2 - space, window_h/3 - space};
        button2.size = {window_w/2 - space, window_h/3 - space};
        button3.size = {window_w   - space, window_h/3 - space};

        button1.position = {window_w/4  , window_h/2};
        button2.position = {window_w*3/4, window_h/2};
        button3.position = {window_w/2  , window_h*5/6};

        button1.draw(window);
        button2.draw(window);
        button3.draw(window);

        window.draw(text);

        // display
        window.display();
    }
    
    return 0;
}