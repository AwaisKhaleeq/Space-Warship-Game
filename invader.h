#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class invader : public enemy
{
	virtual void update() 
	 { 
	 	timer +=0.5f;
	 	if(timer>= maxtime)
	 	
	 	timer = 0.f;
	 	
        	shape.move(movspeed , 0 );
 	 }
 	 
   virtual Sprite& getSprite() 
   {
        return shape;
   }
   
   virtual void loadsprite()=0;
   virtual bool timecheck(float t)=0;
	
};
