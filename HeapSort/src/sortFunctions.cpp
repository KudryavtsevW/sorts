#include "../headers/func.hpp"
void swap(sf::RenderWindow& window, std::vector<sf::RectangleShape>& mass, int i, int j, int MAX)
{
   
    int tmp = mass[i].getSize().y;
    mass[i].setSize(sf::Vector2f(-5, mass[j].getSize().y));
    mass[j].setSize(sf::Vector2f(-5, tmp));
    window.clear();
    for(int k = 0;k<MAX;k++)
    {
        window.draw(mass[k]);
        
    }
    
    window.display();
}
int LEFT(int i)
{
    return 2*i + 1;
}

int RIGHT(int i)
{
    return 2*i + 2;
}



