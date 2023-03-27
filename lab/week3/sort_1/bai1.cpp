#include <iostream>
#include "./sorting.h"

using namespace std;
// TODO: Write your code here

template <class T>
static void sortSegment(T *start, T *end, int segment_idx, int cur_segment_total)
{
  // TODO
}

template <class T>
static void ShellSort(T *start, T *end, int *num_segment_list, int num_phases)
{
  // TODO
  // Note: You must print out the array after sorting segments to check whether your algorithm is true.
}
int main()
{
  int num_segment_list[] = {1, 3, 5};
  int num_phases = 3;
  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);
  // 5 segments: 5 4 3 2 1 10 9 8 7 6
  // 3 segments: 2 1 3 5 4 7 6 8 10 9
  // 1 segments: 1 2 3 4 5 6 7 8 9 10
  return 0;
}
