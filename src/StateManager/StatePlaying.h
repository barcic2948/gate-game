#pragma once

#ifndef STATEPLAYING_H
#define STATEPLAYING_H

#include "StateSlate.h"
#include "../Engine.h"
#include "../GUI/AutoMenu.h"
#include "../GUI/Button.h"

#include <iostream>

class StatePlaying : public StateSlate {

    private:
        gui::AutoMenu s_resoultsMenu;

    public:
        StatePlaying(Engine& game);

        void handleEvent(sf::Event e) override;
        void handleInput() override;
        void update(sf::Time deltaTime) override;
        void fixedUpdate(sf::Time deltaTime) override;
        void render(sf::RenderTarget& renderer) override;
};

#endif