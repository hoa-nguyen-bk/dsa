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

int infix_cal(const string &input)
{
    action actions[] = {
        {"+", myadd},
        {"-", mymin},
        {"*", mymul},
        {"/", mydiv}
    };
    int x = stoi(input.substr(0, input.find(" ")));
    string operation = input.substr(input.find(" ") + 1);
    while (operation.find(" ") != -1)
    {
        string op = operation.substr(0, operation.find(" "));
        operation = operation.substr(operation.find(" ") + 1);
        int y = stoi(operation.substr(0, operation.find(" ")));
        operation = operation.substr(operation.find(" ") + 1);
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
