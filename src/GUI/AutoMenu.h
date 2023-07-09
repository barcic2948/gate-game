#pragma once 

#ifndef STACKMENU_H
#define STACKMENU_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "../Utils/NonCopyable.h"
#include "../ResourceManager/ResourceHolder.h"
#include "Widget.h"

namespace gui {
    class AutoMenu : public NonCopyable {
        public:
            AutoMenu(const sf::RenderWindow& window, float baseY);

            ~AutoMenu() = default;

            void addWidget(std::unique_ptr<Widget> w);

            void setTitle(const std::string& title);

            void handleEvent(sf::Event e, const sf::RenderWindow& widnow);
            void render(sf::RenderTarget& renderer);

        private:

            const float paddingTop = 50.0;
            const float spacing = 30.0;

            const sf::RenderWindow& getWindow() const;

            void initWidget(Widget& w);
            const sf::RenderWindow* s_pWindow;

            std::vector<std::unique_ptr<Widget>> s_widgets;
            sf::RectangleShape s_background;

            sf::Vector2f s_basePosition;
            sf::Vector2f s_baseSize;

            Widget::Text s_titleText;
    };
} 

#endif