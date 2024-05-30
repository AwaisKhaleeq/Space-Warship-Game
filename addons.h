#include <SFML/Graphics.hpp>
#include"bullet.cpp"
using namespace sf;
using namespace std;

class addons
{
public:

Texture tex;
Sprite shape;
float movspeed;
float x,y;
Bullet b[7];


virtual void update(){}
virtual void fire(){}
virtual void hamla(float, float){}
virtual void fire(float, float){}

};


class zindagi: public addons
{
public:
	zindagi()
	{
		tex.loadFromFile("img/PNG/Power-ups/pill_green.png");
		shape.setTexture(tex);
		x= 180 , y=0;
		shape.setPosition( x ,y );
		shape.setScale(1.5,1.5);
		movspeed = 0.009;
	}
	
	void update()
	{
	float x1 = shape.getPosition().x;
	float y1 = shape.getPosition().y;
	
	//if(y1>780)
	shape.move(0 , movspeed );
	}

};


class fire_7 : public addons
{


public:
bool firing = false;
float timer = 0;
fire_7()
	{
		tex.loadFromFile("img/PNG/Power-ups/bolt_bronze.png");
		shape.setTexture(tex);
		x= 380 , y=0;
		shape.setPosition( x ,y );
		shape.setScale(1.7,1.7);
		movspeed = 0.009;
		//b = nullptr;
	}
	
	void update()
	{
	//float x1 = shape.getPosition().x;
	//float y1 = shape.getPosition().y;
	
	//if(y1>780)
	shape.move(0 , movspeed );
	}


void fire(float x1, float y1)
{
float directions[] = {-0.5f, -0.3f, -0.1f, 0.f, 0.1f, 0.3f, 0.5f};
float speed = -2.f;

firing = true;
timer = 5.f;

	
 for (int i = 0; i < 7; i++)
        {
            b[i] =  Bullet("img/enemy_laser.png", x1, y1, -2.f, directions[i],0.7,0.7);
            // add the new Bullet object to your game's bullets vector or list
        }

}


/*
void fire1(float x1, float y1)
{
if(b == nullptr)
    b = new Bullet("img/fire1.png", x1, y1, -2,-0.1);
}

void fire2(float x1, float y1)
{
//if(b == nullptr)
    b = new Bullet("img/fire2.png", x1, y1, -2,-0.3);
}

void fire3(float x1, float y1)
{
//if(b == nullptr)
    b = new Bullet("img/enemy_laser.png", x1, y1, -2.f);
}

void fire4(float x1, float y1)
{
//if(b == nullptr)
    b = new Bullet("img/fire3.png", x1, y1, -2, 0.1);
}

void fire5(float x1, float y1)
{
//if(b == nullptr)
    b = new Bullet("img/fire4.png", x1, y1, -2, 0.3);
}

void hamla(float x, float y)
{

float x1 = x;
float y1 = y;
	fire1(x1,y1);
	fire2(x1,y1);
	fire3(x1,y1);
	fire4(x1,y1);
	fire5(x1,y1);
}

*/


};





