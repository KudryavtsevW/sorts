#include "../headers/header.hpp"
void incDelenie(sf::RenderWindow &window, std::vector<sf::RectangleShape> &mass, int low, int high, int MAX)
{
  if (low >= high)
  {
    return;
  }

  int median = low + (high - low) / 2;
  incDelenie(window, mass, low, median, MAX);
  incDelenie(window, mass, median + 1, high, MAX);
  incMergeSort(window, mass, low, median, high, MAX);
}
void incMergeSort(sf::RenderWindow &window, std::vector<sf::RectangleShape> &mass, int low, int median, int high, int MAX)
{
  int sizeArrLeft = median - low + 1;
  int sizeArrRight = high - median;

  int *arrLeft = new int[sizeArrLeft];
  int *arrRight = new int[sizeArrRight];

  for (int i = 0; i < sizeArrLeft; i++)
  {
    arrLeft[i] = mass[low + i].getSize().y;
  }

  for (int i = 0; i < sizeArrRight; i++)
  {
    arrRight[i] = mass[median + 1 + i].getSize().y;
  }

  int ai = 0, bi = 0, tmp = low;
  while (ai < sizeArrLeft && bi < sizeArrRight)
  {
    if (arrLeft[ai] >= arrRight[bi])
    {
      mass[tmp].setSize(sf::Vector2f(5, arrLeft[ai]));
      ai++;
      window.clear();
      for (int k = 0; k < MAX; k++)
      {
        window.draw(mass[k]);
      }
      sf::sleep(sf::milliseconds(10));
      window.display();
    }
    else
    {
      mass[tmp].setSize(sf::Vector2f(5, arrRight[bi]));
      bi++;
      window.clear();
      for (int k = 0; k < MAX; k++)
      {
        window.draw(mass[k]);
      }
      sf::sleep(sf::milliseconds(10));
      window.display();
    }
    tmp++;
  }

  while (ai < sizeArrLeft)
  {
    mass[tmp].setSize(sf::Vector2f(5, arrLeft[ai]));
    ai++;
    tmp++;
    window.clear();
    for (int k = 0; k < MAX; k++)
    {
      window.draw(mass[k]);
    }
    sf::sleep(sf::milliseconds(10));
    window.display();
  }

  while (bi < sizeArrRight)
  {
    mass[tmp].setSize(sf::Vector2f(5, arrRight[bi]));
    bi++;
    tmp++;
    window.clear();
    for (int k = 0; k < MAX; k++)
    {
      window.draw(mass[k]);
    }
    sf::sleep(sf::milliseconds(10));
    window.display();
  } // window.clear();

  delete[] arrLeft;
  delete[] arrRight;
}