#pragma once

#ifndef WIDGET_H
#define WIDGET_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "../ResourceManager/ResourceHolder.h"
#include "GuiElement.h"

namespace gui {
    class Widget : public GuiElement {
        public:
            virtual void setPosition(const sf::Vector2f& pos) = 0;
            virtual sf::Vector2f getSize() const = 0;

            class Text : public sf::Text {
                public:
                    Text();
            };

            class Rectangle : public sf::RectangleShape {
                public:
                    bool isHover(const sf::RenderWindow& window) const;
                    bool isClicked(sf::Event e, const sf::RenderWindow& window);
            };
    };
}
#endif