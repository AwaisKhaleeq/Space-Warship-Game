
/*
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class dragon : public enemy
{
public:
dragon()
	{
		tex.loadFromFile("img/dragon2.png");
		shape.setTexture(tex);
		shape.setPosition(rand() %200 ,0 );
		shape.setScale(0.7,0.7);
		maxtime = 50.f;
		timer = maxtime;
		b = nullptr;
		counter =5;
		
	}
	
dragon( float x, float y)
	{
		tex.loadFromFile("img/dragon2.png");
		shape.setTexture(tex);
		shape.setPosition(x ,y );
		shape.setScale(0.7,0.7);
		maxtime = 50.f;
		timer = maxtime;
		b = nullptr;
		counter =5;
		movspeed = 5;
		
	
	}
	
void fire_s()
{
 
 //cout<<"fire\n";  
float x1 = shape.getPosition().x;
float y1 = shape.getPosition().y;

if(b == nullptr)
    b = new Bullet("img/PNG/Lasers/laserGreen04.png", x1+190, y1+330, 0.5f, 5, 17);

}

void fire_l()
{
 
 //cout<<"fire\n";  
float x1 = shape.getPosition().x;
float y1 = shape.getPosition().y;

if(b == nullptr)
    b = new Bullet("img/fire_l.png", x1+190, y1+330, 0.5f, 5, 17);

}

void fire_r()
{
 
 //cout<<"fire\n";  
float x1 = shape.getPosition().x;
float y1 = shape.getPosition().y;

if(b == nullptr)
    b = new Bullet("img/fire_r.png", x1+190, y1+330, 0.5f, 5, 17);

}
*/
/*
virtual void update() 
	 { 
	 	timer +=0.5f;
	 	if(timer>= maxtime)
	 	
	 	timer = 0.f;
	 	
        	shape.move(0 , 0);
        	
        	float x1 = shape.getPosition().x;
		float y1 = shape.getPosition().y;
		
		if(x1>500)
		{
		//while(x1<0)
		
		shape.setPosition(0,y1);
		}
 	 }


 virtual Sprite& getTexture() 
   {
        return shape;
   }
*/  
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class dragon : public enemy
{
public:
dragon()
	{
		tex.loadFromFile("img/dragon2.png");
		shape.setTexture(tex);
		shape.setPosition(rand() %200 ,0 );
		shape.setScale(0.7,0.7);
		maxtime = 50.f;
		timer = maxtime;
		b = nullptr;
		counter =5;
		
	}
	
dragon( float x, float y)
	{
		tex.loadFromFile("img/dragon2.png");
		shape.setTexture(tex);
		shape.setPosition(x ,y );
		shape.setScale(0.7,0.7);
		//maxtime = 50.f;
		//timer = maxtime;
		b = nullptr;
		counter =5;
		//movspeed = 5;
		
	
	}
	
	
void fire_s()
{
 
 //cout<<"fire\n";  
float x1 = shape.getPosition().x;
float y1 = shape.getPosition().y;
  if (b != nullptr)
    {
        delete b;
        b = nullptr;
    }

if(b == nullptr)
    b = new Bullet("img/PNG/Lasers/laserGreen06.png", x1+190, y1+330, 0.5f,0, 5, 15);

}
	
void fire_l()
{
 
 //cout<<"fire\n";  
float x1 = shape.getPosition().x;
float y1 = shape.getPosition().y;
  if (b != nullptr)
    {
        delete b;
        b = nullptr;
    }

if(b == nullptr)
    b = new Bullet("img/image (10).png", x1+80, y1+330, 0.5f,0, 5, 19);

}

void fire_r()
{
 
 //cout<<"fire\n";  
float x1 = shape.getPosition().x;
float y1 = shape.getPosition().y;
  if (b != nullptr)
    {
        delete b;
        b = nullptr;
    }

if(b == nullptr)
    b = new Bullet("img/image (8).png", x1+190, y1+330,1, 1, 5, 17);

}

int score(int &s)
	{
	cout<<"lllllllllllllllllllllllllllllllllllll"<<endl;
		s += 50;
		return s;
	}
virtual bool timecheck(float t){
return 0;}

virtual void update() 
	 { 
	
	 	
	 	
	 	
        	shape.move(0 , 1 );
        	float x1 = shape.getPosition().x;
		float y1 = shape.getPosition().y;
		
		if(x1>700)
		{
		//while(x1<0)
		shape.setPosition(0,y1);
		}
 	 }
 	 


};
