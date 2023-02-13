#include "../headers/header.hpp"

statesSort incSort(statesSort st, std::vector<sf::RectangleShape>& mass, int* i, int* j, int MAX)
{
    int bufy_size = 0;
    switch (st)
        {
        case FOR_I:
            if((*i) == 0 && (*j) == 0)
                st = FOR_J;
            else{
                (*i)++;
                (*j) = 0;
                st = FOR_J;
            }
            if((*i) >= MAX)
                st = END;    
            break;
        case FOR_J:
            if((*j) < MAX-1)
            {
                if(mass[(*j)].getSize().y<mass[(*j)+1].getSize().y)
                {
                    bufy_size = mass[(*j)].getSize().y;
                    mass[(*j)].setSize(sf::Vector2f(5, mass[(*j)+1].getSize().y));
                    mass[(*j)+1].setSize(sf::Vector2f(5, bufy_size));
                }
                (*j)++;
                st = FOR_J;
            }
            else
            { 
                st = FOR_I;
            }
            break;
        case END:
            break;
        default:
            break;
        }

    return st;
}