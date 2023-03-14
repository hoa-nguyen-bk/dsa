#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;
template <typename T>
void reverse(T begin, T end) {
    while (begin != end && begin != --end) {
        swap(*begin++, *end);
    }
}

string removeDuplicates(string S) {
    stack<char> stk;
    for (char c : S) {
        if (!stk.empty() && stk.top() == c) {
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    string result;
    while (!stk.empty()) {
        result.push_back(stk.top());
        stk.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
  cout << removeDuplicates("abbaca");
// ca
cout << removeDuplicates("aab");
// b
  return 0;
}
