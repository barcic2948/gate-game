#pragma once

#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceManager.h"
#include "../Utils/NonCopyable.h"
#include "../Utils/NonMoveable.h"

class ResourceHolder : public NonCopyable, public NonMovable {
    private:
        ResourceHolder();

    public:
        static ResourceHolder& get();

        ResourceManager<sf::Font> fonts;
        ResourceManager<sf::Texture> textures;
        ResourceManager<sf::SoundBuffer> soundBuffers;
};

#endif