#include <iostream>

#include "./Shape/polygon.hpp"
#include "./Run/run.hpp"


void remove() noexcept; 

int main() 
{
    PhysicsEngine::Run r;
    r.run();

    remove();  
    return 0; 
}

void remove() noexcept
{
    remove("main.o"); 
    remove("./Shape/Polygon.o"); 
    remove("./Shape/Circle.o");
    remove("./Run/Run.o"); 
    remove("main.exe");
}