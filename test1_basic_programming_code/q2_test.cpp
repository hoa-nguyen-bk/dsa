#include <iostream>
#include <string>
using namespace std;

struct action {
  string op; // operator
  int (*func)(int, int); // function pointer to corresponding function
};
//hết struct mà thiếu ; là mệt

int myadd(int x, int y) { return x + y;}
int mymin(int x, int y) { return x - y;}
int mymul(int x, int y) { return x * y;}
int mydiv(int x, int y) { return x / y;}

int infix_cal (const string &input){
  
  //b1: khai báo mảng action
  action action[4] = {
    {"+", myadd},
    {"-", mymin},
    {"*", mymul},
    {"/", mydiv},
  };
  //dấu ' đại diện cho char, còn dấu " là cho string, chỗ ni khai op là string nên phải để "
  //hết struct mà thiếu ; là mệt


  //b2: làm lại mí cái bài 1 làm hoy
  int space_1 = input.find(" ");
  int space_2 = input.find(" ", space_1+1);
  string operand1_convert = input.substr(0, space_1);
  string operand2_convert = input.substr(space_2+1);
  //bởi vì ở trên định nghĩa op là string nên ở đây là string luôn chứ ko string ko so sánh được với char
  //chỗ này ko chịu input[index] vì nó là string chứu ko phải char nữa
  string op = input.substr(space_1+1,1);
  int operand1 = stoi(operand1_convert);
  int operand2 = stoi(operand2_convert);
  
  int result;
  for (int i = 0; i < 4; i++){
    if (op == action[i].op){
      result = action[i].func(operand1,operand2);
    }
  }

  return result;
}

int main () {
  cout << infix_cal("12 + 2") << endl;
  return 0;
}