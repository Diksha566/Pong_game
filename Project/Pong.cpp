#include "Bat.h"
#include "Ball.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;
int main(){
    //Create video mode object 
    VideoMode vm(1366,768);
    //Create window object
    RenderWindow window(vm,"Pong Game",Style::Fullscreen);

    //create bat
    Bat bat(1366/2.0,768-20);

    //create the ball
    Ball ball (1366/2, 0);

    //create hud(heads up display)
    Text hud;
    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(Color::White);
    hud.setPosition(20,20);
    hud.setString("Score: 0 Lives : 3");

    //initialize the score and lives
    int score = 0;
    int lives = 3;

    //manage time
    Clock clock;

    //main loop
    while(window.isOpen()){
        Event event;
        if(event.type==Event::Closed){
            window.close();
        }
        
        //Handle quitting game
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }
        //handle the right cursor 
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            if(bat.get_Position().left+bat.get_Position().width>1366){
                bat.stopRight();
            }
            else{
                bat.moveRight();
            }
        }
        else{
            bat.stopRight();
        }
        //handle the left cursor 
        if(Keyboard::isKeyPressed(Keyboard::Left)){
            if(bat.get_Position().left<0){
                bat.stopLeft();
            }
            else{
                bat.moveLeft();
            }
        }
        else{
            bat.stopLeft();
        }
        //update time
        Time dt = clock.restart();

        //update bat
        bat.update(dt);

        //update ball
        ball.update(dt);

        //update score 
        std::stringstream ss;
        ss<<"Score:"<< score <<" Lives:"<< lives;
        hud.setString(ss.str());


        //update ball

        if(ball.getPosition().top > window.getSize().y)
        {
            //reverse the ball direction
            ball.reboundBottom();
            //lives reduce            
            lives--;
            if(lives<1)
            {
                //rest score, lives
                score = 0;
                lives = 3;
            }
        
        }

        //ball hitting the top
        if(ball.getPosition().top<0)
        {
            //score inc
            score++;
            ball.reboundBatOrTop();
        }

        //ball hitting the sides

        if(ball.getPosition().left<0 || ball.getPosition().left+10 > window.getSize().x)
        {
            ball.reboundSides();
        }

        //ball hitting the bat
        if(ball.getPosition().intersects(bat.get_Position()))
        {
            
           
            ball.reboundBatOrTop();
            score++;

        }
    
        //displaying the contents
        window.clear();
        window.draw(hud);
        window.draw(bat.get_Shape());
        window.draw(ball.getShape());
        window.display();
    }
    return 0;

}