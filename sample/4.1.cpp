#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define random(x) (rand()%x)

using namespace std;

class TicTacToe
{
public:
    TicTacToe();
    void begin_info();        // 输出欢迎信息
    void user_choose();       // 用户下棋
    void computer_choose();   // 计算机下棋
    void judge_win_or_lose(); // 判断输赢
    void board_info();        // 棋盘状态
    void play_game();         // 下棋

private:
    /* 定义棋盘 board */
    // 分别存储在 boundary（边界）,以及 sidebar（边栏）的变量里
    string boundary;
    string sidebar; //空白的左边栏
    string split_line;// 定义分割线
    string mark[3][3] ; // 定义棋子标记 mark
    string user_name;
    string bar[3] ;  // 定义输出棋子的行
    string piece; // 存放用户选择的棋子
    int user_x, user_y, choose_number; // 存放用户的棋子坐标
    int computer_x, computer_y; // 存放计算机的棋子坐标
    int step;             // 计算是第几步
    bool win_o, win_x; // 判断输赢，是执棋子 O 的还是 X 的赢了
};

TicTacToe::TicTacToe()
{
    srand(time(0));       // 改变随机种子值

    for (int x = 0; x < 3; ++x) // 初始化棋子为空字符串
    {
        for (int y = 0; y <3; ++y)
        {
            mark[x][y] = "   ";
        }
    }

    win_o = false;
    win_x = false;
}

void TicTacToe::begin_info()
{
    cout << "你叫什么呀：";
    cin >> user_name;

    cout << "\nHello, " << user_name << "  ^_^" << "  选择棋子 O 还是 X ：";
    cin >> piece;
    cout << "\n棋盘如下：" << endl;

    boundary = "+---+---+---+";
    sidebar = "      "; //空白的左边栏
    split_line = "------";// 定义分割线
    cout << sidebar << boundary << endl;
    cout << sidebar << "| " << 1 << " | " << 2 << " | " << 3 << " |" << endl;
    cout << sidebar << boundary << endl;
    cout << sidebar << "| " << 4 << " | " << 5 << " | " << 6 << " |" << endl;
    cout << sidebar << boundary << endl;
    cout << sidebar << "| " << 7 << " | " << 8 << " | " << 9 << " |" << endl;
    cout << sidebar << boundary << endl;
}

void TicTacToe::user_choose()
{
    cout << "\n请输入下棋的位置序号（1～9）：";          //用户选择的坐标值
    cin >> choose_number;

    switch (choose_number)
    {
        case 1 : user_x = 0, user_y = 0; break;
        case 2 : user_x = 0, user_y = 1; break;
        case 3 : user_x = 0, user_y = 2; break;
        case 4 : user_x = 1, user_y = 0; break;
        case 5 : user_x = 1, user_y = 1; break;
        case 6 : user_x = 1, user_y = 2; break;
        case 7 : user_x = 2, user_y = 0; break;
        case 8 : user_x = 2, user_y = 1; break;
        case 9 : user_x = 2, user_y = 2; break;
    }

    // 判断用户选择的位置是否已经存在棋子
    while (mark[user_x][user_y] == " O " || mark[user_x][user_y] == " X " )
    {
        cout << "棋盘上已经存在棋子，请重新输入：" << endl;
        cout << "请输入下棋的位置序号（1～9）：";
        cin >> choose_number;

        switch (choose_number)
        {
            case 1 : user_x = 0, user_y = 0; break;
            case 2 : user_x = 0, user_y = 1; break;
            case 3 : user_x = 0, user_y = 2; break;
            case 4 : user_x = 1, user_y = 0; break;
            case 5 : user_x = 1, user_y = 1; break;
            case 6 : user_x = 1, user_y = 2; break;
            case 7 : user_x = 2, user_y = 0; break;
            case 8 : user_x = 2, user_y = 1; break;
            case 9 : user_x = 2, user_y = 2; break;
        }
    }
}

void TicTacToe::computer_choose()
{
    computer_x = random(3), computer_y = random(3); // 随机生成坐标值
    while (mark[computer_x][computer_y] != "   ") // 判断是否棋盘是否已经存在这个棋子
    {                                    
        computer_x = random(3);
        computer_y = random(3);
    }
}

void TicTacToe::judge_win_or_lose()
{
     // 判断交叉线是否相等
     if (mark[0][0] == " O " && mark [1][1] == " O " && mark[2][2] == " O ")
         win_o = true;
     if (mark[0][0] == " X " && mark [1][1] == " X " && mark[2][2] == " X ")
         win_x = true;
     if (mark[0][2] == " O " && mark [1][1] == " O " && mark[2][0] == " O ")
         win_o = true;
     if (mark[0][2] == " X " && mark [1][1] == " X " && mark[2][0] == " X ")
         win_x = true;

     // 判断行和列是否相等
     for (int c = 0; c < 3; ++c)
     {
         if (mark[c][0] == " O " && mark[c][1] == " O " && mark[c][2] == " O ")
             win_o = true;
         if (mark[c][0] == " X " && mark[c][1] == " X " && mark[c][2] == " X ")
             win_x = true;
         if (mark[0][c] == " O " && mark[1][c] == " O " && mark[2][c] == " O ")
             win_o = true;
         if (mark[0][c] == " X " && mark[1][c] == " X " && mark[2][c] == " X ")
             win_x = true;
     }
}

void TicTacToe::board_info()
{
     // 输出每一步下棋的棋盘状态
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
     cout << "   步 " << bar[2] << endl;
     cout << split_line << boundary << endl;
     cout << endl;
}

void TicTacToe::play_game()
{
    for (int i = 0; i < 5; ++i)
    {
        step = i + 1;

        user_choose();

        mark[user_x][user_y] = " " + piece + " ";

        if ( i < 4 )  // 如果进行到了第五轮，只能是轮到用户下棋
            computer_choose();

        judge_win_or_lose();  // 判断用户是否赢了

        if (win_x != true && win_o != true) // 如果用户没有赢，则轮到计算机下棋
        {
            if (piece == "O")  // 定义与用户不同的棋子
                mark[computer_x][computer_y] = " X ";
            else
                mark[computer_x][computer_y] = " O ";
        }

        judge_win_or_lose();  // 判断计算机是否赢了

        board_info();

        if (win_o || win_x)
        {
            if ( (win_o && piece == "O") || (win_x && piece == "X") )
                cout << "      你赢了 ^_^ \n" << endl;
            else
                cout << "      你输了 >_< \n" << endl;

            break;
        }

        if (i == 4) // 判断是否平局
        {
            cout << "      平局 －_－# \n" << endl;
            break;
        }
    }
 }

int main()
{
    TicTacToe tictactoe_sample;
    tictactoe_sample.begin_info();
    tictactoe_sample.play_game();

    return 0;
}