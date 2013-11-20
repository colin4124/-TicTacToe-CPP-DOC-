#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define random(x) (rand()%x)

using namespace std;

int main()
{
    //定义棋盘 board
    // 分别存储在 boundary（边界）,以及 sidebar（边栏）的变量里
    string boundary = "+---+---+---+";
    string sidebar(6, ' '); //空白的左边栏
    string split_line(6, '-');// 定义分割线
    
    string mark[3][3] ; // 定义棋子标记 mark
    
    for (int x = 0; x < 3; ++x) // 初始化棋子为空字符串
    {
        for (int y = 0; y <3; ++y)
        {
            mark[x][y] = "   ";     
        }
    }
    
    string piece; // 存放用户选择的棋子
    cout << "你选择棋子 O 还是 X ：";
    cin >> piece;
    cout << "棋盘如下：" << endl;

    cout << sidebar << boundary << endl;
    cout << sidebar << "| " << 1 << " | " << 2 << " | " << 3 << " |" << endl;
    cout << sidebar << boundary << endl;
    cout << sidebar << "| " << 4 << " | " << 5 << " | " << 6 << " |" << endl;
    cout << sidebar << boundary << endl;
    cout << sidebar << "| " << 7 << " | " << 8 << " | " << 9 << " |" << endl;
    cout << sidebar << boundary << endl;

    int board_x, board_y, board_number; // 存放用户的棋子坐标

    srand(time(0));       // 改变随机种子值
    int step;             // 计算是第几步

    /* 开始循环输出下棋的每一步 */
    for (int i = 0; i < 5; ++i)
    { 
        step = i + 1;

        cout << "请输入下棋的位置序号（1～9）：";          //用户选择的坐标值
        cin >> board_number;
        
        switch (board_number)
        {
           case 1 : board_x = 0, board_y = 0; break;
           case 2 : board_x = 0, board_y = 1; break; 
           case 3 : board_x = 0, board_y = 2; break;
           case 4 : board_x = 1, board_y = 0; break;
           case 5 : board_x = 1, board_y = 1; break;
           case 6 : board_x = 1, board_y = 2; break;
           case 7 : board_x = 2, board_y = 0; break;
           case 8 : board_x = 2, board_y = 1; break;
           case 9 : board_x = 2, board_y = 2; break;        
       }

        while (mark[board_x][board_y] == " O " || mark[board_x][board_y] == " X " )  // 判断用户选择的位置是否已经存在棋子
        {
            cout << "棋盘上已经存在棋子，请重新输入：" << endl;
            cout << "请输入下棋的位置序号（1～9）：";          
            cin >> board_number;

            switch (board_number)
            {
               case 1 : board_x = 0, board_y = 0; break;
               case 2 : board_x = 0, board_y = 1; break; 
               case 3 : board_x = 0, board_y = 2; break;
               case 4 : board_x = 1, board_y = 0; break;
               case 5 : board_x = 1, board_y = 1; break;
               case 6 : board_x = 1, board_y = 2; break;
               case 7 : board_x = 2, board_y = 0; break;
               case 8 : board_x = 2, board_y = 1; break;
               case 9 : board_x = 2, board_y = 2; break;         
            }
        }
              
        mark[board_x][board_y] = " " + piece + " "; // 经过判断后，用户才下棋成功 

        
        int x, y; // 定义计算机下棋的坐标

        x = random(3), y = random(3); // 随机生成坐标值
        while (mark[x][y] != "   " && i < 4) // 判断是否棋盘是否已经存在这个棋子 
        {                                    // 如果进行到第五轮，最后一个棋子是用户下，
            x = random(3);                   // 而不是计算机
            y = random(3);
        }

        // 判断输赢
        bool win_o = false, win_x = false; 

        // 判断用户是否赢了
        // 判断交叉线是否相等
        if (mark[0][0] == " O " && mark [1][1] == " O " && mark[2][2] == " O " ) win_o = true;
        if (mark[0][0] == " X " && mark [1][1] == " X " && mark[2][2] == " X " ) win_x = true;
        if (mark[0][2] == " O " && mark [1][1] == " O " && mark[2][0] == " O " ) win_o = true;
        if (mark[0][2] == " X " && mark [1][1] == " X " && mark[2][0] == " X " ) win_x = true;

        // 判断横竖线是否相等
        for (int c = 0; c < 3; ++c)
        {   
            if (mark[c][0] == " O " && mark[c][1] == " O " && mark[c][2] == " O " ) win_o = true;
            if (mark[c][0] == " X " && mark[c][1] == " X " && mark[c][2] == " X " ) win_x = true;
            if (mark[0][c] == " O " && mark[1][c] == " O " && mark[2][c] == " O " ) win_o = true;
            if (mark[0][c] == " X " && mark[1][c] == " X " && mark[2][c] == " X " ) win_x = true;
        }
        
        if (win_x != true && win_o != true) // 如果用户没有赢，才轮到计算机下棋
        {
            if (piece == "O")   // 计算机选择的棋子要跟用户的不一样
                mark[x][y] = " X ";
            else 
                mark[x][y] = " O ";
        }

        // 判断计算机下棋时是否赢了
        // 判断交叉线是否相等
        if (mark[0][0] == " O " && mark [1][1] == " O " && mark[2][2] == " O " ) win_o = true;
        if (mark[0][0] == " X " && mark [1][1] == " X " && mark[2][2] == " X " ) win_x = true;
        if (mark[0][2] == " O " && mark [1][1] == " O " && mark[2][0] == " O " ) win_o = true;
        if (mark[0][2] == " X " && mark [1][1] == " X " && mark[2][0] == " X " ) win_x = true;

        // 判断横竖线是否相等
        for (int c = 0; c < 3; ++c)
        {   
            if (mark[c][0] == " O " && mark[c][1] == " O " && mark[c][2] == " O " ) win_o = true;
            if (mark[c][0] == " X " && mark[c][1] == " X " && mark[c][2] == " X " ) win_x = true;
            if (mark[0][c] == " O " && mark[1][c] == " O " && mark[2][c] == " O " ) win_o = true;
            if (mark[0][c] == " X " && mark[1][c] == " X " && mark[2][c] == " X " ) win_x = true;
        }

        // 输出每一步下棋的棋盘状态
        string bar[3] ;  // 定义间隔的竖线
        for (int k = 0; k < 3; ++k)
        {   
            bar[k] = '|' + mark[k][0] + '|' + mark[k][1] + '|' + mark[k][2] + '|' ;        
        }
        
        cout << endl;
        cout << split_line << boundary << endl;
        cout << "   第 " << bar[0] << endl;
        cout << sidebar << boundary << endl;
        cout << "   " << step << "  " << bar[1] << endl;
        cout << sidebar << boundary << endl;
        cout << "   轮 " << bar[2] << endl;
        cout << split_line << boundary << endl;
        cout << endl;
   
        if (win_o || win_x) 
        {
            if ( (win_o && piece == "O") || (win_x && piece == "X") )
                cout << "      你赢了 ^_^ \n" << endl;
            else
                cout << "      你输了 >_< \n" << endl;

            break;  // 跳出循环，结束游戏
        } 

        if (i == 4) // 判断是否平局
        {
            cout << "      平局 －_－# \n" << endl;
            break;  // 跳出循环，结束游戏
        }
    }

    //加上一个空的字符串变量，确认退出
    string wait = " " ; 
    cout << "请输入任意字符退出： " ;
    cin >> wait;
    return 0;
}
