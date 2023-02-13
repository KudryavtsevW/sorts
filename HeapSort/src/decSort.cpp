#include "../headers/func.hpp"
#include "../headers/decSort.hpp"
void decHeapSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& mass, int end, int MAX)
{
    buildDecHeap(window, mass, end, MAX);
    for(int i = end-1;i>=0;i--)
    {
        swap(window, mass, 0, i, MAX);
        decHeapify(window, mass, 0, i, MAX);
    }
}
void decHeapify(sf::RenderWindow& window, std::vector<sf::RectangleShape>& mass, int i, int end, int MAX)
{
    int l_ind = LEFT(i);
    int r_ind = RIGHT(i);

    int tmp_ind = i;
    
    if(l_ind < end && mass[tmp_ind].getSize().y > mass[l_ind].getSize().y)
    {
        tmp_ind = l_ind;
    }

    if(r_ind < end && mass[tmp_ind].getSize().y > mass[r_ind].getSize().y)
    {
        tmp_ind = r_ind;
    }
    if(tmp_ind != i)
    {
        swap(window, mass, i, tmp_ind, MAX);
        decHeapify(window, mass, tmp_ind, end, MAX);
    }

}


void buildDecHeap(sf::RenderWindow& window, std::vector<sf::RectangleShape>& mass, int end, int MAX)
{
    for(int i = end/2 - 1; i>=0; i--)
    {
        decHeapify(window, mass, i, end, MAX);
    }
}