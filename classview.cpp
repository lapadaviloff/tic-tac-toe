#include "classview.h"
#include <iostream>
#include <stdio.h>
using namespace std;
classview::classview (classboard *b){
  board =b;
} 
void classview::show(){
  printf("\033[2J\033[1;1H");
  cout<<endl<<"для выхода наберите 30"<<endl;
  cout<<"   ";
  for (int i=0;i<board->getSize();i++){
    cout<<"__"<<i<<'_';
  }
  cout<<endl;
  for(int i=0;i<board->getSize();i++){
    cout<<' '<<i<<' '<<"I ";
    for(int j=0;j<board->getSize();j++){
      if(board->getcell(i,j)==0){
	cout<<' '<<" I ";
      }
      if(board->getcell(i,j)==1){
	
	cout<<'X'<<" I ";
      }
      if(board->getcell(i,j)==2){
	cout<<'O'<<" I ";
      }
    }
    cout <<endl;
  }
}
int classview::startgame(){
  show();
  int x,y=0;
  bool errorvvod;
  int player=1;
 
  while(!(board->getnoWin()==(board->getSize()*board->getSize())))
    {
      do
	{  
	  if (player==1)
	    {
	      cout<< "ходит игрок Х"<<endl;;
	    }
	  else
	    {
	      cout<< "ходит игрок O"<<endl;;
	    }
	  cout<< "введите положение х"<<' ';
	  cin >>y;
	  cout<<"введите положение у"<<' ';
	  cin>>x;
	  if (cin.fail())
	    {
	      cout<<endl<<"это не число"<<endl;
	      cin.clear();
	      cin.ignore(32767,'\n');	
	    }
	  if (y==30||x==30)return 0;
	  errorvvod=board->makemove(x,y,player);
	  if (errorvvod) cout<<endl<<"ошибка ввода"<<endl;
	}
      while (errorvvod);
      /*-----------------------------------------------*/   
      show();
      if(board->getisWin()==numberWins)//количество выигрышних символов 
	{
	  cout<<"игрок ";
	    if(player==1)cout<<"X ";
	    else cout<<"O ";
	  cout<<"выиграл"<<endl;
	  return 0;
	}
      if(player==1)player=2;
      else player=1;
    }
  cout<<"ничья"<<endl;
}
