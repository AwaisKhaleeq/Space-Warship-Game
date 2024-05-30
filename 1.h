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

//#include "bullet.cpp"					//fire function for enemy ==  slow down
//#include <vector>
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;
using namespace std;

class Game
{
public:

Menu m;
Sprite background; //Game background sprite
Texture bg_texture;
Player* p; //player

float temptime,bombtime,montime, dragtime;
bool pressed, collision, flag, mon, drag;
Pause res;
int size;
bool active[8], bomb, beef,all;

enemy **arr;	// enemy
// add other game attributes
int  *ptr;
int counter,a;
float waqt;



Game()
{

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

size=8;
temptime =0;
bombtime=0, montime=0,dragtime=0;
//bombtime=0;
//mon -> loadsprite();
a=0;
pressed = true;
collision = false;
//en1 -> loadsprite();
counter =0;
ptr = new int[counter+1];
flag = true;
cout<<"arr";
for(int i=0 ; i<size ; i++)
active[i] = true;
bomb = false;
beef = false;
all = false;
mon = true;
waqt = 0;
//ptr = new int[counter];

arr = new enemy*[size];
arr[0] = new alpha(100,0,0.01);
arr[1] = new alpha(600,0,0.01);
arr[2] = new gema (300,100,0.01);
arr[3] = new gema (400,100,0.01);
arr[4] = new gema (200,50,0.01);
arr[5] = new alpha(500,50,0.01);
arr[6] = new dragon(200,10);
arr[7] = new monster(300,200);
//cout<<"comp";
/*
for(int i=0 ; i<5 ; i++)
{
	int x= rand() % 700 + 50; // random x-coordinate between 50 and 750
    	int y =rand() %200; // top of the screen
  	 //en[i].shape.setPosition(en[i].x, en[i].y);
	arr[i] = new enemy( x , y , 0.1);
}
*/
/*
for(int i=0 ; i<5 ; i++)
{
	for(int j=0 ; j<5 ; j++)
	{
	 int x= rand() % 700 + 50; // random x-coordinate between 50 and 750
    	 int y =rand() %200; // top of the screen
  	 //en[i].shape.setPosition(en[i].x, en[i].y);
	ene[i][j] = enemy("img/enemy_1.png" , x , y , 0.1);
	}
}
*/
//cout<<"bg";
bg_texture.loadFromFile("img/background.jpg");
background.setTexture(bg_texture);
background.setScale(2, 1.5);
//b=new Bullet("img/PNG/Lasers/laserBlue01.png", p->sprite.getPosition().x, p->sprite.getPosition().y, 0.5f);

}
//arr.erase(arr.begin()+i)


//int NUM_ENEMIES = 5;

//enemy enemies[NUM_ENEMIES];

//enemy enemies[NUM_ENEMIES];


//en1 = new enemy[5]{enemy("img/enemy_1.png",0,0,0.1)};
/*
// Set initial positions of enemies at random x-coordinates at the top of the screen
for(int i=0; i<5; i++)
{
    en[i].x = rand() % 700 + 50; // random x-coordinate between 50 and 750
    en[i].y = 0; // top of the screen
    en[i].shape.setPosition(en[i].x, en[i].y); // use en[i] instead of enemies[i]
}
*/

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
	
	//if(x2 < x1+sw1 && x2+sw2< x1 && y2< y1+sh1 && y2+sh2 > y1  )
	if(x1<=x2+10 && x1+sw1-150 >= x2+sw2 && y2< y1+sh1 && y2+sh2 > y1 )
	{	
		return true;
	}
	
	else
	return false;

}





void start_game()
{	//cout<<"////";
    srand(time(0));
    RenderWindow window(VideoMode(780, 780), title);
    m.display_front_screen(window, background);
    Clock clock;
    float timer=0;
 //  cout<<"open";
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        bombtime =  clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time; 
        bombtime += time;   
 	Event e;
 	 
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
	
         if (e.type == Event :: KeyPressed && e.key.code == sf::Keyboard::P) // If down key is pressed
         {
         	//flag = !flag;
            res.display_pause();
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
	


	
	
	//for(int i=0 ; i<6 ; i++)
	{
		//cout<<"strat";
		//if(arr[i][0].shape.getTexture()->getSize().x == p->b->getTexture()->getSize().x || arr[i][0].getTexture()->getSize().y == p->b->getTexture()->getSize().y)
		/*
		if(p->b != nullptr)
		{
		
		if(check (arr[i][0].shape , p->b->shape))
		{
			active[i] = false;
			collision = true;
		}	
		}
		*/
		///////////////////	/////////////////////////	///////////////////////
		
		//if (p->b->shape.getGlobalBounds().intersects(arr[i][0].shape.getGlobalBounds())) 
		
		/*
		float x1 = arr[i][0].shape.getPosition().x;
		float y1 = arr[i][0].shape.getPosition().y;
		float sw1 = arr[i][0].getGlobalBounds()Width;
		float sh1 = arr[i][0].getGlobalBounds().Height;
		
		float x2 = p->b->shape.getPosition().x;
		float y2 = p->b->shape.getPosition().y;
		float sw2 = p->b->getGlobalBounds().Width;
		float sh2 = p->b->getGlobalBounds().Height;
		*/
	//	cout<<"ddaa";
		//if(x2 < x1+sw1 && x2+sw2< x1 && y2< y1+sh1 && y2+sh2 > y1  )
		//collision  = true;
		/*
		for(int l =0 ; l<counter; l++ )
		{
			if(i == ptr[l])
			{
			flag = true;
			break;
			}
		}
		*/
		//if( i == a&&flag ==true)
		//continue;
		
		//else
		/*
		{
		
		if(active[i])
		{ 
			window.draw(arr[i][0].shape);
			arr[i]->update();
			//if(timer - bombtime > 0.5)
			if(i<2 && timer - bombtime >= 0.75)
			{
				arr[i] -> fire();
				bombtime = 0;
					
				if(arr[i]->b != nullptr && arr[i]->b->shape.getPosition().y > 780)
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
			
			else if(i>=2)
			{
				cout<<"else";
				arr[i] -> fire();
				if(arr[i]->b != nullptr && arr[i]->b->shape.getPosition().y > 780)
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
			cout<<"end";
		}
		
		
		}
	//	collision = false;
		//flag = false;
	*/
	}
	
	for(int i=0 ; i<size-2 ; i++)
{
if(timer >5 && timer<15)
{
i=6;
waqt+=time;
cout<<waqt<<endl;
   if(p->b != nullptr && check_mon(arr[i][0].shape, p->b->shape))
    {
        //active[i] = false;
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
     if(waqt - dragtime > 1)
     {
     dragtime = waqt;
     
   
     //arr[i]->update();
     int f = p->sprite.getPosition().x;
       if(f > 200 && f<= 400)
     {
     arr[i] -> fire_s();
     
     }
    
        
     if(f>= 0 && f<= 200)
     {
     arr[i] -> fire_l();
       }
       
    // if(f > 400 && f<= 750)
    	else
    	{
     arr[i] -> fire_r();
     
     }
     
      if(arr[i]->b != nullptr)       
       window.draw(arr[i]->b->shape);
        
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
      if(arr[i]->b != nullptr)       
      window.draw(arr[i]->b->shape);
     
     /*\\
     else 
     {
      cout<<"dt";
     dragtime=0;
	}
	
	}
	/*
	
	if(arr[i][0].b != nullptr && check(p->sprite, arr[i][0].b->shape))
    {
    	bomb = true;
    }
    
    if(bomb)
    {
    	p->sprite.setPosition(340,700);
    	bomb = false;
    }
    
    
     if(arr[i][0].b != nullptr && check(arr[i][0].shape, p->sprite))
    {
    	beef = true;
    }
    
    if(beef)
    {
    	p->sprite.setPosition(340,700);
    	beef = false;
    }
    
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






else if(timer>20 && timer<30)
{
i=7;
//montime = timer;
cout<<"sv"; 
if(p->b != nullptr && check(arr[i][0].shape, p->b->shape))
    {
        active[i] = false;
       //cout<<i;
        collision = true;
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
     
     if(montime>=2 )
     {
     window.draw(arr[i][0].shape); 
     //arr[i]->update();
     arr[i] -> fire();
        if(arr[i]->b != nullptr)
            {
            	
                window.draw(arr[i]->b->shape);
                   // arr[i]-> b-> update();
           }
     montime += time;
     if(montime>=4) 
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
      //if(timer - montime > 1)
        //mon = true;
       // arr[i]->update();
       // if(i<2 && timer - bombtime >= 0.75)
        cout<<"sv";
       // while(timer<8)
       
       
        //arr[i] -> fire();
            
          //  bombtime = 0;
            /*    
            if(arr[i]->b != nullptr && arr[i]->b->shape.getPosition().y > 780)
            // if(arr[i]->b != nullptr && arr[i]->b->shape.getPosition().y > 780)
            {   
                 delete arr[i]->b;
                 arr[i]->b=nullptr;
            }
            */
           cout<<"sv";
          //  for(int k=0 ; k <arr[i]->counter ; k++)
	/*{
         	window.draw(arr[i]->b->shape);
         	arr[i]->b->update();
        }*/
          
          /*
           if(arr[i]->b != nullptr)
            {
                    window.draw(arr[i]->b->shape);
                    //arr[i]-> b-> update();
           }
            */
        
        /*
        else if(i>=2)
        {
            arr[i] -> fire();
            if(arr[i]->b != nullptr && arr[i]->b->shape.getPosition().y > 780)
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
        */
    }
    if(arr[i][0].b != nullptr && check(p->sprite, arr[i][0].b->shape))
    {
    	bomb = true;
    }
    
    if(bomb)
    {
    	p->sprite.setPosition(340,700);
    	bomb = false;
    }
    
    
     if(arr[i][0].b != nullptr && check(arr[i][0].shape, p->sprite))
    {
    	beef = true;
    }
    
    if(beef)
    {
    	p->sprite.setPosition(340,700);
    	beef = false;
    }
    
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
    cout<<all;
    cout<<"///";
    /*
    if(all== false)
    {
    cout<<"..";
    	enemy **ptr = new enemy *[6];
    	ptr[0] = new gema(100,0,0.01);
	ptr[1] = new gema(600,0,0.01);

	ptr[2] = new gema(300,100,0.01);
	ptr[3] = new gema(400,100,0.01);
	ptr[4] = new alpha(200,50,0.01);
	ptr[5] = new alpha(500,50,0.01);
	
	for(int k=0 ; k<6 ; k++)
	{
	
	delete[] arr[k];
	active[k] = true;
	arr[k] = ptr[k];
	
	}
	
	
	delete[] ptr;
	
	
	//delete ptr;
	
	//arr = ptr;
    	
    }
}
    if(p->b != nullptr && check(arr[i][0].shape, p->b->shape))
    {
        active[i] = false;
       //cout<<i;
        collision = true;
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
        {
            arr[i] -> fire();
            bombtime = 0;
                
            if(arr[i]->b != nullptr && arr[i]->b->shape.getPosition().y > 780)
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
        /*
        else if(i>=2)
        {
            arr[i] -> fire();
            if(arr[i]->b != nullptr && arr[i]->b->shape.getPosition().y > 780)
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
        */
       // mon = false;
      //  delete[] arr[i];
    }
    else
    {
    if(p->b != nullptr && check(arr[i][0].shape, p->b->shape))
    {
        active[i] = false;
       //cout<<i;
        collision = true;
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
        {cout<<"d";
            arr[i] -> fire();
            bombtime = 0;
                
            if(arr[i]->b != nullptr && arr[i]->b->shape.getPosition().y > 780)
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
    	bomb = true;
    }
    
    if(bomb)
    {
    	p->sprite.setPosition(340,700);
    	bomb = false;
    }
    
    
     if(arr[i][0].b != nullptr && check(arr[i][0].shape, p->sprite))
    {
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
    	
    	all = true;
    
    	}
    	
    	//cout<<k;	
    }
    cout<<all;
    cout<<"///";
    /*
    if(all== false)
    {
    cout<<"..";
    	enemy **ptr = new enemy *[6];
    	ptr[0] = new gema(100,0,0.01);
	ptr[1] = new gema(600,0,0.01);

	ptr[2] = new gema(300,100,0.01);
	ptr[3] = new gema(400,100,0.01);
	ptr[4] = new alpha(200,50,0.01);
	ptr[5] = new alpha(500,50,0.01);
	
	for(int k=0 ; k<6 ; k++)
	{
	
	delete[] arr[k];
	active[k] = true;
	arr[k] = ptr[k];
	
	}
	
	
	delete[] ptr;
	
	
	//delete ptr;
	
	//arr = ptr;
    	
    }
    cout<<"..";
    */
    }
}
}
collision = false;
flag = false;
	
	
	

	
	
	
	
	
/*	
	for(int i=0 ; i < 5 ; i++)
	{
         	window.draw(newEnemy[i].shape);
         	newEnemy[i]. update();
        }
		
	//window.draw(p->b->shape);
	
	for(int i=0; i<5; i++) {
        en[i].update();
        window.draw(en[i].getSprite());
    }
   
    
    for (int i = 0; i < 5; i++) 
{
    for (int j = 0; j < 5; j++) 
    {
        en[i][j].update();
        window.draw(en[i][j].shape);
    }
}*/ 
	

	window.display();  //Displying all the sprites
    }
    }
    





};

#endif
