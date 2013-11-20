#include <iostream>
#include <string>

using namespace std;

int main()
{

     // 定义棋盘 board
     // 分别存储在 boundary（边界）, bar（栏）以及 sidebar（边栏）的变量里
     string boundary = "+---+---+---+";
     string bar = "|   |   |   |";
     string sidebar(6, ' '); //空白的左边栏

     // 输出界面
     cout << sidebar << boundary << endl;
     cout << sidebar << bar << endl;
     cout << sidebar << boundary << endl;
     cout << sidebar << bar << endl;
     cout << sidebar << boundary << endl;
     cout << sidebar << bar << endl;
     cout << sidebar << boundary << endl;

     return 0;
 }