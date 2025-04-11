#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball{
    private:
    Vector2f m_position;
    CircleShape m_shape;
    float m_Speed=1000.f;
    float m_DirectionX=.2f;
    float m_DirectionY=.2f;

    public:
    Ball(float startx, float starty);
    FloatRect getPosition();
    CircleShape getShape();
    float getXVelocity();
    void reboundSides();
    void reboundBatOrTop();
    void reboundBottom();
    void update(Time dt);


};