#pragma once

#ifndef CUSTOMTEXT_H
#define CUSTOMTEXT_H

#include "Widget.h"


namespace gui {

    enum class TextSize {
        Small,
        Medium,
        Big
    };


    class CustomText : public gui::GuiElement, public sf::Text {

        public: 
            CustomText(TextSize s);
            void render(sf::RenderTarget& renderer) override;


        private:

    };

    inline std::unique_ptr<CustomText> makeCustomText() {
        return std::make_unique(CustomText)(TextSize s);
    };
}

#endif