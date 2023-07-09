#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include <functional>
#include <iostream>

#include "Widget.h"

namespace gui {

    class Button : public gui::Widget {
        public:
            Button();

            void setFunction(std::function<void(void)> func);
            void setText(const std::string& str);
            void setTexture(const sf::Texture& texture);

            void handleEvent(sf::Event e, const sf::RenderWindow& window) override;
            void render(sf::RenderTarget& renderer) override;
            void setPosition(const sf::Vector2f& pos) override;
            sf::Vector2f getSize() const override;

        private:
            void updateText();

            sf::Vector2f s_position;

            Rectangle s_button;
            Text s_text;
            std::function<void(void)> s_function = []() {};
    };

    inline std::unique_ptr<Button> makeButton() {
        return std::make_unique<Button>();
    };
}

#endif