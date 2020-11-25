#ifndef CLASSVIEW_H_
#define CLASSVIEW_H_
#include "classboard.h"
class classview{
 private:
 classboard *board;
  void show();
 public:
  classview(classboard*b);
  int startgame();
 
  
};


#endif

