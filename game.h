#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "player.h"
#include "pause.h"
#include"enemy.h"
#include"monster.h"
#include"invader.h"					// more then one enemy ==  no bullets
#include"aplha.h"					// array of enemies   == no monsters
#include"beta.h"
#include"gema.h"
#include"menu.h"
#include"dragon.h"
#include"addons.h"
#include <SFML/Audio.hpp>
#include<cmath>
#include"filehandeling.cpp"

//#include"lives.h"
//#include "bullet.cpp"					//fire function for enemy ==  slow down

const char title[] = "OOP-Project, Spring-2023";
using namespace sf;
using namespace std;

class Game
{
public:
int lives, points, level,counter;
Menu m;
Pause res;
Sprite background; //Game background sprite
Texture bg_texture;
Player* p; //player
string name;
int id;
float temptime,bombtime,montime, dragtime, spawntime,spawntime2 ;
bool pressed, collision, flag, mon, drag, spawnmon, spawndrag, mondodge, dragdodge;

int size, levelcount;
bool active[12], bomb, beef,all, levelflag;

enemy **arr;	// enemy
// add other game attributes
int  *ptr;
int levelcounter;
int a;
float waqt;
addons *liv;
addons *brust;


Game()
{
cout<<"ENTER NAME: ";
cin>>name;

cout<<"ENTER ID:";
cin>>id;
brust = new fire_7;
liv = new zindagi; 
//cout<<"gc";
p = new Player("img/player_ship.png");
//en = &mon;
/*
mon = new monster;
ene[0] =  new enemy(100,0,0.1);
ene[1] =  new enemy(200,0,0.1);
ene[2] =  new enemy(300,0,0.1);
ene[3] =  new enemy(400,0,0.1);
ene[4] =  new enemy(500,0,0.1);
*/
//en1= new enemy(100,0,0.1);
//en2= new enemy(300,0,0.2); 
//en1 = new enemy;
levelflag = true, spawnmon = true, spawndrag = true;
size=12, lives = 5,points = 0, level = 1;
temptime =0, spawntime=0,spawntime=0;
bombtime=0, montime=0,dragtime=0;
//bombtime=0;
//mon -> loadsprite();
a=0;
levelcount = 0;
pressed = true;
collision = false;
//en1 -> loadsprite();
counter =0;
//ptr = new int[counter+1];
flag = false;
//cout<<"arr";
for(int i=0 ; i<size ; i++)
active[i] = true;
bomb = false;
beef = false;
all = false;
mon = true;
mondodge = false, dragdodge = false;
waqt = 0;

//ptr = new int[counter];
levelcounter = 0;

arr = new enemy*[size];




bg_texture.loadFromFile("img/background.jpg");
background.setTexture(bg_texture);
background.setScale(2, 1.5);
//b=new Bullet("img/PNG/Lasers/laserBlue01.png", p->sprite.getPosition().x, p->sprite.getPosition().y, 0.5f);


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
	//if(x2 < x1+sw1 && x2+sw2< x1 && y2< y1+sh1 && y2+sh2 > y1  )
	if(x1<=x2 && x1+sw1 >= x2+sw2 && y2< y1+sh1 && y2+sh2 > y1 )
	{	
		return true;
	}
	else
	return false;

}


	virtual bool check_mon(Sprite &shape1, Sprite& shape2)
{
	float x1 = shape1.getPosition().x;
	float y1 = shape1.getPosition().y;
	float sw1 = shape1.getTexture()->getSize().x;
	float sh1 = shape1.getTexture()->getSize().y;
	float x2  = shape2.getPosition().x;
	float y2  = shape2.getPosition().y;
	float sw2 = shape2.getTexture()->getSize().x;
	float sh2 = shape2.getTexture()->getSize().y;
	cout<<x1<<"         x       "<<x1+sw1<<endl;
	cout<<y1<<"         y       "<<y1+sh1<<endl;
	//if(x2 < x1+sw1 && x2+sw2< x1 && y2< y1+sh1 && y2+sh2 > y1  )
	
	if(x1<=x2 && x1+sw1-900 >= x2+sw2 || (y2 >= 290 && y2+sh2 <= 350) )
	{	//cout<<x1<<"            "<<x1+sw1<<endl;
		//cout<<p->sprite.getPosition().x<<"	player	"<<p->sprite.getPosition().y<<endl;
		return true;
	}
	else
	return false;

}


	virtual bool check_mon2(Sprite &shape1,float x1, float y1, Sprite& shape2,float x2, float y2)
{
	//float x1 = shape1.getPosition().x;
	//float y1 = shape1.getPosition().y;
	float sw1 = shape1.getTexture()->getSize().x;
	float sh1 = shape1.getTexture()->getSize().y;
	///float x2  = shape2.getPosition().x;
	//float y2  = shape2.getPosition().y;
	float sw2 = shape2.getTexture()->getSize().x;
	float sh2 = shape2.getTexture()->getSize().y;
	cout<<x1<<"         x       "<<x1+sw1<<endl;
	cout<<y1<<"         y       "<<y1+sh1<<endl;
	//if(x2 < x1+sw1 && x2+sw2< x1 && y2< y1+sh1 && y2+sh2 > y1  )
	
	if(x1<=x2 && x1+sw1+100 >= x2 && (y2 >= 200 && y2 <= 260) )
	{	//cout<<x1<<"            "<<x1+sw1<<endl;
		//cout<<p->sprite.getPosition().x<<"	player	"<<p->sprite.getPosition().y<<endl;
		return true;
	}
	else
	return false;

}



	virtual bool check_drag(Sprite &shape1, Sprite& shape2)
{
	float x1 = shape1.getPosition().x;
	float y1 = shape1.getPosition().y;
	float sw1 = shape1.getTexture()->getSize().x;
	float sh1 = shape1.getTexture()->getSize().y;
	float x2  = shape2.getPosition().x;
	float y2  = shape2.getPosition().y;
	float sw2 = shape2.getTexture()->getSize().x;
	float sh2 = shape2.getTexture()->getSize().y;
	cout<<x1<<"                "<<x1+sw1<<endl;
	cout<<y1<<"                "<<y1+sh1<<endl;
	//if(x2 < x1+sw1 && x2+sw2< x1 && y2< y1+sh1 && y2+sh2 > y1  )
	
	if(200<=x2 && 740 >= x2+sw2 && y2 >= 10 && y2+sh2 <= 500 )
	{	//cout<<x1<<"            "<<x1+sw1<<endl;
		//cout<<p->sprite.getPosition().x<<"	player	"<<p->sprite.getPosition().y<<endl;
		return true;
	}
	else
	return false;

}

	virtual bool check_dragfire(Sprite &shape1, Sprite& shape2 )
{
	float x1 = shape1.getPosition().x;
	float y1 = shape1.getPosition().y;
	float sw1 = shape1.getTexture()->getSize().x;
	float sh1 = shape1.getTexture()->getSize().y;
	float x2  = shape2.getPosition().x;
	float y2  = shape2.getPosition().y;
	float sw2 = shape2.getTexture()->getSize().x;
	float sh2 = shape2.getTexture()->getSize().y;
	cout<<x1<<"                "<<x1+sw1<<endl;
	cout<<y1<<"                "<<y1+sh1<<endl;
	//if(x2 < x1+sw1 && x2+sw2< x1 && y2< y1+sh1 && y2+sh2 > y1  )
	
	if(x1>=x2 && x1 <= x2+sw2 && y1 >= y2 && y2+sh2 <= y1  )
	{	//cout<<x1<<"            "<<x1+sw1<<endl;
		//cout<<p->sprite.getPosition().x<<"	player	"<<p->sprite.getPosition().y<<endl;
		return true;
	}
	else
	return false;

}




void start_game()
{	//cout<<"////";

Music sound;
sound.setVolume(50);
sound.openFromFile("Brave Pilots (Menu Screen).ogg");
sound.setLoop(true);
sound.play();

    srand(time(0));
   
    RenderWindow window(VideoMode(780, 780), title);

  
    m.display_front_screen(window, background);
    Font font;
    if(!font.loadFromFile("Pain Circus.ttf"))
        {
            // error handling here
            cout << "Error: Font not found!" << endl;
        }
            sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    sf::Text livesText;
    livesText.setFont(font);
    livesText.setCharacterSize(24);
    livesText.setFillColor(sf::Color::White);
    livesText.setPosition(330, 10);
    
    sf::Text timeText;
    timeText.setFont(font);
    timeText.setCharacterSize(24);
    timeText.setFillColor(sf::Color::White);
    timeText.setPosition(600, 10);

    Clock clock;
    float timer=0; 
    int timer2=0;
 //  cout<<"open";
    while (window.isOpen())
    {
    
        float time = clock.getElapsedTime().asSeconds();
        bombtime =  clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time; 
        bombtime += time; 
        timer2 += time;  
 	Event e;
 	
 	
 if(level == 1 && levelflag == true && levelcounter ==0 )
 {
 //   square
 
arr[0] = new alpha(100, 100, 0.01);
arr[1] = new alpha(100, 300, 0.01);
arr[2] = new alpha(500, 100, 0.01);
arr[3] = new alpha(500, 300, 0.01);
arr[4] = new gema(100, 170, 0.01);
arr[5] = new alpha(300, 100, 0.01);		//square
arr[6] = new alpha(300, 300, 0.01);
arr[7] = new alpha(600, 100, 0.01);
arr[8] = new alpha(600, 200, 0.01);
arr[9] = new alpha(600, 300, 0.01);
arr[10] = new dragon(200,10);
arr[11] = new monster(100,200);

levelflag = false;
}

if(level == 1 && levelflag == true && levelcounter ==1 )
{
arr[0] = new alpha(100, 100, 0.01);
arr[1] = new alpha(200, 100, 0.01);
arr[2] = new alpha(300, 100, 0.01);		// triangle
arr[3] = new alpha(400, 100, 0.01);
arr[4] = new gema(150, 200, 0.01);
arr[5] = new alpha(250, 200, 0.01);
arr[6] = new alpha(350, 200, 0.01);
arr[7] = new alpha(200, 300, 0.01);
arr[8] = new alpha(300, 300, 0.01);
arr[9] = new alpha(250, 400, 0.01);
arr[10] = new dragon(200,10);
arr[11] = new monster(100,200);

levelflag = false;
}

if(level == 1 && levelflag == true && levelcounter ==2 )
{
arr[0] = new alpha(250, 100, 0.01);
arr[1] = new alpha(350, 100, 0.01);
arr[2] = new alpha(300, 150, 0.01);
arr[3] = new alpha(300, 250, 0.01);
arr[4] = new gema(300, 200, 0.01);		//cross
arr[5] = new alpha(250, 300, 0.01);
arr[6] = new alpha(350, 300, 0.01);
arr[7] = new alpha(300, 350, 0.01);
arr[8] = new alpha(300, 450, 0.01);
arr[9] = new alpha(250, 400, 0.01);

arr[10] = new dragon(200,10);
arr[11] = new monster(100,200);

levelflag = false;
}


if(level == 2 && levelflag == true && levelcounter ==2 )
{
arr[0] = new alpha(300, 100, 0.01);
arr[1] = new alpha(200, 200, 0.01);
arr[2] = new alpha(300, 300, 0.01);
arr[3] = new alpha(400, 200, 0.01);
arr[4] = new gema(300, 200, 0.01);
arr[5] = new alpha(200, 100, 0.01);
arr[6] = new alpha(400, 100, 0.01);
arr[7] = new alpha(200, 300, 0.01);		// box
arr[8] = new alpha(400, 300, 0.01);
arr[9] = new alpha(300, 400, 0.01);
arr[10] = new dragon(200,10);
arr[11] = new monster(100,200);

levelflag = false;
}

 if(level == 2 && levelflag == true && levelcounter ==0 )
 {


float midX = 400; // X coordinate of the center point
float midY = 300; // Y coordinate of the center point
float radius = 200; // Radius of the circle
float newangle = 2 * M_PI / 10; // Angle increment for each object

for (int i = 0; i < 10; i++) {				//circle
    float angle = i * newangle;
    float x = midX + radius * std::cos(angle);
    float y = midY + radius * std::sin(angle);
    arr[i] = new alpha(x, y, 0.06);
}
arr[10] = new dragon(200,10);
arr[11] = new monster(300,200);

levelflag = false;
}


if(level == 2 && levelflag == true && levelcounter ==1 )
{
arr[0] = new alpha(300, 100, 0.01);
arr[1] = new alpha(400, 200, 0.01);
arr[2] = new alpha(500, 300, 0.01);
arr[3] = new alpha(400, 400, 0.01);
arr[4] = new alpha(300, 500, 0.01);		//diamond
arr[5] = new alpha(200, 400, 0.01);
arr[6] = new alpha(100, 300, 0.01);
arr[7] = new alpha(200, 200, 0.01);


arr[10] = new dragon(200,10);
arr[11] = new monster(100,200);

levelflag = false;

}

 if(level == 3 && levelflag == true && levelcounter == 0)
 {
arr[0] = new gema(300, 100, 0.01);
arr[1] = new gema(200, 200, 0.01);
arr[2] = new gema(300, 300, 0.01);
arr[3] = new gema(400, 200, 0.01);
arr[4] = new gema(300, 200, 0.01);
arr[5] = new gema(200, 100, 0.01);
arr[6] = new gema(400, 100, 0.01);
arr[7] = new gema(200, 300, 0.01);		// box
arr[8] = new gema(400, 300, 0.01);
arr[9] = new gema(300, 400, 0.01);

arr[10] = new dragon(200,10);
arr[11] = new monster(300,200);

levelflag = false;
}

if(level == 3 && levelflag == true && levelcounter == 1)
 {
 
 arr[0] = new gema(300, 100, 0.01);
arr[1] = new alpha(400, 200, 0.01);
arr[2] = new gema(500, 300, 0.01);
arr[3] = new alpha(400, 400, 0.01);
arr[4] = new gema(300, 500, 0.01);		//diamond
arr[5] = new alpha(200, 400, 0.01);
arr[6] = new gema(100, 300, 0.01);
arr[7] = new alpha(200, 200, 0.01);


arr[10] = new dragon(200,10);
arr[11] = new monster(100,200);

levelflag = false;
}

if(level == 3 && levelflag == true && levelcounter == 2)
{
arr[0] = new alpha(100, 100, 0.01);
arr[1] = new gema(200, 100, 0.01);
arr[2] = new alpha(300, 100, 0.01);		// triangle
arr[3] = new gema(400, 100, 0.01);
arr[4] = new alpha(150, 200, 0.01);
arr[5] = new gema(250, 200, 0.01);
arr[6] = new alpha(350, 200, 0.01);
arr[7] = new gema(200, 300, 0.01);
arr[8] = new alpha(300, 300, 0.01);
arr[9] = new gema(250, 400, 0.01);
arr[10] = new dragon(200,10);
arr[11] = new monster(100,200);

levelflag = false;
}



 	
 	 
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game                        	    
        }
        //  cout<<"open";
	if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
	{
           p->move("r");  //player will move to right
        }   
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed 
            p->move("d");  //player will move downwards
     //   if (Keyboard::isKeyPressed(Keyboard::Space)) // If down key is pressed
       //     p->move("p");  //player will move downwards
       if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right) )
       {
       p->move("t");
       pressed = true;
       }
       
       if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left) )
       {
       p->move("lt");
       pressed = true;
       }
       
       

         if (Keyboard::isKeyPressed(Keyboard::Space))
         {
         	if(timer - temptime >0.5)
         	{
		 	p->fire();
		 	//cout<<"bullet\n";
		 	temptime = timer;
         	} 
	 }
	 
	 if(p->b != nullptr && p->b->shape.getPosition().y < 0)
	 {
		 delete p->b;
		 p->b=nullptr;
	 }
        // if (e.type == Event :: KeyPressed && e.key.code == sf::Keyboard::) // If down key is pressed
        if(e.key.code == sf::Keyboard::Escape)
         {
         	flag = !flag;
         	if(flag)
            res.displayPause();
         }
	////////////////////////////////////////////////
	/////  Call your functions here            ////
	//////////////////////////////////////////////

	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background
	window.draw(p->sprite);   // setting player on screen
	//if (flag)
	{
	/*
	for(int i=0 ; i < p->counter ; i++)
	{
         	window.draw(p->b[i].shape);
         	p-> b[i]. update();
        }
        */
	if(p->b != nullptr)
	{
    		window.draw(p->b->shape);
    		p-> b-> update();
	}
	}



	for(int i=0 ; i<size-2 ; i++)
{
if(int(timer) %20 == 0 && timer >1 )
{
spawntime2 = timer;
spawndrag = false;
}

if(spawndrag == false && i != 11)
{




if(timer - spawntime2 > 5)
{
cout<<"========================================================="<<endl;
if(!dragdodge)
{
cout<<"========================================================="<<endl;
points = arr[10][0].score(points);

}
dragdodge = false;
spawndrag = true;

}

i=10;
//waqt+=time;
//cout<<waqt<<endl;
//cout<<"start"<<endl;
   if(p->b != nullptr && check_mon(arr[i][0].shape, p->b->shape))
    {
   // cout<<"ddddddddddd"<<endl;
       // active[i] = false;
        //collision = true;
    }
    
    if(!active[i])
    {
    //cout<<i;
    continue; 
    }
    
    else
    {
    
     window.draw(arr[i][0].shape); 
    
     if(timer - dragtime >1 )
     { 
     dragtime = timer;
  //if(  arr[i]->b != nullptr) 
  
   //arr[i][0].b = nullptr;
   
     //arr[i]->update();
     int f = p->sprite.getPosition().x;
     cout<<f<<"		[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[["<<endl;
       if(f > 200 && f<= 400)
     {
     cout<<"sss"<<endl;
     arr[i] -> fire_s();
  //    arr[i] -> fire();
     
     }
    
        
     if(f>= 0 && f<= 200)
     {
      cout<<"llll"<<endl;
     arr[i] -> fire_l();
  //arr[i] -> fire();
       }
       
    // if(f > 400 && f<= 750)
    	else
    	{
    	 cout<<"r"<<endl;
     arr[i] -> fire_r();
   // arr[i] -> fire();
     
     }
     if(arr[i]->b != nullptr) 
     {      
       window.draw(arr[i]->b->shape);
      arr[i]->b->update();
      } 
       
        
                   // arr[i]-> b-> update();
           
   // dragtime += time;
    
    /* if(waqt - dragtime > 1.5) 
     {
     dragtime  = waqt;
     cout<<dragtime<<"----------------------------------------------------"<<endl;
     cout<<"dt";
   //dragtime=0;
   }*/
     }
//cout<<"ddddddddddd"<<endl;
      if(arr[i]->b != nullptr)   
      {    
      
      window.draw(arr[i]->b->shape);
     }
     
   
	
	  
	if(arr[i][0].b != nullptr && check_dragfire(   p->sprite , arr[i][0].b->shape))
    {
    dragdodge= true;
    	lives--;
    	bomb = true;
    }
    
    if(bomb)
    {
    	p->sprite.setPosition(340,700);
    	bomb = false;
    }
   
    
     if(arr[i][0].b != nullptr && check_drag(arr[i][0].shape, p->sprite))
    {
    	lives--;
    	beef = true;
    	dragdodge = true;
    }
    
    if(beef)
    {
    	p->sprite.setPosition(340,700);
    	beef = false;
    }
   /*
    for(int k=0 ; k<size ; k++)
    {
  
    	if(active[k])
    	{
    		all = false;
    		break;
    	}
  	
    	else
    	{
    	
    	all = true;
    
    	}
    	
    	//cout<<k;	
    }
    */
}
}



//int x = rand() %5; 


else if(int (timer) % 30  == 0 && timer > 1 && i != 10 )
{
//cout<<timer<<endl;
spawnmon = false;
spawntime = timer;
}
/*
if(spawnmon == false)
{
spawntime = timer;
spawnmon = true;
}
*/
if(spawnmon == false && i != 10)
{
if(timer - spawntime > 5)
{
if(!mondodge)
{
cout<<"========================================================="<<endl;
points = arr[11][0].score(points);

}
mondodge = false;
spawnmon = true;
}
i=11;
//montime = timer;
//cout<<"sv"; 
if(p->b != nullptr && check_mon(arr[i][0].shape, p->b->shape))
    {
       // active[i] = false;
       //cout<<i;
        collision = true;
        cout<<p->b->shape.getPosition().x<<"yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy"<<endl;
    }
    
    if(!active[i])
    {
    //cout<<i;
    continue; 
    }
    
    else
    { 
  /*  if(timer > 4 && timer < 6)
    {
    mon = true;
    montime=0;
     }
     else 
     mon = false ;
     */
     
     if(montime>=1 )
     {
     window.draw(arr[i][0].shape); 
     //arr[i]->update();
     arr[i]->b= nullptr;
     arr[i] -> fire_mon( arr[i]->shape.getPosition().x, arr[i]->shape.getPosition().y);
   //  cout<<arr[i]->shape.getPosition().x<<endl;
        if(arr[i]->b != nullptr)
            {
            	
                window.draw(arr[i]->b->shape);
                   // arr[i]-> b-> update();
           }
     montime += time;
     if(montime>=3) 
     montime=0;
     }
     
       else  
     {
        window.draw(arr[i][0].shape);
        arr[i]->update(); 
        montime+=time;
        if(arr[i]->b != nullptr)
            {
                   // window.draw(arr[i]->b->shape);
                   // arr[i]-> b-> update();
           } 
     }
    
          
          
        
        
    }
    
    if(!active[i])
    p->sprite.setPosition(340,700);
    
  
    if(arr[i][0].b != nullptr && check_mon2( arr[i][0].b->shape , arr[i]->shape.getPosition().x , arr[i]->shape.getPosition().y ,p->sprite, p->sprite.getPosition().x , p->sprite.getPosition().y ))
    {
    	cout<<p->sprite.getPosition().x<<"	player	"<<p->sprite.getPosition().y<<endl;
    	delete arr[i][0].b;
    	arr[i][0].b = nullptr;
    	bomb = true;
    	lives--;
    	cout<<lives<<"-------------------"<<endl;
    	mondodge= true;
    }
    
    if(bomb)
    {
    	p->sprite.setPosition(340,700);
    	bomb = false;
    }
    
    
     if(arr[i][0].b != nullptr && check_dragfire(p->sprite, arr[i][0].b->shape ))
    {
   lives--;
    cout<<lives<<"-------------------"<<endl;
    	beef = true;
    	mondodge = true;
    }
   
    if(beef)
    {
    	p->sprite.setPosition(340,700);
    	beef = false;
    }
    
   
    }
    else if( i != 10 && i!= 11)
    {
    //cout<<"tttttttttttttttttttttt"<<endl;
    if(p->b != nullptr && check(arr[i][0].shape, p->b->shape))
    {
    
    	delete p->b;
    	p->b = nullptr;
    	arr[i][0].score(points);
    //	cout<<points<<"555555555555555555555555555555555555555555555555555555555"<<endl;
        active[i] = false;
        counter++;
        cout<<counter<<"		cccccccccccccccccccccccccccccccccccccccccccccccccccccccccc"<<endl;
       //cout<<i;
        collision = true;
       // lives--;
        //cout<<lives<<endl;
        arr[i][0].shape.setPosition(-1000,0);
    }
    
    if(int(timer)%10 == 0 && timer>1)
    {
    	window.draw(liv->shape);
    }
    
    if(liv->shape.getPosition().y<780)
    {					//TODO 		POWER UP (LIVES)
    window.draw(liv->shape);
    liv->update();
    }
    
    
    if(check(p->sprite, liv->shape))
    {
    lives++;
    cout<<lives<<"        ooooooooooooooooooooooooooooooooooooooooooooooooo"<<endl;
    liv->shape.setPosition(4040,1212);
    }
    
    if(int(timer)%10 == 0 && timer>1)
    {
    window.draw(brust->shape);
    }
    
    if(brust->shape.getPosition().y<780)
    {					//TODO 		POWER UP (LIVES)
    window.draw(brust->shape);
    brust->update();
    }
    
    if(check(p->sprite, brust->shape))
    {
    	brust->fire(p->sprite.getPosition().x , p->sprite.getPosition().y);
    	//brust->b->update;
    	
    	for(int j=0 ; j<7 ;j++)
    	{
    		window.draw(brust->b[j].shape);
    		brust->b[j].update();
    		
    	}
    	brust->shape.setPosition(4040,1212);
    	//brust->hamla(p->sprite.getPosition().x , p->sprite.getPosition().y);
    	/*if(brust->b != nullptr && brust->b->shape.getPosition().y < 0)
	 {
		 delete brust->b;
		 brust->b=nullptr;
	 }
    	window.draw(brust->b->shape);
    	brust->b->update();
    	brust->shape.setPosition(4040,1212);
    	*/
    }
    
    if(!active[i])
    {
    //cout<<i;
    continue; 
    }
    
    
    
    else
    { 
        window.draw(arr[i][0].shape);
        arr[i]->update();
       // if(i<2 && timer - bombtime >= 0.75)
        {//cout<<"d";
            arr[i] -> fire();
            bombtime = 0;
                
            if(arr[i]->b != nullptr && arr[i]->timecheck(timer)  )  //arr[i]->b->shape.getPosition().y > 780)
            {   
                 delete arr[i]->b;
                 arr[i]->b=nullptr;
            }
            
            if(arr[i]->b != nullptr)
            {
                    window.draw(arr[i]->b->shape);
                    arr[i]-> b-> update();
            }
        }
    if(arr[i][0].b != nullptr && check(p->sprite, arr[i][0].b->shape))
    {
    delete arr[i][0].b;
    	arr[i][0].b = nullptr;
    	lives--;
    	cout<<lives<<"-------------------"<<endl;
    	bomb = true;
    }
    
    if(bomb)
    {
    	p->sprite.setPosition(340,700);
    	bomb = false;
    }
    
    
     if(arr[i][0].b != nullptr && check(arr[i][0].shape, p->sprite))
    {
    	
    	lives--;
    	cout<<lives<<"-------------------"<<endl;
    	beef = true;
    }
    
    if(beef)
    {
    	p->sprite.setPosition(340,700);
    	beef = false;
    }
    
    for(int k=0 ; k<size-2 ; k++)
    {
   
    	if(active[k])
    	{
    		all = false;
    		
    		break;
    	}
  	
    	else
    	{
    	//cout<<k<<"\\\\\\\\\\\\\\\\\\\\\\\\\\"<<endl;
    //	all = true;
    	
    	//cout<<k<<endl;
    	
    
    	}
    	
    	//cout<<k;	
    }
  //  cout<<all;
   // cout<<"///";
    
    if( counter>=9)
    {
     cout<<".............................."<<endl;
     levelcounter++;
     if(levelcounter>2)
     {
     level++;
     levelcounter=0;
     }
     levelflag = true;
     counter = 0;
     for(int k=0 ; k<size-2 ; k++)
    {
    active[k] = true;
    }
	if(level>3)
	{
	input(points, name, id);
	output();
	m.gameover()                                                                   ;
	return;
	}
   // cout<<"..";
    
    }
}
}

///////////------------------------	lives 	power up	---------------------------------------///////////////////////////////
/*
if (rand() %200 == 6)
{
	
	if(check(arr[i][0].shape, liv->shape))	
	{
	lives++;
	cout<<lives<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	}
	
	else
	{
	window.draw(liv->shape);
	liv->update();
	}
	
}*/

}
collision = false;
flag = false;


	if(lives<=0)
	{
	input(points, name, id);
	output();
	m.gameover();
	return;
	}
	
	scoreText.setString("Score: " + std::to_string(points));
        livesText.setString("Lives: " + std::to_string(lives));
        timeText.setString("TIME: " + std::to_string(timer));
                window.draw(scoreText);
        window.draw(livesText);
        window.draw(timeText);
	window.display();  //Displying all the sprites
	
    }
    }

};

#endif
