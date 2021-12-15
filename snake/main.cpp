#include <iostream>
#include <vector>
#include "fruit.h"
#include "bg.h"
#include "snake.h"
#include "keyboard.h"
#include "display.h"
#include "test.h"
#include <chrono>

void startgame(const int bg_width, const int bg_len,std::vector< std::vector<int> > & bg, snake & snake, fruit & fruit)
{   std::pair<int, int> direction = {0,1};   
    keyboard_init();

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    long duree = 0;
    while (true)
{   // temporisation
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        duree = (long)std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

        if (duree > 200)
    {
    // mangé?
    fruit::create_fruit(fruit, snake, bg, bg_width, bg_len);
    /* deplacement */
    int key_scan = keyboard_scan();
    std::pair<int, int> back = snake::move(snake, key_scan, bg_width, bg_len, direction );
    snake::snake_move_bg(snake, back, bg);
    

    /*affichage*/
    backgroundClear();
    printFrame(bg_width, bg_len, bg);
    begin = end;
    }

    

    


}
}
 
int main()
{snake snake ;
fruit fruit;
add(3, 2);
fruit::init_fruit(fruit);
const int bg_width{10}, bg_len{10}, snake_len{3};
std::vector< std::vector<int> > bg(bg_width, std::vector<int>(bg_len));  
define_limits(bg, bg_width, bg_len);
snake::init_snake(snake, bg_width, bg_len,snake_len);
snake_init_background(snake_len, bg_width, bg_len, bg);
startgame(bg_width, bg_len, bg, snake, fruit );



return 0;

}

