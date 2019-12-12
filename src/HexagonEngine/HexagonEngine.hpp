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
           This product includes software developed by the <organization>.
        4. Neither the name of the <organization> nor the
           names of its contributors may be used to endorse or promote products
           derived from this software without specific prior written permission.

        THIS SOFTWARE IS PROVIDED BY <COPYRIGHT HOLDER> "AS IS" AND ANY
        EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
        WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
        DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
        DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
        (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
        LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
        ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
        (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
        SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Contributors to this File:
    - Felix Eckert (Original Author)
*/

#ifndef HEXAGON_ENGINE_HPP
#define HEXAGON_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Graphics/SpriteLoader.hpp"

namespace Hexagon {
    class Engine {
        public:
            static SpriteLoader* spriteLoader;

            // Engine Setup
            Engine (int WIDTH, int HEIGHT, char* TITLE);
            ~Engine();

            void initHexagonEngine(int WIDTH, int HEIGHT, char* TITLE); // Initialize the Engine

            // Update & Rendering
            void Start      (); // Starts the game loop

            void Update     (); // Runs every run through of the game loop
            void FixedUpdate(); // Runs every 20 run throughs of the game loop
            void Render     (); // Runs every run through of the game loop

        private:
            string EngineResources;
            sf::RenderWindow hexWindow; // Main Window
    };
}

#endif // HEXAGON_ENGINE_HPP
