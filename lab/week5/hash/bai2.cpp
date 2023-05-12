#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
// The folding method for constructing hash functions begins by dividing the item into equal-size pieces (the last piece may not be of equal size). These pieces are then added together to give the resulting hash value.
int foldShift(long long key, int addressSize)
{
  string st1 = to_string(key);
  int arrSize = st1.size() / addressSize;
  int arr[arrSize];
  int sum = 0;
  for (int i = 0; i < arrSize; i++)
  {
    string smst = st1.substr(i * addressSize, addressSize);
    cout << smst << endl;
    sum += stoi(smst);
  }
  return sum;
}

int rotation(long long key, int addressSize)
{
  string keyStr = to_string(key);
  string lastOne = keyStr.substr(keyStr.length() - 1);
  string rota = lastOne + keyStr.substr(0, keyStr.length() - 1);
  int result = foldShift(stoi(rota), addressSize);
  return result;
}
int main()
{
  cout << rotation(234567891, 3);
  // 26 //1368
  return 0;
}
