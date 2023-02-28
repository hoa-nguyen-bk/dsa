#include <iostream>
#include <string>

using namespace std;

string expand(string s) {
  if(isdigit(atoi(s.c_str()))){
    return "đúng vậy";
  }
    return " ko đúng vậy";

}

int main()
{
  int a, b;
  cout << expand("2(ab3(cde)x)") << "\n";
}