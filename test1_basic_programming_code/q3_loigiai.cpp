//  Given the following types:

// typedef struct Item* ptr;
// struct Item
// {
//     int value;
//     ptr next;
// }

// Write function inputList() that inputs from stdin a sequence of non-negative integer numbers until meeting a negative value and returns the linked list of input values (excluding the negative value) in reversed order.  -->

#include <iostream>
using namespace std;

//này là định nghĩa ptr là con trỏ cho struct Item, mục đích định nghĩa là để đơn giản cho con trỏ ptr sau mỗi lần định nghĩa
typedef struct Item* ptr;
struct Item{
    int value;
    ptr next;
}
//  có thể viết đầy đủ là Item* next; là lồng lại nó zô 
//  means: next is a pointer to a node structure, and indicates the next item in the list.  https://www.codeproject.com/Questions/5162706/Can-someone-explain-what-does-node-next-mean-intui#:~:text=C%2B%2B-,node*%20next%3B,next%20item%20in%20the%20list.
//  _______         ________
// |       | next  |        | next
// |data=5 | ----> |data=12 | ----> ...
// |_______|       |________|
// ví dụ cho linked list ./q3_linkedlist.cpp
// https://www.geeksforgeeks.org/create-linked-list-from-a-given-array/

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