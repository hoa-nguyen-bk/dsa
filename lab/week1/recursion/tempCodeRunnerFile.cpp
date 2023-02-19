 if (length <= 1)
  {
    return true;
  }
  else if (str[0] == str[length - 1])
  {
    string new_string = str.substr(1, length - 2);
    cout << " == ";
    printChar(new_string);
    return isPalindrome(new_string);
  }