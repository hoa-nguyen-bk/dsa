#include <iostream>
#include "sortingyoutube.h"
using namespace std;
// Helping functions go here
// vector<int> heapSort(T* start)
// {
// 	priority_queue<T, vector<T>, greater<T> > minHeap;

// 	for (T num : start) {
// 		minHeap.push(num);
// 	}

// 	vector<int> result;
// 	while (!minHeap.empty()) {
// 		int top = minHeap.top();
// 		minHeap.pop();
// 		result.insert(result.begin(), top);
// 	}

// 	return result;
// }
int main()
{
  int arr[4] = {4, 2, 9, 1};
  Sorting<int>::heapSort(&arr[0], &arr[4]);
  // int arr[6] = {1, 12, 9, 5, 6, 10};
  // Sorting<int>::heapSort(&arr[0], &arr[6]);
  // 1, 2, 4, 9
  // int arr[4] = {-1, 0, 2, 3};
  // Sorting<int>::heapSort(&arr[0], &arr[4]);
  // -1, 0, 2, 3
  return 0;
}
