#pragma once

#ifndef GUIELEMENT_H
#define GUIELEMENT_H

#include "../ResourceManager/ResourceHolder.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace gui {
    class GuiElement {
        public: 
            virtual void handleEvent(sf::Event e, const sf::RenderWindow& window) = 0;
            virtual void render(sf::RenderTarget& renderer) = 0;
    };
}

#endif