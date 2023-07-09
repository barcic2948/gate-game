#pragma once

#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include <SFML/Graphics.hpp>
#include "../ResourceManager/ResourceHolder.h"

class FPSCounter {
    private:
        sf::Text s_text;
        sf::Font s_font;

        sf::Clock s_delayT, s_fpsT;

        float s_fps = 0;
        int s_frameCnt = 0;

    public:
        FPSCounter();
        void update();
        void draw(sf::RenderTarget& renderer);
};

#endif