#include "polygon.hpp"

// ---------------------------------------- Priavte Section ------------------------------------------ 

void PhysicsEngine::Shape::Polygon::RegularPolygon(float r, int n) 
{   
    vec2 temp {0, 0}; 
    float TotalAngleSum = (n - 2) * 180; 
    float angle = 360 / n; 

    std::cout << "\nTotal Angle Sum equals: " << TotalAngleSum << "\nOne Angle equals: " << angle << "\n" << std::endl; 
    std::cout << "RegularPolygon [private] : " << std::endl; 

    for( int i = 0; i < n; i++) 
    {
        temp.x = cos((2 * PI * (i )) / (n)) * r;  
        temp.y = sin((2 * PI * (i )) / (n)) * r; 
        points.push_back(temp); 

        std::cout << "x: " << std::fixed << temp.x << "\ty: " << std::fixed << temp.y << std::endl;     
    }

    temp.x = cos((2 * PI * (0 )) / (n)) * r;  
    temp.y = sin((2 * PI * (0 )) / (n)) * r; 
    points.push_back(temp); 

}

void PhysicsEngine::Shape::Polygon::print_position() 
{
    std::cout << "Position: \tx: " << pos.x << " y: " << pos.y << std::endl;
}

float PhysicsEngine::Shape::Polygon::dotProduct(const vec2 _v1, const vec2 _v2) 
{
    return (_v1.x * _v2.x) + (_v1.y * _v2.y); 
}

// ---------------------------------------- Public Section ------------------------------------------ 

PhysicsEngine::Shape::Polygon::Polygon(const float _r, const int _n) noexcept : radius(_r), sumOfCorners(_n) 
{   
    std::cout << "\n\nPolygon ["<< this->getName() << "] ctor called! .... New object created" << std::endl; 
    this->RegularPolygon(_r, _n); 
} 

PhysicsEngine::Shape::Polygon::Polygon(const float _r, const int _n, const std::string _name) : radius(_r), sumOfCorners(_n), name(_name) 
{
    std::cout << "\n\nPolygon ["<< this->getName() << "] ctor called! .... New object created" << std::endl; 
    this->RegularPolygon(_r, _n);  
}

PhysicsEngine::Shape::Polygon::Polygon(const float _r, const int _n, const vec2 _pos) noexcept : radius(_r), sumOfCorners(_n)
{   
    try {
        this->pos = _pos; 

        std::cout << "\n\nPolygon ["<< this->getName() << "] ctor called! .... New object created" << std::endl; 
        this->RegularPolygon(_r, _n);
    }
    catch(...) 
    {
        std::cerr << "Error, something went wrong. Please try again and check you input\n" << std::endl;  
    }
}

PhysicsEngine::Shape::Polygon::~Polygon() 
{
    std::cout << "\nPolygon: " << this->getName() << " got destroyed" << std::endl;
    std::cout << "max: " << this->max(500, 3) << std::endl; 
    std::cout << "min: " << this->min(500, 3) << std::endl; 
    std::cout << "min: " << this->min(3, 3) << std::endl; 
}

void PhysicsEngine::Shape::Polygon::setPoints(const std::vector<vec2> _points) 
{
    points = _points; 
}

void PhysicsEngine::Shape::Polygon::setAngle(const float _angle) 
{
    angle = _angle; 
}

void PhysicsEngine::Shape::Polygon::setPosition(const vec2 _pos) 
{
    pos = _pos; 
}

void PhysicsEngine::Shape::Polygon::setPosition(const float _x, const float _y) 
{
    pos.x = _x; 
    pos.y = _y; 
}

void PhysicsEngine::Shape::Polygon::setRotation(const float _theta) 
{

    if(!this->points.empty())
    {
        std::vector<vec2> _tvec; 
        vec2 temp {0, 0};
        float theta= _theta * (PI / 180);

        std::cout << "\n\nsetRotation : " << std::endl; 

        for( int i = 0; i < points.size(); i++) 
        {
            temp.x = points.at(i).x * cos(theta)  - points.at(i).y * sin(theta);
            temp.y =  points.at(i).x * sin(theta)  + points.at(i).y * cos(theta);  
            _tvec.push_back(temp); 

            std::cout << "x: " << std::fixed << temp.x << "\ty: " << std::fixed << temp.y << std::endl;     
        }

        std::cout << std::endl;
        this->points = _tvec; 
    }
}

vec2 PhysicsEngine::Shape::Polygon::getPosition(const bool _print)
{
    if(_print) {
        print_position();   
    }
    return pos; 
}

float PhysicsEngine::Shape::Polygon::gp_x() const 
{
    return this->pos.x;
}

float PhysicsEngine::Shape::Polygon::gp_y() const 
{
    return this->pos.y;
}


sf::ConvexShape PhysicsEngine::Shape::Polygon::TransformPolygon(color _col) 
{
    sf::ConvexShape _temp; 
    std::vector<sf::Vector2f> _vec; 
    _vec = v2Tv2f(this->points); 

    _temp.setPosition( 
        sf::Vector2f(
            this->gp_x(), 
            this->gp_y()
        )); 
    
    _temp.setPointCount(
        this->points.size() 
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

    for(int i = 0; i < _vec.size(); i++) 
    {
        _temp.setPoint(i, _vec.at(i)); 
    }
    return _temp; 
}

bool PhysicsEngine::Shape::Polygon::SAT_Collision(const PhysicsEngine::Shape::Polygon& _poly1, const PhysicsEngine::Shape::Polygon& _poly2)
{
    _p1* 

}   


std::string PhysicsEngine::Shape::Polygon::getName() const 
{
    return name;
}

std::vector<vec2> PhysicsEngine::Shape::Polygon::getNormal() const 
{
    std::vector<vec2> normals; 
    for(int i = 0; i < points.size() - 1; i++)
    {
        vec2 currentNormal( 
            points.at(i + 1).x - points.at(i).x, 
            points.at(i + 1).y - points.at(i).y
        ); 
        normals.push_back(currentNormal);
    }
    normals.push_back(
        vec2(
            points.at(0).x - points.at(points.size() - 1).x,
            points.at(0).y - points.at(points.size() - 1).y
        ));
    return normals; 
}

std::vector<vec2> PhysicsEngine::Shape::Polygon::getPoints(bool _print) const 
{
    if(_print) {
        std::cout << "\nPolygonzug("; 
        for(int i = 0; i < points.size(); i++) {
            std::cout << "(" << std::fixed <<points.at(i).x << "," << std::fixed << points.at(i).y << ")"; 
            if(i != points.size() - 1) {
                std::cout << ','; 
            }
        }
        std::cout << ")" << std::endl;
    }
    return points; 
}


std::vector<sf::Vector2f> PhysicsEngine::Shape::Polygon::v2Tv2f(std::vector<vec2> _points) {
    std::vector<sf::Vector2f> _p; 

    //Debug
    std::cerr << "\n\nv2Tv2f : \n";  
    for(int i = 0; i < _points.size(); i++) 
    {
        _p.push_back(
            sf::Vector2f(
                _points.at(i).x,
                 _points.at(i).y
            )); 

        std::cerr << "x : " << _p.at(i).x;
        std::cerr << "\ty : " << _p.at(i).y << std::endl;
    }
    std::cout << std::endl; 
    return _p; 
}