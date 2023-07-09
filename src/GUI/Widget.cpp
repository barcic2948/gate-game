#include "Widget.h"

namespace gui {
    Widget::Text::Text() {
        setCharacterSize(25);
        setOutlineColor(sf::Color::Black);
        setFillColor(sf::Color::White);
        setFont(ResourceHolder::get().fonts.get("arial"));
    }

    bool Widget::Rectangle::isHover(const sf::RenderWindow& window) const {
        auto pos = sf::Mouse::getPosition(window);
        return getGlobalBounds().contains((float)pos.x, (float)pos.y);
    }

    bool Widget::Rectangle::isClicked(sf::Event e, const sf::RenderWindow& window) {
        if (isHover(window)) {
            if(e.type == sf::Event::MouseButtonPressed) {
                return e.mouseButton.button == sf::Mouse::Left;
            }
        }
        return false;
    }
}