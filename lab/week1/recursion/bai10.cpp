#include <iostream>
#include <string>

using namespace std;
int find(string& s, int idx, int open, int close){
  if(idx>=(int)s.length()) return open+close;
  if(s[idx]==')' && open == 0) return find(s, idx+1,open,close+1);
  if(s[idx]==')'&&open>0) return find(s,idx+1,open-1,close);
  return find(s,idx+1,open+1,close);
}

int mininumBracketAdd(string s) {
    // STUDENT ANSWER
    return find(s,0,0,0);
}

int main()
{
  cout << mininumBracketAdd("))()))()()") << endl;
  cout << mininumBracketAdd(")()))()))())())))))(") << endl;
  return 0;
}
