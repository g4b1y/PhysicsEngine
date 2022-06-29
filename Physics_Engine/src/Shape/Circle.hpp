#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__

#include<iostream>
#include<string>
#include<vector>

#include "./polygon.hpp"
#include "../Assets/Assets.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


namespace PhysicsEngine { 

    namespace Shape {
        
        class Circle
        {
        private:
            vec2 pos {0, 0}; 
            float radius { 1 }; 
            std::string name {"NULL"}; 

            void print_info(); 
        public: 
            Circle() = default; 
            Circle(const float); 
            Circle(const float, const std::string); 
            Circle(const float, const std::string, const vec2);
            Circle(const float, const std::string, const float, const float);
            ~Circle() = default; 
        
        public: 
            vec2 getPosition(const bool) const;
            std::string getName(const bool) const;
            float getRadius(const bool) const; 
            float gp_x(const bool) const; 
            float gp_y(const bool) const; 

            sf::CircleShape TransformCirlce(color); 
            static bool CircleCollision(const PhysicsEngine::Shape::Circle&, const PhysicsEngine::Shape::Circle&); 

            void setPosition(const vec2);
            void setPosition(const float, const float);
            void setName(const std::string); 
            void setRadius(const float);
        };
    }
}
#endif