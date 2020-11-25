#include "classview.h"
#include <iostream>
#include <stdio.h>
using namespace std;
classview::classview (classboard *b){
  board =b;
} 
void classview::show(){

  // printf("\033[2J\033[1;1H");
  cout<<"   __0___1___2__"<<endl;
  for(int i=0;i<3;i++){
    cout<<' '<<i<<' '<<"I ";
    for(int j=0;j<3;j++){
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
  int x,y,s=0;
  bool errorvvod;

  while(!(board->getnoWin()==9)) {
    do{
      
     cout<< "введите положение х"<<' ';
    cin >>y;
    cout<<"введите положение у"<<' ';
    cin>>x;
    cout<< "введите символ(1-X,2-O)"<<' ';
    cin>>s;
    if (cin.fail()){
      cout<<endl<<"это не число"<<endl;
     
      cin.clear();
      cin.ignore(32767,'\n');
     
 
    }
    if (s==3){return 3;}
    errorvvod=board->makemove(x,y,s);
    
    if (errorvvod) cout<<endl<<"ошибка ввода"<<endl;
 
    }
    
    while (errorvvod);
	 
	   show();
	   cout<<"iswin"<<board->getisWin()<<endl;
           cout<<"nowin"<<board->getnoWin()<<endl;

  }
  cout<<"ничья";
}
