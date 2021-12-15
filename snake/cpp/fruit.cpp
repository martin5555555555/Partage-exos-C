#include "fruit.h"
#include "stdlib.h"

#include <array>
#include <vector>

void fruit::create_fruit(fruit & fruit, snake & snake, std::vector< std::vector<int>> &bg, const int bg_width, const int bg_len)
{  if(snake.head == fruit.position)
    {
        fruit.has_eaten = true;
        snake.has_to_grow = true;

    }
    
    if (fruit.has_eaten)
    {
   fruit.position = {rand()%(bg_width-1), rand()%(bg_len-1)};
   fruit.has_eaten = false;

   }
   
  
}

void fruit::init_fruit(fruit & fruit)
{
    fruit.has_eaten = false;
}