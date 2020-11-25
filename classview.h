#ifndef CLASSVIEW_H_
#define CLASSVIEW_H_
#include "classboard.h"
class classview{
 private:
 classboard *board;
 static const int numberWins=5;
  void show();
 public:
  classview(classboard*b);
  int startgame();
 
  
};


#endif

