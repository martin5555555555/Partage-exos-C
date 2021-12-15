#pragma once
#include <iostream>
#include <queue> 

//using namespace std;

class snake
    {
    public:
    /* data */
    std::queue<std::pair <int, int>> pile ;
    std::pair<int, int> head;
    bool has_to_grow;
   


    public:
    snake();
    ~snake();

    public:
    static void init_snake(snake & snake, const int bg_width, const int bg_len, const int snake_len);
    static std::pair<int, int> move( snake & snake,int key_scan, const int bg_width, const int bg_len, std::pair<int, int> & direction);
    static bool limit_control(snake & snake, const int bg_width, const int bg_len);
    static void snake_move_bg(snake & snake, std::pair<int, int> back, std::vector< std::vector<int>> & bg);
};   
 