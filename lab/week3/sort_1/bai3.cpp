
#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting
{
private:
  static void printArray(T *start, T *end)
  {
    int size = end - start;
    for (int i = 0; i < size; i++)
      cout << start[i] << " ";
    cout << endl;
  }

public:
  static void sortSegment(T *start, T *end, int segment_idx, int cur_segment_total)
  {
    // TODO
    // Calculate the segment size
    int k = cur_segment_total;
    int count = (end - start);
    if (count <= 0)
      return;

    int current = segment_idx + k;
    while (current < count)
    {

      T temp = start[current];
      int walker = current - k;
      while (walker >= 0 && temp < start[walker])
      {
        start[walker + k] = start[walker];
        walker = walker - k;
      }
      start[walker + k] = temp;
      current = current + k;
    }
  }

  static void ShellSort(T *start, T *end, int *num_segment_list, int num_phases)
  {
    // TODO
    // Note: You must print out the array after sorting segments to check whether your algorithm is true.
    // Iterate over each phase, lấy từ cái 5 segment đổ xún, là lấy cái cuối đổ xún
    for (int phase = num_phases - 1; phase >= 0; phase--)
    {
      // Get the number of segments and the segment size for the current phase
      int k = num_segment_list[phase];
      if (k < 1)
        return;

      int segment = 0;
      // Sort each segment for the current phase
      while (segment <= k)
      {
        sortSegment(start, end, segment, k);
        segment++;
      }

      // Print the sorted array for the current phase
      cout << k << " segments: ";
      printArray(start, end);
    }
  }
};
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