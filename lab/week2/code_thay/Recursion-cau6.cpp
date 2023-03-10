// cout << expand("2(ab3(cde)x)") << "\n";
// abcdecdecdexabcdecdecdex

// cout << expand("2(x0(y))3(z)") << "\n";
// xxzzz

//rfind()
//find()
//substr()
//replace()
string mulString(string s, int n){
    if (n == 0) return "";
    return s + mulString(s, n - 1);
}
string expand(string s) {
    if(s.length() == 0) return "";
    int last_open = s.rfind("(");
    if(last_open == -1) return s;
    int first_close = s.find(")", last_open + 1);
    // if(first_close == -1) return s;

    int times = s[last_open - 1] - '0';
    
    string temp = mulString(s.substr(last_open + 1, first_close - last_open - 1), times);

    return expand(s.replace(last_open - 1, first_close - last_open + 2, temp));
}