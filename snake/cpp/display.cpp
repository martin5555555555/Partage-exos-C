#include "stdlib.h"
#include <iostream>
#include <vector>

const char* cmd_clear="clear";


void printFrame(const int bg_width, const int bg_len, const std::vector<std::vector<int> >& bg){
    for( int j=0; j< bg_len; j++){
        for( int i=0; i<bg_width; i++){
            if( bg[i][j] == 0 ){
                std::cout << "#";
            }
            else if( bg[i][j] == 1 ){
                std::cout << "@" ; 
            }    
            else{
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void backgroundClear(){
    int out = system( cmd_clear);
    if( out != 0){
        std::cerr << "clear command failed" << std::endl;
        exit(1);
    }
}
