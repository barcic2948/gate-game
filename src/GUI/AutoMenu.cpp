#include "AutoMenu.h"

namespace gui {
    AutoMenu::AutoMenu(const sf::RenderWindow& window, float baseY)
        : s_basePosition((float)window.getSize().x / 2.0f, baseY)
        , s_baseSize(300, paddingTop) 
    {
        s_background.setOutlineThickness(2);
        s_background.setOutlineColor(sf::Color::Cyan);
        s_background.setFillColor({27,27,27,220});
        s_background.setSize(s_baseSize);
        s_background.setPosition(s_basePosition.x - s_baseSize.x / 2, baseY - paddingTop/2);

        s_titleText.setPosition(0, baseY - paddingTop);
        s_titleText.setOutlineColor(sf::Color::Black);
        s_titleText.setOutlineThickness(1);
        s_titleText.setCharacterSize(42);
    }

    void AutoMenu::addWidget(std::unique_ptr<Widget> w) {
        initWidget(*w);
        s_widgets.push_back(std::move(w));
    }

    void AutoMenu::initWidget(Widget& widget) {
        widget.setPosition({s_basePosition.x - widget.getSize().x / 2, s_basePosition.y});

        s_basePosition.y += widget.getSize().y + spacing;
        s_baseSize.y += widget.getSize().y + spacing;
        s_background.setSize(s_baseSize);
    }

    void AutoMenu::setTitle(const std::string& title) {
        s_titleText.setString(title);
        s_titleText.setPosition(s_background.getPosition().x + s_background.getSize().x / 2 - 
                                s_titleText.getGlobalBounds().width / 2,
                                s_titleText.getPosition().y + paddingTop);

        s_basePosition.y += s_titleText.getGlobalBounds().height + paddingTop;
        s_baseSize.y += s_titleText.getGlobalBounds().height + paddingTop / 2;
        s_background.setSize(s_baseSize);
    }

    void AutoMenu::handleEvent(sf::Event e, const sf::RenderWindow& window) {
        for (auto& widget : s_widgets) {
            widget->handleEvent(e, window);
        }
    }

    void AutoMenu::render(sf::RenderTarget& renderer) {
        renderer.draw(s_background);
        renderer.draw(s_titleText);
        for (auto& widget : s_widgets) {
            widget->render(renderer);
        }
    }

    const sf::RenderWindow& AutoMenu::getWindow() const {
        return *s_pWindow;
    }
}