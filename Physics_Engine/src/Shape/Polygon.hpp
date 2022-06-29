#ifndef __POLYGON_HPP__
#define __POLYGON_HPP__

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>  

#include "./circle.hpp"
#include "../Assets/Assets.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace PhysicsEngine {

    #define PI 3.14159265359


    namespace Shape {

        class Polygon 
        {
        private:
            std::string name = {"NULL"}; 
            vec2 pos {0, 0}; 
            float angle = 0; 
            int sumOfCorners = 0; 
            float radius = 1; 
            std::vector<vec2> points; 

        private: 
            void RegularPolygon(float, int); 
            void print_position(); 
            static float dotProduct(const vec2, const vec2); 
            vec2 projectOnAxis();
        public: 
            Polygon(const float _r) noexcept;  
            Polygon(const float _r, const int _n) noexcept; 
            Polygon(const float _r, const int _n, const std::string _name) ; 
            Polygon(const float _r, const int _n, const vec2) noexcept;
            ~Polygon(); 
            

            void setPoints(const std::vector<vec2>); 
            void setAngle(const float); 
            void setPosition(const vec2);
            void setPosition(const float, const float); 
            void setRotation(const float);  
            

            vec2 getPosition(const bool _print = false); 
            float gp_x() const; 
            float gp_y() const; 

            sf::ConvexShape TransformPolygon(color);
            static bool SAT_Collision(const PhysicsEngine::Shape::Polygon&, const PhysicsEngine::Shape::Polygon&); 

            std::string getName() const; 
            std::vector<vec2> getNormal() const;
            std::vector<vec2> getPoints(bool print) const; 
            static std::vector<sf::Vector2f> v2Tv2f(std::vector<vec2> _points);  
            
        public:
            template<typename T> 
                inline T max(const T v1, const T v2) {
                    if(v1 >= v2) {
                        return v1; 
                    } else {
                        return v2; 
                    }
                } 

            template<typename T> 
                inline T min(const T v1, const T v2) {
                    if(v1 <= v2) {
                        return v1; 
                    } else {
                        return v2; 
                    }
                }
        }; 
    }; 
};
#endif