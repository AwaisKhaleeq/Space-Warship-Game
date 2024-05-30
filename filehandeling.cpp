#include<iostream>
#include<sstream>
#include<cstring>
#include<fstream>
using namespace std;
void output()//void highscore();
{
ifstream file("highscore.txt");

    if (file.is_open())
   { string player_id, highscore,vname,name;
        string line;
bool found = false; //cout<<"Jijs;
        while (getline(file, line)) { //(getline(cin,line))
            istringstream iss(line); //is space
           
            if (iss >> name >> player_id >> highscore) {
               
                    cout<<"NAME: "<< name <<" PLAYERID: "<<player_id<<" HIGHSCORE: "<<highscore<<endl;
                    found = true;
                   
               
           
            }
        }
        file.close();
}
}

//////////////////////////////////////////////////////////////////////////////////




void input(int score, string playerName,int playerID)
{
    ofstream file("highscore.txt", ios::app); // Open the file in append mode

    if (file.is_open())
    {
       // string playerName, playerID, playerHighScore;
        //cout << "Enter player name: ";
        //getline(cin, playerName);
        //cout << "Enter player ID: ";
        //getline(cin, playerID);
        file << playerName << " " << playerID << " " << score<< endl;
        file.close();

        cout << "Data saved successfully." << endl;
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }

}
