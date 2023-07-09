#pragma once

#ifndef STATESLATE_H
#define STATESLATE_H

#include <SFML/Graphics.hpp>

#include "../Utils/NonCopyable.h"

class Engine;

class StateSlate : public NonCopyable {

    protected:
        Engine* s_Game;

    public:
        StateSlate(Engine& game)
            : s_Game(&game) {};

        virtual ~StateSlate() = default;

        virtual void handleEvent(sf::Event) {}
        virtual void handleInput() = 0;
        virtual void update(sf::Time deltaTime) {}
        virtual void fixedUpdate(sf::Time deltaTime) {}
        virtual void render(sf::RenderTarget& renderer) = 0;
};

#endif