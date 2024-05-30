#include<iostream>
#include <SFML/Graphics.hpp>
#include"bullet.cpp"
#include<cmath>
using namespace std;

class enemy {
public:

	Sprite shape;
	Texture tex;
	float movspeed;
	float x,y;
	float timer, maxtime;
	Bullet *b;
	int counter;
	 bool flag;
	 int lasttime;
	/*
	 enemy()
	{
		tex.loadFromFile("img/enemy_1.png");
		shape.setTexture(tex);
		shape.setPosition(rand() %200 ,0 );
		shape.setScale(0.7,0.7);
		maxtime = 50.f;
		timer = maxtime;
		b = nullptr;
		counter =5;
	
	} 
	
	
	enemy( float x, float y, float speed)
	{
		tex.loadFromFile("img/enemy_1.png");
		shape.setTexture(tex);
	  	movspeed = speed;
		shape.setPosition(x, y);
		shape.setScale(0.7,0.7);
		maxtime = 50.f;
		timer = maxtime;
		b = nullptr;
		counter =5;
	
	}
	*/
	
	
	
	
	
	
	virtual void update() 
	 { 
	 	timer +=0.5f;
	 	if(timer>= maxtime)
	 	
	 	timer = 0.f;
	 	
        	shape.move(0 , movspeed );
        	
        	float x1 = shape.getPosition().x;
		float y1 = shape.getPosition().y;
		
		if(y1>300)
		{
		shape.setPosition(x1,0);
		}
		
 	 }
 	 
   virtual Sprite& getTexture() 
   {
        return shape;
   }
   
   
   
  virtual void fire()
{
 
 //cout<<"fire\n";  
float x1 = shape.getPosition().x;
float y1 = shape.getPosition().y;

if(b == nullptr)
{
	b = new Bullet[1] {Bullet("img/enemy_laser.png", x1, y1, 0.2f)};
	//if(b.shape.shape.getPosition().y;
	
}

}

virtual bool check(Sprite &shape1, Sprite& shape2)
{
	float x1 = shape1.getPosition().x;
	float y1 = shape1.getPosition().y;
	float sw1 = shape1.getTexture()->getSize().x;
	float sh1 = shape1.getTexture()->getSize().y;
			
	float x2  = shape2.getPosition().x;
	float y2  = shape2.getPosition().y;
	float sw2 = shape2.getTexture()->getSize().x;
	float sh2 = shape2.getTexture()->getSize().y;
	
	if(x2 < x1+sw1 && x2+sw2< x1 && y2< y1+sh1 && y2+sh2 > y1  )
	{	
		return true;
	}
	
	else
	return false;

}
virtual int score(int &s)= 0;
virtual void fire_s(){}
virtual void fire_l(){}
virtual void fire_r(){}
virtual bool timecheck(float t)=0;
virtual void fire_mon(float, float){}
	

};
