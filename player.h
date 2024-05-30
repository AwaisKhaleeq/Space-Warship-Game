#include <SFML/Graphics.hpp>
#include<string.h>
#include<iostream>
#include"bullet.cpp"

using namespace std;
using namespace sf;
class Player{
public:
Texture tex,  tilt;
Sprite sprite, sprite2;
float speed=0.3;
int x,y;
Bullet *b; 
int counter;
Player(std::string png_path)
{


tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=340;y=700;
sprite.setPosition(x,y);
sprite.setScale(0.75,0.75);


b = nullptr;
}


void fire()
{
 
 cout<<"fire\n";  
float x1 = sprite.getPosition().x;
float y1 = sprite.getPosition().y;

if(b == nullptr)
    b = new Bullet("img/PNG/Lasers/laserBlue02.png", x1, y1, -2.f);

}



/*
void fire()
{
 
 cout<<"fire\n";  
float x1 = sprite.getPosition().x;
float y1 = sprite.getPosition().y;

if(b == nullptr)
    b = new Bullet[1] {Bullet("img/PNG/Lasers/laserBlue02.png", x1, y1, -4.f)};
else
{
    // Create a new bullet object with the given parameters
    Bullet newBullet("img/PNG/Lasers/laserBlue02.png", x1, y1, -4.f);

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
    counter += 1;
}

}
*/
	

/*

void move(std::string s){
float delta_x=0,delta_y=0;
int check_x = 0;
int check_y = 0;
*/
void move(std::string s){

 
    float delta_x=0,delta_y=0;
    if(s=="l")
    {
    tex.loadFromFile("img/player_ship.png");
	sprite.setTexture(tex);
        delta_x = -1;       //move the player left
       
    }
    else if(s=="r")
    {
    tex.loadFromFile("img/player_ship.png");
	sprite.setTexture(tex);
        delta_x =1;        //move the player right
        
       
    }
    if(s=="u")
    {
    tex.loadFromFile("img/player_ship.png");
	sprite.setTexture(tex);
        delta_y =-1;
        
       
    }   
    
    else if(s=="d")
    {
        delta_y = 1;
        
    }
    else if(s == "t")
    {
    	tex.loadFromFile("img/player_ship_rt.png");
	sprite.setTexture(tex);
    }
    
    if(s == "lt" )
    {
    tex.loadFromFile("img/player_ship_lt.png");
	sprite.setTexture(tex);
    }
    
    
    delta_x*=speed;
    delta_y*=speed;
    
    // Fix for wrapping around right edge of screen
    float check_x = sprite.getPosition().x + delta_x;
float check_y = sprite.getPosition().y+ delta_y;
    if (check_x < 0) {
        check_x = 700;
        }
        else if (check_x >700)
        {
        check_x = 0;
        }
        if (check_y < 0)
        {
        check_y = 780;
        }
        else if (check_y >780 )
        {
        check_y = 0;
        }
        sprite.setPosition(check_x, check_y); // Set y to its original value
    
    
    //sprite.move(delta_x, delta_y);
}




};
