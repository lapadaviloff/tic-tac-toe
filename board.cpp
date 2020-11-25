#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
void printGomoke (int arr[][5],int);//поле+2

int main ()
{
  int board [5][5];//поле+2
  int isWin=0;
  int noWin=0;
  int maxcol=3;// количество ячеек
  for(int i=0;i<5;i++){ //поле
    for(int j=0;j<5;j++){
      board[i][j]=0;
    }
  }
  int x,y=0;
  int s=0;
  printGomoke(board,maxcol);
  while (1){
    do{
      cout<< "введите положение х"<<' ';
      cin >>y;
      cout<<"введите положение у"<<' ';
      cin>>x;
      cout<< "введите символ(1-X,2-O)"<<' ';
      cin>>s;
      if (cin.fail()){
	cout<<endl<<"ошибка ввода"<<endl;
	return 0;}
      if (s==3){return 0;}
    }
    while(!((x>-1 && x<maxcol) && (y>-1 && y<maxcol ) && (s>0 && s<3))); 
    noWin++;
    x++;//
    y++;//устанавливаем ячейку на 0
    //проверка занятости и вывод
    if (board[x][y]==0){
      board [x][y]=s;    
      printGomoke(board,maxcol);
      int flagProv=1;
      //проверка на выигрыш
      
      if (board[x-1][y]==board[x][y]&& flagProv==1){      //проверка меньше y
	for(int i=0;i>(-1*maxcol-1);i--){
	  
	if (board[x+i][y]!=board[x][y]){
	  
	  i=(-1*maxcol-1);
	  isWin--;
	}
	isWin++;
	}
	
      for (int i=1;i<maxcol+1;i++){
	
	if (board[x+i][y]!=board[x][y]){
	  i=maxcol+1;
	  isWin--;
	}
	isWin++;
       }
      flagProv=0;
      }
      
      if (board[x+1][y]==board[x][y]&& flagProv==1){                         // проверка больше y
        for(int i=0;i<(maxcol+1);i++){
	  
	if (board[x+i][y]!=board[x][y]){
	  
	  i=(maxcol+1);
          isWin--;
	}
	isWin++;
	}
	for (int i=-1;i>(-1*maxcol-1);i--){
	
	  if (board[x+i][y]!=board[x][y]){
	    i=(-1*maxcol-1);
	    isWin--;
	  }
	  isWin++;	
	}
	flagProv=0;
      }
      
      if (board[x-1][y-1]==board[x][y]){      //прверка меньше по диагонали
	
	for(int i=0;i>(-1*maxcol-1);i--){
	  
	  if (board[x+i][y+i]!=board[x][y]){    
	    
	    i=(-1*maxcol-1);
	    isWin--;
          }
	  isWin++;
	}
	for (int i=1;i<maxcol+1;i++){
	  
	  if (board[x+i][y+i]!=board[x][y]){
	    i=maxcol+1;
	    isWin--;
	  }
	  isWin++;	
	}
	flagProv=0;
	
      }
      
      if (board[x+1][y+1]==board[x][y]){  //проверка больше диагонали
	
	for(int i=0;i<(maxcol+1);i++){
	  
	  if (board[x+i][y+i]!=board[x][y]){
	    
	    i=maxcol+1;
	    isWin--;
	  }
	  isWin++;
       }
	for (int i=-1;i>(-1*maxcol-1);i--){
	  
           if (board[x+i][y+i]!=board[x][y]){
	     i=(-1*maxcol-1);
	     isWin--;
	   }
	   isWin++;	
	}
	flagProv=0;
      }
      
      if (isWin==3){                            //проверка выигрыша

	
	if (board[x][y]==1){
	  cout<<" X "<<"WIN!!!"<<endl;
	}
	else {
	  cout<<" O "<<"WIN!!!"<<endl;
	  return 0;
	}
      }
      if (noWin==maxcol*maxcol)
	{
	  cout<<"NO WIN"<<endl;;
	  return 0;
	}
      isWin=0;
    }
    else {
      cout<<"неправильный ход"<<endl;
    return 0;
    
     }
  }
  
  return 0;
}

void printGomoke(int arr[][5],int maxcol)//поле +2
{
  printf("\033[2J\033[1;1H");
  cout<<"   __0___1___2__"<<endl;
  for(int i=1;i<maxcol+1;i++){
    cout<<' '<<i-1<<' '<<"I ";
    for(int j=1;j<maxcol+1;j++){
      if(arr[i][j]==0){
	cout<<' '<<" I ";
      }
      if(arr[i][j]==1){
	cout<<'X'<<" I ";
      }
      if(arr[i][j]==2){
	cout<<'O'<<" I ";
      }
    }
    cout <<endl;
  }
  
}
