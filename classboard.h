#ifndef CLASSBOARD_H_
#define CLASSBOARD_H_
class classboard{
 private:
static const int FILED_SIZE=10;
  int board[FILED_SIZE+2][FILED_SIZE+2];
  int isWin;
  int noWin;
  int maxcol;// количество ячеекy
 public:
  classboard();
  bool makemove(int x,int y, int sign);
  int getSize();
  int getisWin();
  int getcell(int x, int y);
  int getnoWin();
  
};


#endif

