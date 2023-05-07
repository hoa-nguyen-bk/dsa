#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<int> sortArrayInDescendingOrder(vector<int>& arr)
{
	priority_queue<int, vector<int>, less<int> > minHeap;

	for (int num : arr) {
    cout << num <<endl;
		minHeap.push(num);
	}

	vector<int> result;
	while (!minHeap.empty()) {
		int top = minHeap.top();
		minHeap.pop();
		result.insert(result.begin(), top);
	}

	return result;
}

int main()
{
	vector<int> arr = { 4, 6, 3, 2, 9 };
	vector<int> result = sortArrayInDescendingOrder(arr);

	for (int num : result) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}
// This code is contributed by chinmaya121221
