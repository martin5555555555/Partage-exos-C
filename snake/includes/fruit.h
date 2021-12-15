#include <iostream>
#include "snake.h"


class fruit
{
    private: 
    std::pair<int, int> position;
    bool has_eaten;
    
    public:
    fruit();
    ~fruit();

    public:
    static void  create_fruit(fruit & fruit, snake & snake, std::vector< std::vector<int>> &bg, const int bg_width, const int bg_len);
    static void  init_fruit(fruit & fruit);
};