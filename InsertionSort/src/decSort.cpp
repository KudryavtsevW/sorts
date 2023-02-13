#include "../headers/header.hpp"
void decInsSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& mass, int MAX)
{
    for(int k = 1; k<MAX;k++)
        {
            int bufY_size = mass[k].getSize().y;//zapomnim element
            int j = k - 1; //go to back
            while(j>=0 && mass[j].getSize().y > bufY_size)//peremeshaem element vlevo
            {
                mass[j+1].setSize(sf::Vector2f(5, mass[j].getSize().y));//perestanovka dvyh sosednih elementov
                mass[j].setSize(sf::Vector2f(5,bufY_size));
                window.clear();
                for(int n = 0;n<MAX;n++)
                {
                    window.draw(mass[n]);
                    
                }
                window.display();
                j--;
            }

        }
}