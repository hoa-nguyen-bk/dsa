#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// Để đảo ngược một stack bằng cách sử dụng queue, ta cần thực hiện các bước sau:

// Khởi tạo một queue.
// Lấy phần tử đầu tiên của stack và đẩy nó vào queue.
// Pop phần tử đầu tiên của stack.
// Lặp lại bước 2 và 3 cho đến khi stack trống.
// Lặp lại các bước sau đây cho đến khi queue trống:
// a. Lấy phần tử đầu tiên của queue và đẩy nó vào stack.
// b. Xóa phần tử đầu tiên của queue.
// Stack đã được đảo ngược.
void reverseStack(stack<int> &st)
{
  queue<int> q;
  while (!st.empty())
  {
    q.push(st.top());
    st.pop();
  }
  while (!q.empty())
  {
    st.push(q.front());
    q.pop();
  }
}

int main()
{
  int arr[] = {1, 2, 3};
  int size = sizeof(arr) / sizeof(arr[0]);
  stack<int> st;
  for (int i = 0; i < size; ++i)
  {
    st.push(arr[i]);
  }
  cout << stackToStr(st) << endl;
  reverseStack(st);
  cout << stackToStr(st) << endl;
  // TOP-> 3 2 1|BOTTOM
  // TOP-> 1 2 3|BOTTOM

  return 0;
}
