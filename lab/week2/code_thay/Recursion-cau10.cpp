//cout << mininumBracketAdd(")))((");
//5

//
// int mininumHelper(const string& s, int idx, int balance, int add){
//     if(idx == s.length()) return balance + add;
//     if(s[idx] == '(') {
//         balance++;
//     } else balance--;
//     if(balance == -1) {
//         balance += 1;
//         add += 1;
//     }
//     return mininumHelper(s, idx + 1, balance, add);
// }

int mininumBracketAdd(string s){
    // return mininumHelper(s, 0, 0, 0);
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(') st.push(s[i]);
        //short-circuit
        else if (s[i] == ')' && !st.empty() && st.top() == '(') st.pop();
        else st.push(s[i]);
    }
    
    return st.size();
}