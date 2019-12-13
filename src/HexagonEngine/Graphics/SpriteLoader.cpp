/*
        +---------------------------------------------------------+
        | Hexagon Game Engine                                     |
        | Copyright (c) 2019 Felix Eckert                         |
        | This Project is licensed under the 4-Clause-BSD license!|
        +---------------------------------------------------------+

        Copyright (c) 2019, Felix Eckert
        All rights reserved.

        Redistribution and use in source and binary forms, with or without
        modification, are permitted provided that the following conditions are met:
        1. Redistributions of source code must retain the above copyright
           notice, this list of conditions and the following disclaimer.
        2. Redistributions in binary form must reproduce the above copyright
           notice, this list of conditions and the following disclaimer in the
           documentation and/or other materials provided with the distribution.
        3. All advertising materials mentioning features or use of this software
           must display the following acknowledgement:
           This product includes software developed by the SFML-team.
        4. Neither the name of the HexagonEngine-team nor the
           names of its contributors may be used to endorse or promote products
           derived from this software without specific prior written permission.

        THIS SOFTWARE IS PROVIDED BY HexagonEngine-team "AS IS" AND ANY
        EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
        WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
        DISCLAIMED. IN NO EVENT SHALL HexagonEngine-team BE LIABLE FOR ANY
        DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
        (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
        LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
        ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
        (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
        SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Contributors to this File:
    - Felix Eckert (Original Author)
*/

#include "SpriteLoader.hpp"
#include <iostream>

using namespace std;
using namespace Hexagon;

string SpriteLoader::ResourceLocation;
std::vector<sf::Sprite*>* SpriteLoader::sprites;

// Constructor for Spriteloader class
SpriteLoader::SpriteLoader(string ResourceLocation) {
    if (sprites == NULL) {
        sprites = new std::vector<sf::Sprite*>();
    }

    InitSpriteLoader(ResourceLocation);
}

// Deconstructor for Spriteloader class
SpriteLoader::~SpriteLoader() {
    delete sprites;
}

// Initialization Method
void SpriteLoader::InitSpriteLoader(string ResourceLocation) {
    cout << "HE: SpriteLoader: Initializing..." << endl;

    SpriteLoader::ResourceLocation = ResourceLocation;
}

// Method for loading/creating a Sprite
void SpriteLoader::LoadSprite(string name, int RectSizeX, int RectSizeY, int RectLocX, int RectLocY, bool SmoothTexture, bool SetRepeated) {
    cout << "HE: SpriteLoader: Loading sprite " << name << endl;

    sf::Texture* texture = LoadTexture(name, RectSizeX, RectSizeY, RectLocX, RectLocY); // Load Texture

    texture->setSmooth(SmoothTexture); // Set texture smoothing
    texture->setRepeated(SetRepeated); // Set texture repeating

    sf::Sprite* sprite = new sf::Sprite;
    sprite->setTexture(*texture);
    AddSprite(sprite);
}

// Method for loading Textures
sf::Texture* SpriteLoader::LoadTexture(string name, int RectSizeX, int RectSizeY, int RectLocX, int RectLocY) {
    sf::Texture* texture = new sf::Texture;

    // Load the texture
    if(!texture->loadFromFile(GetResourceLocation()+"/"+name, sf::IntRect(RectLocX, RectLocY, RectSizeX, RectSizeY))) {
        cerr << "[ERROR]HE: SpriteLoader: Texture failed to load! (" << name << ")" << endl;
    }

    // Create the Texture
    if(!texture->create(RectSizeX, RectSizeY)) {
        cerr << "[ERROR]HE: SpriteLoader: Texture failed to create! (" << name << ")" << endl;
    }

    return texture;
}

bool SpriteLoader::AddSprite(sf::Sprite* sprite) {
    try {
        SpriteLoader::sprites->push_back(sprite);
    } catch(exception e) {
        cout << "[ERROR]HE: SpriteLoader: An error occured whilst adding the Sprite to the sprite-vector!" << endl;
        return false;
    }
    cout << sprite->getTexture();

    return true;
}

// Method for getting "ResourceLocation"
string SpriteLoader::GetResourceLocation() {
    return SpriteLoader::ResourceLocation;
}
