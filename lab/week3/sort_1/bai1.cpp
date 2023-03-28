
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
    cout << "current = " << current << "; count = " << count << endl;
    while (current < count)
    {

      T temp = start[current];
      int walker = current - k;
      cout << "temp = " << temp << "; walker = " << walker << endl;
      while (walker >= 0 && temp < start[walker])
      {
        start[walker + k] = start[walker];
        cout << "start[walker + k] [" << walker + k << "]  = start[walker][" << walker << "]" << endl;
        cout << "while: ";
        printArray(start, end);
        walker = walker - k;
        cout << "walker - k = " << walker << endl;
      }
      start[walker + k] = temp;
      current = current + k;
      cout << "walker + k = " << walker + k << "; current + k = " << current << endl;
      cout << "out: ";
      printArray(start, end);
      cout << endl;
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
      int segment_size = (end - start) / k;

      int segment = 0;
      while (segment <= k)
      {
        cout << "segment = " << segment << "; k = " << k << endl;
        sortSegment(start, end, segment, k);
        segment++;
      }

      cout << segment_size << " = segment size" << endl;
      // Sort each segment for the current phase

      // Print the sorted array for the current phase
      cout << "========== ";
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