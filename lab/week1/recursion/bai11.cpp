#include <iostream>
#include <string>

using namespace std;

string reverseSentence(string s)
{
  // STUDENT ANSWER
  if (s.length() == 0)
    return s;
  char space = ' ';
  string::size_type firstSpace = s.find(space);
  //nếu không tìm thấy
  if (firstSpace == string::npos)
    return s;
  //nếu tìm thấy
  string firstWord = s.substr(0, firstSpace);
  cout << "firstWord = " << firstWord << "; firstSpace = " << firstSpace << endl;
  string remainSentence = s.substr(firstSpace + 1);
  cout << "remainSentence = " << remainSentence << endl;
  return reverseSentence(remainSentence) + " " + firstWord;
}
int main()
{
  cout << reverseSentence("data structure and algorithm is scary"); // scary is algorithm and structure data
  return 0;
}
