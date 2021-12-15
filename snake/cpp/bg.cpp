#include <vector>
#include "../includes/bg.h"
#include "../includes/snake.h"
#include <iostream>

void define_limits(std::vector< std::vector<int>> &bg, const int bg_width,const int bg_len)
    {   int i,j;
        for (i=0; i<bg_width; i++)
           { for (j=0; j<bg_len; j++)
                {bg[i][j] = 0;}
           }
    }


void snake_init_background(const int snake_len, const int bg_width,const int bg_len, std::vector<std::vector<int>> &bg)
    {  
        for (int i=0; i<snake_len+1; i++)
            {
                bg[i][0] = 1;
            }
    }

