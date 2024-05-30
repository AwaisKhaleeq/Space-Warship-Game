#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
class Bullet {
public:
	Sprite shape;
	Texture tex;
	//Bullet *b;
	//Vector2f direction;
	float movspeedx, movspeedy;
	float x,y;
	
	Bullet()
	{
	//tex.loadFromFile("img/PNG/Lasers/laserBlue06.png");
	//shape.setTexture(tex);
  	movspeedy = 10.f;
  	movspeedx=0;
        shape.setPosition(-20, 0);
       shape.setScale(0.7,0.7);
	
	
	}
	

    Bullet(string png , float x, float y, float speedy=0.01,float speedx=0, float w=0.7, float h=0.7)  {
	tex.loadFromFile(png);
	shape.setTexture(tex);
  	movspeedx = speedx;
  	movspeedy = speedy;
        shape.setPosition(x, y);
        shape.setScale(w,h);
    }

    void update() {
   
    	//sf::Vector2f position = shape.getPosition();
	 //while( position.y < -1500) 
	 {
        shape.move(movspeedx, movspeedy );
 	    
    }
}
  virtual Sprite& getTexture() 
   {
        return shape;
   }


};
#endif
