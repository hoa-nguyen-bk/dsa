#include <iostream>
using namespace std;

// typedef giúp cho code dễ đọc dễ maintain, alias ptr có ý nghĩa hơn int * trong cái ex này
// typedef int *ptr;
typedef struct Item* ptr;
// bi giờ cho thêm cái struct mới mệt
struct Item
{
  int value;
  //trong chatgpt kêu cái dòng dưới thay thế cho int *next tại có cái typedef bên trên rồi
  ptr next;
};

int main()
{
  // ptr x;
  // int y = 10;
  // gán địa chỉ y cho x
  // x = &y;
  // giá trị y được truy cập thông qua con trỏ x
  // cout << *x << endl;

  ptr head;
  head = new Item;
  //This code creates a pointer head  and assigns it a new instance of the Item  class. head  is now a pointer to the newly created Item instance.
  // head là một con trỏ tới đối tượng Item mới được tạo
  head->value = 5;
  head->next = nullptr;
  //nullptr is a keyword in C++ that represents a null pointer. It is used to represent a pointer that does not point to an object or a function. It is often used to indicate an empty or invalid pointer, and can be used to initialize a pointer to an invalid value.
  cout << head->next << endl;


  return 0;
}