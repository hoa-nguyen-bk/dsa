#include <iostream>
#include <string>

using namespace std;

struct action {
    string op;
    int (*func)(int, int);
};

int myadd(int x, int y) { return x + y;}
int mymin(int x, int y) { return x - y;}
int mymul(int x, int y) { return x * y;}
int mydiv(int x, int y) { return x / y;}

int infix_cal(string s)
{
    action actions[] = {
        {"+", myadd},
        {"-", mymin},
        {"*", mymul},
        {"/", mydiv}
    };
    int x = stoi(s.substr(0, s.find(" ")));
    s = s.substr(s.find(" ") + 1);
    while (s.find(" ") != -1)
    {
        string op = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1);
        int y = stoi(s.substr(0, s.find(" ")));
        s = s.substr(s.find(" ") + 1);
        for (int i = 0; i < 4; i++)
        {
            if (actions[i].op == op)
            {
                x = actions[i].func(x, y);
                break;
            }
        }
    }
    return x;
}

int main()
{
    cout << infix_cal("10 + 2") << endl;
    return 0;
}
