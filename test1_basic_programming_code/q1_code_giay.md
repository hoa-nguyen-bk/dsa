#include <iostream>
#include <string>
using namespace std;

int infix_call (const string &input){
  //b1: tìm dấu cách
 // string space_1 = input.find(" ");
 // string space_2 = input.find(" ", space_1+1);
  //sai mẹ nó chỗ này phải xài int chứ ko phải string
  //phải có ép kiểu (int)
  int space_1 = (int) input.find(" ");
  int space_2 = (int) input.find(" ", space_1+1);


  //b2: tách chuỗi
  string operand1_convert = input.substr(0, space_1);
  string operand2_convert = input.substr(space_2 + 1);

  //b3: convert lại thành kiểu mình dễ tính
  int operand1 = stoi(operand1_convert);
  char operator = input[space_1+1];
  int operand2 = stoi(operand2_convert);

  //b4: tính
  int result;
  switch(operator){
    case "+":{
      result = operand1 + operand2;
      break;
    }
    case "-":{
      result = operand1 - operand2;
      break;
    }
    case "*":{
      result = operand1 * operand2;
      break;
    }
    case "/":{
      result = operand1 / operand2;
      break;
    }
    default: {
      break;
    }
  }
  return result;
}

int main () {
  cout << infix_call("12 + 2") << endl;
  return 0;
}