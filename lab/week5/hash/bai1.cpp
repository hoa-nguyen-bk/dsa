#include <iostream>

using namespace std;

// In midSquare function: we eliminate 2 last digits and get the 4 next digits.
long int midSquare(long int seed)
{
  long int keySquare = seed * seed;
  long int takeOut2digit = keySquare / 100;
  long int result = takeOut2digit % 10000;
  return result;
}
long int moduloDivision(long int seed, long int mod)
{
  return seed % mod;
}
// In digitExtraction: extractDigits is a sorted array from smallest to largest index of digit in seed (index starts from 0). The array has size size.
long int digitExtraction(long int seed, int *extractDigits, int size)
{
  string st1 = to_string(seed);
  string st2 = "";
  for( int i = 0; i < size; i++){
    st2 += st1[extractDigits[i]];
  }
  return stoi(st2);
}
int main()
{
  int a[] = {1, 2, 5};
  cout << digitExtraction(122443, a, 3); // 223
  // cout << midSquare(9452);               // 3403
  return 0;
}
