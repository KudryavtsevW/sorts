/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief HeapSort SFML
 * @version 0.1
 * @date 2022-11-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string.h>
#define NMAX 150
#include "headers/decSort.hpp"
#include "headers/incSort.hpp"

int main(int argv, char* argc[])
{
    int mode = -1;
    int MAX = 0;
    if(argv<2 || argv>3)
    {
        std::cout<<"Incorrect number of arguments\n";
        return -10;
    }
    if(strcmp(argc[1], "inc") == 0)
        mode = 2;
    if(strcmp(argc[1], "dec") == 0)
        mode = 1;
    if(mode < 0)
    {
        std::cout<<"Incorrect 1-st argument\n";
        return -11;
    } 

    if(argv == 3)
    {
        int l = 0;
        int error = 0;
        while(argc[2][l]!='\0')
        {
            if(isdigit(argc[2][l])==0)
                error++;
            l++;
        }
        if(error!=0)
        {
            std::cout<<"Incorrect 2-nd argument\n";
            return -12;
        }

        MAX = atoi(argc[2]);    
    }
    if(argv == 2)
    {
        MAX = NMAX;
    } 
    if(MAX > 150)
    {
        std::cout<<"So much value\n";
        return -13; 
    }  
    sf::RenderWindow window(sf::VideoMode(1000, 400), "SFML works!");
    sf::RectangleShape rectangle;
    std::vector<sf::RectangleShape> massRect;
    int val = 0;
    int height = 0;
    for(int i = 0;i<NMAX;i++)
    {
        val+=6;
        height = rand() % 250;
        rectangle.setSize(sf::Vector2f(5,-height)); // определяем прямоугольник размером 120x50
        rectangle.setFillColor(sf::Color(255, 255, 255)); // Прикручиваем ему цвет
        rectangle.setPosition(val + 50, 300); // Смещаем чуть в сторону
        massRect.push_back(rectangle);
    }
    bool sort = true;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(sort)
        {
            if(mode == 1)
            {
                incHeapSort(window, massRect, MAX, MAX);
            }
            if(mode == 2)
            {
                decHeapSort(window, massRect, MAX, MAX);
            }
            sort = false;
        }
    }
    return 0;
}
