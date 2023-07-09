#include "Engine.h"

Engine::Engine()
    : s_window({1000, 800}, "SPACE SHOOTER") 
{
    s_window.setPosition({s_window.getPosition().x, 0});
    s_window.setFramerateLimit(60);
    pushState(std::make_unique<StatePlaying>(*this));

}


void Engine::run() {

    while (s_window.isOpen() && !s_states.empty()) {
        auto& state = getCurrentState();

        //Handle Time
        handleTime();

        //Real time update -> priority/reading input
        state.handleInput();
        state.update(elapsed);
        counter.update();
        
        //Fixed time update -> Actual update of game elements
        while (lag >= TPU) {
            ticks++;
            lag -= TPU;
            state.fixedUpdate(elapsed);
        }

        //Rendering 
        s_window.clear();
        state.render(s_window);
        counter.draw(s_window);
        s_window.display();

        handleEvent();
        tryPop();
    }
}

void Engine::handleTime() {
    time = timer.getElapsedTime();
    elapsed = time - LastTime;
    LastTime = time;
    lag += elapsed;
}

void Engine::tryPop() {
    if(s_doPop) {
        s_doPop = false;
        if (s_doExit) {
            s_states.clear();
            return;
        }
        else if (s_doChangeState) {
            s_doChangeState = false;
            s_states.pop_back();
            pushState(std::move(s_change));
            return;
        }
        s_states.pop_back();
    }
}


void Engine::handleEvent() {
    sf::Event e;

    while(s_window.pollEvent(e)) {
        getCurrentState().handleEvent(e);
        switch (e.type) {
            case sf::Event::Closed:
                s_window.close();
                break;
            default:
                break;
        }
    }
}

StateSlate& Engine::getCurrentState() { return *s_states.back(); }

void Engine::pushState(std::unique_ptr<StateSlate> state) { s_states.push_back(std::move(state)); }

void Engine::changeState(std::unique_ptr<StateSlate> state) {
    s_change = std::move(state);
    s_doPop = true;
    s_doChangeState = true;
}


void Engine::popState() { s_doPop = true; }

void Engine::exitEngine() { s_doPop = true; s_doExit = true; }

const sf::RenderWindow& Engine::getWindow() const { return s_window; }
