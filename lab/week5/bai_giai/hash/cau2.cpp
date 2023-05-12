int foldShift(long long key, int addressSize)
{
  long long p = key;
  int demso = 1; // so chu so của key
  while (p >= 10)
  {
    p /= 10;
    demso++;
  }
  int n; // so phan duoc chia
  if (demso % addressSize == 0)
  {
    n = demso / addressSize;
  }
  else
  {
    n = demso / addressSize + 1;
  }
  // cout<<demso<<endl;
  // cout<<n<<endl;
  long long arr[n];
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      arr[i] = key / pow(10, demso - addressSize * (i + 1));
    }
    else if (i == n - 1)
    {
      arr[i] = key % (long long)pow(10, demso - addressSize * (i));
    }
    else
    {
      arr[i] = ((key) % ((long long)pow(10, demso - addressSize * (i)))) / pow(10, demso - addressSize * (i + 1));
    }
  }
  int foldshift = 0;
  for (int j = 0; j < n; j++)
  {
    foldshift += arr[j];
  }
  if (foldshift >= pow(10, addressSize))
  {
    foldshift = (int)foldshift % (int)pow(10, addressSize);
  }
  return foldshift;
}

int rotation(long long key, int addressSize)
{
  int demso = 1;
  long long p = key;
  while (p >= 10)
  {
    p /= 10;
    demso++;
  }
  long long temp = key % 10;
  temp = temp * pow(10, demso - 1) + key / 10;
  return foldShift(temp, addressSize);
}
