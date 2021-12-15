#include "../includes/snake.h"
#include "../includes/bg.h"
#define UP_ARROW    65
#define LEFT_ARROW  68
#define DOWN_ARROW  66
#define RIGHT_ARROW 67

snake::snake()
    {
        std::pair<int, int> first = {4,2};
        std::pair<int, int> last = {4,2};
    }
snake::~snake()
{ 

}

void snake::init_snake(snake & snake, const int bg_width, const int bg_len, const int snake_len)
{
    for (int i=0; i < snake_len+1; i++)
        {
            snake.pile.push({i,0});
        }
    snake.head = {snake_len, 0} ;
    snake.has_to_grow = false;
}
 std::pair<int, int> snake::move( snake & snake,int key_scan, const int bg_width, const int bg_len, std::pair<int,int> &direction)
{   std::pair<int, int> back = {-1, -1};
    if (~snake.has_to_grow)
        {
    std::pair<int, int> back = snake.pile.front();
    snake.pile.pop();
        }
    int x = snake.head.first;
    int y = snake.head.second;
        if (key_scan == UP_ARROW)
        {
            direction = {0,1};
        }
        else if (key_scan == DOWN_ARROW)
        {
            direction = {0,-1};
        }
        else if (key_scan == LEFT_ARROW)
        {
            direction = {-1,0};
        }
        else if (key_scan == RIGHT_ARROW)
        {
            direction = {1,0};
        }
    int dx  = direction.first;
    int dy = direction.second;
    x = x + dx ;
    y = y + dy; 
    snake.pile.push({x,y});
    snake.head = {x,y};
    snake.has_to_grow = false;
    
    return back;
}
 bool snake::limit_control(snake & snake, const int bg_width, const int bg_len)
    {    int x = snake.head.first;
          int y = snake.head.second;  
        if (x < 0) return false;
        if (x > bg_width ) return false;
        if (y > bg_len ) return false;
        return true;

}
void snake::snake_move_bg(snake & snake, std::pair<int, int> back, std::vector<std::vector<int> > & bg)
{ if ( back.first != -1 )
    {int x = back.first;
  int y = back.second;
  bg[x][y] = 0;
    }

  int x1 = snake.head.first;
  int x2 = snake.head.second;
  bg[x1][x2] = 1;

   }
    


    