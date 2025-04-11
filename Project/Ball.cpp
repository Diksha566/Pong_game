#include "Ball.h"

Ball::Ball(float startX, float startY)
{
    m_position.x= startX;
    m_position.y= startY;
    m_shape.setRadius(10.0);
    m_shape.setPosition(m_position);

}

FloatRect Ball::getPosition()
{
    return m_shape.getGlobalBounds();

}

CircleShape Ball::getShape()
{
    return m_shape;
}

float Ball::getXVelocity()
{
    return m_DirectionX;
}

void Ball::reboundSides()
{
    m_DirectionX = -m_DirectionX;

}

void Ball::reboundBatOrTop()
{
    m_DirectionY = -m_DirectionY;
}

void Ball::reboundBottom(){
    m_position.y=0;
    m_position.x=500;
    m_DirectionX = -m_DirectionX;
}

void Ball::update(Time dt){
    m_position.x+=m_DirectionX * m_Speed *dt.asSeconds();
    m_position.y+=m_DirectionY * m_Speed *dt.asSeconds();
    m_shape.setPosition(m_position);

}
