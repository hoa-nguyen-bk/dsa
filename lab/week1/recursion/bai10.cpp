#include <iostream>
#include <string>

using namespace std;
int countBracket(string s)
{
}
int mininumBracketAdd(string s)
{
  cout << "----1 vong----" << endl;
  // STUDENT ANSWER
  if (s == "")
  {
    return 0;
  }
  char firstChar = s[0];
  // nếu ngay phần tử đầu tiên là ngoặc đóng cũng xóa nó đi và lấy chuỗi tiếp theo thôi
  if (firstChar == ')')
  {
    return 1 + mininumBracketAdd(s.substr(1));
  }
  // trường hợp này rơi vào firstChar là ngoặc mở, thì tìm ngoặc đóng tiếp theo
  int nextClosedBracket = s.find(')');
  cout << "firstChar = " << firstChar << "; next cloase = " << nextClosedBracket << endl;
  // có ngoặc mở và đòng
  if (nextClosedBracket != -1)
  {
    // cắt bỏ 2 ngoặc đó ra khỏi chuỗi
    string newCutString = s.substr(1);
    //xóa ngoặc mở
    cout << "1.newCutString = " << newCutString << endl;

    //xóa ngoặc đóng
    newCutString.erase(1, nextClosedBracket);
    cout << "2.newCutString = " << newCutString << endl;
    // nếu chuỗi sau đó vẫn còn
    if (nextClosedBracket != s.length() - 1)
    {
      string rest = s.substr(nextClosedBracket + 1);
      string finalString = newCutString + rest;
      cout << "finalString = " << finalString << endl;
      return mininumBracketAdd(finalString);
    }
    // nếu là phần tử cuối cùng
    cout << "newCutString = " << newCutString << endl;
    return mininumBracketAdd(newCutString);
  }
  // thêm 1 sẹo ở đây
  cout << "them 1 seo" << endl;
  // cắt bỏ ngoặc dư ra khỏi chuỗi, bắt đầu lại với chuổi bỏ ngoặc dư
  return 1 + mininumBracketAdd(s.substr(1));
}
int main()
{
  cout << mininumBracketAdd("(((") << endl;   // 3
  cout << mininumBracketAdd("(()") << endl;   // 1
  cout << "Ket luan (()( :  " << mininumBracketAdd("(()(") << endl; // 5
  cout << mininumBracketAdd(")))((") << endl; // 5
  return 0;
}
