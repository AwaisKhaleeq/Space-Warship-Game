#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class alpha : public invader
{
public:

	alpha()
	{
		tex.loadFromFile("img/enemy_1.png");
		shape.setTexture(tex);
		shape.setPosition(rand() %200 ,0 );
		shape.setScale(0.7,0.7);
		maxtime = 50.f;
		timer = maxtime;
		b = nullptr;
		counter =5;
		lasttime= 0;
		flag = false;
		
	}
	
	alpha( float x, float y, float speed)
	{
		tex.loadFromFile("img/enemy_1.png");
		shape.setTexture(tex);
		shape.setPosition(x ,y );
		shape.setScale(0.7,0.7);
		maxtime = 50.f;
		timer = maxtime;
		b = nullptr;
		counter =5;
		movspeed = speed;
		
	
	}

	virtual void update() 
	 { 
	
	 	
	 	
	 	
        	shape.move(movspeed , 0 );
        	float x1 = shape.getPosition().x;
		float y1 = shape.getPosition().y;
		
		if(x1>700)
		{
		//while(x1<0)
		shape.setPosition(0,y1);
		}
 	 }
 	 
  virtual Sprite& getTexture() 
   {
        return shape;
   }
   
   virtual void loadsprite() override
	{
		tex.loadFromFile("img/enemy_2.png");
		shape.setTexture(tex);
	}
	
	int score(int &s)
	{cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
		s+=10;
		return s;
	}

/*	
	   void fire()
{
 
 //cout<<"fire\n";  
float x1 = shape.getPosition().x;
float y1 = shape.getPosition().y;

if(b == nullptr)
    b = new Bullet[1] {Bullet("img/enemy_laser.png", x1, y1, 0.2f)};
else
{
    // Create a new bullet object with the given parameters
    Bullet newBullet("img/enemy_laser.png", x1, y1, 0.2f);

    // Create a new array with size equal to counter + 1
    Bullet* newBulletArray = new Bullet[counter + 1];

    // Copy the contents of the old array to the new array
    for(int i=0 ; i<counter ; i++)
    {
        newBulletArray[i] = b[i];
    }

    // Add the new bullet object to the end of the new array
    newBulletArray[counter] = newBullet;

    // Delete the old array
    delete[] b;

    // Point b to the new array
    b = newBulletArray;

    // Increment counter
    //counter += 1;
}

}
*/



void fire()
{
 
 //cout<<"fire\n";  
float x1 = shape.getPosition().x;
float y1 = shape.getPosition().y;

if(b == nullptr)
    b = new Bullet("img/enemy_laser.png", x1, y1, 0.2f);

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

virtual bool timecheck(float t)
{
if(t - lasttime > 5)
{
flag = true;
lasttime = t;
}

else
flag = false;



return flag;
	
}

};
