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

#include "HexagonEngine.hpp"
#include <iostream>

using namespace Hexagon;
using namespace std;

SpriteLoader* Engine::spriteLoader;
sf::RenderWindow hexWindow;

sf::Sprite sprite;

Engine::Engine(int WIDTH, int HEIGHT, char* TITLE) {
    Engine::initHexagonEngine(WIDTH, HEIGHT, TITLE);
}
Engine::~Engine() {}

void Engine::initHexagonEngine(int WIDTH, int HEIGHT, char* TITLE) {
    cout << "HE: Initializing" << endl;

    string EngineResources = "src/HexagonEngine/defaultRes";

    spriteLoader = new SpriteLoader(EngineResources);

    cout << "HE: Creating new sf::Window" << endl;
    hexWindow.create(sf::VideoMode(WIDTH, HEIGHT), TITLE); // Create new sf::RenderWindow

    cout << "HE: Initializing finished." << endl;
}

// Method Runs GameLoop
void Engine::Start() {
    cout << "HE: Starting GameLoop" << endl;

    spriteLoader->LoadSprite("MissingTexture.png", 16, 16, 0, 0, true, false);

     // Gameloop
    while(hexWindow.isOpen()) {
        sf::Event event;

        while(hexWindow.pollEvent(event)) { // Run this loop aslong as there are window events
            if (event.type == sf::Event::Closed) { // Execute any requested events
                hexWindow.close();
            }
        }

        Update();
        FixedUpdate();
        Render();
    }
}

void Engine::Update() {}
void Engine::FixedUpdate() {}

// Render Function is called every go through of the gameloop
void Engine::Render() {
    hexWindow.clear(sf::Color::Magenta);

    hexWindow.draw(sprite);

    hexWindow.display();
}
