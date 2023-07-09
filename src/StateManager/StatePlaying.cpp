#include "StatePlaying.h"

StatePlaying::StatePlaying(Engine& game)
    : StateSlate(game)
    , s_resoultsMenu(game.getWindow(), 50)
{
    s_resoultsMenu.setTitle("HIGHSCORES");
    auto rez1 = gui::makeButton();
    auto rez2 = gui::makeButton();

    rez1->setText("Hello 1");
    rez2->setText("Hello 2");

    s_resoultsMenu.addWidget(std::move(rez1));
    s_resoultsMenu.addWidget(std::move(rez2));
}

void StatePlaying::handleEvent(sf::Event e) {
    s_resoultsMenu.handleEvent(e, s_Game->getWindow());
}

void StatePlaying::handleInput() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        s_Game->popState();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
        std::cout << "Button Pressed" << std::endl;
    }
}

void StatePlaying::update(sf::Time deltaTime) {
    float dt = deltaTime.asSeconds();
}

void StatePlaying::fixedUpdate(sf::Time deltaTime) {

}

void StatePlaying::render(sf::RenderTarget& renderer) {
    s_resoultsMenu.render(renderer);
}