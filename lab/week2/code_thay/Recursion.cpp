//Cau 1

void printArray(int n)
{
    if(n == 0) {
        cout << 0;
        return;
    }
    printArray(n - 1);
    cout << ", " << n;
}

//Cau 2
void printPattern(int n) 
{ 
    if(n <= 0) {
        cout << n;
        return;
    }
    cout << n << " ";
    printPattern(n - 5);
    cout << " " << n;
}

//Cau 3
int findMax(int* arr, int length)
{
    /*  
     * STUDENT ANSWER
     */
    if(length == 0) return arr[0];
    int maxi = findMax(arr, length - 1);
    if(maxi > arr[n - 1]){
        return maxi;
    }
    else return arr[n - 1];
}

//Cau 4
bool isPalindrome(string str){
    if(str.length() < 2) return true;
    if(str[0] == ' ') return isPalindrome(str.substr(1, str.length() - 1));
    if(str[str.length() - 1] == ' ') return isPalindrome(str.substr(0, str.length() - 1));
    if(str[0] != str[str.length() - 1]) return false;
    return isPalindrome(str.substr(1,str.length() - 2);
}

//Cau 4-Cach 2
bool isPalindromeRec(string str, int left, int right){
    if(left > right - 1) return true;
    if(str[left] == ' ') return isPalindromeRec(str, left + 1, right);
    if(str[right] == ' ') return isPalindromeRec(str, left, right - 1);
    if(str[left] != str[right]) return false;
    return isPalindromeRec(str, left + 1, right - 1);
}

bool isPalindrome(string str){
    return isPalindromeRec(str, 0, str.length() - 1);
}

