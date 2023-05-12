long int midSquare(long int seed)
{
	long int number = pow(seed, 2);
	string str = to_string(number);
	int res = stoi(str.substr(str.length() - 6, 4));
	return res;

}
long int moduloDivision(long int seed, long int mod)
{
	return seed % mod;
}
long int digitExtraction(long int seed, int* extractDigits, int size)
{
	string str1 = to_string(seed);
	string str2 = "";
	int i = 0;
	while(i<size)
	{	
		str2 = str2 + str1[extractDigits[i]];
		i++;
	}
	int res = stoi(str2);
	return res;
}