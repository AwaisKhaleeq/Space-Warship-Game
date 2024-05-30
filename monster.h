#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class monster : public enemy
{
int counter;
public:

	monster()
	{
		tex.loadFromFile("img/monster.png");
		shape.setTexture(tex);
		movspeed = 0.01;
		shape.setPosition( 200 ,200 );
		shape.setScale(0.1,0.1);
		maxtime = 50.f;
		timer = maxtime;	
		b = nullptr;
		counter=0;

	}
	
	monster(float x, float y)
	{
		tex.loadFromFile("img/monster.png");
		shape.setTexture(tex);
		movspeed = 0.01;
		shape.setPosition(x ,y );
		shape.setScale(0.1,0.1);
		maxtime = 50.f;
		timer = maxtime;
		b = nullptr;	
		counter=0;
	}
	/*
	virtual void loadsprite() override
	{
		tex.loadFromFile("img/monter.png");
		shape.setTexture(tex);
	}
	*/
	
	void fire_mon(float x1, float y1)
{
 
 //cout<<"fire\n";  
//float x1 = shape.getPosition().x;
//float y1 = shape.getPosition().y;

if(b == nullptr)
    b = new Bullet("img/PNG/Lasers/laserRed01.png", x1+40, y1+90, 3,0, 7,17 );

}

int score(int &s)
	{
		return s+40;
	}

/*
	   void fire()
{
 
 //cout<<"fire\n";  
float x1 = shape.getPosition().x;
float y1 = shape.getPosition().y;

if(b == nullptr)
    b = new Bullet[1] {Bullet("img/PNG/Lasers/laserRed01.png", x1, y1, 1.f,1,1.5)};
//else
{
    // Create a new bullet object with the given parameters
    Bullet newBullet("img/PNG/Lasers/laserRed01.png", x1, y1, 1.f,1,1.5);

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
  //  delete[] b;

    // Point b to the new array
    b = newBulletArray;

    // Increment counter
    counter += 1;
    cout<<counter;
}

}
*/





	virtual void update() 
	 { 
	 	timer +=0.5f;
	 	if(timer>= maxtime)
	 	
	 	timer = 0.f;
	 	
        	shape.move(0.02 , 0);
        	
        	float x1 = shape.getPosition().x;
		float y1 = shape.getPosition().y;
		
		if(x1>500)
		{
		//while(x1<0)
		
		shape.setPosition(0,y1);
		}
 	 }
 	 
 	 virtual Sprite& getSprite() 
   {
        return shape;
   }
   
   virtual bool timecheck(float t){
 if(t - lasttime >5 )
	{
	flag = true;
	lasttime = t;
	}

	else
	flag = false;



	return flag;
   }
	
};
