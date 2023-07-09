#pragma once

#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "Utils/NonMoveable.h"
#include "Utils/NonCopyable.h"
#include "Utils/FPSCounter.h"
#include "Utils/FileUtil.h"

#include "StateManager/StateSlate.h"
#include "StateManager/StatePlaying.h"
#include "ResourceManager/ResourceHolder.h"



class Engine : public NonCopyable, public NonMovable {
    private:
        void handleEvent();
        void tryPop();

        StateSlate& getCurrentState();
        sf::RenderWindow s_window;
        std::vector<std::unique_ptr<StateSlate>> s_states;

        FPSCounter counter;

        bool s_doPop            = false;
        bool s_doExit           = false;
        bool s_doChangeState    = false;
        std::unique_ptr<StateSlate> s_change;

        //Time stuff
        const unsigned TPS = 20;
        const sf::Time TPU = sf::seconds(1.0f / float(TPS));
        sf::Clock timer;
        sf::Time LastTime = sf::Time::Zero;
        sf::Time lag = sf::Time::Zero;
        sf::Time time;
        sf::Time elapsed;

        unsigned ticks = 0;
        
        void handleTime();

    public:
    
        Engine();

        void run();

        void pushState(std::unique_ptr<StateSlate> state);

        void changeState(std::unique_ptr<StateSlate> state);

        void popState();

        void exitEngine();

        const sf::RenderWindow& getWindow() const;
};

#endif