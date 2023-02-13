
/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief InsertionSort SFML
 * @version 0.1
 * @date 2022-11-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string.h>
#include "./headers/header.hpp"
#define NMAX 150

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
        mode = 1;
    if(strcmp(argc[1], "dec") == 0)
        mode = 2;
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
    std::vector<sf::RectangleShape> mass;
    int val = 0;
    int height = 0;
    for(int i = 0;i<MAX;i++)
    {
        val+=6;
        height = rand() % 250+10;
        rectangle.setSize(sf::Vector2f(5,-height)); // определяем прямоугольник размером 120x50
        rectangle.setFillColor(sf::Color(255, 255, 255)); // Прикручиваем ему цвет
        rectangle.setPosition(val + 50, 300); // Смещаем чуть в сторону
        mass.push_back(rectangle);
    }
    bool sort = true;
    int j = 0;
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
                incInsSort(window, mass, MAX);            
            }
            if(mode == 2)
            {
                decInsSort(window, mass, MAX);
            }
        }
        sort  = false;

    }
    return 0;
}
