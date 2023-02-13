#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
enum statesSort{
    FOR_I,
    FOR_J,
    END
};
statesSort incSort(statesSort st, std::vector<sf::RectangleShape>& mass, int* i, int* j, int MAX);
statesSort decSort(statesSort st, std::vector<sf::RectangleShape>& mass, int* i, int* j, int MAX);