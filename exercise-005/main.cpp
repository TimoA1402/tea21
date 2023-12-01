#include <fmt/chrono.h>
#include <fmt/format.h>
#include<unistd.h>
#include <chrono>
#include <thread>




#include "CLI/CLI.hpp"
#include "config.h"





  typedef enum {
    DB_STATE_UP = 0,
    DB_STATE_DOWN = 1,
    DB_STATE_TOP = 2,
    DB_STATE_BOTTOM = 3,
    DB_STATE_MAX
  } DebounceState_t;

  DebounceState_t state  = DB_STATE_BOTTOM;


  void stateMachine()
  {
    int input;
    std::cin >> input;
    switch(state)
    {
      case DB_STATE_UP:
      
          if(1 == input)
          {
            std::cout<<"1 für nächsten Status"<<std::endl;
            state = DB_STATE_DOWN;
            std::cout<<"Der aktuelle Status ist DOWN: " <<std::endl;
          }
          else if( 1 != input){
            state = DB_STATE_TOP;
            std::cout<<"Der aktuelle Status ist TOP: " <<std::endl;
          }break;

      case DB_STATE_DOWN:
          if(1 == input)
          {
            state = DB_STATE_UP;
            std::cout<<"Der aktuelle Status ist UP: " <<std::endl;
          }
          else if (1 != input){
            state = DB_STATE_BOTTOM;
            std::cout<<"Der aktuelle Status ist BOTTOM: " <<std::endl;
          }break;

      case DB_STATE_TOP:
        if(1 ==input){
            state = DB_STATE_DOWN;
            std::cout<<"Der aktuelle Status ist DOWN: " <<std::endl;
        }   
        else{
          std::cout<<"Der aktuelle Status ist TOP: " <<std::endl;
        }
        break;

      case DB_STATE_BOTTOM:
        if(1 ==input){
            state = DB_STATE_UP;
            std::cout<<"Der aktuelle Status ist UP: " <<std::endl;
        }  
        else{
          std::cout<<"Der aktuelle Status ist BOTTOM: " <<std::endl;
        }
        break;
    }
  }



       

void sleep_ms(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}



auto main(int argc, char **argv) -> int
{

    std::cout << "Aktueller Status: Bottom" << std::endl;


     while( 1==1 )
    {
      stateMachine();
      sleep_ms(100);
    }


    return 0; /* exit gracefully*/
}
