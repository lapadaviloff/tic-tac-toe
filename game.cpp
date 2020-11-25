#include "classboard.h"
#include"classview.h"
#include <iostream>
/*# include <stdlib.h>
  #include  <stdio.h>
*/
using namespace std;
main(){
  classboard game;
  
  
  classview view(&game);
  view.startgame();
  
  return 0;
}

