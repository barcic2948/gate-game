#include "Button.h"

namespace gui {
    Button::Button() {
        s_button.setOutlineThickness(1);
        s_button.setOutlineColor(sf::Color::Cyan);
        s_button.setFillColor(sf::Color::Black);
        s_button.setSize({256, 64});
    }

    void Button::setFunction(std::function<void(void)> func) {
        s_function = func;
    }

    void Button::setText(const std::string& str) {
        s_text.setString(str);
        updateText();
    }

    void Button::setTexture(const sf::Texture& texture) {
        s_button.setTexture(&texture);
    }

    void Button::handleEvent(sf::Event e, const sf::RenderWindow& window) {
        auto pos = sf::Mouse::getPosition(window);

        s_button.setFillColor(s_button.isHover(window) ? sf::Color{27,27,27,220} : sf::Color::Black);
        
        switch (e.type) {
            case sf::Event::MouseButtonPressed:
                switch (e.mouseButton.button) {
                    case sf::Mouse::Left:
                        if (s_button.getGlobalBounds().contains((float)pos.x, (float)pos.y)) {
                            s_function();
                        }
                    default:
                        break;
                }
            default:
                break;
        }
    }

    void Button::render(sf::RenderTarget& renderer) {
        renderer.draw(s_button);
        renderer.draw(s_text);
    }

    void Button::setPosition(const sf::Vector2f& pos) {
        s_position = pos;
        s_button.setPosition(s_position);
        s_text.setPosition(s_position);

        updateText();
    }

    void Button::updateText() {
        s_text.setOrigin(s_text.getGlobalBounds().width / 2,
                         s_text.getGlobalBounds().height / 2);

        s_text.move(s_button.getGlobalBounds().width / 2.0f,
                    s_button.getGlobalBounds().height / 2.5f);
    }

    sf::Vector2f Button::getSize() const {
        return s_button.getSize();
    }
}