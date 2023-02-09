<!-- Given the following types:

typedef struct Item* ptr;
struct Item
{
    int value;
    ptr next;
}

Write function inputList() that inputs from stdin a sequence of non-negative integer numbers until meeting a negative value and returns the linked list of input values (excluding the negative value) in reversed order.  -->

#include <iostream>;
using namespace std;

//này là định nghĩa ptr là con trỏ cho struct Item, mục đích định nghĩa là để đơn giản cho con trỏ ptr sau mỗi lần định nghĩa
typedef struct Item* ptr;
struct Item{
    int value;
    ptr next;
}

int inputList(){
    do{
        int 
        cin >> 
    }
}

int main (){
    inputList();
    return 0;
}