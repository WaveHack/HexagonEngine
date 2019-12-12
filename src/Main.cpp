#include <iostream>
#include <SFML/Window.hpp>

#include "HexagonEngine/HexagonEngine.hpp"

using namespace std;
using namespace Hexagon;

int main() {
    char* test = "HEGE Debug/Tech Test 0.0.0.0 (RELEASE-BUILD 0)";
    Engine engine{1920, 1080, test};
    engine.Start();
}
