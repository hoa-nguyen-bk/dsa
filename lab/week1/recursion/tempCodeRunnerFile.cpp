int i = 2; // Skip the opening bracket
    int countBracket = 1;
    while (countBracket != 0)
    {
      cout << "[" << i << "]:" << s[i] << " - ";
      str += s[i];
      if (s[i] == ')')
      {
        countBracket--;
      }
      else if (s[i] == '(')
      {
        countBracket++;
      }
      i++;
    }