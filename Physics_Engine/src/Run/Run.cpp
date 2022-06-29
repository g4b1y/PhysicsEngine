#include "run.hpp"

void CircleContrl(std::vector<sf::CircleShape>* _ptr) 
{
    PhysicsEngine::Shape::Circle c1(80.f,"", vec2( 200, 150 ));
    PhysicsEngine::Shape::Circle c2(80.f,"", vec2( 200, 310 )); 
    PhysicsEngine::Shape::Circle c3(80.f,"", vec2( 800, 150 ));
    PhysicsEngine::Shape::Circle c4(80.f,"", vec2( 800, 311 )); 

    _ptr->push_back(
        c1.TransformCirlce(Orange)
    ); 
    _ptr->push_back(
        c2.TransformCirlce(Orange)
    );
    _ptr->push_back(
        c3.TransformCirlce(Orange)
    );
    _ptr->push_back(
        c4.TransformCirlce(Orange)
    );


    if(PhysicsEngine::Shape::Circle::CircleCollision(c1, c2)) { 
        _ptr->at(0).setFillColor(sf::Color::Red);
        _ptr->at(1).setFillColor(sf::Color::Red);
    }
    else 
    {
        _ptr->at(0).setFillColor(sf::Color::Green);
        _ptr->at(1).setFillColor(sf::Color::Green);
    }
    if(PhysicsEngine::Shape::Circle::CircleCollision(c2, c3)) 
    {
        _ptr->at(2).setFillColor(sf::Color::Red);
        _ptr->at(3).setFillColor(sf::Color::Red);
    }
    else 
    {
        _ptr->at(2).setFillColor(sf::Color::Green);
        _ptr->at(3).setFillColor(sf::Color::Green);
    }
}


void PolyContrl(std::vector<sf::ConvexShape>* _ptr)
{
    PhysicsEngine::Shape::Polygon p1(100, 4, vec2(500 , 500));  
    PhysicsEngine::Shape::Polygon p2(100, 3, vec2(500 , 600)); 
    PhysicsEngine::Shape::Polygon p3(100, 4, vec2(700 , 450)); 
    PhysicsEngine::Shape::Polygon p4(100, 3, vec2(700 , 800)); 

    
    
    p1.setRotation(40.f); 
    p2.setRotation(33.3333f);
    p3.setRotation(45.f); 
    p4.setRotation(360/3);


    _ptr->push_back(p1.TransformPolygon(Orange)); 
    _ptr->push_back(p2.TransformPolygon(Blue)); 
    _ptr->push_back(p3.TransformPolygon(Purple)); 
    _ptr->push_back(p4.TransformPolygon(Yellow)); 
}

PhysicsEngine::Run::Run() 
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window_width = desktop.width;
    window_height = desktop.height;

    this->window.create(sf::VideoMode(window_width, window_height, desktop.bitsPerPixel), "Window", sf::Style::None);
    window.setFramerateLimit(60);
}

void PhysicsEngine::Run::run()
{   

    /*
    std::vector<sf::CircleShape>* _cptr = &vec_circles; 
    CircleContrl(_cptr); //Circle Collision Simmulation
    */

    std::vector<sf::ConvexShape>* _pptr = &vec_polygons; 
    PolyContrl(_pptr); 
    


                                                                                                                       

    while(window.isOpen()) {
        Render();   
        EventHandler(); 
    }  
}

void PhysicsEngine::Run::Render() 
{
    window.clear(sf::Color::White);
    for(int i = 0; i < vec_circles.size(); i++) 
    {   
        window.draw(vec_circles.at(i));
    }

    for(int i = 0; i < vec_polygons.size(); i++)
    {
        window.draw(vec_polygons.at(i));
    }

    window.display();
}

void PhysicsEngine::Run::EventHandler() 
{
    sf::Event event; 

    while(window.pollEvent(event)) {
        
        switch(event.type) {
            case sf::Event::Closed : 
                window.close();
                break;
            case sf::Event::KeyPressed: 
                if(event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                break;
            default: 
                std::cout << "No event" << std::endl;
        }
    }
}