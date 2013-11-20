#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define random(x) (rand()%x) 

using namespace std;

int main()
{

     // 定义棋盘 board
     // 分别存储在 boundary（边界）, bar（栏）以及 sidebar（边栏）的变量里
     string boundary = "+---+---+---+";
     string bar = "| X |   | O |";
     string sidebar(6, ' '); //空白的左边栏

     string mark[3][3] ; // 定义棋子标记 mark
    
    for (int x = 0; x < 3; ++x) // 初始化棋子为空字符串
    {
        for (int y = 0; y <3; ++y)
        {
            mark[x][y] = "   ";     
        }
    }

     srand(time(0)); // 改变随机种子值

     for (int i = 0; i < 9; ++i)
     { 
          int x = random(3), y = random(3); // 随机生成坐标值
        
          while (mark[x][y] != "   ") // 判断棋盘是否已经存在这个棋子
          {
               x = random(3);
               y = random(3);
          }

          // 定义一个计数器 b，交替赋值棋子 X 和 O
          int b = pow(-1, i);
          if (b == -1)
              mark[x][y] = " X ";
          else
               mark[x][y] = " O ";

          string bar[3] ;  // 定义间隔的竖线
          for (int x = 0; x < 3; ++x)
          {   
              bar[x] = '|' + mark[x][0] + '|' + mark[x][1] + '|' + mark[x][2] + '|' ;        
          }

          // 输出界面
          cout << sidebar << boundary << endl;
          cout << sidebar << bar[0] << endl;
          cout << sidebar << boundary << endl;
          cout << sidebar << bar[1] << endl;
          cout << sidebar << boundary << endl;
          cout << sidebar << bar[2] << endl;
          cout << sidebar << boundary << endl;

          // 判断输赢
          bool win = false;

          // 判断交叉线是否相等
          if (mark[0][0] == " O " && mark [1][1] == " O " && mark[2][2] == " O " ) win = true;
          if (mark[0][0] == " X " && mark [1][1] == " X " && mark[2][2] == " X " ) win = true;
          if (mark[0][2] == " O " && mark [1][1] == " O " && mark[2][0] == " O " ) win = true;
          if (mark[0][2] == " X " && mark [1][1] == " X " && mark[2][0] == " X " ) win = true;

          // 判断横竖线是否相等
          for (int x = 0; x < 3; ++x)
          {
             if (mark[x][0] == " O " && mark[x][1] == " O " && mark[x][2] == " O " ) win = true;
             if (mark[x][0] == " X " && mark[x][1] == " X " && mark[x][2] == " X " ) win = true;
             if (mark[0][x] == " O " && mark[1][x] == " O " && mark[2][x] == " O " ) win = true;
             if (mark[0][x] == " X " && mark[1][x] == " X " && mark[2][x] == " X " ) win = true;
          }

          if (win) break;

     }

     return 0;
}