#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
char board[3][3]={{'7','8','9'},{'4','5','6'},{'1','2','3'}};
char turn ='X';
int row,column;
bool draw=false;
void display(){
                        	system("cls");//Additional function
                          		cout<<"\n\n !! TIC TAC TOE !!"<<endl;
                          		cout<<"\t player1[x]\n\t Player2[0]\n\n";
                                cout<<"\t\t     |     |     \n";
	                            cout<<"\t\t "<<board[0][0]<<"   |  "<<board[0][1]<<"  |  "<<board[0][2]<< " \n";
                                cout<<"\t\t_____|_____|_____\n";
                                cout<<"\t\t     |     |     \n";
                                cout<<"\t\t "<<board[1][0]<<"   |  "<<board[1][1]<<"  |  "<<board[1][2]<<  "\n"; 
                                cout<<"\t\t_____|_____|_____\n";
                                cout<<"\t\t     |     |     \n";
                                cout<<"\t\t "<<board[2][0]<<"   |  "<<board[2][1]<<"  |  "<<board[2][2]<< "\n";
                                cout<<"\t\t     |     |     \n";

                }             
void player_turn(){	
            int choice;
     if(turn=='X')
          {
		      cout<<"\n\tplayer1[X] turn:";
          }
     if(turn=='O')
          { 
		     cout<<"\n\tplayer2 [O] turn:";
          }
         cin>>choice;
switch(choice){
	
	case 1:row=2;column=0;break;
	case 2:row=2;column=1;break;
	case 3:row=2;column=2;break;
	case 4:row=1;column=0;break;
	case 5:row=1;column=1;break;
	case 6:row=1;column=2;break;
	case 7:row=0;column=0;break;
	case 8:row=0;column=1;break;
	case 9:row=0;column=2;break;
	
	default:
		cout<<"Invalid choice!!";
	
}
           if(turn=='X'&& board[row][column]!='X'&& board[row][column]!='0')
             { 
                board[row][column]='X';
                turn='O';
             }
           else if(turn=='O'&&board[row][column]!='X'&& board[row][column]!='0')
            {
			    board[row][column]='O';
                turn='X';
            }
            else
           {
		    cout<<"Box already filled !!\n Please try again";
            player_turn();
			}
}
bool gameover(){
	//check win
	for(int i=0;i<3;i++)
		if(board[i][0]==board[i][1]&&board[i][0]==board[i][2]||board[0][i]==board[1][i]&&board[0][i]==board[2][i]||board[0][0]==board[1][1]&&board[0][0]==board[2][2])
	return false;
	//if there is any box not filled
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	if(board[i][j]!='X'&&board[i][j]!='O')
	return true;
//draw
draw=true;
return false;
}

main()
{
while(gameover()){
  display();
  player_turn();
  display();	
}

if(turn=='X'&&draw==false)
cout<<"player2[0] Wins!! congratulations\n";
else if(turn=='O'&&draw==false)
cout<<"player1 [X] Wins!! congratulations \n";
else
cout<<"game draw!!\n";
getch();
}


