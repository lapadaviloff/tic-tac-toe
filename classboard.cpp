#include "classboard.h"
#include <iostream>
using namespace std;
classboard::classboard(){

  // board[FILED_SIZE][FILED_SIZE];
  isWin=0;
  noWin=0;
  maxcol=FILED_SIZE;
  for(int i=0;i<FILED_SIZE+2;i++){ //поле
    for(int j=0;j<FILED_SIZE+2;j++){
      board[i][j]=0;
    }
  }
}
bool classboard::makemove (int x, int y, int sign){
  
  
  if(!((x>-1 && x<maxcol)&&(y>-1&&y<maxcol ) && (sign>0 && sign<3)))return 1; 
  int tempWin=0; 
  isWin=0;
  noWin++;
  x++;//
  y++;//устанавливаем ячейку на 0
  //проверка занятости и вывод
  if (board[x][y]==0){
    board [x][y]=sign;      
    /*-----------------------------------------------*/ //проверка на выигрыш
    /*-----------------------------------------------*/ //проверка меньше y
    if (board[x-1][y]==board[x][y]){                  
      tempWin=0;
      for(int i=0;i>(-1*maxcol-1);i--){	  
	if (board[x+i][y]!=board[x][y]){  
	  i=(-1*maxcol-1);
	  tempWin--;
	}
	tempWin++;
      }	
      for (int i=1;i<maxcol+1;i++){	  
	if (board[x+i][y]!=board[x][y]){
	  i=maxcol+1;
	  tempWin--;
	}
	tempWin++;
      }
      if (tempWin>isWin)isWin=tempWin; 
    } 
    /*--------------------------------------------*/ // проверка больше y
    if (board[x+1][y]==board[x][y]){ 
      tempWin=0;
	for(int i=0;i<(maxcol+1);i++){
	  if (board[x+i][y]!=board[x][y]){
	    i=(maxcol+1);
	    tempWin--;
	  }
	  tempWin++;
	}
	for (int i=-1;i>(-1*maxcol-1);i--){
	  if (board[x+i][y]!=board[x][y]){
	    i=(-1*maxcol-1);
	    tempWin--;
	  }
	  tempWin++;	
	}
	if (tempWin>isWin)isWin=tempWin; 
    }
    /*---------------------------------------------*/ //проверка меньше x
      if (board[x][y-1]==board[x][y]){
	tempWin=0;
	for(int i=0;i>(-1*maxcol-1);i--){
	  if (board[x][y+i]!=board[x][y]){
	    i=(-1*maxcol-1);
	    tempWin--;
	  }
	  tempWin++;
	}
	for (int i=1;i<maxcol+1;i++){
	  if (board[x][y+i]!=board[x][y]){
	    i=maxcol+1;
	    tempWin--;
	  }
	  tempWin++;
	}
	if (tempWin>isWin)isWin=tempWin; 
      }
      /*---------------------------------------------*/ // проверка больше x
      if (board[x][y+1]==board[x][y]){ 
	tempWin=0;
	for(int i=0;i<(maxcol+1);i++){
	  if (board[x][y+i]!=board[x][y]){
	    i=(maxcol+1);
	    tempWin--;
	  }
	  tempWin++;
	}
	for (int i=-1;i>(-1*maxcol-1);i--){	
	  if (board[x][y+i]!=board[x][y]){
	    i=(-1*maxcol-1);
	    tempWin--;
	  }
	  tempWin++;	
	}
	if (tempWin>isWin)isWin=tempWin; 
      }      
      /*----------------------------------------*/ //прверка меньше по диагонали2 
      if (board[x-1][y+1]==board[x][y]  ){      	
	tempWin=0;
	for(int i=0;i<maxcol+1;i++){	  
	  if (board[x-i][y+i]!=board[x][y]){    	    
	    i=maxcol+1;
	    tempWin--;
          }
	  tempWin++;
	}
	for (int i=1;i<maxcol+1;i++){	  
	  if (board[x+i][y-i]!=board[x][y]){
	    i=maxcol+1;
	    tempWin--;
	  }
	  tempWin++;	
	}
	if (tempWin>isWin)isWin=tempWin; 
      }      
      /*------------------------------------------*/ //проверка больше диагонали2
      if (board[x+1][y-1]==board[x][y]  ){      	
	tempWin=0;
	for(int i=0;i<maxcol+1;i++){	  
	  if (board[x+i][y-i]!=board[x][y]){    	    
	    i=maxcol+1;
	    tempWin--;
          }
	  tempWin++;
	}
	for (int i=1;i<maxcol+1;i++){	  
	  if (board[x-i][y+i]!=board[x][y]){
	    i=maxcol+1;
	    tempWin--;
	  }
	  tempWin++;	
	}
       	if (tempWin>isWin)isWin=tempWin; 
      }  
      /*----------------------------------------*/ //прверка меньше по диагонали 
      if (board[x-1][y-1]==board[x][y] ){      	
	tempWin=0;
	for(int i=0;i>(-1*maxcol-1);i--){	  
	  if (board[x+i][y+i]!=board[x][y]){    	    
	    i=(-1*maxcol-1);
	    tempWin--;
          }
	  tempWin++;
	}
	for (int i=1;i<maxcol+1;i++){	  
	  if (board[x+i][y+i]!=board[x][y]){
	    i=maxcol+1;
	    tempWin--;
	  }
	  tempWin++;	
	}
       	if (tempWin>isWin)isWin=tempWin; 
      }      
      /*------------------------------------------*/ //проверка больше диагонали
      if (board[x+1][y+1]==board[x][y]){  	
	tempWin=0;
	for(int i=0;i<(maxcol+1);i++){	  
	  if (board[x+i][y+i]!=board[x][y]){	    
	    i=maxcol+1;
	    tempWin--;
	  }
	  tempWin++;
	}
	for (int i=-1;i>(-1*maxcol-1);i--){	  
	  if (board[x+i][y+i]!=board[x][y]){
	    i=(-1*maxcol-1);
	     tempWin--;
	  }
	  tempWin++;	
	}
	if (tempWin>isWin)isWin=tempWin; 
      }
      cout<<"iswin classboard"<<isWin<<endl;
  }
  
  else {
    return 1;
    
    
  }
  
  return 0;
  
}
int classboard::getisWin(){
  return isWin;
}
int classboard::getcell(int x, int y){
  
  return board[x+1][y+1];
}
int classboard::getnoWin(){
  return noWin;
}
int classboard::getSize(){

  return FILED_SIZE;
}
