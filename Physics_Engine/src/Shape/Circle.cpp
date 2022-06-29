#include "circle.hpp"


PhysicsEngine::Shape::Circle::Circle(const float _r) : radius(_r) {
    std::cout << "Cirlce Ctor called ... Object[" << this->name << "] gets created" << std::endl; 
}

PhysicsEngine::Shape::Circle::Circle(const float _r, const std::string _n) : radius(_r), name(_n) {
    std::cout << "Cirlce Ctor called ... Object[" << this->name << "] gets created" << std::endl; 
}

PhysicsEngine::Shape::Circle::Circle(const float _r, const std::string _n, const vec2 _pos) : radius(_r), name(_n), pos(_pos) {
    std::cout << "Cirlce Ctor called ... Object[" << this->name << "] gets created" << std::endl; 
}

PhysicsEngine::Shape::Circle::Circle(const float _r, const std::string _n, const float _x, const float _y) : radius(_r), name(_n) {
    std::cout << "Cirlce Ctor called ... Object[" << this->name << "] gets created" << std::endl; 
    pos.x = _x; 
    pos.y = _y; 
}

float PhysicsEngine::Shape::Circle::getRadius(const bool _print) const 
{
    if(_print) {
        std::cout << "Circle[" << this->name << "] radius: " << this->radius << std::endl;
    }
    return this->radius;
}

float PhysicsEngine::Shape::Circle::gp_x(const bool _print) const 
{
    if(_print) {
        std::cout << "x: " << this->pos.x << std::endl;
    }
    return this->pos.x; 
}

float PhysicsEngine::Shape::Circle::gp_y(const bool _print) const 
{
    if(_print) {
        std::cout << "y: " << this->pos.y << std::endl;
    }
    return this->pos.y; 
}

sf::CircleShape PhysicsEngine::Shape::Circle::TransformCirlce(color _col) 
{   
    sf::CircleShape _temp; 

    _temp.setRadius(
        this->getRadius(false)
    );

    _temp.setPosition(
        this->gp_x(false), 
        this->gp_y(false)
    ); 

    switch(_col) 
    {
        case Black: 
            _temp.setFillColor(
                sf::Color::Black
            ); 
            break;

        case White: 
            _temp.setFillColor(
                sf::Color::White
            ); 
            break;

        case Grey: 
            _temp.setFillColor(
                sf::Color(103, 103, 103)
            ); 
            break;
        
        case Blue: 
            _temp.setFillColor(
                sf::Color::Blue
            ); 
            break; 

        case Orange: 
            _temp.setFillColor(
                sf::Color(255, 164, 0)
            ); 
            break;

        case Red: 
            _temp.setFillColor(
                sf::Color::Red
            ); 
            break;

        case Yellow: 
            _temp.setFillColor(
                sf::Color::Yellow
            ); 

            break;

        case Purple: 
            _temp.setFillColor(
                sf::Color(145, 0, 175)
            ); 

            break;

        case Pink: 
            _temp.setFillColor(
                sf::Color(251, 153, 238)
            ); 
            break;

        case Green: 
            _temp.setFillColor(
                sf::Color::Green
            ); 
            break;

        default: 
            //
            break; 
    }
    return _temp; 
}

bool PhysicsEngine::Shape::Circle::CircleCollision(const PhysicsEngine::Shape::Circle& c1, const PhysicsEngine::Shape::Circle& c2) 
{
    int maX = std::max(c1.gp_x(false), c2.gp_x(false)); 
    int maY = std::max(c1.gp_y(false), c2.gp_y(false));

    int miX = std::min(c1.gp_x(false), c2.gp_x(false));
    int miY = std::min(c1.gp_y(false), c2.gp_y(false)); 

    if( sqrt(pow((maX - miX),2) + pow(maY - miY, 2)) > c1.getRadius(false) + c2.getRadius(false)) 
    {
        return false;
    }   
    else
    {
        return true; 
    }
}

void PhysicsEngine::Shape::Circle::setPosition(const vec2 _v) 
{
    pos = _v; 
}

void PhysicsEngine::Shape::Circle::setPosition(const float _x, const float _y) 
{
    pos = vec2 (
        _x,
        _y
    ); 
}

void PhysicsEngine::Shape::Circle::setName(const std::string _n) 
{
    name = _n; 
}

void PhysicsEngine::Shape::Circle::setRadius( const float _r) 
{
    radius = _r; 
}

