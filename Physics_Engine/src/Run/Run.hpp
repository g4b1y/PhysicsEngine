#ifndef __RUN_HPP__
#define __RUN_HPP__

#include "../Shape/circle.hpp"
#include "../Shape/polygon.hpp"


#include <SFML/Window.hpp> 
#include <SFML/Graphics.hpp> 


namespace PhysicsEngine {

    class Run {
    private: 
        sf::RenderWindow window;
        int window_width;
        int window_height;

        std::vector<sf::ConvexShape> vec_polygons;
        std::vector<sf::CircleShape> vec_circles; 

        void Render();
        void EventHandler();
    public: 
        Run();
        void run();
    }; 

};

#endif