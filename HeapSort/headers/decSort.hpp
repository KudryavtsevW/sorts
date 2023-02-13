#pragma once
#include "func.hpp"
void decHeapSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& mass, int end, int MAX);
void decHeapify(sf::RenderWindow& window, std::vector<sf::RectangleShape>& mass, int i, int end, int MAX);
void buildDecHeap(sf::RenderWindow& window, std::vector<sf::RectangleShape>& mass, int end, int MAX);