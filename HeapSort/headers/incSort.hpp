#pragma once
#include "func.hpp"
void incHeapSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& mass, int end, int MAX);
void incHeapify(sf::RenderWindow& window, std::vector<sf::RectangleShape>& mass, int i, int end, int MAX);
void buildIncHeap(sf::RenderWindow& window, std::vector<sf::RectangleShape>& mass, int end, int MAX);