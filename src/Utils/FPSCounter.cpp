#include "FPSCounter.h"

FPSCounter::FPSCounter() {
    s_text.move(0,0);
    s_text.setOutlineColor(sf::Color::Black);
    s_text.setFillColor({255,255,255});
    s_text.setOutlineThickness(2);
    s_text.setFont(ResourceHolder::get().fonts.get("arial"));
    s_text.setCharacterSize(15);
}

void FPSCounter::update() {
    s_frameCnt++;
    if(s_delayT.getElapsedTime().asSeconds() > 0.2f) {
        s_fps = s_frameCnt / s_fpsT.restart().asSeconds();
        s_frameCnt = 0;
        s_delayT.restart();
    }
}

void FPSCounter::draw(sf::RenderTarget& renderer) {
    s_text.setString("FPS " + std::to_string((int)s_fps));
    renderer.draw(s_text);
}